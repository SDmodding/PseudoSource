// File Line: 15
// RVA: 0xD7D500
void __fastcall hkpPhantomBroadPhaseListener::addCollisionPair(
        hkpPhantomBroadPhaseListener *this,
        hkpTypedBroadPhaseHandlePair *pair)
{
  char *v3; // rcx
  hkpBroadPhaseHandle *m_b; // rcx
  char *v5; // rcx

  if ( LOBYTE(pair->m_a[1].m_id) == 2 )
  {
    v3 = (char *)pair->m_a + SBYTE1(pair->m_a[1].m_id) + *((char *)&pair->m_a[8].m_id + SBYTE1(pair->m_a[1].m_id));
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)v3 + 64i64))(v3, (char *)pair->m_b + SBYTE1(pair->m_b[1].m_id));
  }
  m_b = pair->m_b;
  if ( LOBYTE(m_b[1].m_id) == 2 )
  {
    v5 = (char *)m_b + SBYTE1(m_b[1].m_id) + *((char *)&m_b[8].m_id + SBYTE1(m_b[1].m_id));
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)v5 + 64i64))(v5, (char *)pair->m_a + SBYTE1(pair->m_a[1].m_id));
  }
}

// File Line: 35
// RVA: 0xD7D580
void __fastcall hkpPhantomBroadPhaseListener::removeCollisionPair(
        hkpPhantomBroadPhaseListener *this,
        hkpTypedBroadPhaseHandlePair *pair)
{
  char *v3; // rcx
  hkpBroadPhaseHandle *m_b; // rcx
  char *v5; // rcx

  if ( LOBYTE(pair->m_a[1].m_id) == 2 )
  {
    v3 = (char *)pair->m_a + SBYTE1(pair->m_a[1].m_id) + *((char *)&pair->m_a[8].m_id + SBYTE1(pair->m_a[1].m_id));
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)v3 + 80i64))(v3, (char *)pair->m_b + SBYTE1(pair->m_b[1].m_id));
  }
  m_b = pair->m_b;
  if ( LOBYTE(m_b[1].m_id) == 2 )
  {
    v5 = (char *)m_b + SBYTE1(m_b[1].m_id) + *((char *)&m_b[8].m_id + SBYTE1(m_b[1].m_id));
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)v5 + 80i64))(v5, (char *)pair->m_a + SBYTE1(pair->m_a[1].m_id));
  }
}

