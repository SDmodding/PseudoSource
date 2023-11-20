// File Line: 139
// RVA: 0x1459B10
__int64 UFG::_dynamic_initializer_for__UIBlipIcon_Crime_Scene__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Crime_Scene", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UIBlipIcon_Crime_Scene, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__UIBlipIcon_Crime_Scene__);
}

// File Line: 161
// RVA: 0xBB950
void __fastcall UFG::UIHKMinimapBlipType::UIHKMinimapBlipType(UFG::UIHKMinimapBlipType *this)
{
  UFG::UIHKMinimapBlipType *v1; // rbx

  v1 = this;
  *(_QWORD *)&this->TypeNameSymbol.mUID = -1i64;
  UFG::qString::qString(&this->Caption);
  *(_DWORD *)&v1->IsWorldMapOnly = 0;
  v1->IsWorldMapZoomFiltered = 0;
  *(_QWORD *)&v1->FilterDistance = 0i64;
  v1->DrawDepth = 0;
  *(_DWORD *)&v1->IsHiddenIndoors = 256;
  v1->ProgressionFlow.mUID = qSymbol_none.mUID;
  v1->IsVisible = 1;
}

