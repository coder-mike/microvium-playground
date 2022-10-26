
// ------------------------- Beginning of implementation -----------------------------
// WARNING: This file is auto-generated. DO NOT EDIT

#include "App_ffi.h"

static const mvm_VMExportID _vmExportsIDs[3] = {
  /*[0]*/ 65535, // runRestoreEvents
  /*[1]*/ 65534, // fibonacci
  /*[2]*/ 65533, // command
};

static mvm_Value _vmExports[3];


const ImportRecord App::_vmImports[6] = {
  /*[0]*/ { 65535, App::_intToString_wrapper },
  /*[1]*/ { 65534, App::_floatToString_wrapper },
  /*[2]*/ { 65533, App::_floatLog_wrapper },
  /*[3]*/ { 65532, App::_stringLog_wrapper },
  /*[4]*/ { 65531, App::_emitAck_wrapper },
  /*[5]*/ { 65530, App::_emitError_wrapper },
};

App::App(const uint8_t* snapshot, size_t snapshotSize): mvm::VM() {
  _initialize(snapshot, snapshotSize);
}

void App::_initialize(const uint8_t* snapshot, size_t snapshotSize) {
  mvm_TeError err;
  err = mvm_restore(&_vm, (MVM_LONG_PTR_TYPE)snapshot, snapshotSize, this, _resolveImport);
  if (err != MVM_E_SUCCESS) MVM_FATAL_ERROR(_vm, err);
  err = mvm_resolveExports(_vm, _vmExportsIDs, _vmExports, 3);
  if (err != MVM_E_SUCCESS) MVM_FATAL_ERROR(_vm, err);
  runRestoreEvents();
}

App::App(const std::vector<uint8_t>& snapshot): _snapshotCopy(snapshot) {
  _initialize(_snapshotCopy.data(), _snapshotCopy.size());
}

mvm_TeError App::_resolveImport(mvm_HostFunctionID hostFunctionID, void* context, mvm_TfHostFunction* out_hostFunction) {
  for (int i = 0; i < 6; i++) {
    if (_vmImports[i].id == hostFunctionID) {
      *out_hostFunction = _vmImports[i].func;
      return MVM_E_SUCCESS;
    }
  }
  return MVM_E_FUNCTION_NOT_FOUND;
}


void App::runRestoreEvents() {
  mvm_Value _result;

  // Call the JS function
  mvm_TeError err = mvm_call(_vm, _vmExports[0], &_result, NULL, 0);
  if (err != MVM_E_SUCCESS) MVM_FATAL_ERROR(_vm, err);

  // Convert/return the result
  return ;
}

mvm_TeError App::_intToString_wrapper(mvm_VM* _vm, mvm_HostFunctionID hostFunctionID, mvm_Value* _result, mvm_Value* _args, uint8_t _argCount) {
  App* _app = (App*)mvm_getContext(_vm);

  // Prepare the arguments
  int32_t val = mvm_toInt32(_vm, _argCount >= 1 ? _args[0] : mvm_undefined);

  // Call the C function
  std::string __result = _app->intToString(val);

  // Convert the result
  *_result = mvm_newString(_vm, __result.c_str(), __result.size());

  return MVM_E_SUCCESS;
}


mvm_TeError App::_floatToString_wrapper(mvm_VM* _vm, mvm_HostFunctionID hostFunctionID, mvm_Value* _result, mvm_Value* _args, uint8_t _argCount) {
  App* _app = (App*)mvm_getContext(_vm);

  // Prepare the arguments
  double val = mvm_toFloat64(_vm, _argCount >= 1 ? _args[0] : mvm_undefined);

  // Call the C function
  std::string __result = _app->floatToString(val);

  // Convert the result
  *_result = mvm_newString(_vm, __result.c_str(), __result.size());

  return MVM_E_SUCCESS;
}


mvm_TeError App::_floatLog_wrapper(mvm_VM* _vm, mvm_HostFunctionID hostFunctionID, mvm_Value* _result, mvm_Value* _args, uint8_t _argCount) {
  App* _app = (App*)mvm_getContext(_vm);

  // Prepare the arguments
  double val = mvm_toFloat64(_vm, _argCount >= 1 ? _args[0] : mvm_undefined);

  // Call the C function
  _app->floatLog(val);

  // Convert the result
  *_result = mvm_undefined;

  return MVM_E_SUCCESS;
}


mvm_TeError App::_stringLog_wrapper(mvm_VM* _vm, mvm_HostFunctionID hostFunctionID, mvm_Value* _result, mvm_Value* _args, uint8_t _argCount) {
  App* _app = (App*)mvm_getContext(_vm);

  // Prepare the arguments
  std::string val = std::string(mvm_toStringUtf8(_vm, _argCount >= 1 ? _args[0] : mvm_undefined, NULL));

  // Call the C function
  _app->stringLog(val);

  // Convert the result
  *_result = mvm_undefined;

  return MVM_E_SUCCESS;
}


mvm_TeError App::_emitAck_wrapper(mvm_VM* _vm, mvm_HostFunctionID hostFunctionID, mvm_Value* _result, mvm_Value* _args, uint8_t _argCount) {
  App* _app = (App*)mvm_getContext(_vm);

  // Prepare the arguments
  std::string command = std::string(mvm_toStringUtf8(_vm, _argCount >= 1 ? _args[0] : mvm_undefined, NULL));

  // Call the C function
  _app->emitAck(command);

  // Convert the result
  *_result = mvm_undefined;

  return MVM_E_SUCCESS;
}


mvm_TeError App::_emitError_wrapper(mvm_VM* _vm, mvm_HostFunctionID hostFunctionID, mvm_Value* _result, mvm_Value* _args, uint8_t _argCount) {
  App* _app = (App*)mvm_getContext(_vm);

  // Prepare the arguments
  std::string command = std::string(mvm_toStringUtf8(_vm, _argCount >= 1 ? _args[0] : mvm_undefined, NULL));
  std::string err = std::string(mvm_toStringUtf8(_vm, _argCount >= 2 ? _args[1] : mvm_undefined, NULL));

  // Call the C function
  _app->emitError(command, err);

  // Convert the result
  *_result = mvm_undefined;

  return MVM_E_SUCCESS;
}


void App::fibonacci(int32_t limit) {
  // Prepare the arguments
  mvm_Value _args[1];
  _args[0] = mvm_newInt32(_vm, limit);
  mvm_Value _result;

  // Call the JS function
  mvm_TeError err = mvm_call(_vm, _vmExports[1], &_result, _args, 1);
  if (err != MVM_E_SUCCESS) MVM_FATAL_ERROR(_vm, err);

  // Convert/return the result
  return ;
}

void App::command(std::string command) {
  // Prepare the arguments
  mvm_Value _args[1];
  _args[0] = mvm_newString(_vm, command.c_str(), command.size());
  mvm_Value _result;

  // Call the JS function
  mvm_TeError err = mvm_call(_vm, _vmExports[2], &_result, _args, 1);
  if (err != MVM_E_SUCCESS) MVM_FATAL_ERROR(_vm, err);

  // Convert/return the result
  return ;
}
// ------------------------- End of implementation -----------------------------
