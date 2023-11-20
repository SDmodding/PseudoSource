// File Line: 35
// RVA: 0xD68EE0
void __fastcall hkpResponseModifier::setInvMassScalingForContact(hkpDynamicsContactMgr *manager, hkpRigidBody *bodyA, hkpRigidBody *bodyB, hkpConstraintOwner *constraintOwner, hkVector4f *factorA, hkVector4f *factorB)
{
  hkpConstraintOwner *v6; // rsi
  hkpRigidBody *v7; // rbp
  hkpConstraintInstance *v8; // rdi
  _QWORD *v9; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  hkpModifierConstraintAtom *v13; // rbx
  _QWORD **v14; // rax
  hkpModifierConstraintAtom *v15; // rax
  __m128 v16; // xmm0
  hkVector4f *v17; // rax
  _QWORD *v18; // rax
  _QWORD *v19; // rcx
  _QWORD *v20; // r8
  unsigned __int64 v21; // rax
  signed __int64 v22; // rcx

  v6 = constraintOwner;
  v7 = bodyA;
  v8 = (hkpConstraintInstance *)((__int64 (__fastcall *)(hkpDynamicsContactMgr *, hkpRigidBody *, hkpRigidBody *))manager->vfptr[8].__vecDelDtor)(
                                  manager,
                                  bodyA,
                                  bodyB);
  if ( v8 )
  {
    ((void (__fastcall *)(hkpConstraintOwner *))v6->vfptr[3].__vecDelDtor)(v6);
    v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v10 = (_QWORD *)v9[1];
    if ( (unsigned __int64)v10 < v9[3] )
    {
      *v10 = "TtSetMassChang";
      v11 = __rdtsc();
      v12 = (signed __int64)(v10 + 2);
      *(_DWORD *)(v12 - 8) = v11;
      v9[1] = v12;
    }
    v13 = hkpWorldConstraintUtil::findModifier(v8, TYPE_MAX|TYPE_CONVEX_LIST_CONTACT_MGR|0x18);
    if ( !v13 )
    {
      v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v15 = (hkpModifierConstraintAtom *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v14[11] + 8i64))(
                                           v14[11],
                                           80i64);
      v13 = v15;
      if ( v15 )
      {
        v15->m_type.m_storage = 31;
        v15->m_modifierAtomSize = 80;
      }
      else
      {
        v13 = 0i64;
      }
      hkpWorldConstraintUtil::addModifier(v8, v6, v13);
    }
    if ( v7 == (hkpRigidBody *)v8->m_entities[0] )
    {
      v16 = factorA->m_quad;
      v17 = factorB;
    }
    else
    {
      v16 = factorB->m_quad;
      v17 = factorA;
    }
    *(__m128 *)&v13[1].m_type.m_storage = v16;
    *(hkVector4f *)&v13[1].m_modifierAtomSize = (hkVector4f)v17->m_quad;
    v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v19 = (_QWORD *)v18[1];
    v20 = v18;
    if ( (unsigned __int64)v19 < v18[3] )
    {
      *v19 = "Et";
      v21 = __rdtsc();
      v22 = (signed __int64)(v19 + 2);
      *(_DWORD *)(v22 - 8) = v21;
      v20[1] = v22;
    }
  }
}

// File Line: 83
// RVA: 0xD69030
void __fastcall hkpResponseModifier::setInvMassScalingForContact(hkpDynamicsContactMgr *manager, hkpRigidBody *body, hkpConstraintOwner *constraintOwner, hkVector4f *factor)
{
  hkVector4f *v4; // rdi
  hkpConstraintOwner *v5; // r14
  hkpRigidBody *v6; // rbp
  hkpConstraintInstance *v7; // rsi
  _QWORD *v8; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  hkpModifierConstraintAtom *v12; // rax
  _QWORD **v13; // rax
  hkpModifierConstraintAtom *v14; // rax
  hkpModifierConstraintAtom *v15; // rbx
  __m128 v16; // xmm0
  __m128 v17; // xmm0
  __m128 v18; // xmm1
  _QWORD *v19; // rax
  _QWORD *v20; // rcx
  _QWORD *v21; // r8
  unsigned __int64 v22; // rax
  signed __int64 v23; // rcx

  v4 = factor;
  v5 = constraintOwner;
  v6 = body;
  v7 = (hkpConstraintInstance *)((__int64 (*)(void))manager->vfptr[8].__vecDelDtor)();
  if ( v7 )
  {
    ((void (__fastcall *)(hkpConstraintOwner *))v5->vfptr[3].__vecDelDtor)(v5);
    v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v9 = (_QWORD *)v8[1];
    if ( (unsigned __int64)v9 < v8[3] )
    {
      *v9 = "TtSetMassChang";
      v10 = __rdtsc();
      v11 = (signed __int64)(v9 + 2);
      *(_DWORD *)(v11 - 8) = v10;
      v8[1] = v11;
    }
    v12 = hkpWorldConstraintUtil::findModifier(v7, TYPE_MAX|TYPE_CONVEX_LIST_CONTACT_MGR|0x18);
    if ( v12 )
    {
      v17 = v4->m_quad;
      if ( v6 == (hkpRigidBody *)v7->m_entities[0] )
        *(__m128 *)&v12[1].m_type.m_storage = v17;
      else
        *(__m128 *)&v12[1].m_modifierAtomSize = v17;
      v18 = *(__m128 *)&v12[1].m_type.m_storage;
      if ( COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 255)) == 0.0
        && COERCE_FLOAT(_mm_shuffle_ps(*(__m128 *)&v12[1].m_modifierAtomSize, *(__m128 *)&v12[1].m_modifierAtomSize, 255)) == 0.0 )
      {
        *(__m128 *)&v12[1].m_type.m_storage = _mm_shuffle_ps(v18, _mm_unpackhi_ps(v18, query.m_quad), 196);
        *(__m128 *)&v12[1].m_modifierAtomSize = _mm_shuffle_ps(
                                                  *(__m128 *)&v12[1].m_modifierAtomSize,
                                                  _mm_unpackhi_ps(*(__m128 *)&v12[1].m_modifierAtomSize, query.m_quad),
                                                  196);
      }
    }
    else
    {
      v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v14 = (hkpModifierConstraintAtom *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v13[11] + 8i64))(
                                           v13[11],
                                           80i64);
      v15 = v14;
      if ( v14 )
      {
        v14->m_type.m_storage = 31;
        v14->m_modifierAtomSize = 80;
      }
      else
      {
        v15 = 0i64;
      }
      hkpWorldConstraintUtil::addModifier(v7, v5, v15);
      if ( v6 == (hkpRigidBody *)v7->m_entities[0] )
      {
        v16 = v4->m_quad;
        *(hkVector4f *)&v15[1].m_modifierAtomSize = (hkVector4f)query.m_quad;
        *(__m128 *)&v15[1].m_type.m_storage = v16;
      }
      else
      {
        *(hkVector4f *)&v15[1].m_type.m_storage = (hkVector4f)query.m_quad;
        *(hkVector4f *)&v15[1].m_modifierAtomSize = (hkVector4f)v4->m_quad;
      }
    }
    v19 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v20 = (_QWORD *)v19[1];
    v21 = v19;
    if ( (unsigned __int64)v20 < v19[3] )
    {
      *v20 = "Et";
      v22 = __rdtsc();
      v23 = (signed __int64)(v20 + 2);
      *(_DWORD *)(v23 - 8) = v22;
      v21[1] = v23;
    }
  }
}

// File Line: 145
// RVA: 0xD691F0
void __fastcall hkpResponseModifier::setCenterOfMassDisplacementForContact(hkpDynamicsContactMgr *manager, hkpRigidBody *bodyA, hkpRigidBody *bodyB, hkpConstraintOwner *constraintOwner, hkVector4f *displacementA, hkVector4f *displacementB)
{
  hkpConstraintOwner *v6; // rsi
  hkpRigidBody *v7; // rbp
  hkpConstraintInstance *v8; // rdi
  _QWORD *v9; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  hkpModifierConstraintAtom *v13; // rbx
  _QWORD **v14; // rax
  hkpModifierConstraintAtom *v15; // rax
  __m128 v16; // xmm0
  hkVector4f *v17; // rax
  _QWORD *v18; // rax
  _QWORD *v19; // rcx
  _QWORD *v20; // r8
  unsigned __int64 v21; // rax
  signed __int64 v22; // rcx

  v6 = constraintOwner;
  v7 = bodyA;
  v8 = (hkpConstraintInstance *)((__int64 (__fastcall *)(hkpDynamicsContactMgr *, hkpRigidBody *, hkpRigidBody *))manager->vfptr[8].__vecDelDtor)(
                                  manager,
                                  bodyA,
                                  bodyB);
  if ( v8 )
  {
    ((void (__fastcall *)(hkpConstraintOwner *))v6->vfptr[3].__vecDelDtor)(v6);
    v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v10 = (_QWORD *)v9[1];
    if ( (unsigned __int64)v10 < v9[3] )
    {
      *v10 = "TtSetMassChang";
      v11 = __rdtsc();
      v12 = (signed __int64)(v10 + 2);
      *(_DWORD *)(v12 - 8) = v11;
      v9[1] = v12;
    }
    v13 = hkpWorldConstraintUtil::findModifier(v8, TYPE_NULL_CONTACT_MGR|0x20);
    if ( !v13 )
    {
      v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v15 = (hkpModifierConstraintAtom *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v14[11] + 8i64))(
                                           v14[11],
                                           80i64);
      v13 = v15;
      if ( v15 )
      {
        v15->m_type.m_storage = 35;
        v15->m_modifierAtomSize = 80;
      }
      else
      {
        v13 = 0i64;
      }
      hkpWorldConstraintUtil::addModifier(v8, v6, v13);
    }
    if ( v7 == (hkpRigidBody *)v8->m_entities[0] )
    {
      v16 = displacementA->m_quad;
      v17 = displacementB;
    }
    else
    {
      v16 = displacementB->m_quad;
      v17 = displacementA;
    }
    *(__m128 *)&v13[1].m_type.m_storage = v16;
    *(hkVector4f *)&v13[1].m_modifierAtomSize = (hkVector4f)v17->m_quad;
    v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v19 = (_QWORD *)v18[1];
    v20 = v18;
    if ( (unsigned __int64)v19 < v18[3] )
    {
      *v19 = "Et";
      v21 = __rdtsc();
      v22 = (signed __int64)(v19 + 2);
      *(_DWORD *)(v22 - 8) = v21;
      v20[1] = v22;
    }
  }
}

// File Line: 189
// RVA: 0xD69340
void __fastcall hkpResponseModifier::setImpulseScalingForContact(hkpDynamicsContactMgr *manager, hkpRigidBody *bodyA, hkpRigidBody *bodyB, hkpConstraintOwner *constraintOwner, float usedImpulseFraction, float maxAcceleration)
{
  hkpConstraintOwner *v6; // rdi
  hkpConstraintInstance *v7; // rbx
  _QWORD *v8; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  hkpModifierConstraintAtom *v12; // rax
  _QWORD **v13; // rax
  __int64 v14; // rax
  _QWORD *v15; // rax
  _QWORD *v16; // rcx
  _QWORD *v17; // r8
  unsigned __int64 v18; // rax
  signed __int64 v19; // rcx

  v6 = constraintOwner;
  v7 = (hkpConstraintInstance *)((__int64 (__fastcall *)(hkpDynamicsContactMgr *, hkpRigidBody *, hkpRigidBody *))manager->vfptr[8].__vecDelDtor)(
                                  manager,
                                  bodyA,
                                  bodyB);
  if ( v7 )
  {
    ((void (__fastcall *)(hkpConstraintOwner *))v6->vfptr[3].__vecDelDtor)(v6);
    v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v9 = (_QWORD *)v8[1];
    if ( (unsigned __int64)v9 < v8[3] )
    {
      *v9 = "TtSetSoftContact";
      v10 = __rdtsc();
      v11 = (signed __int64)(v9 + 2);
      *(_DWORD *)(v11 - 8) = v10;
      v8[1] = v11;
    }
    v12 = hkpWorldConstraintUtil::findModifier(v7, (hkpConstraintAtom::AtomType)30);
    if ( v12 )
    {
      *(float *)&v12[1].m_type.m_storage = usedImpulseFraction;
      *((float *)&v12[1].0 + 1) = maxAcceleration;
    }
    else
    {
      v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v14 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v13[11] + 8i64))(v13[11], 64i64);
      if ( v14 )
      {
        *(_WORD *)v14 = 30;
        *(_WORD *)(v14 + 16) = 64;
        *(_DWORD *)(v14 + 48) = 1036831949;
        *(_DWORD *)(v14 + 52) = 1101004800;
      }
      *(float *)(v14 + 48) = usedImpulseFraction;
      *(float *)(v14 + 52) = maxAcceleration;
      hkpWorldConstraintUtil::addModifier(v7, v6, (hkpModifierConstraintAtom *)v14);
    }
    v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v16 = (_QWORD *)v15[1];
    v17 = v15;
    if ( (unsigned __int64)v16 < v15[3] )
    {
      *v16 = "Et";
      v18 = __rdtsc();
      v19 = (signed __int64)(v16 + 2);
      *(_DWORD *)(v19 - 8) = v18;
      v17[1] = v19;
    }
  }
}

// File Line: 234
// RVA: 0xD69490
void __fastcall hkpResponseModifier::setSurfaceVelocity(hkpDynamicsContactMgr *manager, hkpRigidBody *body, hkpConstraintOwner *constraintOwner, hkVector4f *velWorld)
{
  hkVector4f *v4; // rsi
  hkpConstraintOwner *v5; // rdi
  hkpRigidBody *v6; // rbp
  hkpConstraintInstance *v7; // rbx
  _QWORD *v8; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  __m128 v12; // xmm6
  hkpModifierConstraintAtom *v13; // rax
  _QWORD **v14; // rax
  __int64 v15; // rax
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  signed __int64 v19; // rcx

  v4 = velWorld;
  v5 = constraintOwner;
  v6 = body;
  v7 = (hkpConstraintInstance *)((__int64 (*)(void))manager->vfptr[8].__vecDelDtor)();
  if ( v7 )
  {
    ((void (__fastcall *)(hkpConstraintOwner *))v5->vfptr[3].__vecDelDtor)(v5);
    v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v9 = (_QWORD *)v8[1];
    if ( (unsigned __int64)v9 < v8[3] )
    {
      *v9 = "TtSetSurfVel";
      v10 = __rdtsc();
      v11 = (signed __int64)(v9 + 2);
      *(_DWORD *)(v11 - 8) = v10;
      v8[1] = v11;
    }
    v12 = v4->m_quad;
    if ( (hkpRigidBody *)v7->m_entities[0] == v6 )
      v12 = _mm_xor_ps(v12, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
    v13 = hkpWorldConstraintUtil::findModifier(v7, (hkpConstraintAtom::AtomType)33);
    if ( v13 )
    {
      *(__m128 *)&v13[1].m_type.m_storage = v12;
    }
    else
    {
      v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v15 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v14[11] + 8i64))(v14[11], 64i64);
      if ( v15 )
      {
        *(_WORD *)v15 = 33;
        *(_WORD *)(v15 + 16) = 64;
      }
      *(__m128 *)(v15 + 48) = v12;
      hkpWorldConstraintUtil::addModifier(v7, v5, (hkpModifierConstraintAtom *)v15);
    }
    v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v17 = (_QWORD *)v16[1];
    if ( (unsigned __int64)v17 < v16[3] )
    {
      *v17 = "Et";
      v18 = __rdtsc();
      v19 = (signed __int64)(v17 + 2);
      *(_DWORD *)(v19 - 8) = v18;
      v16[1] = v19;
    }
  }
}

// File Line: 283
// RVA: 0xD695E0
void __fastcall hkpResponseModifier::clearSurfaceVelocity(hkpDynamicsContactMgr *manager, hkpConstraintOwner *constraintOwner, hkpRigidBody *body)
{
  hkpConstraintOwner *v3; // rbx
  hkpConstraintInstance *v4; // rdi
  _QWORD *v5; // r8
  _QWORD *v6; // rcx
  unsigned __int64 v7; // rax
  signed __int64 v8; // rcx
  _QWORD *v9; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx

  v3 = constraintOwner;
  v4 = (hkpConstraintInstance *)((__int64 (__fastcall *)(hkpDynamicsContactMgr *, hkpConstraintOwner *, hkpRigidBody *))manager->vfptr[8].__vecDelDtor)(
                                  manager,
                                  constraintOwner,
                                  body);
  if ( v4 )
  {
    ((void (__fastcall *)(hkpConstraintOwner *))v3->vfptr[3].__vecDelDtor)(v3);
    v5 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v6 = (_QWORD *)v5[1];
    if ( (unsigned __int64)v6 < v5[3] )
    {
      *v6 = "TtClrSurfVel";
      v7 = __rdtsc();
      v8 = (signed __int64)(v6 + 2);
      *(_DWORD *)(v8 - 8) = v7;
      v5[1] = v8;
    }
    hkpWorldConstraintUtil::removeAndDeleteModifier(v4, v3, (hkpConstraintAtom::AtomType)33);
    v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v10 = (_QWORD *)v9[1];
    if ( (unsigned __int64)v10 < v9[3] )
    {
      *v10 = "Et";
      v11 = __rdtsc();
      v12 = (signed __int64)(v10 + 2);
      *(_DWORD *)(v12 - 8) = v11;
      v9[1] = v12;
    }
  }
}

// File Line: 302
// RVA: 0xD696A0
void __fastcall hkpResponseModifier::setLowSurfaceViscosity(hkpDynamicsContactMgr *manager, hkpConstraintOwner *constraintOwner)
{
  hkpConstraintOwner *v2; // rdi
  hkpConstraintInstance *v3; // rbx
  _QWORD *v4; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  signed __int64 v7; // rcx
  _QWORD **v8; // rax
  hkpModifierConstraintAtom *v9; // rax
  _QWORD *v10; // rax
  _QWORD *v11; // rcx
  _QWORD *v12; // r8
  unsigned __int64 v13; // rax
  signed __int64 v14; // rcx

  v2 = constraintOwner;
  v3 = (hkpConstraintInstance *)((__int64 (*)(void))manager->vfptr[8].__vecDelDtor)();
  if ( v3 )
  {
    ((void (__fastcall *)(hkpConstraintOwner *))v2->vfptr[3].__vecDelDtor)(v2);
    v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v5 = (_QWORD *)v4[1];
    if ( (unsigned __int64)v5 < v4[3] )
    {
      *v5 = "TtSetSurfVisc";
      v6 = __rdtsc();
      v7 = (signed __int64)(v5 + 2);
      *(_DWORD *)(v7 - 8) = v6;
      v4[1] = v7;
    }
    if ( !hkpWorldConstraintUtil::findModifier(v3, (hkpConstraintAtom::AtomType)32) )
    {
      v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v9 = (hkpModifierConstraintAtom *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(
                                          v8[11],
                                          48i64);
      if ( v9 )
      {
        v9->m_type.m_storage = 32;
        v9->m_modifierAtomSize = 48;
      }
      hkpWorldConstraintUtil::addModifier(v3, v2, v9);
    }
    v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v11 = (_QWORD *)v10[1];
    v12 = v10;
    if ( (unsigned __int64)v11 < v10[3] )
    {
      *v11 = "Et";
      v13 = __rdtsc();
      v14 = (signed __int64)(v11 + 2);
      *(_DWORD *)(v14 - 8) = v13;
      v12[1] = v14;
    }
  }
}

// File Line: 339
// RVA: 0xD697B0
void __fastcall hkpResponseModifier::disableConstraint(hkpConstraintInstance *instance, hkpConstraintOwner *constraintOwner)
{
  hkpConstraintInstance *v2; // rdi
  hkpConstraintOwner *v3; // rbx
  _QWORD *v4; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  signed __int64 v7; // rcx
  _QWORD **v8; // rax
  hkpModifierConstraintAtom *v9; // rax
  _QWORD *v10; // rax
  _QWORD *v11; // rcx
  _QWORD *v12; // r8
  unsigned __int64 v13; // rax
  signed __int64 v14; // rcx

  v2 = instance;
  v3 = constraintOwner;
  ((void (__fastcall *)(hkpConstraintOwner *))constraintOwner->vfptr[3].__vecDelDtor)(constraintOwner);
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)v4[1];
  if ( (unsigned __int64)v5 < v4[3] )
  {
    *v5 = "TtDsblConstr";
    v6 = __rdtsc();
    v7 = (signed __int64)(v5 + 2);
    *(_DWORD *)(v7 - 8) = v6;
    v4[1] = v7;
  }
  if ( !hkpWorldConstraintUtil::findModifier(v2, (hkpConstraintAtom::AtomType)34) )
  {
    v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v9 = (hkpModifierConstraintAtom *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(
                                        v8[11],
                                        48i64);
    if ( v9 )
    {
      v9->m_type.m_storage = 34;
      v9->m_modifierAtomSize = 48;
    }
    hkpWorldConstraintUtil::addModifier(v2, v3, v9);
  }
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)v10[1];
  v12 = v10;
  if ( (unsigned __int64)v11 < v10[3] )
  {
    *v11 = "Et";
    v13 = __rdtsc();
    v14 = (signed __int64)(v11 + 2);
    *(_DWORD *)(v14 - 8) = v13;
    v12[1] = v14;
  }
}

// File Line: 360
// RVA: 0xD698B0
void __fastcall hkpResponseModifier::enableConstraint(hkpConstraintInstance *instance, hkpConstraintOwner *constraintOwner)
{
  hkpConstraintInstance *v2; // rdi
  hkpConstraintOwner *v3; // rbx
  _QWORD *v4; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  signed __int64 v7; // rcx
  __int64 v8; // rdx
  struct hkpConstraintRuntime *v9; // rbx
  __int64 v10; // rax
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  signed __int64 v14; // rcx
  char v15; // [rsp+30h] [rbp+8h]
  unsigned int v16; // [rsp+34h] [rbp+Ch]

  v2 = instance;
  v3 = constraintOwner;
  ((void (__fastcall *)(hkpConstraintOwner *))constraintOwner->vfptr[3].__vecDelDtor)(constraintOwner);
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)v4[1];
  if ( (unsigned __int64)v5 < v4[3] )
  {
    *v5 = "TtEnblConstr";
    v6 = __rdtsc();
    v7 = (signed __int64)(v5 + 2);
    *(_DWORD *)(v7 - 8) = v6;
    v4[1] = v7;
  }
  hkpWorldConstraintUtil::removeAndDeleteModifier(v2, v3, (hkpConstraintAtom::AtomType)34);
  v9 = v2->m_internal->m_runtime;
  if ( v9 )
  {
    LOBYTE(v8) = 1;
    ((void (__fastcall *)(hkpConstraintData *, __int64, char *))v2->m_data->vfptr[8].__first_virtual_table_function__)(
      v2->m_data,
      v8,
      &v15);
    v10 = v16;
    if ( (signed int)v16 > 0 )
    {
      do
      {
        *(_QWORD *)v9 = 0i64;
        v9 = (struct hkpConstraintRuntime *)((char *)v9 + 8);
        --v10;
      }
      while ( v10 );
    }
  }
  v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v12 = (_QWORD *)v11[1];
  if ( (unsigned __int64)v12 < v11[3] )
  {
    *v12 = "Et";
    v13 = __rdtsc();
    v14 = (signed __int64)(v12 + 2);
    *(_DWORD *)(v14 - 8) = v13;
    v11[1] = v14;
  }
}

