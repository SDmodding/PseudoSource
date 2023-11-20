// File Line: 16
// RVA: 0xD7D750
void __fastcall hkpBroadPhaseBorderListener::addCollisionPair(hkpBroadPhaseBorderListener *this, hkpTypedBroadPhaseHandlePair *pair)
{
  hkpTypedBroadPhaseHandlePair *v2; // rbx
  hkpBroadPhaseHandle *v3; // rdx
  char *v4; // rax
  hkpBroadPhaseHandle *v5; // rcx
  char *v6; // rcx

  v2 = pair;
  v3 = pair->m_a;
  if ( LOBYTE(v3[1].m_id) == 3 )
  {
    if ( LOBYTE(v2->m_b[1].m_id) == 3 )
      return;
    v4 = (char *)v3 + SBYTE1(v3[1].m_id);
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)&v4[v4[32]] + 64i64))(
      &v4[v4[32]],
      (char *)v2->m_b + SBYTE1(v2->m_b[1].m_id));
  }
  v5 = v2->m_b;
  if ( LOBYTE(v5[1].m_id) == 3 )
  {
    v6 = (char *)v5 + SBYTE1(v5[1].m_id) + *((char *)&v5[8].m_id + SBYTE1(v5[1].m_id));
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)v6 + 64i64))(v6, (char *)v2->m_a + SBYTE1(v2->m_a[1].m_id));
  }
}

// File Line: 41
// RVA: 0xD7D7E0
void __fastcall hkpBroadPhaseBorderListener::removeCollisionPair(hkpBroadPhaseBorderListener *this, hkpTypedBroadPhaseHandlePair *pair)
{
  hkpTypedBroadPhaseHandlePair *v2; // rbx
  hkpBroadPhaseHandle *v3; // rdx
  char *v4; // rax
  hkpBroadPhaseHandle *v5; // rcx
  char *v6; // rcx

  v2 = pair;
  v3 = pair->m_a;
  if ( LOBYTE(v3[1].m_id) == 3 )
  {
    if ( LOBYTE(v2->m_b[1].m_id) == 3 )
      return;
    v4 = (char *)v3 + SBYTE1(v3[1].m_id);
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)&v4[v4[32]] + 80i64))(
      &v4[v4[32]],
      (char *)v2->m_b + SBYTE1(v2->m_b[1].m_id));
  }
  v5 = v2->m_b;
  if ( LOBYTE(v5[1].m_id) == 3 )
  {
    v6 = (char *)v5 + SBYTE1(v5[1].m_id) + *((char *)&v5[8].m_id + SBYTE1(v5[1].m_id));
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)v6 + 80i64))(v6, (char *)v2->m_a + SBYTE1(v2->m_a[1].m_id));
  }
}

