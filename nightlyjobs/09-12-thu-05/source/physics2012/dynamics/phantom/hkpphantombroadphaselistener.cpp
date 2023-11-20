// File Line: 15
// RVA: 0xD7D500
void __fastcall hkpPhantomBroadPhaseListener::addCollisionPair(hkpPhantomBroadPhaseListener *this, hkpTypedBroadPhaseHandlePair *pair)
{
  hkpTypedBroadPhaseHandlePair *v2; // rbx
  char *v3; // rcx
  hkpBroadPhaseHandle *v4; // rcx
  char *v5; // rcx

  v2 = pair;
  if ( LOBYTE(pair->m_a[1].m_id) == 2 )
  {
    v3 = (char *)pair->m_a + SBYTE1(pair->m_a[1].m_id) + *((char *)&pair->m_a[8].m_id + SBYTE1(pair->m_a[1].m_id));
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)v3 + 64i64))(v3, (char *)pair->m_b + SBYTE1(pair->m_b[1].m_id));
  }
  v4 = v2->m_b;
  if ( LOBYTE(v4[1].m_id) == 2 )
  {
    v5 = (char *)v4 + SBYTE1(v4[1].m_id) + *((char *)&v4[8].m_id + SBYTE1(v4[1].m_id));
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)v5 + 64i64))(v5, (char *)v2->m_a + SBYTE1(v2->m_a[1].m_id));
  }
}

// File Line: 35
// RVA: 0xD7D580
void __fastcall hkpPhantomBroadPhaseListener::removeCollisionPair(hkpPhantomBroadPhaseListener *this, hkpTypedBroadPhaseHandlePair *pair)
{
  hkpTypedBroadPhaseHandlePair *v2; // rbx
  char *v3; // rcx
  hkpBroadPhaseHandle *v4; // rcx
  char *v5; // rcx

  v2 = pair;
  if ( LOBYTE(pair->m_a[1].m_id) == 2 )
  {
    v3 = (char *)pair->m_a + SBYTE1(pair->m_a[1].m_id) + *((char *)&pair->m_a[8].m_id + SBYTE1(pair->m_a[1].m_id));
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)v3 + 80i64))(v3, (char *)pair->m_b + SBYTE1(pair->m_b[1].m_id));
  }
  v4 = v2->m_b;
  if ( LOBYTE(v4[1].m_id) == 2 )
  {
    v5 = (char *)v4 + SBYTE1(v4[1].m_id) + *((char *)&v4[8].m_id + SBYTE1(v4[1].m_id));
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)v5 + 80i64))(v5, (char *)v2->m_a + SBYTE1(v2->m_a[1].m_id));
  }
}

