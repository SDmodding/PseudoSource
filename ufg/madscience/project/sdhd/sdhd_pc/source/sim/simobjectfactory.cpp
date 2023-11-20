// File Line: 16
// RVA: 0x5807B0
UFG::SimObject *__fastcall SimObjectFactory::CreateSimObject(UFG::qPropertySet *propertySet, UFG::qSymbol *name, UFG::qSymbol *objectTypeResult)
{
  UFG::qSymbol *v3; // rbx
  UFG::qSymbol *v4; // rdi
  UFG::qSymbol *v5; // rax
  unsigned int v6; // eax
  UFG::qMemoryPool *v7; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::SimObject *v9; // rax
  UFG::SimObject *v10; // rbx
  UFG::allocator::free_link *v11; // rax
  UFG::SimObject *v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::SimObject *v14; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::SimObject *v16; // rax
  UFG::allocator::free_link *v17; // rax
  UFG::SimObject *v18; // rax
  UFG::allocator::free_link *v19; // rax
  UFG::SimObject *v20; // rax
  UFG::allocator::free_link *v21; // rax
  UFG::SimObject *v22; // rax

  v3 = objectTypeResult;
  v4 = name;
  v5 = PropertyUtils::Get<UFG::qSymbol>(propertySet, (UFG::qSymbol *)&qSymbol_ObjectType.mUID, DEPTH_RECURSE);
  if ( !v5 )
    return UFG::Simulation::CreateSimObject(&UFG::gSim, v4);
  v6 = v5->mUID;
  if ( v6 == -1 )
    return UFG::Simulation::CreateSimObject(&UFG::gSim, v4);
  v3->mUID = v6;
  if ( v6 == qSymbol_Character.mUID )
  {
    v7 = UFG::GetSimulationMemoryPool();
    v8 = UFG::qMemoryPool::Allocate(v7, 0x90ui64, "SimObject", 0i64, 1u);
    if ( v8 )
    {
      UFG::SimObjectCharacter::SimObjectCharacter((UFG::SimObjectCharacter *)v8, v4);
      v10 = v9;
    }
    else
    {
      v10 = 0i64;
    }
  }
  else if ( v6 == qSymbol_Vehicle.mUID )
  {
    v11 = UFG::SimObject::operator new(0x90ui64);
    if ( v11 )
    {
      UFG::SimObjectVehicle::SimObjectVehicle((UFG::SimObjectVehicle *)v11, v4);
      v10 = v12;
    }
    else
    {
      v10 = 0i64;
    }
  }
  else if ( v6 == qSymbol_Prop.mUID )
  {
    v13 = UFG::SimObject::operator new(0x90ui64);
    if ( v13 )
    {
      UFG::SimObjectProp::SimObjectProp((UFG::SimObjectProp *)v13, v4);
      v10 = v14;
    }
    else
    {
      v10 = 0i64;
    }
  }
  else if ( v6 == qSymbol_Weapon.mUID )
  {
    v15 = UFG::SimObject::operator new(0x90ui64);
    if ( v15 )
    {
      UFG::SimObjectProp::SimObjectProp((UFG::SimObjectProp *)v15, v4);
      v10 = v16;
    }
    else
    {
      v10 = 0i64;
    }
  }
  else if ( v6 == qSymbol_Door.mUID )
  {
    v17 = UFG::SimObject::operator new(0x90ui64);
    if ( v17 )
    {
      UFG::SimObjectProp::SimObjectProp((UFG::SimObjectProp *)v17, v4);
      v10 = v18;
    }
    else
    {
      v10 = 0i64;
    }
  }
  else if ( v6 == qSymbol_InterestPoint.mUID )
  {
    v19 = UFG::SimObject::operator new(0x90ui64);
    if ( v19 )
    {
      UFG::SimObjectInterestPoint::SimObjectInterestPoint((UFG::SimObjectInterestPoint *)v19, v4);
      v10 = v20;
    }
    else
    {
      v10 = 0i64;
    }
  }
  else
  {
    if ( v6 != qSymbol_character_motion_tester.mUID )
      return UFG::Simulation::CreateSimObject(&UFG::gSim, v4);
    v21 = UFG::SimObject::operator new(0x90ui64);
    if ( v21 )
    {
      UFG::SimObjectCharacter::SimObjectCharacter((UFG::SimObjectCharacter *)v21, v4);
      v10 = v22;
    }
    else
    {
      v10 = 0i64;
    }
  }
  UFG::Simulation::TrackSimObject(&UFG::gSim, v10);
  if ( v10 )
    return v10;
  return UFG::Simulation::CreateSimObject(&UFG::gSim, v4);
}

