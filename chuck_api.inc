<?php

function chuck_api_validation()
{
  $url = 'http://';
  $url .= variable_get('chuck_api_url', 'chucknorrisfacts.fr');
  $url .= '/api/ping';
  
  $response = drupal_http_request($url);
  
  if($response->code == 200 )
  {
    $data = json_decode($response->data);
    return ($data->ping == 'pong') ? TRUE : FALSE ;
  }
  
  return FALSE;
}

function chuck_api_make_request($page = null)
{
  $url = 'http://';
  $url .= variable_get('chuck_api_url', 'chucknorrisfacts.fr');
  $url .= '/api/get';
  
  $data = 'data=';
  $data .= 'type:'.variable_get('chuck_api_type', 'txt').';';
  $data .= 'tri:'.variable_get('chuck_api_sort', 'alea').';';
  
  $nb = variable_get('chuck_api_nb', '');
  if($nb != '') $data .= ';nb:'.$nb;
  
  $out = drupal_http_request($url,array('data'=>$data));
  dpm($data);
  dpm($url);
  dpm($out);
  
}