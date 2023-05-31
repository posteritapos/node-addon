#include <node_api.h>
#include <stdio.h>

napi_value HelloWorld(napi_env env, napi_callback_info info) {
  printf("Hello, World!\n");
  return NULL;
}

napi_value Init(napi_env env, napi_value exports) {
  napi_value fn;
  napi_create_function(env, NULL, 0, HelloWorld, NULL, &fn);
  napi_set_named_property(env, exports, "helloWorld", fn);
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
