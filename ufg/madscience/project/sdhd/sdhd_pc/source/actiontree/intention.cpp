// File Line: 17
// RVA: 0x1483DC0
__int64 dynamic_initializer_for__gActionRequestEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&gActionRequestEnum, "Global/Act/ActionRequestEnum.xml");
  return atexit(dynamic_atexit_destructor_for__gActionRequestEnum__);
}

// File Line: 18
// RVA: 0x1488230
__int64 dynamic_initializer_for__gFacialRequestEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&gFacialRequestEnum, "Global/Act/FacialRequestEnum.xml");
  return atexit(dynamic_atexit_destructor_for__gFacialRequestEnum__);
}

// File Line: 20
// RVA: 0x1485840
__int64 dynamic_initializer_for__gActionRequest_INVALID__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "INVALID");
  gActionRequest_INVALID.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_INVALID;
  gActionRequest_INVALID.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_INVALID;
  gActionRequest_INVALID.m_EnumSymbol.mUID = -1;
  gActionRequest_INVALID.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_INVALID.m_EnumValue = 0i64;
  gActionRequest_INVALID.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_INVALID);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_INVALID;
    gActionRequest_INVALID.mPrev = v1;
    gActionRequest_INVALID.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_INVALID;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_INVALID__);
}

// File Line: 22
// RVA: 0x14864A0
__int64 dynamic_initializer_for__gActionRequest_PDAExit__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "PDAExit");
  gActionRequest_PDAExit.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_PDAExit;
  gActionRequest_PDAExit.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_PDAExit;
  gActionRequest_PDAExit.m_EnumSymbol.mUID = -1;
  gActionRequest_PDAExit.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_PDAExit.m_EnumValue = 0i64;
  gActionRequest_PDAExit.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_PDAExit);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_PDAExit;
    gActionRequest_PDAExit.mPrev = v1;
    gActionRequest_PDAExit.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_PDAExit;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_PDAExit__);
}

// File Line: 23
// RVA: 0x1486550
__int64 dynamic_initializer_for__gActionRequest_PDATalk__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "PDATalk");
  gActionRequest_PDATalk.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_PDATalk;
  gActionRequest_PDATalk.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_PDATalk;
  gActionRequest_PDATalk.m_EnumSymbol.mUID = -1;
  gActionRequest_PDATalk.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_PDATalk.m_EnumValue = 0i64;
  gActionRequest_PDATalk.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_PDATalk);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_PDATalk;
    gActionRequest_PDATalk.mPrev = v1;
    gActionRequest_PDATalk.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_PDATalk;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_PDATalk__);
}

// File Line: 24
// RVA: 0x1486600
__int64 dynamic_initializer_for__gActionRequest_PDAViewText__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "PDAViewText");
  gActionRequest_PDAViewText.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_PDAViewText;
  gActionRequest_PDAViewText.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_PDAViewText;
  gActionRequest_PDAViewText.m_EnumSymbol.mUID = -1;
  gActionRequest_PDAViewText.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_PDAViewText.m_EnumValue = 0i64;
  gActionRequest_PDAViewText.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_PDAViewText);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_PDAViewText;
    gActionRequest_PDAViewText.mPrev = v1;
    gActionRequest_PDAViewText.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_PDAViewText;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_PDAViewText__);
}

// File Line: 26
// RVA: 0x1486970
__int64 dynamic_initializer_for__gActionRequest_Raw_Focus__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Raw_Focus");
  gActionRequest_Raw_Focus.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Raw_Focus;
  gActionRequest_Raw_Focus.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Raw_Focus;
  gActionRequest_Raw_Focus.m_EnumSymbol.mUID = -1;
  gActionRequest_Raw_Focus.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Raw_Focus.m_EnumValue = 0i64;
  gActionRequest_Raw_Focus.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Raw_Focus);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Raw_Focus;
    gActionRequest_Raw_Focus.mPrev = v1;
    gActionRequest_Raw_Focus.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Raw_Focus;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Raw_Focus__);
}

// File Line: 27
// RVA: 0x1486A20
__int64 dynamic_initializer_for__gActionRequest_Raw_Focus_Full__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Raw_Focus_Full");
  gActionRequest_Raw_Focus_Full.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Raw_Focus_Full;
  gActionRequest_Raw_Focus_Full.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Raw_Focus_Full;
  gActionRequest_Raw_Focus_Full.m_EnumSymbol.mUID = -1;
  gActionRequest_Raw_Focus_Full.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Raw_Focus_Full.m_EnumValue = 0i64;
  gActionRequest_Raw_Focus_Full.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Raw_Focus_Full);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Raw_Focus_Full;
    gActionRequest_Raw_Focus_Full.mPrev = v1;
    gActionRequest_Raw_Focus_Full.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Raw_Focus_Full;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Raw_Focus_Full__);
}

// File Line: 28
// RVA: 0x1486AD0
__int64 dynamic_initializer_for__gActionRequest_Raw_Focus_Lock__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Raw_Focus_Lock");
  gActionRequest_Raw_Focus_Lock.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Raw_Focus_Lock;
  gActionRequest_Raw_Focus_Lock.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Raw_Focus_Lock;
  gActionRequest_Raw_Focus_Lock.m_EnumSymbol.mUID = -1;
  gActionRequest_Raw_Focus_Lock.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Raw_Focus_Lock.m_EnumValue = 0i64;
  gActionRequest_Raw_Focus_Lock.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Raw_Focus_Lock);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Raw_Focus_Lock;
    gActionRequest_Raw_Focus_Lock.mPrev = v1;
    gActionRequest_Raw_Focus_Lock.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Raw_Focus_Lock;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Raw_Focus_Lock__);
}

// File Line: 30
// RVA: 0x1483F80
__int64 dynamic_initializer_for__gActionRequest_Action__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Action");
  gActionRequest_Action.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Action;
  gActionRequest_Action.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Action;
  gActionRequest_Action.m_EnumSymbol.mUID = -1;
  gActionRequest_Action.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Action.m_EnumValue = 0i64;
  gActionRequest_Action.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Action);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Action;
    gActionRequest_Action.mPrev = v1;
    gActionRequest_Action.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Action;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Action__);
}

// File Line: 31
// RVA: 0x1485420
__int64 dynamic_initializer_for__gActionRequest_Grab__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Grab");
  gActionRequest_Grab.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Grab;
  gActionRequest_Grab.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Grab;
  gActionRequest_Grab.m_EnumSymbol.mUID = -1;
  gActionRequest_Grab.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Grab.m_EnumValue = 0i64;
  gActionRequest_Grab.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Grab);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Grab;
    gActionRequest_Grab.mPrev = v1;
    gActionRequest_Grab.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Grab;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Grab__);
}

// File Line: 32
// RVA: 0x14880D0
__int64 dynamic_initializer_for__gActionRequest_Weapon__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Weapon");
  gActionRequest_Weapon.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Weapon;
  gActionRequest_Weapon.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Weapon;
  gActionRequest_Weapon.m_EnumSymbol.mUID = -1;
  gActionRequest_Weapon.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Weapon.m_EnumValue = 0i64;
  gActionRequest_Weapon.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Weapon);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Weapon;
    gActionRequest_Weapon.mPrev = v1;
    gActionRequest_Weapon.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Weapon;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Weapon__);
}

// File Line: 33
// RVA: 0x1487AA0
__int64 dynamic_initializer_for__gActionRequest_VehicleEnter__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "VehicleEnter");
  gActionRequest_VehicleEnter.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleEnter;
  gActionRequest_VehicleEnter.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleEnter;
  gActionRequest_VehicleEnter.m_EnumSymbol.mUID = -1;
  gActionRequest_VehicleEnter.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_VehicleEnter.m_EnumValue = 0i64;
  gActionRequest_VehicleEnter.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_VehicleEnter);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleEnter;
    gActionRequest_VehicleEnter.mPrev = v1;
    gActionRequest_VehicleEnter.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleEnter;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_VehicleEnter__);
}

// File Line: 34
// RVA: 0x1484D40
__int64 dynamic_initializer_for__gActionRequest_EnterVehicleForced__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "EnterVehicleForced");
  gActionRequest_EnterVehicleForced.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_EnterVehicleForced;
  gActionRequest_EnterVehicleForced.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_EnterVehicleForced;
  gActionRequest_EnterVehicleForced.m_EnumSymbol.mUID = -1;
  gActionRequest_EnterVehicleForced.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_EnterVehicleForced.m_EnumValue = 0i64;
  gActionRequest_EnterVehicleForced.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_EnterVehicleForced);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_EnterVehicleForced;
    gActionRequest_EnterVehicleForced.mPrev = v1;
    gActionRequest_EnterVehicleForced.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_EnterVehicleForced;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_EnterVehicleForced__);
}

// File Line: 36
// RVA: 0x1483E20
__int64 dynamic_initializer_for__gActionRequest_AIAvoidanceStrafe__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "AIAvoidanceStrafe");
  gActionRequest_AIAvoidanceStrafe.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_AIAvoidanceStrafe;
  gActionRequest_AIAvoidanceStrafe.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_AIAvoidanceStrafe;
  gActionRequest_AIAvoidanceStrafe.m_EnumSymbol.mUID = -1;
  gActionRequest_AIAvoidanceStrafe.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_AIAvoidanceStrafe.m_EnumValue = 0i64;
  gActionRequest_AIAvoidanceStrafe.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_AIAvoidanceStrafe);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_AIAvoidanceStrafe;
    gActionRequest_AIAvoidanceStrafe.mPrev = v1;
    gActionRequest_AIAvoidanceStrafe.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_AIAvoidanceStrafe;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_AIAvoidanceStrafe__);
}

// File Line: 38
// RVA: 0x1483ED0
__int64 dynamic_initializer_for__gActionRequest_Accept__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Accept");
  gActionRequest_Accept.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Accept;
  gActionRequest_Accept.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Accept;
  gActionRequest_Accept.m_EnumSymbol.mUID = -1;
  gActionRequest_Accept.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Accept.m_EnumValue = 0i64;
  gActionRequest_Accept.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Accept);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Accept;
    gActionRequest_Accept.mPrev = v1;
    gActionRequest_Accept.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Accept;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Accept__);
}

// File Line: 39
// RVA: 0x1484030
__int64 dynamic_initializer_for__gActionRequest_Activate__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Activate");
  gActionRequest_Activate.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Activate;
  gActionRequest_Activate.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Activate;
  gActionRequest_Activate.m_EnumSymbol.mUID = -1;
  gActionRequest_Activate.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Activate.m_EnumValue = 0i64;
  gActionRequest_Activate.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Activate);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Activate;
    gActionRequest_Activate.mPrev = v1;
    gActionRequest_Activate.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Activate;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Activate__);
}

// File Line: 40
// RVA: 0x14840E0
__int64 dynamic_initializer_for__gActionRequest_Aiming__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Aiming");
  gActionRequest_Aiming.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Aiming;
  gActionRequest_Aiming.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Aiming;
  gActionRequest_Aiming.m_EnumSymbol.mUID = -1;
  gActionRequest_Aiming.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Aiming.m_EnumValue = 0i64;
  gActionRequest_Aiming.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Aiming);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Aiming;
    gActionRequest_Aiming.mPrev = v1;
    gActionRequest_Aiming.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Aiming;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Aiming__);
}

// File Line: 41
// RVA: 0x1484190
__int64 dynamic_initializer_for__gActionRequest_AimingPreventFreeAimSpeedModifier__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "AimingPreventFreeAimSpeedModifier");
  gActionRequest_AimingPreventFreeAimSpeedModifier.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_AimingPreventFreeAimSpeedModifier;
  gActionRequest_AimingPreventFreeAimSpeedModifier.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_AimingPreventFreeAimSpeedModifier;
  gActionRequest_AimingPreventFreeAimSpeedModifier.m_EnumSymbol.mUID = -1;
  gActionRequest_AimingPreventFreeAimSpeedModifier.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_AimingPreventFreeAimSpeedModifier.m_EnumValue = 0i64;
  gActionRequest_AimingPreventFreeAimSpeedModifier.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_AimingPreventFreeAimSpeedModifier);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_AimingPreventFreeAimSpeedModifier;
    gActionRequest_AimingPreventFreeAimSpeedModifier.mPrev = v1;
    gActionRequest_AimingPreventFreeAimSpeedModifier.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_AimingPreventFreeAimSpeedModifier;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_AimingPreventFreeAimSpeedModifier__);
}

// File Line: 42
// RVA: 0x1484240
__int64 dynamic_initializer_for__gActionRequest_AimingSupressReticle__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "AimingSupressReticle");
  gActionRequest_AimingSupressReticle.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_AimingSupressReticle;
  gActionRequest_AimingSupressReticle.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_AimingSupressReticle;
  gActionRequest_AimingSupressReticle.m_EnumSymbol.mUID = -1;
  gActionRequest_AimingSupressReticle.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_AimingSupressReticle.m_EnumValue = 0i64;
  gActionRequest_AimingSupressReticle.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_AimingSupressReticle);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_AimingSupressReticle;
    gActionRequest_AimingSupressReticle.mPrev = v1;
    gActionRequest_AimingSupressReticle.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_AimingSupressReticle;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_AimingSupressReticle__);
}

// File Line: 43
// RVA: 0x14843A0
__int64 dynamic_initializer_for__gActionRequest_Attack__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Attack");
  gActionRequest_Attack.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Attack;
  gActionRequest_Attack.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Attack;
  gActionRequest_Attack.m_EnumSymbol.mUID = -1;
  gActionRequest_Attack.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Attack.m_EnumValue = 0i64;
  gActionRequest_Attack.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Attack);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Attack;
    gActionRequest_Attack.mPrev = v1;
    gActionRequest_Attack.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Attack;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Attack__);
}

// File Line: 44
// RVA: 0x14842F0
__int64 dynamic_initializer_for__gActionRequest_Attack2__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Attack2");
  gActionRequest_Attack2.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Attack2;
  gActionRequest_Attack2.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Attack2;
  gActionRequest_Attack2.m_EnumSymbol.mUID = -1;
  gActionRequest_Attack2.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Attack2.m_EnumValue = 0i64;
  gActionRequest_Attack2.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Attack2);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Attack2;
    gActionRequest_Attack2.mPrev = v1;
    gActionRequest_Attack2.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Attack2;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Attack2__);
}

// File Line: 45
// RVA: 0x1484450
__int64 dynamic_initializer_for__gActionRequest_Avoid__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Avoid");
  gActionRequest_Avoid.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Avoid;
  gActionRequest_Avoid.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Avoid;
  gActionRequest_Avoid.m_EnumSymbol.mUID = -1;
  gActionRequest_Avoid.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Avoid.m_EnumValue = 0i64;
  gActionRequest_Avoid.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Avoid);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Avoid;
    gActionRequest_Avoid.mPrev = v1;
    gActionRequest_Avoid.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Avoid;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Avoid__);
}

// File Line: 46
// RVA: 0x1484500
__int64 dynamic_initializer_for__gActionRequest_CameraZoom__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "CameraZoom");
  gActionRequest_CameraZoom.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_CameraZoom;
  gActionRequest_CameraZoom.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_CameraZoom;
  gActionRequest_CameraZoom.m_EnumSymbol.mUID = -1;
  gActionRequest_CameraZoom.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_CameraZoom.m_EnumValue = 0i64;
  gActionRequest_CameraZoom.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_CameraZoom);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_CameraZoom;
    gActionRequest_CameraZoom.mPrev = v1;
    gActionRequest_CameraZoom.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_CameraZoom;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_CameraZoom__);
}

// File Line: 47
// RVA: 0x14845B0
__int64 dynamic_initializer_for__gActionRequest_Cancel__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Cancel");
  gActionRequest_Cancel.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Cancel;
  gActionRequest_Cancel.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Cancel;
  gActionRequest_Cancel.m_EnumSymbol.mUID = -1;
  gActionRequest_Cancel.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Cancel.m_EnumValue = 0i64;
  gActionRequest_Cancel.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Cancel);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Cancel;
    gActionRequest_Cancel.mPrev = v1;
    gActionRequest_Cancel.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Cancel;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Cancel__);
}

// File Line: 48
// RVA: 0x1484660
__int64 dynamic_initializer_for__gActionRequest_CantTarget__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "CantTarget");
  gActionRequest_CantTarget.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_CantTarget;
  gActionRequest_CantTarget.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_CantTarget;
  gActionRequest_CantTarget.m_EnumSymbol.mUID = -1;
  gActionRequest_CantTarget.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_CantTarget.m_EnumValue = 0i64;
  gActionRequest_CantTarget.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_CantTarget);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_CantTarget;
    gActionRequest_CantTarget.mPrev = v1;
    gActionRequest_CantTarget.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_CantTarget;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_CantTarget__);
}

// File Line: 49
// RVA: 0x1484710
__int64 dynamic_initializer_for__gActionRequest_CellPhone__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "CellPhone");
  gActionRequest_CellPhone.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_CellPhone;
  gActionRequest_CellPhone.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_CellPhone;
  gActionRequest_CellPhone.m_EnumSymbol.mUID = -1;
  gActionRequest_CellPhone.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_CellPhone.m_EnumValue = 0i64;
  gActionRequest_CellPhone.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_CellPhone);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_CellPhone;
    gActionRequest_CellPhone.mPrev = v1;
    gActionRequest_CellPhone.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_CellPhone;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_CellPhone__);
}

// File Line: 50
// RVA: 0x14847C0
__int64 dynamic_initializer_for__gActionRequest_CoverPopout__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "CoverPopout");
  gActionRequest_CoverPopout.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_CoverPopout;
  gActionRequest_CoverPopout.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_CoverPopout;
  gActionRequest_CoverPopout.m_EnumSymbol.mUID = -1;
  gActionRequest_CoverPopout.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_CoverPopout.m_EnumValue = 0i64;
  gActionRequest_CoverPopout.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_CoverPopout);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_CoverPopout;
    gActionRequest_CoverPopout.mPrev = v1;
    gActionRequest_CoverPopout.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_CoverPopout;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_CoverPopout__);
}

// File Line: 51
// RVA: 0x1484870
__int64 dynamic_initializer_for__gActionRequest_CoverPopoutBlind__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "CoverPopoutBlind");
  gActionRequest_CoverPopoutBlind.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_CoverPopoutBlind;
  gActionRequest_CoverPopoutBlind.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_CoverPopoutBlind;
  gActionRequest_CoverPopoutBlind.m_EnumSymbol.mUID = -1;
  gActionRequest_CoverPopoutBlind.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_CoverPopoutBlind.m_EnumValue = 0i64;
  gActionRequest_CoverPopoutBlind.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_CoverPopoutBlind);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_CoverPopoutBlind;
    gActionRequest_CoverPopoutBlind.mPrev = v1;
    gActionRequest_CoverPopoutBlind.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_CoverPopoutBlind;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_CoverPopoutBlind__);
}

// File Line: 52
// RVA: 0x1484920
__int64 dynamic_initializer_for__gActionRequest_CoverToggle__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "CoverToggle");
  gActionRequest_CoverToggle.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_CoverToggle;
  gActionRequest_CoverToggle.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_CoverToggle;
  gActionRequest_CoverToggle.m_EnumSymbol.mUID = -1;
  gActionRequest_CoverToggle.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_CoverToggle.m_EnumValue = 0i64;
  gActionRequest_CoverToggle.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_CoverToggle);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_CoverToggle;
    gActionRequest_CoverToggle.mPrev = v1;
    gActionRequest_CoverToggle.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_CoverToggle;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_CoverToggle__);
}

// File Line: 53
// RVA: 0x14849D0
__int64 dynamic_initializer_for__gActionRequest_Cower__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Cower");
  gActionRequest_Cower.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Cower;
  gActionRequest_Cower.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Cower;
  gActionRequest_Cower.m_EnumSymbol.mUID = -1;
  gActionRequest_Cower.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Cower.m_EnumValue = 0i64;
  gActionRequest_Cower.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Cower);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Cower;
    gActionRequest_Cower.mPrev = v1;
    gActionRequest_Cower.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Cower;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Cower__);
}

// File Line: 54
// RVA: 0x1484A80
__int64 dynamic_initializer_for__gActionRequest_Crouch__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Crouch");
  gActionRequest_Crouch.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Crouch;
  gActionRequest_Crouch.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Crouch;
  gActionRequest_Crouch.m_EnumSymbol.mUID = -1;
  gActionRequest_Crouch.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Crouch.m_EnumValue = 0i64;
  gActionRequest_Crouch.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Crouch);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Crouch;
    gActionRequest_Crouch.mPrev = v1;
    gActionRequest_Crouch.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Crouch;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Crouch__);
}

// File Line: 55
// RVA: 0x1484B30
__int64 dynamic_initializer_for__gActionRequest_Deactivate__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Deactivate");
  gActionRequest_Deactivate.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Deactivate;
  gActionRequest_Deactivate.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Deactivate;
  gActionRequest_Deactivate.m_EnumSymbol.mUID = -1;
  gActionRequest_Deactivate.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Deactivate.m_EnumValue = 0i64;
  gActionRequest_Deactivate.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Deactivate);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Deactivate;
    gActionRequest_Deactivate.mPrev = v1;
    gActionRequest_Deactivate.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Deactivate;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Deactivate__);
}

// File Line: 56
// RVA: 0x1484BE0
__int64 dynamic_initializer_for__gActionRequest_DirectFollowerToAttack__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "DirectFollowerToAttack");
  gActionRequest_DirectFollowerToAttack.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_DirectFollowerToAttack;
  gActionRequest_DirectFollowerToAttack.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_DirectFollowerToAttack;
  gActionRequest_DirectFollowerToAttack.m_EnumSymbol.mUID = -1;
  gActionRequest_DirectFollowerToAttack.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_DirectFollowerToAttack.m_EnumValue = 0i64;
  gActionRequest_DirectFollowerToAttack.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_DirectFollowerToAttack);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_DirectFollowerToAttack;
    gActionRequest_DirectFollowerToAttack.mPrev = v1;
    gActionRequest_DirectFollowerToAttack.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_DirectFollowerToAttack;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_DirectFollowerToAttack__);
}

// File Line: 57
// RVA: 0x1484C90
__int64 dynamic_initializer_for__gActionRequest_Dive__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Dive");
  gActionRequest_Dive.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Dive;
  gActionRequest_Dive.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Dive;
  gActionRequest_Dive.m_EnumSymbol.mUID = -1;
  gActionRequest_Dive.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Dive.m_EnumValue = 0i64;
  gActionRequest_Dive.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Dive);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Dive;
    gActionRequest_Dive.mPrev = v1;
    gActionRequest_Dive.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Dive;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Dive__);
}

// File Line: 58
// RVA: 0x14858F0
__int64 dynamic_initializer_for__gActionRequest_Inventory__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Inventory");
  gActionRequest_Inventory.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Inventory;
  gActionRequest_Inventory.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Inventory;
  gActionRequest_Inventory.m_EnumSymbol.mUID = -1;
  gActionRequest_Inventory.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Inventory.m_EnumValue = 0i64;
  gActionRequest_Inventory.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Inventory);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Inventory;
    gActionRequest_Inventory.mPrev = v1;
    gActionRequest_Inventory.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Inventory;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Inventory__);
}

// File Line: 59
// RVA: 0x1484DF0
__int64 dynamic_initializer_for__gActionRequest_Equip__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Equip");
  gActionRequest_Equip.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Equip;
  gActionRequest_Equip.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Equip;
  gActionRequest_Equip.m_EnumSymbol.mUID = -1;
  gActionRequest_Equip.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Equip.m_EnumValue = 0i64;
  gActionRequest_Equip.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Equip);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Equip;
    gActionRequest_Equip.mPrev = v1;
    gActionRequest_Equip.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Equip;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Equip__);
}

// File Line: 60
// RVA: 0x1484EA0
__int64 dynamic_initializer_for__gActionRequest_EquipUP__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "EquipUP");
  gActionRequest_EquipUP.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_EquipUP;
  gActionRequest_EquipUP.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_EquipUP;
  gActionRequest_EquipUP.m_EnumSymbol.mUID = -1;
  gActionRequest_EquipUP.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_EquipUP.m_EnumValue = 0i64;
  gActionRequest_EquipUP.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_EquipUP);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_EquipUP;
    gActionRequest_EquipUP.mPrev = v1;
    gActionRequest_EquipUP.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_EquipUP;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_EquipUP__);
}

// File Line: 61
// RVA: 0x1484F50
__int64 dynamic_initializer_for__gActionRequest_Fire__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Fire");
  gActionRequest_Fire.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Fire;
  gActionRequest_Fire.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Fire;
  gActionRequest_Fire.m_EnumSymbol.mUID = -1;
  gActionRequest_Fire.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Fire.m_EnumValue = 0i64;
  gActionRequest_Fire.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Fire);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Fire;
    gActionRequest_Fire.mPrev = v1;
    gActionRequest_Fire.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Fire;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Fire__);
}

// File Line: 62
// RVA: 0x1485000
__int64 dynamic_initializer_for__gActionRequest_FirePartial__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "FirePartial");
  gActionRequest_FirePartial.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_FirePartial;
  gActionRequest_FirePartial.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_FirePartial;
  gActionRequest_FirePartial.m_EnumSymbol.mUID = -1;
  gActionRequest_FirePartial.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_FirePartial.m_EnumValue = 0i64;
  gActionRequest_FirePartial.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_FirePartial);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_FirePartial;
    gActionRequest_FirePartial.mPrev = v1;
    gActionRequest_FirePartial.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_FirePartial;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_FirePartial__);
}

// File Line: 63
// RVA: 0x14850B0
__int64 dynamic_initializer_for__gActionRequest_FireWeapon__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "FireWeapon");
  gActionRequest_FireWeapon.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_FireWeapon;
  gActionRequest_FireWeapon.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_FireWeapon;
  gActionRequest_FireWeapon.m_EnumSymbol.mUID = -1;
  gActionRequest_FireWeapon.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_FireWeapon.m_EnumValue = 0i64;
  gActionRequest_FireWeapon.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_FireWeapon);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_FireWeapon;
    gActionRequest_FireWeapon.mPrev = v1;
    gActionRequest_FireWeapon.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_FireWeapon;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_FireWeapon__);
}

// File Line: 64
// RVA: 0x1485160
__int64 dynamic_initializer_for__gActionRequest_Flich__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Flich");
  gActionRequest_Flich.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Flich;
  gActionRequest_Flich.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Flich;
  gActionRequest_Flich.m_EnumSymbol.mUID = -1;
  gActionRequest_Flich.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Flich.m_EnumValue = 0i64;
  gActionRequest_Flich.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Flich);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Flich;
    gActionRequest_Flich.mPrev = v1;
    gActionRequest_Flich.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Flich;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Flich__);
}

// File Line: 65
// RVA: 0x1485210
__int64 dynamic_initializer_for__gActionRequest_Focus__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Focus");
  gActionRequest_Focus.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Focus;
  gActionRequest_Focus.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Focus;
  gActionRequest_Focus.m_EnumSymbol.mUID = -1;
  gActionRequest_Focus.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Focus.m_EnumValue = 0i64;
  gActionRequest_Focus.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Focus);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Focus;
    gActionRequest_Focus.mPrev = v1;
    gActionRequest_Focus.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Focus;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Focus__);
}

// File Line: 66
// RVA: 0x14852C0
__int64 dynamic_initializer_for__gActionRequest_Focus_Lock__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Focus_Lock");
  gActionRequest_Focus_Lock.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Focus_Lock;
  gActionRequest_Focus_Lock.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Focus_Lock;
  gActionRequest_Focus_Lock.m_EnumSymbol.mUID = -1;
  gActionRequest_Focus_Lock.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Focus_Lock.m_EnumValue = 0i64;
  gActionRequest_Focus_Lock.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Focus_Lock);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Focus_Lock;
    gActionRequest_Focus_Lock.mPrev = v1;
    gActionRequest_Focus_Lock.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Focus_Lock;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Focus_Lock__);
}

// File Line: 67
// RVA: 0x1485370
__int64 dynamic_initializer_for__gActionRequest_Freerun__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Freerun");
  gActionRequest_Freerun.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Freerun;
  gActionRequest_Freerun.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Freerun;
  gActionRequest_Freerun.m_EnumSymbol.mUID = -1;
  gActionRequest_Freerun.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Freerun.m_EnumValue = 0i64;
  gActionRequest_Freerun.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Freerun);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Freerun;
    gActionRequest_Freerun.mPrev = v1;
    gActionRequest_Freerun.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Freerun;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Freerun__);
}

// File Line: 68
// RVA: 0x14854D0
__int64 dynamic_initializer_for__gActionRequest_GrappleDownUp__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "GrappleDownUp");
  gActionRequest_GrappleDownUp.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_GrappleDownUp;
  gActionRequest_GrappleDownUp.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_GrappleDownUp;
  gActionRequest_GrappleDownUp.m_EnumSymbol.mUID = -1;
  gActionRequest_GrappleDownUp.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_GrappleDownUp.m_EnumValue = 0i64;
  gActionRequest_GrappleDownUp.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_GrappleDownUp);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_GrappleDownUp;
    gActionRequest_GrappleDownUp.mPrev = v1;
    gActionRequest_GrappleDownUp.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_GrappleDownUp;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_GrappleDownUp__);
}

// File Line: 69
// RVA: 0x1485580
__int64 dynamic_initializer_for__gActionRequest_GrappleLeftRight__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "GrappleLeftRight");
  gActionRequest_GrappleLeftRight.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_GrappleLeftRight;
  gActionRequest_GrappleLeftRight.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_GrappleLeftRight;
  gActionRequest_GrappleLeftRight.m_EnumSymbol.mUID = -1;
  gActionRequest_GrappleLeftRight.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_GrappleLeftRight.m_EnumValue = 0i64;
  gActionRequest_GrappleLeftRight.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_GrappleLeftRight);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_GrappleLeftRight;
    gActionRequest_GrappleLeftRight.mPrev = v1;
    gActionRequest_GrappleLeftRight.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_GrappleLeftRight;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_GrappleLeftRight__);
}

// File Line: 70
// RVA: 0x1485630
__int64 dynamic_initializer_for__gActionRequest_GrappleRightLeft__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "GrappleRightLeft");
  gActionRequest_GrappleRightLeft.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_GrappleRightLeft;
  gActionRequest_GrappleRightLeft.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_GrappleRightLeft;
  gActionRequest_GrappleRightLeft.m_EnumSymbol.mUID = -1;
  gActionRequest_GrappleRightLeft.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_GrappleRightLeft.m_EnumValue = 0i64;
  gActionRequest_GrappleRightLeft.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_GrappleRightLeft);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_GrappleRightLeft;
    gActionRequest_GrappleRightLeft.mPrev = v1;
    gActionRequest_GrappleRightLeft.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_GrappleRightLeft;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_GrappleRightLeft__);
}

// File Line: 71
// RVA: 0x14856E0
__int64 dynamic_initializer_for__gActionRequest_GrappleUpDown__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "GrappleUpDown");
  gActionRequest_GrappleUpDown.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_GrappleUpDown;
  gActionRequest_GrappleUpDown.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_GrappleUpDown;
  gActionRequest_GrappleUpDown.m_EnumSymbol.mUID = -1;
  gActionRequest_GrappleUpDown.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_GrappleUpDown.m_EnumValue = 0i64;
  gActionRequest_GrappleUpDown.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_GrappleUpDown);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_GrappleUpDown;
    gActionRequest_GrappleUpDown.mPrev = v1;
    gActionRequest_GrappleUpDown.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_GrappleUpDown;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_GrappleUpDown__);
}

// File Line: 72
// RVA: 0x1485790
__int64 dynamic_initializer_for__gActionRequest_Guard__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Guard");
  gActionRequest_Guard.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Guard;
  gActionRequest_Guard.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Guard;
  gActionRequest_Guard.m_EnumSymbol.mUID = -1;
  gActionRequest_Guard.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Guard.m_EnumValue = 0i64;
  gActionRequest_Guard.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Guard);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Guard;
    gActionRequest_Guard.mPrev = v1;
    gActionRequest_Guard.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Guard;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Guard__);
}

// File Line: 73
// RVA: 0x14859A0
__int64 dynamic_initializer_for__gActionRequest_Jog__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Jog");
  gActionRequest_Jog.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Jog;
  gActionRequest_Jog.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Jog;
  gActionRequest_Jog.m_EnumSymbol.mUID = -1;
  gActionRequest_Jog.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Jog.m_EnumValue = 0i64;
  gActionRequest_Jog.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Jog);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Jog;
    gActionRequest_Jog.mPrev = v1;
    gActionRequest_Jog.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Jog;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Jog__);
}

// File Line: 74
// RVA: 0x1485A50
__int64 dynamic_initializer_for__gActionRequest_Jump__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Jump");
  gActionRequest_Jump.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Jump;
  gActionRequest_Jump.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Jump;
  gActionRequest_Jump.m_EnumSymbol.mUID = -1;
  gActionRequest_Jump.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Jump.m_EnumValue = 0i64;
  gActionRequest_Jump.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Jump);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Jump;
    gActionRequest_Jump.mPrev = v1;
    gActionRequest_Jump.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Jump;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Jump__);
}

// File Line: 75
// RVA: 0x1486080
__int64 dynamic_initializer_for__gActionRequest_MidRangeAttack__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "MidRangeAttack");
  gActionRequest_MidRangeAttack.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_MidRangeAttack;
  gActionRequest_MidRangeAttack.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_MidRangeAttack;
  gActionRequest_MidRangeAttack.m_EnumSymbol.mUID = -1;
  gActionRequest_MidRangeAttack.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_MidRangeAttack.m_EnumValue = 0i64;
  gActionRequest_MidRangeAttack.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_MidRangeAttack);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_MidRangeAttack;
    gActionRequest_MidRangeAttack.mPrev = v1;
    gActionRequest_MidRangeAttack.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_MidRangeAttack;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_MidRangeAttack__);
}

// File Line: 76
// RVA: 0x1486130
__int64 dynamic_initializer_for__gActionRequest_MoveBackward__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "MoveBackward");
  gActionRequest_MoveBackward.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_MoveBackward;
  gActionRequest_MoveBackward.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_MoveBackward;
  gActionRequest_MoveBackward.m_EnumSymbol.mUID = -1;
  gActionRequest_MoveBackward.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_MoveBackward.m_EnumValue = 0i64;
  gActionRequest_MoveBackward.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_MoveBackward);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_MoveBackward;
    gActionRequest_MoveBackward.mPrev = v1;
    gActionRequest_MoveBackward.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_MoveBackward;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_MoveBackward__);
}

// File Line: 77
// RVA: 0x14861E0
__int64 dynamic_initializer_for__gActionRequest_MoveForward__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "MoveForward");
  gActionRequest_MoveForward.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_MoveForward;
  gActionRequest_MoveForward.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_MoveForward;
  gActionRequest_MoveForward.m_EnumSymbol.mUID = -1;
  gActionRequest_MoveForward.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_MoveForward.m_EnumValue = 0i64;
  gActionRequest_MoveForward.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_MoveForward);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_MoveForward;
    gActionRequest_MoveForward.mPrev = v1;
    gActionRequest_MoveForward.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_MoveForward;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_MoveForward__);
}

// File Line: 78
// RVA: 0x1486290
__int64 dynamic_initializer_for__gActionRequest_MoveLeft__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "MoveLeft");
  gActionRequest_MoveLeft.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_MoveLeft;
  gActionRequest_MoveLeft.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_MoveLeft;
  gActionRequest_MoveLeft.m_EnumSymbol.mUID = -1;
  gActionRequest_MoveLeft.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_MoveLeft.m_EnumValue = 0i64;
  gActionRequest_MoveLeft.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_MoveLeft);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_MoveLeft;
    gActionRequest_MoveLeft.mPrev = v1;
    gActionRequest_MoveLeft.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_MoveLeft;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_MoveLeft__);
}

// File Line: 79
// RVA: 0x1486340
__int64 dynamic_initializer_for__gActionRequest_MoveRight__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "MoveRight");
  gActionRequest_MoveRight.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_MoveRight;
  gActionRequest_MoveRight.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_MoveRight;
  gActionRequest_MoveRight.m_EnumSymbol.mUID = -1;
  gActionRequest_MoveRight.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_MoveRight.m_EnumValue = 0i64;
  gActionRequest_MoveRight.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_MoveRight);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_MoveRight;
    gActionRequest_MoveRight.mPrev = v1;
    gActionRequest_MoveRight.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_MoveRight;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_MoveRight__);
}

// File Line: 80
// RVA: 0x14863F0
__int64 dynamic_initializer_for__gActionRequest_None__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "None");
  gActionRequest_None.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_None;
  gActionRequest_None.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_None;
  gActionRequest_None.m_EnumSymbol.mUID = -1;
  gActionRequest_None.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_None.m_EnumValue = 0i64;
  gActionRequest_None.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_None);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_None;
    gActionRequest_None.mPrev = v1;
    gActionRequest_None.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_None;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_None__);
}

// File Line: 81
// RVA: 0x1486810
__int64 dynamic_initializer_for__gActionRequest_Pickup__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Pickup");
  gActionRequest_Pickup.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Pickup;
  gActionRequest_Pickup.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Pickup;
  gActionRequest_Pickup.m_EnumSymbol.mUID = -1;
  gActionRequest_Pickup.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Pickup.m_EnumValue = 0i64;
  gActionRequest_Pickup.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Pickup);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Pickup;
    gActionRequest_Pickup.mPrev = v1;
    gActionRequest_Pickup.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Pickup;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Pickup__);
}

// File Line: 82
// RVA: 0x14866B0
__int64 dynamic_initializer_for__gActionRequest_POI_Timeout__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "POI_Timeout");
  gActionRequest_POI_Timeout.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_POI_Timeout;
  gActionRequest_POI_Timeout.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_POI_Timeout;
  gActionRequest_POI_Timeout.m_EnumSymbol.mUID = -1;
  gActionRequest_POI_Timeout.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_POI_Timeout.m_EnumValue = 0i64;
  gActionRequest_POI_Timeout.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_POI_Timeout);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_POI_Timeout;
    gActionRequest_POI_Timeout.mPrev = v1;
    gActionRequest_POI_Timeout.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_POI_Timeout;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_POI_Timeout__);
}

// File Line: 83
// RVA: 0x1486760
__int64 dynamic_initializer_for__gActionRequest_POI_Use__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "POI_Use");
  gActionRequest_POI_Use.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_POI_Use;
  gActionRequest_POI_Use.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_POI_Use;
  gActionRequest_POI_Use.m_EnumSymbol.mUID = -1;
  gActionRequest_POI_Use.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_POI_Use.m_EnumValue = 0i64;
  gActionRequest_POI_Use.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_POI_Use);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_POI_Use;
    gActionRequest_POI_Use.mPrev = v1;
    gActionRequest_POI_Use.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_POI_Use;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_POI_Use__);
}

// File Line: 84
// RVA: 0x14868C0
__int64 dynamic_initializer_for__gActionRequest_PressAgainstWall__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "PressAgainstWall");
  gActionRequest_PressAgainstWall.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_PressAgainstWall;
  gActionRequest_PressAgainstWall.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_PressAgainstWall;
  gActionRequest_PressAgainstWall.m_EnumSymbol.mUID = -1;
  gActionRequest_PressAgainstWall.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_PressAgainstWall.m_EnumValue = 0i64;
  gActionRequest_PressAgainstWall.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_PressAgainstWall);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_PressAgainstWall;
    gActionRequest_PressAgainstWall.mPrev = v1;
    gActionRequest_PressAgainstWall.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_PressAgainstWall;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_PressAgainstWall__);
}

// File Line: 85
// RVA: 0x1486B80
__int64 dynamic_initializer_for__gActionRequest_Release__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Release");
  gActionRequest_Release.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Release;
  gActionRequest_Release.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Release;
  gActionRequest_Release.m_EnumSymbol.mUID = -1;
  gActionRequest_Release.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Release.m_EnumValue = 0i64;
  gActionRequest_Release.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Release);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Release;
    gActionRequest_Release.mPrev = v1;
    gActionRequest_Release.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Release;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Release__);
}

// File Line: 86
// RVA: 0x1486C30
__int64 dynamic_initializer_for__gActionRequest_Reload__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Reload");
  gActionRequest_Reload.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Reload;
  gActionRequest_Reload.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Reload;
  gActionRequest_Reload.m_EnumSymbol.mUID = -1;
  gActionRequest_Reload.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Reload.m_EnumValue = 0i64;
  gActionRequest_Reload.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Reload);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Reload;
    gActionRequest_Reload.mPrev = v1;
    gActionRequest_Reload.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Reload;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Reload__);
}

// File Line: 87
// RVA: 0x1486CE0
__int64 dynamic_initializer_for__gActionRequest_RotateLeft__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "RotateLeft");
  gActionRequest_RotateLeft.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_RotateLeft;
  gActionRequest_RotateLeft.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_RotateLeft;
  gActionRequest_RotateLeft.m_EnumSymbol.mUID = -1;
  gActionRequest_RotateLeft.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_RotateLeft.m_EnumValue = 0i64;
  gActionRequest_RotateLeft.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_RotateLeft);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_RotateLeft;
    gActionRequest_RotateLeft.mPrev = v1;
    gActionRequest_RotateLeft.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_RotateLeft;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_RotateLeft__);
}

// File Line: 88
// RVA: 0x1486D90
__int64 dynamic_initializer_for__gActionRequest_RotateRight__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "RotateRight");
  gActionRequest_RotateRight.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_RotateRight;
  gActionRequest_RotateRight.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_RotateRight;
  gActionRequest_RotateRight.m_EnumSymbol.mUID = -1;
  gActionRequest_RotateRight.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_RotateRight.m_EnumValue = 0i64;
  gActionRequest_RotateRight.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_RotateRight);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_RotateRight;
    gActionRequest_RotateRight.mPrev = v1;
    gActionRequest_RotateRight.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_RotateRight;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_RotateRight__);
}

// File Line: 89
// RVA: 0x1486E40
__int64 dynamic_initializer_for__gActionRequest_RunningAttack__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "RunningAttack");
  gActionRequest_RunningAttack.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_RunningAttack;
  gActionRequest_RunningAttack.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_RunningAttack;
  gActionRequest_RunningAttack.m_EnumSymbol.mUID = -1;
  gActionRequest_RunningAttack.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_RunningAttack.m_EnumValue = 0i64;
  gActionRequest_RunningAttack.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_RunningAttack);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_RunningAttack;
    gActionRequest_RunningAttack.mPrev = v1;
    gActionRequest_RunningAttack.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_RunningAttack;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_RunningAttack__);
}

// File Line: 90
// RVA: 0x1486EF0
__int64 dynamic_initializer_for__gActionRequest_SocialNegative__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "SocialNegative");
  gActionRequest_SocialNegative.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_SocialNegative;
  gActionRequest_SocialNegative.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_SocialNegative;
  gActionRequest_SocialNegative.m_EnumSymbol.mUID = -1;
  gActionRequest_SocialNegative.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_SocialNegative.m_EnumValue = 0i64;
  gActionRequest_SocialNegative.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_SocialNegative);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_SocialNegative;
    gActionRequest_SocialNegative.mPrev = v1;
    gActionRequest_SocialNegative.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_SocialNegative;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_SocialNegative__);
}

// File Line: 91
// RVA: 0x1486FA0
__int64 dynamic_initializer_for__gActionRequest_SocialPositive__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "SocialPositive");
  gActionRequest_SocialPositive.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_SocialPositive;
  gActionRequest_SocialPositive.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_SocialPositive;
  gActionRequest_SocialPositive.m_EnumSymbol.mUID = -1;
  gActionRequest_SocialPositive.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_SocialPositive.m_EnumValue = 0i64;
  gActionRequest_SocialPositive.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_SocialPositive);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_SocialPositive;
    gActionRequest_SocialPositive.mPrev = v1;
    gActionRequest_SocialPositive.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_SocialPositive;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_SocialPositive__);
}

// File Line: 92
// RVA: 0x1487050
__int64 dynamic_initializer_for__gActionRequest_Sprint__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Sprint");
  gActionRequest_Sprint.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Sprint;
  gActionRequest_Sprint.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Sprint;
  gActionRequest_Sprint.m_EnumSymbol.mUID = -1;
  gActionRequest_Sprint.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Sprint.m_EnumValue = 0i64;
  gActionRequest_Sprint.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Sprint);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Sprint;
    gActionRequest_Sprint.mPrev = v1;
    gActionRequest_Sprint.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Sprint;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Sprint__);
}

// File Line: 93
// RVA: 0x1487100
__int64 dynamic_initializer_for__gActionRequest_SteerLeft__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "SteerLeft");
  gActionRequest_SteerLeft.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_SteerLeft;
  gActionRequest_SteerLeft.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_SteerLeft;
  gActionRequest_SteerLeft.m_EnumSymbol.mUID = -1;
  gActionRequest_SteerLeft.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_SteerLeft.m_EnumValue = 0i64;
  gActionRequest_SteerLeft.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_SteerLeft);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_SteerLeft;
    gActionRequest_SteerLeft.mPrev = v1;
    gActionRequest_SteerLeft.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_SteerLeft;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_SteerLeft__);
}

// File Line: 94
// RVA: 0x14871B0
__int64 dynamic_initializer_for__gActionRequest_SteerNeutral__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "SteerNeutral");
  gActionRequest_SteerNeutral.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_SteerNeutral;
  gActionRequest_SteerNeutral.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_SteerNeutral;
  gActionRequest_SteerNeutral.m_EnumSymbol.mUID = -1;
  gActionRequest_SteerNeutral.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_SteerNeutral.m_EnumValue = 0i64;
  gActionRequest_SteerNeutral.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_SteerNeutral);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_SteerNeutral;
    gActionRequest_SteerNeutral.mPrev = v1;
    gActionRequest_SteerNeutral.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_SteerNeutral;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_SteerNeutral__);
}

// File Line: 95
// RVA: 0x1487260
__int64 dynamic_initializer_for__gActionRequest_SteerRight__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "SteerRight");
  gActionRequest_SteerRight.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_SteerRight;
  gActionRequest_SteerRight.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_SteerRight;
  gActionRequest_SteerRight.m_EnumSymbol.mUID = -1;
  gActionRequest_SteerRight.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_SteerRight.m_EnumValue = 0i64;
  gActionRequest_SteerRight.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_SteerRight);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_SteerRight;
    gActionRequest_SteerRight.mPrev = v1;
    gActionRequest_SteerRight.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_SteerRight;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_SteerRight__);
}

// File Line: 96
// RVA: 0x1487310
__int64 dynamic_initializer_for__gActionRequest_StrafeFacing__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "StrafeFacing");
  gActionRequest_StrafeFacing.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_StrafeFacing;
  gActionRequest_StrafeFacing.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_StrafeFacing;
  gActionRequest_StrafeFacing.m_EnumSymbol.mUID = -1;
  gActionRequest_StrafeFacing.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_StrafeFacing.m_EnumValue = 0i64;
  gActionRequest_StrafeFacing.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_StrafeFacing);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_StrafeFacing;
    gActionRequest_StrafeFacing.mPrev = v1;
    gActionRequest_StrafeFacing.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_StrafeFacing;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_StrafeFacing__);
}

// File Line: 97
// RVA: 0x14873C0
__int64 dynamic_initializer_for__gActionRequest_StrikeRelease__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "StrikeRelease");
  gActionRequest_StrikeRelease.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_StrikeRelease;
  gActionRequest_StrikeRelease.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_StrikeRelease;
  gActionRequest_StrikeRelease.m_EnumSymbol.mUID = -1;
  gActionRequest_StrikeRelease.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_StrikeRelease.m_EnumValue = 0i64;
  gActionRequest_StrikeRelease.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_StrikeRelease);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_StrikeRelease;
    gActionRequest_StrikeRelease.mPrev = v1;
    gActionRequest_StrikeRelease.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_StrikeRelease;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_StrikeRelease__);
}

// File Line: 98
// RVA: 0x1487470
__int64 dynamic_initializer_for__gActionRequest_Talk__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Talk");
  gActionRequest_Talk.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Talk;
  gActionRequest_Talk.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Talk;
  gActionRequest_Talk.m_EnumSymbol.mUID = -1;
  gActionRequest_Talk.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Talk.m_EnumValue = 0i64;
  gActionRequest_Talk.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Talk);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Talk;
    gActionRequest_Talk.mPrev = v1;
    gActionRequest_Talk.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Talk;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Talk__);
}

// File Line: 99
// RVA: 0x1487520
__int64 dynamic_initializer_for__gActionRequest_TargetingAutoAcquisition__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "TargetingAutoAcquisition");
  gActionRequest_TargetingAutoAcquisition.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_TargetingAutoAcquisition;
  gActionRequest_TargetingAutoAcquisition.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_TargetingAutoAcquisition;
  gActionRequest_TargetingAutoAcquisition.m_EnumSymbol.mUID = -1;
  gActionRequest_TargetingAutoAcquisition.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_TargetingAutoAcquisition.m_EnumValue = 0i64;
  gActionRequest_TargetingAutoAcquisition.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_TargetingAutoAcquisition);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_TargetingAutoAcquisition;
    gActionRequest_TargetingAutoAcquisition.mPrev = v1;
    gActionRequest_TargetingAutoAcquisition.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_TargetingAutoAcquisition;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_TargetingAutoAcquisition__);
}

// File Line: 100
// RVA: 0x1487680
__int64 dynamic_initializer_for__gActionRequest_TargetingFreeShootingDesired__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "TargetingFreeShootingDesired");
  gActionRequest_TargetingFreeShootingDesired.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_TargetingFreeShootingDesired;
  gActionRequest_TargetingFreeShootingDesired.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_TargetingFreeShootingDesired;
  gActionRequest_TargetingFreeShootingDesired.m_EnumSymbol.mUID = -1;
  gActionRequest_TargetingFreeShootingDesired.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_TargetingFreeShootingDesired.m_EnumValue = 0i64;
  gActionRequest_TargetingFreeShootingDesired.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_TargetingFreeShootingDesired);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_TargetingFreeShootingDesired;
    gActionRequest_TargetingFreeShootingDesired.mPrev = v1;
    gActionRequest_TargetingFreeShootingDesired.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_TargetingFreeShootingDesired;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_TargetingFreeShootingDesired__);
}

// File Line: 101
// RVA: 0x14875D0
__int64 dynamic_initializer_for__gActionRequest_TargetingFreeAimAssistance__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "TargetingFreeAimAssistance");
  gActionRequest_TargetingFreeAimAssistance.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_TargetingFreeAimAssistance;
  gActionRequest_TargetingFreeAimAssistance.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_TargetingFreeAimAssistance;
  gActionRequest_TargetingFreeAimAssistance.m_EnumSymbol.mUID = -1;
  gActionRequest_TargetingFreeAimAssistance.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_TargetingFreeAimAssistance.m_EnumValue = 0i64;
  gActionRequest_TargetingFreeAimAssistance.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_TargetingFreeAimAssistance);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_TargetingFreeAimAssistance;
    gActionRequest_TargetingFreeAimAssistance.mPrev = v1;
    gActionRequest_TargetingFreeAimAssistance.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_TargetingFreeAimAssistance;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_TargetingFreeAimAssistance__);
}

// File Line: 102
// RVA: 0x1487730
__int64 dynamic_initializer_for__gActionRequest_Taunt__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Taunt");
  gActionRequest_Taunt.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Taunt;
  gActionRequest_Taunt.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Taunt;
  gActionRequest_Taunt.m_EnumSymbol.mUID = -1;
  gActionRequest_Taunt.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Taunt.m_EnumValue = 0i64;
  gActionRequest_Taunt.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Taunt);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Taunt;
    gActionRequest_Taunt.mPrev = v1;
    gActionRequest_Taunt.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Taunt;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Taunt__);
}

// File Line: 103
// RVA: 0x1487890
__int64 dynamic_initializer_for__gActionRequest_VaultFail__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "VaultFail");
  gActionRequest_VaultFail.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VaultFail;
  gActionRequest_VaultFail.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VaultFail;
  gActionRequest_VaultFail.m_EnumSymbol.mUID = -1;
  gActionRequest_VaultFail.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_VaultFail.m_EnumValue = 0i64;
  gActionRequest_VaultFail.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_VaultFail);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VaultFail;
    gActionRequest_VaultFail.mPrev = v1;
    gActionRequest_VaultFail.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VaultFail;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_VaultFail__);
}

// File Line: 104
// RVA: 0x1487940
__int64 dynamic_initializer_for__gActionRequest_VaultSuccess__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "VaultSuccess");
  gActionRequest_VaultSuccess.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VaultSuccess;
  gActionRequest_VaultSuccess.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VaultSuccess;
  gActionRequest_VaultSuccess.m_EnumSymbol.mUID = -1;
  gActionRequest_VaultSuccess.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_VaultSuccess.m_EnumValue = 0i64;
  gActionRequest_VaultSuccess.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_VaultSuccess);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VaultSuccess;
    gActionRequest_VaultSuccess.mPrev = v1;
    gActionRequest_VaultSuccess.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VaultSuccess;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_VaultSuccess__);
}

// File Line: 105
// RVA: 0x14879F0
__int64 dynamic_initializer_for__gActionRequest_VehicleActionHijackDesired__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "VehicleActionHijackDesired");
  gActionRequest_VehicleActionHijackDesired.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleActionHijackDesired;
  gActionRequest_VehicleActionHijackDesired.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleActionHijackDesired;
  gActionRequest_VehicleActionHijackDesired.m_EnumSymbol.mUID = -1;
  gActionRequest_VehicleActionHijackDesired.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_VehicleActionHijackDesired.m_EnumValue = 0i64;
  gActionRequest_VehicleActionHijackDesired.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_VehicleActionHijackDesired);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleActionHijackDesired;
    gActionRequest_VehicleActionHijackDesired.mPrev = v1;
    gActionRequest_VehicleActionHijackDesired.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleActionHijackDesired;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_VehicleActionHijackDesired__);
}

// File Line: 106
// RVA: 0x1487B50
__int64 dynamic_initializer_for__gActionRequest_VehicleFocus__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "VehicleFocus");
  gActionRequest_VehicleFocus.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleFocus;
  gActionRequest_VehicleFocus.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleFocus;
  gActionRequest_VehicleFocus.m_EnumSymbol.mUID = -1;
  gActionRequest_VehicleFocus.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_VehicleFocus.m_EnumValue = 0i64;
  gActionRequest_VehicleFocus.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_VehicleFocus);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleFocus;
    gActionRequest_VehicleFocus.mPrev = v1;
    gActionRequest_VehicleFocus.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleFocus;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_VehicleFocus__);
}

// File Line: 107
// RVA: 0x1487C00
__int64 dynamic_initializer_for__gActionRequest_VehicleGas__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "VehicleGas");
  gActionRequest_VehicleGas.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleGas;
  gActionRequest_VehicleGas.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleGas;
  gActionRequest_VehicleGas.m_EnumSymbol.mUID = -1;
  gActionRequest_VehicleGas.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_VehicleGas.m_EnumValue = 0i64;
  gActionRequest_VehicleGas.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_VehicleGas);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleGas;
    gActionRequest_VehicleGas.mPrev = v1;
    gActionRequest_VehicleGas.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleGas;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_VehicleGas__);
}

// File Line: 108
// RVA: 0x1487CB0
__int64 dynamic_initializer_for__gActionRequest_VehicleHandBrake__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "VehicleHandBrake");
  gActionRequest_VehicleHandBrake.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleHandBrake;
  gActionRequest_VehicleHandBrake.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleHandBrake;
  gActionRequest_VehicleHandBrake.m_EnumSymbol.mUID = -1;
  gActionRequest_VehicleHandBrake.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_VehicleHandBrake.m_EnumValue = 0i64;
  gActionRequest_VehicleHandBrake.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_VehicleHandBrake);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleHandBrake;
    gActionRequest_VehicleHandBrake.mPrev = v1;
    gActionRequest_VehicleHandBrake.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleHandBrake;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_VehicleHandBrake__);
}

// File Line: 109
// RVA: 0x1487D60
__int64 dynamic_initializer_for__gActionRequest_VehicleLookBack__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "VehicleLookBack");
  gActionRequest_VehicleLookBack.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleLookBack;
  gActionRequest_VehicleLookBack.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleLookBack;
  gActionRequest_VehicleLookBack.m_EnumSymbol.mUID = -1;
  gActionRequest_VehicleLookBack.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_VehicleLookBack.m_EnumValue = 0i64;
  gActionRequest_VehicleLookBack.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_VehicleLookBack);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleLookBack;
    gActionRequest_VehicleLookBack.mPrev = v1;
    gActionRequest_VehicleLookBack.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleLookBack;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_VehicleLookBack__);
}

// File Line: 110
// RVA: 0x1487EC0
__int64 dynamic_initializer_for__gActionRequest_VehicleReverse__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "VehicleReverse");
  gActionRequest_VehicleReverse.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleReverse;
  gActionRequest_VehicleReverse.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleReverse;
  gActionRequest_VehicleReverse.m_EnumSymbol.mUID = -1;
  gActionRequest_VehicleReverse.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_VehicleReverse.m_EnumValue = 0i64;
  gActionRequest_VehicleReverse.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_VehicleReverse);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleReverse;
    gActionRequest_VehicleReverse.mPrev = v1;
    gActionRequest_VehicleReverse.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleReverse;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_VehicleReverse__);
}

// File Line: 111
// RVA: 0x1487F70
__int64 dynamic_initializer_for__gActionRequest_VehicleToggleFocus__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "VehicleToggleFocus");
  gActionRequest_VehicleToggleFocus.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleToggleFocus;
  gActionRequest_VehicleToggleFocus.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleToggleFocus;
  gActionRequest_VehicleToggleFocus.m_EnumSymbol.mUID = -1;
  gActionRequest_VehicleToggleFocus.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_VehicleToggleFocus.m_EnumValue = 0i64;
  gActionRequest_VehicleToggleFocus.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_VehicleToggleFocus);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleToggleFocus;
    gActionRequest_VehicleToggleFocus.mPrev = v1;
    gActionRequest_VehicleToggleFocus.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleToggleFocus;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_VehicleToggleFocus__);
}

// File Line: 112
// RVA: 0x1488020
__int64 dynamic_initializer_for__gActionRequest_Walk__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "Walk");
  gActionRequest_Walk.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Walk;
  gActionRequest_Walk.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Walk;
  gActionRequest_Walk.m_EnumSymbol.mUID = -1;
  gActionRequest_Walk.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_Walk.m_EnumValue = 0i64;
  gActionRequest_Walk.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_Walk);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Walk;
    gActionRequest_Walk.mPrev = v1;
    gActionRequest_Walk.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_Walk;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_Walk__);
}

// File Line: 113
// RVA: 0x1488180
__int64 dynamic_initializer_for__gActionRequest_WeaponMode__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "WeaponMode");
  gActionRequest_WeaponMode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_WeaponMode;
  gActionRequest_WeaponMode.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_WeaponMode;
  gActionRequest_WeaponMode.m_EnumSymbol.mUID = -1;
  gActionRequest_WeaponMode.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_WeaponMode.m_EnumValue = 0i64;
  gActionRequest_WeaponMode.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_WeaponMode);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_WeaponMode;
    gActionRequest_WeaponMode.mPrev = v1;
    gActionRequest_WeaponMode.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_WeaponMode;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_WeaponMode__);
}

// File Line: 114
// RVA: 0x1485FD0
__int64 dynamic_initializer_for__gActionRequest_LookTorso__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "LookTorso");
  gActionRequest_LookTorso.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookTorso;
  gActionRequest_LookTorso.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookTorso;
  gActionRequest_LookTorso.m_EnumSymbol.mUID = -1;
  gActionRequest_LookTorso.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_LookTorso.m_EnumValue = 0i64;
  gActionRequest_LookTorso.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_LookTorso);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookTorso;
    gActionRequest_LookTorso.mPrev = v1;
    gActionRequest_LookTorso.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookTorso;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_LookTorso__);
}

// File Line: 115
// RVA: 0x1485E70
__int64 dynamic_initializer_for__gActionRequest_LookPants__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "LookPants");
  gActionRequest_LookPants.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookPants;
  gActionRequest_LookPants.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookPants;
  gActionRequest_LookPants.m_EnumSymbol.mUID = -1;
  gActionRequest_LookPants.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_LookPants.m_EnumValue = 0i64;
  gActionRequest_LookPants.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_LookPants);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookPants;
    gActionRequest_LookPants.mPrev = v1;
    gActionRequest_LookPants.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookPants;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_LookPants__);
}

// File Line: 116
// RVA: 0x1485B00
__int64 dynamic_initializer_for__gActionRequest_LookFeet__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "LookFeet");
  gActionRequest_LookFeet.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookFeet;
  gActionRequest_LookFeet.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookFeet;
  gActionRequest_LookFeet.m_EnumSymbol.mUID = -1;
  gActionRequest_LookFeet.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_LookFeet.m_EnumValue = 0i64;
  gActionRequest_LookFeet.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_LookFeet);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookFeet;
    gActionRequest_LookFeet.mPrev = v1;
    gActionRequest_LookFeet.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookFeet;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_LookFeet__);
}

// File Line: 117
// RVA: 0x1485C60
__int64 dynamic_initializer_for__gActionRequest_LookHead__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "LookHead");
  gActionRequest_LookHead.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookHead;
  gActionRequest_LookHead.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookHead;
  gActionRequest_LookHead.m_EnumSymbol.mUID = -1;
  gActionRequest_LookHead.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_LookHead.m_EnumValue = 0i64;
  gActionRequest_LookHead.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_LookHead);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookHead;
    gActionRequest_LookHead.mPrev = v1;
    gActionRequest_LookHead.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookHead;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_LookHead__);
}

// File Line: 118
// RVA: 0x1485BB0
__int64 dynamic_initializer_for__gActionRequest_LookGlasses__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "LookGlasses");
  gActionRequest_LookGlasses.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookGlasses;
  gActionRequest_LookGlasses.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookGlasses;
  gActionRequest_LookGlasses.m_EnumSymbol.mUID = -1;
  gActionRequest_LookGlasses.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_LookGlasses.m_EnumValue = 0i64;
  gActionRequest_LookGlasses.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_LookGlasses);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookGlasses;
    gActionRequest_LookGlasses.mPrev = v1;
    gActionRequest_LookGlasses.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookGlasses;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_LookGlasses__);
}

// File Line: 119
// RVA: 0x1485DC0
__int64 dynamic_initializer_for__gActionRequest_LookNeck__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "LookNeck");
  gActionRequest_LookNeck.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookNeck;
  gActionRequest_LookNeck.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookNeck;
  gActionRequest_LookNeck.m_EnumSymbol.mUID = -1;
  gActionRequest_LookNeck.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_LookNeck.m_EnumValue = 0i64;
  gActionRequest_LookNeck.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_LookNeck);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookNeck;
    gActionRequest_LookNeck.mPrev = v1;
    gActionRequest_LookNeck.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookNeck;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_LookNeck__);
}

// File Line: 120
// RVA: 0x1485D10
__int64 dynamic_initializer_for__gActionRequest_LookLeftWrist__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "LookLeftWrist");
  gActionRequest_LookLeftWrist.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookLeftWrist;
  gActionRequest_LookLeftWrist.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookLeftWrist;
  gActionRequest_LookLeftWrist.m_EnumSymbol.mUID = -1;
  gActionRequest_LookLeftWrist.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_LookLeftWrist.m_EnumValue = 0i64;
  gActionRequest_LookLeftWrist.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_LookLeftWrist);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookLeftWrist;
    gActionRequest_LookLeftWrist.mPrev = v1;
    gActionRequest_LookLeftWrist.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookLeftWrist;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_LookLeftWrist__);
}

// File Line: 121
// RVA: 0x1485F20
__int64 dynamic_initializer_for__gActionRequest_LookRightWrist__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "LookRightWrist");
  gActionRequest_LookRightWrist.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookRightWrist;
  gActionRequest_LookRightWrist.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookRightWrist;
  gActionRequest_LookRightWrist.m_EnumSymbol.mUID = -1;
  gActionRequest_LookRightWrist.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_LookRightWrist.m_EnumValue = 0i64;
  gActionRequest_LookRightWrist.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_LookRightWrist);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookRightWrist;
    gActionRequest_LookRightWrist.mPrev = v1;
    gActionRequest_LookRightWrist.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_LookRightWrist;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_LookRightWrist__);
}

// File Line: 122
// RVA: 0x14877E0
__int64 dynamic_initializer_for__gActionRequest_UseCover__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "UseCover");
  gActionRequest_UseCover.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_UseCover;
  gActionRequest_UseCover.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_UseCover;
  gActionRequest_UseCover.m_EnumSymbol.mUID = -1;
  gActionRequest_UseCover.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_UseCover.m_EnumValue = 0i64;
  gActionRequest_UseCover.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_UseCover);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_UseCover;
    gActionRequest_UseCover.mPrev = v1;
    gActionRequest_UseCover.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_UseCover;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_UseCover__);
}

// File Line: 123
// RVA: 0x1487E10
__int64 dynamic_initializer_for__gActionRequest_VehicleRam__()
{
  UFG::qSymbol *v0; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v1; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v0 = UFG::qSymbol::create_from_string(&result, "VehicleRam");
  gActionRequest_VehicleRam.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleRam;
  gActionRequest_VehicleRam.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleRam;
  gActionRequest_VehicleRam.m_EnumSymbol.mUID = -1;
  gActionRequest_VehicleRam.m_EnumSymbol = (UFG::qSymbol)v0->mUID;
  *(_QWORD *)&gActionRequest_VehicleRam.m_EnumValue = 0i64;
  gActionRequest_VehicleRam.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &gActionRequest_VehicleRam);
  }
  else
  {
    v1 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleRam;
    gActionRequest_VehicleRam.mPrev = v1;
    gActionRequest_VehicleRam.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gActionRequest_VehicleRam;
  }
  return atexit(dynamic_atexit_destructor_for__gActionRequest_VehicleRam__);
}

// File Line: 126
// RVA: 0x268D50
void __fastcall Intention::Intention(Intention *this)
{
  Intention *v1; // rbx
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4

  v1 = this;
  this->mActionRequests.mBits[0] = 0i64;
  this->mActionRequests.mBits[1] = 0i64;
  this->mActionRequests.mBits[2] = 0i64;
  this->mActionRequests.mBits[3] = 0i64;
  this->mActionRequests.mBits[4] = 0i64;
  this->mActionRequests.mBits[5] = 0i64;
  this->mActionRequests.mBits[6] = 0i64;
  this->mActionRequests.mBits[7] = 0i64;
  this->mActionRequests.mBits[8] = 0i64;
  this->mFacialRequests.mBits[0] = 0i64;
  Intention::Clear(this);
  v2 = UFG::qVector3::msAxisY.y;
  v3 = UFG::qVector3::msAxisY.z;
  v1->mMotionIntentionDirection.x = UFG::qVector3::msAxisY.x;
  v1->mMotionIntentionDirection.y = v2;
  v1->mMotionIntentionDirection.z = v3;
  v4 = UFG::qVector3::msAxisY.y;
  v5 = UFG::qVector3::msAxisY.z;
  v1->mMotionIntentionDirectionRaw.x = UFG::qVector3::msAxisY.x;
  v1->mMotionIntentionDirectionRaw.y = v4;
  v1->mMotionIntentionDirectionRaw.z = v5;
  v6 = UFG::qVector3::msZero.y;
  v7 = UFG::qVector3::msZero.z;
  v1->mDesiredLookAtPoint.x = UFG::qVector3::msZero.x;
  v1->mDesiredLookAtPoint.y = v6;
  v1->mDesiredLookAtPoint.z = v7;
}

// File Line: 140
// RVA: 0x26C010
void __fastcall Intention::Clear(Intention *this)
{
  Intention *v1; // rbx

  v1 = this;
  this->mCurrentRotationInput = -1.0;
  this->mMotionIntentionSpeed = 0.0;
  this->mMotionIntentionSpeedRaw = 0.0;
  this->mDesireToLookAtPoint = 0;
  this->mDesireToLookAtPointEye = 0;
  *(_QWORD *)&this->mCurrentRotationSpeed = 0i64;
  *(_QWORD *)&this->mCurrentRotationAccel = 0i64;
  this->mNodeRequestHash = 0;
  UFG::AIAwareness::SubProfileAnimation::Clear(&this->mAwarenessIntention);
  v1->mEnableManualStrafeFacingDirection = 0;
  v1->mActionRequests.mBits[0] = 0i64;
  v1->mActionRequests.mBits[1] = 0i64;
  v1->mActionRequests.mBits[2] = 0i64;
  v1->mActionRequests.mBits[3] = 0i64;
  v1->mActionRequests.mBits[4] = 0i64;
  v1->mActionRequests.mBits[5] = 0i64;
  v1->mActionRequests.mBits[6] = 0i64;
  v1->mActionRequests.mBits[7] = 0i64;
  v1->mActionRequests.mBits[8] = 0i64;
  v1->mFastClear[0] = 0i64;
  v1->mFastClear[1] = 0i64;
  v1->mFastClear[2] = 0i64;
  v1->mFastClear[3] = 0i64;
  v1->mFastClear[4] = 0i64;
  v1->mFastClear[5] = 0i64;
  v1->mFastClear[6] = 0i64;
  v1->mFastClear[7] = 0i64;
  v1->mFastClear[8] = 0i64;
  v1->mFacialRequests.mBits[0] = 0i64;
  v1->mFacialFastClear[0] = 0i64;
  v1->mSignals = 0i64;
}

// File Line: 175
// RVA: 0x26E040
char __fastcall Intention::GetActionRequest(const char *action_request_name, unsigned int *action_request)
{
  unsigned int *v2; // r14
  const char *v3; // rbp
  signed int v4; // er8
  EnumList<unsigned long> **v5; // r9
  unsigned int v6; // esi
  unsigned int v7; // ebx
  __int64 v8; // rdi
  const char *v9; // rcx

  v2 = action_request;
  v3 = action_request_name;
  *action_request = gActionRequest_INVALID.m_EnumValue;
  v4 = gActionRequestEnum.m_enumLists.size;
  v5 = gActionRequestEnum.m_enumLists.p;
  if ( (gActionRequestEnum.m_enumLists.size & 0x80000000) != 0 )
    v6 = 0;
  else
    v6 = (*gActionRequestEnum.m_enumLists.p)->m_enumName.size;
  v7 = 0;
  if ( !v6 )
    return 0;
  v8 = 0i64;
  while ( 1 )
  {
    v9 = v4 < 0 ? 0i64 : (*v5)->m_enumName.p[v8];
    if ( !(unsigned int)UFG::qStringCompareInsensitive(v9, v3, -1) )
      break;
    ++v7;
    ++v8;
    if ( v7 >= v6 )
      return 0;
    v5 = gActionRequestEnum.m_enumLists.p;
    v4 = gActionRequestEnum.m_enumLists.size;
  }
  *v2 = v7;
  return 1;
}

// File Line: 215
// RVA: 0x26A2B0
Intention *__fastcall Intention::operator=(Intention *this, Intention *other)
{
  Intention *v2; // rbx

  v2 = this;
  UFG::qMemCopy(this, other, 0x348u);
  return v2;
}

// File Line: 225
// RVA: 0x148A4F0
const char *dynamic_initializer_for__sActionRequestFactoryList__()
{
  const char *result; // rax

  result = ActionRequestDebug::sClassName;
  sActionRequestFactoryList[0].mClassName = ActionRequestDebug::sClassName;
  return result;
}

// File Line: 231
// RVA: 0x1483DF0
__int64 dynamic_initializer_for__gActionRequestFactoryList__()
{
  Expression::MemberMapFactory::MemberMapFactory(
    &gActionRequestFactoryList,
    sActionRequestFactoryList,
    sActionRequestFactoryListNum);
  return atexit(dynamic_atexit_destructor_for__gActionRequestFactoryList__);
}

// File Line: 236
// RVA: 0x14804F0
__int64 dynamic_initializer_for__ActionRequestDebug::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ActionRequestDebug", 0xFFFFFFFF);
  ActionRequestDebug::sClassNameUID = result;
  return result;
}

// File Line: 249
// RVA: 0x2727D0
void __fastcall ActionRequestDebug::SetName(ActionRequestDebug *this, const char *namestr)
{
  ActionRequestDebug *v2; // rbx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v3; // rax
  unsigned __int16 v4; // dx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v5; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v6; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h]
  UFG::qSymbol v8; // [rsp+60h] [rbp+10h]

  v2 = this;
  v8.mUID = -1;
  UFG::qSymbol::set_from_cstr(&v8, namestr);
  pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.m_EnumSymbol = v8;
  *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
  pTrackEnumBinding.m_uEnumUID = 0;
  if ( gActionRequestEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gActionRequestEnum, &pTrackEnumBinding);
  }
  else
  {
    v3 = gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mPrev = v3;
    pTrackEnumBinding.mNext = &gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gActionRequestEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  }
  v4 = pTrackEnumBinding.m_EnumValue;
  v5 = pTrackEnumBinding.mPrev;
  v6 = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  v6->mPrev = v5;
  v2->mActionRequest = v4;
}

// File Line: 256
// RVA: 0x26EA00
char *__fastcall ActionRequestDebug::GetName_DBG(ActionRequestDebug *this)
{
  char *result; // rax

  if ( (gActionRequestEnum.m_enumLists.size & 0x80000000) != 0 )
    result = 0i64;
  else
    result = (*gActionRequestEnum.m_enumLists.p)->m_enumName.p[this->mActionRequest];
  return result;
}

// File Line: 264
// RVA: 0x14805D0
__int64 dynamic_initializer_for__IntentionDebug::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IntentionDebug", 0xFFFFFFFF);
  IntentionDebug::sClassNameUID = result;
  return result;
}

