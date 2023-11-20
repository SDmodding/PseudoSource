// File Line: 83
// RVA: 0x44D760
void __fastcall UFG::SimObjectProp::SimObjectProp(UFG::SimObjectProp *this, UFG::qSymbol *name)
{
  UFG::qSymbol *v2; // rbx
  UFG::SimObjectProp *v3; // rdi
  UFG::ComponentTypeTable *v4; // rax

  v2 = name;
  v3 = this;
  v4 = UFG::GetTypeTableProp();
  UFG::SimObjectGame::SimObjectGame((UFG::SimObjectGame *)&v3->vfptr, v4, v2);
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimObject>Vtbl *)&UFG::SimObjectProp::`vftable';
  v3->m_Flags |= 0x2000u;
}

// File Line: 117
// RVA: 0x57D060
void __fastcall UFG::SimObjectInterestPoint::SimObjectInterestPoint(UFG::SimObjectInterestPoint *this, UFG::qSymbol *name)
{
  UFG::qSymbol *v2; // rbx
  UFG::SimObjectInterestPoint *v3; // rdi
  UFG::ComponentTypeTable *v4; // rax

  v2 = name;
  v3 = this;
  v4 = UFG::GetTypeTableInterestPoint();
  UFG::SimObjectGame::SimObjectGame((UFG::SimObjectGame *)&v3->vfptr, v4, v2);
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimObject>Vtbl *)&UFG::SimObjectInterestPoint::`vftable';
  v3->m_Flags |= 0x1000u;
}

// File Line: 183
// RVA: 0x57D000
void __fastcall UFG::SimObjectCharacter::SimObjectCharacter(UFG::SimObjectCharacter *this, UFG::qSymbol *name)
{
  UFG::qSymbol *v2; // rbx
  UFG::SimObjectCharacter *v3; // rdi
  UFG::ComponentTypeTable *v4; // rax

  v2 = name;
  v3 = this;
  v4 = UFG::GetTypeTableCharacter();
  UFG::SimObjectGame::SimObjectGame((UFG::SimObjectGame *)&v3->vfptr, v4, v2);
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimObject>Vtbl *)&UFG::SimObjectCVBase::`vftable';
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimObject>Vtbl *)&UFG::SimObjectCharacter::`vftable';
  v3->m_Flags |= 0x4000u;
}

// File Line: 217
// RVA: 0x57D0C0
void __fastcall UFG::SimObjectVehicle::SimObjectVehicle(UFG::SimObjectVehicle *this, UFG::qSymbol *name)
{
  UFG::qSymbol *v2; // rbx
  UFG::SimObjectVehicle *v3; // rdi
  UFG::ComponentTypeTable *v4; // rax

  v2 = name;
  v3 = this;
  v4 = UFG::GetTypeTableVehicle();
  UFG::SimObjectGame::SimObjectGame((UFG::SimObjectGame *)&v3->vfptr, v4, v2);
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimObject>Vtbl *)&UFG::SimObjectCVBase::`vftable';
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimObject>Vtbl *)&UFG::SimObjectVehicle::`vftable';
  v3->m_Flags |= 0x8000u;
}

