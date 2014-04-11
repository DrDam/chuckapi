<?php

function chuck_api_ping() {

  $response = drupal_http_request(chuck_api_getUrl('api-ping'));

  if ($response->code == 200) {
    $data = json_decode($response->data);
    return ($data->ping == 'pong') ? TRUE : FALSE;
  }

  return FALSE;
}

function chuck_api_simple_fact() {
  $data = chuck_api_request('txt', 'alea', 1);

  return (isset($data[0]->fact))? $data[0]->fact : '';
}

function chuck_api_simple_request($page = '') {

  $type = variable_get('chuck_api_type', 'txt');
  $tri = variable_get('chuck_api_sort', 'alea');
  $nb = variable_get('chuck_api_nb', '');

  return chuck_api_request($type, $tri, $nb, $page);
}

function chuck_api_request($type = 'txt', $tri = 'alea', $nb = '', $p = '') {

  $data = 'data=';
  $data .= 'type:' . $type . ';';
  $data .= 'tri:' . $tri . ';';

  if ($nb != '')
    $data .= 'nb:' . $nb;

  if ($p != '')
    $data .= ';p:' . $p;

  $response = drupal_http_request(chuck_api_getUrl() . '?' . $data);

  if ($response->code == 200) {
    return json_decode($response->data);
  }
  else {
    watchdog('notice', 'AAA');
    return FALSE;
  }
}

function chuck_api_getUrl($action = 'get') {
  $url = 'http://';
  $url .= variable_get('chuck_api_url', 'chucknorrisfacts.fr');
  $url .= '/api/'.$action;
  return $url;
}
