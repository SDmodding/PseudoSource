// File Line: 29
// RVA: 0xD98E80
void __fastcall addConstraintToCriticalLockedIsland(hkpWorld *world, hkpConstraintInstance *constraint, int callbackRequest)
{
  char v3; // di
  hkpConstraintInstance *v4; // rbx

  v3 = callbackRequest;
  v4 = constraint;
  hkpWorldOperationUtil::addConstraintToCriticalLockedIsland(world, constraint);
  v4->m_internal->m_callbackRequest |= v3;
}

// File Line: 35
// RVA: 0xD98E10
void __fastcall hkPhysicsCommandMachineProcess(hkpWorld *world, hkpPhysicsCommand *begin, int size)
{
  hkpPhysicsCommand *v3; // rbx
  hkpWorld *v4; // rdi
  hkpPhysicsCommand *v5; // rsi

  v3 = begin;
  v4 = world;
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
          v4,
          *(hkpConstraintInstance **)&v3[8].m_type.m_storage);
        v3 += 16;
      }
      else
      {
        addConstraintToCriticalLockedIsland(
          v4,
          *(hkpConstraintInstance **)&v3[8].m_type.m_storage,
          *(_DWORD *)&v3[16].m_type.m_storage);
        v3 += 32;
      }
    }
    while ( v3 < v5 );
  }
}

