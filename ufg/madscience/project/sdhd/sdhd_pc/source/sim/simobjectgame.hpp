// File Line: 83
// RVA: 0x44D760
void __fastcall UFG::SimObjectProp::SimObjectProp(UFG::SimObjectProp *this, UFG::qSymbol *name)
{
  UFG::ComponentTypeTable *TypeTableProp; // rax

  TypeTableProp = UFG::GetTypeTableProp();
  UFG::SimObjectGame::SimObjectGame(this, TypeTableProp, name);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimObject>Vtbl *)&UFG::SimObjectProp::`vftable;
  this->m_Flags |= 0x2000u;
}

// File Line: 117
// RVA: 0x57D060
void __fastcall UFG::SimObjectInterestPoint::SimObjectInterestPoint(
        UFG::SimObjectInterestPoint *this,
        UFG::qSymbol *name)
{
  UFG::ComponentTypeTable *TypeTableInterestPoint; // rax

  TypeTableInterestPoint = UFG::GetTypeTableInterestPoint();
  UFG::SimObjectGame::SimObjectGame(this, TypeTableInterestPoint, name);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimObject>Vtbl *)&UFG::SimObjectInterestPoint::`vftable;
  this->m_Flags |= 0x1000u;
}

// File Line: 183
// RVA: 0x57D000
void __fastcall UFG::SimObjectCharacter::SimObjectCharacter(UFG::SimObjectCharacter *this, UFG::qSymbol *name)
{
  UFG::ComponentTypeTable *TypeTableCharacter; // rax

  TypeTableCharacter = UFG::GetTypeTableCharacter();
  UFG::SimObjectGame::SimObjectGame(this, TypeTableCharacter, name);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimObject>Vtbl *)&UFG::SimObjectCVBase::`vftable;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimObject>Vtbl *)&UFG::SimObjectCharacter::`vftable;
  this->m_Flags |= 0x4000u;
}

// File Line: 217
// RVA: 0x57D0C0
void __fastcall UFG::SimObjectVehicle::SimObjectVehicle(UFG::SimObjectVehicle *this, UFG::qSymbol *name)
{
  UFG::ComponentTypeTable *TypeTableVehicle; // rax

  TypeTableVehicle = UFG::GetTypeTableVehicle();
  UFG::SimObjectGame::SimObjectGame(this, TypeTableVehicle, name);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimObject>Vtbl *)&UFG::SimObjectCVBase::`vftable;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimObject>Vtbl *)&UFG::SimObjectVehicle::`vftable;
  this->m_Flags |= 0x8000u;
}

