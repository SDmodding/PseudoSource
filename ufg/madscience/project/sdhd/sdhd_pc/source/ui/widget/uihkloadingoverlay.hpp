// File Line: 16
// RVA: 0x1481EA0
__int64 UFG::_dynamic_initializer_for__UI_HASH_LOADING_ICON_SHOW__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("LOADING_ICON_SHOW", 0xFFFFFFFF);
  UI_HASH_LOADING_ICON_SHOW = result;
  return result;
}

// File Line: 17
// RVA: 0x1481EC0
__int64 UFG::_dynamic_initializer_for__UI_HASH_LOADING_ICON_SHOW_NEXT_SAVE_ICON__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("LOADING_ICON_SHOW_NEXT_SAVE_ICON", 0xFFFFFFFF);
  UI_HASH_LOADING_ICON_SHOW_NEXT_SAVE_ICON = result;
  return result;
}

// File Line: 18
// RVA: 0x1481E80
__int64 UFG::_dynamic_initializer_for__UI_HASH_LOADING_ICON_HIDE__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("LOADING_ICON_HIDE", 0xFFFFFFFF);
  UI_HASH_LOADING_ICON_HIDE = result;
  return result;
}

// File Line: 25
// RVA: 0x5C9790
void __fastcall UFG::UIHKLoadingOverlay::~UIHKLoadingOverlay(UFG::UIHKLoadingOverlay *this)
{
  this->vfptr = (UFG::UIHKLoadingOverlayVtbl *)&UFG::UIHKLoadingOverlay::`vftable;
}

