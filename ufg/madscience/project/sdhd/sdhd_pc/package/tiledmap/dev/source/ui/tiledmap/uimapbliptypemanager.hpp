// File Line: 139
// RVA: 0x1459B10
__int64 UFG::_dynamic_initializer_for__UIBlipIcon_Crime_Scene__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Crime_Scene", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UIBlipIcon_Crime_Scene, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__UIBlipIcon_Crime_Scene__);
}

// File Line: 161
// RVA: 0xBB950
void __fastcall UFG::UIHKMinimapBlipType::UIHKMinimapBlipType(UFG::UIHKMinimapBlipType *this)
{
  *(_QWORD *)&this->TypeNameSymbol.mUID = -1i64;
  UFG::qString::qString(&this->Caption);
  *(_DWORD *)&this->IsWorldMapOnly = 0;
  this->IsWorldMapZoomFiltered = 0;
  *(_QWORD *)&this->FilterDistance = 0i64;
  this->DrawDepth = 0;
  *(_DWORD *)&this->IsHiddenIndoors = 256;
  this->ProgressionFlow.mUID = qSymbol_none.mUID;
  this->IsVisible = 1;
}

