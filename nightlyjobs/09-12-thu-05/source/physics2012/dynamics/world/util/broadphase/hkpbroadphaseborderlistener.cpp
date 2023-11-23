// File Line: 16
// RVA: 0xD7D750
void __fastcall hkpBroadPhaseBorderListener::addCollisionPair(
        hkpBroadPhaseBorderListener *this,
        hkpTypedBroadPhaseHandlePair *pair)
{
  hkpBroadPhaseHandle *m_a; // rdx
  char *v4; // rax
  hkpBroadPhaseHandle *m_b; // rcx
  char *v6; // rcx

  m_a = pair->m_a;
  if ( LOBYTE(m_a[1].m_id) == 3 )
  {
    if ( LOBYTE(pair->m_b[1].m_id) == 3 )
      return;
    v4 = (char *)m_a + SBYTE1(m_a[1].m_id);
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)&v4[v4[32]] + 64i64))(
      &v4[v4[32]],
      (char *)pair->m_b + SBYTE1(pair->m_b[1].m_id));
  }
  m_b = pair->m_b;
  if ( LOBYTE(m_b[1].m_id) == 3 )
  {
    v6 = (char *)m_b + SBYTE1(m_b[1].m_id) + *((char *)&m_b[8].m_id + SBYTE1(m_b[1].m_id));
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)v6 + 64i64))(v6, (char *)pair->m_a + SBYTE1(pair->m_a[1].m_id));
  }
}

// File Line: 41
// RVA: 0xD7D7E0
void __fastcall hkpBroadPhaseBorderListener::removeCollisionPair(
        hkpBroadPhaseBorderListener *this,
        hkpTypedBroadPhaseHandlePair *pair)
{
  hkpBroadPhaseHandle *m_a; // rdx
  char *v4; // rax
  hkpBroadPhaseHandle *m_b; // rcx
  char *v6; // rcx

  m_a = pair->m_a;
  if ( LOBYTE(m_a[1].m_id) == 3 )
  {
    if ( LOBYTE(pair->m_b[1].m_id) == 3 )
      return;
    v4 = (char *)m_a + SBYTE1(m_a[1].m_id);
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)&v4[v4[32]] + 80i64))(
      &v4[v4[32]],
      (char *)pair->m_b + SBYTE1(pair->m_b[1].m_id));
  }
  m_b = pair->m_b;
  if ( LOBYTE(m_b[1].m_id) == 3 )
  {
    v6 = (char *)m_b + SBYTE1(m_b[1].m_id) + *((char *)&m_b[8].m_id + SBYTE1(m_b[1].m_id));
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)v6 + 80i64))(v6, (char *)pair->m_a + SBYTE1(pair->m_a[1].m_id));
  }
}

