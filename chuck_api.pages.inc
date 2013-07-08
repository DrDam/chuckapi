<?php

function chuck_page_form() {
  $form = array();
  chuck_get_validation();

  $form['params'] = array(
    '#type' => 'fieldset',
    '#title' => t('Contact settings'),
    '#weight' => 5,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['params']['intro'] = array(
    '#markup' => t('Introduction'),
  );

  $form['params']['chuck_api_url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL'),
    '#default_value' => variable_get('chuck_api_url', 'chucknorrisfacts.fr'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => TRUE,
  );
  $form['params']['chuck_api_type'] = array(
    '#type' => 'select',
    '#title' => t('Fact Type'),
    '#options' => array(
      'txt' => t('Text facts'),
      'img' => t('Image facts'),
    ),
    '#default_value' => variable_get('chuck_api_type', 'txt'),
    '#description' => t('Choose type of fact'),
  );

  $form['params']['chuck_api_sort'] = array(
    '#type' => 'select',
    '#title' => t('Sort parameter'),
    '#options' => array(
      'last' => t('lasts facts'),
      'first' => t('firsts facts'),
      'alea' => t('random facts'),
      'top' => t('top facts'),
      'flop' => t('worst facts'),
      'mtop' => t('median top facts'),
      'mflop' => t('median worst facts')
    ),
    '#default_value' => variable_get('chuck_api_sort', 'alea'),
    '#description' => t('choose the sort parameter'),
  );

  $form['params']['chuck_api_nb'] = array(
    '#type' => 'textfield',
    '#title' => t('number'),
    '#default_value' => variable_get('chuck_api_nb', ''),
    '#size' => 10,
    '#maxlength' => 10,
    '#description' => t('Number of facts , max 100'),
  );

  return system_settings_form($form);
}

function chuck_get_validation()
{
  module_load_include('inc', 'chuck_api');
  $bool = chuck_api_validation();
  
  return ($bool == TRUE) 
            ? drupal_set_message(t('ChuckNorrisFacts-fr contacted !'))
            : drupal_set_message(t('Can\'t contact ChuckNorrisFacts-fr'),'error')
    ;
}