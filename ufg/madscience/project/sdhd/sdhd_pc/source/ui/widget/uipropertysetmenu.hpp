// File Line: 23
// RVA: 0x5CE1B0
void __fastcall UFG::UIPropertySetMenuData::~UIPropertySetMenuData(UFG::UIPropertySetMenuData *this)
{
  this->vfptr = (UFG::UIPropertySetMenuDataVtbl *)&UFG::UIPropertySetMenuData::`vftable;
  UFG::qString::~qString(&this->mPathToWidget);
  UFG::qString::~qString(&this->mPropertySetName);
}

