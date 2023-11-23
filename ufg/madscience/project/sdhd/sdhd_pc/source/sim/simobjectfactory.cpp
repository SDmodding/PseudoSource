// File Line: 16
// RVA: 0x5807B0
UFG::SimObject *__fastcall SimObjectFactory::CreateSimObject(
        UFG::qPropertySet *propertySet,
        UFG::qSymbol *name,
        UFG::qSymbol *objectTypeResult)
{
  UFG::qSymbol *v5; // rax
  unsigned int mUID; // eax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::SimObject *v9; // rbx
  UFG::allocator::free_link *v10; // rax
  UFG::SimObject *v11; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::SimObject *v13; // rax
  UFG::allocator::free_link *v14; // rax
  UFG::SimObject *v15; // rax
  UFG::SimObject *v16; // rax

  v5 = PropertyUtils::Get<UFG::qSymbol>(propertySet, (UFG::qArray<unsigned long,0> *)&qSymbol_ObjectType, DEPTH_RECURSE);
  if ( !v5 )
    return UFG::Simulation::CreateSimObject(&UFG::gSim, name);
  mUID = v5->mUID;
  if ( mUID == -1 )
    return UFG::Simulation::CreateSimObject(&UFG::gSim, name);
  objectTypeResult->mUID = mUID;
  if ( mUID == qSymbol_Character.mUID )
  {
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v8 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x90ui64, "SimObject", 0i64, 1u);
    if ( !v8 )
    {
      v9 = 0i64;
      goto LABEL_29;
    }
    goto LABEL_27;
  }
  if ( mUID == qSymbol_Vehicle.mUID )
  {
    v10 = UFG::SimObject::operator new(0x90ui64);
    if ( v10 )
    {
      UFG::SimObjectVehicle::SimObjectVehicle((UFG::SimObjectVehicle *)v10, name);
      v9 = v11;
    }
    else
    {
      v9 = 0i64;
    }
    goto LABEL_29;
  }
  if ( mUID == qSymbol_Prop.mUID )
  {
    v12 = UFG::SimObject::operator new(0x90ui64);
    if ( !v12 )
    {
      v9 = 0i64;
      goto LABEL_29;
    }
    goto LABEL_19;
  }
  if ( mUID == qSymbol_Weapon.mUID )
  {
    v12 = UFG::SimObject::operator new(0x90ui64);
    if ( !v12 )
    {
      v9 = 0i64;
      goto LABEL_29;
    }
    goto LABEL_19;
  }
  if ( mUID == qSymbol_Door.mUID )
  {
    v12 = UFG::SimObject::operator new(0x90ui64);
    if ( !v12 )
    {
      v9 = 0i64;
      goto LABEL_29;
    }
LABEL_19:
    UFG::SimObjectProp::SimObjectProp((UFG::SimObjectProp *)v12, name);
    v9 = v13;
    goto LABEL_29;
  }
  if ( mUID == qSymbol_InterestPoint.mUID )
  {
    v14 = UFG::SimObject::operator new(0x90ui64);
    if ( v14 )
    {
      UFG::SimObjectInterestPoint::SimObjectInterestPoint((UFG::SimObjectInterestPoint *)v14, name);
      v9 = v15;
    }
    else
    {
      v9 = 0i64;
    }
  }
  else
  {
    if ( mUID != qSymbol_character_motion_tester.mUID )
      return UFG::Simulation::CreateSimObject(&UFG::gSim, name);
    v8 = UFG::SimObject::operator new(0x90ui64);
    if ( v8 )
    {
LABEL_27:
      UFG::SimObjectCharacter::SimObjectCharacter((UFG::SimObjectCharacter *)v8, name);
      v9 = v16;
      goto LABEL_29;
    }
    v9 = 0i64;
  }
LABEL_29:
  UFG::Simulation::TrackSimObject(&UFG::gSim, v9);
  if ( v9 )
    return v9;
  return UFG::Simulation::CreateSimObject(&UFG::gSim, name);
}

