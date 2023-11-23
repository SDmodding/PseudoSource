// File Line: 26
// RVA: 0x154CA80
__int64 LayerView::_dynamic_initializer_for__smhDebugSymbols__()
{
  LayerView::smhDebugSymbols.mCallback = 0i64;
  LayerView::smhDebugSymbols.mCallbackParam = 0i64;
  LayerView::smhDebugSymbols.mImpl = 0i64;
  *(_DWORD *)&LayerView::smhDebugSymbols.mFlags = 536870915;
  LayerView::smhDebugSymbols._mTargetState.mValue = 1;
  return atexit((int (__fastcall *)())LayerView::_dynamic_atexit_destructor_for__smhDebugSymbols__);
}

