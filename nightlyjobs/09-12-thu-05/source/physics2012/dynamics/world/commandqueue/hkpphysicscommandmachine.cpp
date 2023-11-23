// File Line: 29
// RVA: 0xD98E80
void __fastcall addConstraintToCriticalLockedIsland(
        hkpWorld *world,
        hkpConstraintInstance *constraint,
        char callbackRequest)
{
  hkpWorldOperationUtil::addConstraintToCriticalLockedIsland(world, constraint);
  constraint->m_internal->m_callbackRequest |= callbackRequest;
}

// File Line: 35
// RVA: 0xD98E10
void __fastcall hkPhysicsCommandMachineProcess(hkpWorld *world, hkpPhysicsCommand *begin, int size)
{
  hkpPhysicsCommand *v3; // rbx
  hkpPhysicsCommand *v5; // rsi

  v3 = begin;
  v5 = &begin[size];
  if ( begin < v5 )
  {
    do
    {
      if ( v3->m_type.m_storage )
      {
        if ( v3->m_type.m_storage != 1 )
          return;
        hkpWorldOperationUtil::removeConstraintFromCriticalLockedIsland(
          world,
          *(hkpConstraintInstance **)&v3[8].m_type.m_storage);
        v3 += 16;
      }
      else
      {
        addConstraintToCriticalLockedIsland(
          world,
          *(hkpConstraintInstance **)&v3[8].m_type.m_storage,
          *(_DWORD *)&v3[16].m_type.m_storage);
        v3 += 32;
      }
    }
    while ( v3 < v5 );
  }
}

