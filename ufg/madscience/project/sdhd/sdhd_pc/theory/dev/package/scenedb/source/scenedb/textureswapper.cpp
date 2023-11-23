// File Line: 32
// RVA: 0x1470670
__int64 UFG::_dynamic_initializer_for__smhTextureData__()
{
  UFG::smhTextureData.mCallback = 0i64;
  UFG::smhTextureData.mCallbackParam = 0i64;
  UFG::smhTextureData.mImpl = 0i64;
  *(_DWORD *)&UFG::smhTextureData.mFlags = 536870915;
  UFG::smhTextureData._mTargetState.mValue = 1;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__smhTextureData__);
}

// File Line: 33
// RVA: 0x1470620
__int64 UFG::_dynamic_initializer_for__smhModelData__()
{
  UFG::smhModelData.mCallback = 0i64;
  UFG::smhModelData.mCallbackParam = 0i64;
  UFG::smhModelData.mImpl = 0i64;
  *(_DWORD *)&UFG::smhModelData.mFlags = 536870915;
  UFG::smhModelData._mTargetState.mValue = 1;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__smhModelData__);
}

