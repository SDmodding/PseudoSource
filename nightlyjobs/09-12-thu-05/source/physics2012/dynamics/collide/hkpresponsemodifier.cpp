// File Line: 35
// RVA: 0xD68EE0
void __fastcall hkpResponseModifier::setInvMassScalingForContact(
        hkpDynamicsContactMgr *manager,
        hkpRigidBody *bodyA,
        hkpRigidBody *bodyB,
        hkpConstraintOwner *constraintOwner,
        hkVector4f *factorA,
        hkVector4f *factorB)
{
  __int64 v8; // rdi
  _QWORD *Value; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  hkpModifierConstraintAtom *Modifier; // rbx
  _QWORD **v14; // rax
  hkpModifierConstraintAtom *v15; // rax
  __m128 m_quad; // xmm0
  hkVector4f *v17; // rax
  _QWORD *v18; // rax
  _QWORD *v19; // rcx
  _QWORD *v20; // r8
  unsigned __int64 v21; // rax
  _QWORD *v22; // rcx

  v8 = ((__int64 (__fastcall *)(hkpDynamicsContactMgr *, hkpRigidBody *, hkpRigidBody *))manager->vfptr[8].__vecDelDtor)(
         manager,
         bodyA,
         bodyB);
  if ( v8 )
  {
    ((void (__fastcall *)(hkpConstraintOwner *))constraintOwner->vfptr[3].__vecDelDtor)(constraintOwner);
    Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v10 = (_QWORD *)Value[1];
    if ( (unsigned __int64)v10 < Value[3] )
    {
      *v10 = "TtSetMassChang";
      v11 = __rdtsc();
      v12 = v10 + 2;
      *((_DWORD *)v12 - 2) = v11;
      Value[1] = v12;
    }
    Modifier = hkpWorldConstraintUtil::findModifier(
                 (hkpConstraintInstance *)v8,
                 TYPE_MAX|TYPE_CONVEX_LIST_CONTACT_MGR|0x18);
    if ( !Modifier )
    {
      v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v15 = (hkpModifierConstraintAtom *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v14[11] + 8i64))(
                                           v14[11],
                                           80i64);
      Modifier = v15;
      if ( v15 )
      {
        v15->m_type.m_storage = 31;
        v15->m_modifierAtomSize = 80;
      }
      else
      {
        Modifier = 0i64;
      }
      hkpWorldConstraintUtil::addModifier((hkpConstraintInstance *)v8, constraintOwner, Modifier);
    }
    if ( bodyA == *(hkpRigidBody **)(v8 + 40) )
    {
      m_quad = factorA->m_quad;
      v17 = factorB;
    }
    else
    {
      m_quad = factorB->m_quad;
      v17 = factorA;
    }
    *(__m128 *)&Modifier[1].m_type.m_storage = m_quad;
    *(hkVector4f *)&Modifier[1].m_modifierAtomSize = (hkVector4f)v17->m_quad;
    v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v19 = (_QWORD *)v18[1];
    v20 = v18;
    if ( (unsigned __int64)v19 < v18[3] )
    {
      *v19 = "Et";
      v21 = __rdtsc();
      v22 = v19 + 2;
      *((_DWORD *)v22 - 2) = v21;
      v20[1] = v22;
    }
  }
}

// File Line: 83
// RVA: 0xD69030
void __fastcall hkpResponseModifier::setInvMassScalingForContact(
        hkpDynamicsContactMgr *manager,
        hkpRigidBody *body,
        hkpConstraintOwner *constraintOwner,
        hkVector4f *factor)
{
  __int64 v7; // rsi
  _QWORD *Value; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  hkpModifierConstraintAtom *Modifier; // rax
  _QWORD **v13; // rax
  hkpModifierConstraintAtom *v14; // rax
  hkpModifierConstraintAtom *v15; // rbx
  __m128 v16; // xmm0
  __m128 m_quad; // xmm0
  __m128 v18; // xmm1
  _QWORD *v19; // rax
  _QWORD *v20; // rcx
  _QWORD *v21; // r8
  unsigned __int64 v22; // rax
  _QWORD *v23; // rcx

  v7 = ((__int64 (__fastcall *)(hkpDynamicsContactMgr *))manager->vfptr[8].__vecDelDtor)(manager);
  if ( v7 )
  {
    ((void (__fastcall *)(hkpConstraintOwner *))constraintOwner->vfptr[3].__vecDelDtor)(constraintOwner);
    Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v9 = (_QWORD *)Value[1];
    if ( (unsigned __int64)v9 < Value[3] )
    {
      *v9 = "TtSetMassChang";
      v10 = __rdtsc();
      v11 = v9 + 2;
      *((_DWORD *)v11 - 2) = v10;
      Value[1] = v11;
    }
    Modifier = hkpWorldConstraintUtil::findModifier(
                 (hkpConstraintInstance *)v7,
                 TYPE_MAX|TYPE_CONVEX_LIST_CONTACT_MGR|0x18);
    if ( Modifier )
    {
      m_quad = factor->m_quad;
      if ( body == *(hkpRigidBody **)(v7 + 40) )
        *(__m128 *)&Modifier[1].m_type.m_storage = m_quad;
      else
        *(__m128 *)&Modifier[1].m_modifierAtomSize = m_quad;
      v18 = *(__m128 *)&Modifier[1].m_type.m_storage;
      if ( _mm_shuffle_ps(v18, v18, 255).m128_f32[0] == 0.0
        && _mm_shuffle_ps(*(__m128 *)&Modifier[1].m_modifierAtomSize, *(__m128 *)&Modifier[1].m_modifierAtomSize, 255).m128_f32[0] == 0.0 )
      {
        *(__m128 *)&Modifier[1].m_type.m_storage = _mm_shuffle_ps(v18, _mm_unpackhi_ps(v18, query.m_quad), 196);
        *(__m128 *)&Modifier[1].m_modifierAtomSize = _mm_shuffle_ps(
                                                       *(__m128 *)&Modifier[1].m_modifierAtomSize,
                                                       _mm_unpackhi_ps(
                                                         *(__m128 *)&Modifier[1].m_modifierAtomSize,
                                                         query.m_quad),
                                                       196);
      }
    }
    else
    {
      v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v14 = (hkpModifierConstraintAtom *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v13[11] + 8i64))(
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
      hkpWorldConstraintUtil::addModifier((hkpConstraintInstance *)v7, constraintOwner, v15);
      if ( body == *(hkpRigidBody **)(v7 + 40) )
      {
        v16 = factor->m_quad;
        *(hkVector4f *)&v15[1].m_modifierAtomSize = (hkVector4f)query.m_quad;
        *(__m128 *)&v15[1].m_type.m_storage = v16;
      }
      else
      {
        *(hkVector4f *)&v15[1].m_type.m_storage = (hkVector4f)query.m_quad;
        *(hkVector4f *)&v15[1].m_modifierAtomSize = (hkVector4f)factor->m_quad;
      }
    }
    v19 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v20 = (_QWORD *)v19[1];
    v21 = v19;
    if ( (unsigned __int64)v20 < v19[3] )
    {
      *v20 = "Et";
      v22 = __rdtsc();
      v23 = v20 + 2;
      *((_DWORD *)v23 - 2) = v22;
      v21[1] = v23;
    }
  }
}

// File Line: 145
// RVA: 0xD691F0
void __fastcall hkpResponseModifier::setCenterOfMassDisplacementForContact(
        hkpDynamicsContactMgr *manager,
        hkpRigidBody *bodyA,
        hkpRigidBody *bodyB,
        hkpConstraintOwner *constraintOwner,
        hkVector4f *displacementA,
        hkVector4f *displacementB)
{
  __int64 v8; // rdi
  _QWORD *Value; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  hkpModifierConstraintAtom *Modifier; // rbx
  _QWORD **v14; // rax
  hkpModifierConstraintAtom *v15; // rax
  __m128 m_quad; // xmm0
  hkVector4f *v17; // rax
  _QWORD *v18; // rax
  _QWORD *v19; // rcx
  _QWORD *v20; // r8
  unsigned __int64 v21; // rax
  _QWORD *v22; // rcx

  v8 = ((__int64 (__fastcall *)(hkpDynamicsContactMgr *, hkpRigidBody *, hkpRigidBody *))manager->vfptr[8].__vecDelDtor)(
         manager,
         bodyA,
         bodyB);
  if ( v8 )
  {
    ((void (__fastcall *)(hkpConstraintOwner *))constraintOwner->vfptr[3].__vecDelDtor)(constraintOwner);
    Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v10 = (_QWORD *)Value[1];
    if ( (unsigned __int64)v10 < Value[3] )
    {
      *v10 = "TtSetMassChang";
      v11 = __rdtsc();
      v12 = v10 + 2;
      *((_DWORD *)v12 - 2) = v11;
      Value[1] = v12;
    }
    Modifier = hkpWorldConstraintUtil::findModifier((hkpConstraintInstance *)v8, TYPE_NULL_CONTACT_MGR|0x20);
    if ( !Modifier )
    {
      v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v15 = (hkpModifierConstraintAtom *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v14[11] + 8i64))(
                                           v14[11],
                                           80i64);
      Modifier = v15;
      if ( v15 )
      {
        v15->m_type.m_storage = 35;
        v15->m_modifierAtomSize = 80;
      }
      else
      {
        Modifier = 0i64;
      }
      hkpWorldConstraintUtil::addModifier((hkpConstraintInstance *)v8, constraintOwner, Modifier);
    }
    if ( bodyA == *(hkpRigidBody **)(v8 + 40) )
    {
      m_quad = displacementA->m_quad;
      v17 = displacementB;
    }
    else
    {
      m_quad = displacementB->m_quad;
      v17 = displacementA;
    }
    *(__m128 *)&Modifier[1].m_type.m_storage = m_quad;
    *(hkVector4f *)&Modifier[1].m_modifierAtomSize = (hkVector4f)v17->m_quad;
    v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v19 = (_QWORD *)v18[1];
    v20 = v18;
    if ( (unsigned __int64)v19 < v18[3] )
    {
      *v19 = "Et";
      v21 = __rdtsc();
      v22 = v19 + 2;
      *((_DWORD *)v22 - 2) = v21;
      v20[1] = v22;
    }
  }
}

// File Line: 189
// RVA: 0xD69340
void __fastcall hkpResponseModifier::setImpulseScalingForContact(
        hkpDynamicsContactMgr *manager,
        hkpRigidBody *bodyA,
        hkpRigidBody *bodyB,
        hkpConstraintOwner *constraintOwner,
        float usedImpulseFraction,
        float maxAcceleration)
{
  hkpConstraintInstance *v7; // rbx
  _QWORD *Value; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  hkpModifierConstraintAtom *Modifier; // rax
  _QWORD **v13; // rax
  __int64 v14; // rax
  _QWORD *v15; // rax
  _QWORD *v16; // rcx
  _QWORD *v17; // r8
  unsigned __int64 v18; // rax
  _QWORD *v19; // rcx

  v7 = (hkpConstraintInstance *)((__int64 (__fastcall *)(hkpDynamicsContactMgr *, hkpRigidBody *, hkpRigidBody *))manager->vfptr[8].__vecDelDtor)(
                                  manager,
                                  bodyA,
                                  bodyB);
  if ( v7 )
  {
    ((void (__fastcall *)(hkpConstraintOwner *))constraintOwner->vfptr[3].__vecDelDtor)(constraintOwner);
    Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v9 = (_QWORD *)Value[1];
    if ( (unsigned __int64)v9 < Value[3] )
    {
      *v9 = "TtSetSoftContact";
      v10 = __rdtsc();
      v11 = v9 + 2;
      *((_DWORD *)v11 - 2) = v10;
      Value[1] = v11;
    }
    Modifier = hkpWorldConstraintUtil::findModifier(v7, (hkpConstraintAtom::AtomType)30);
    if ( Modifier )
    {
      *(float *)&Modifier[1].m_type.m_storage = usedImpulseFraction;
      *((float *)&Modifier[1].hkpConstraintAtom + 1) = maxAcceleration;
    }
    else
    {
      v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v14 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v13[11] + 8i64))(v13[11], 64i64);
      if ( v14 )
      {
        *(_WORD *)v14 = 30;
        *(_WORD *)(v14 + 16) = 64;
        *(_DWORD *)(v14 + 48) = 1036831949;
        *(_DWORD *)(v14 + 52) = 1101004800;
      }
      *(float *)(v14 + 48) = usedImpulseFraction;
      *(float *)(v14 + 52) = maxAcceleration;
      hkpWorldConstraintUtil::addModifier(v7, constraintOwner, (hkpModifierConstraintAtom *)v14);
    }
    v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v16 = (_QWORD *)v15[1];
    v17 = v15;
    if ( (unsigned __int64)v16 < v15[3] )
    {
      *v16 = "Et";
      v18 = __rdtsc();
      v19 = v16 + 2;
      *((_DWORD *)v19 - 2) = v18;
      v17[1] = v19;
    }
  }
}

// File Line: 234
// RVA: 0xD69490
void __fastcall hkpResponseModifier::setSurfaceVelocity(
        hkpDynamicsContactMgr *manager,
        hkpRigidBody *body,
        hkpConstraintOwner *constraintOwner,
        hkVector4f *velWorld)
{
  __int64 v7; // rbx
  _QWORD *Value; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  __m128 m_quad; // xmm6
  hkpModifierConstraintAtom *Modifier; // rax
  _QWORD **v14; // rax
  __int64 v15; // rax
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  _QWORD *v19; // rcx

  v7 = ((__int64 (__fastcall *)(hkpDynamicsContactMgr *))manager->vfptr[8].__vecDelDtor)(manager);
  if ( v7 )
  {
    ((void (__fastcall *)(hkpConstraintOwner *))constraintOwner->vfptr[3].__vecDelDtor)(constraintOwner);
    Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v9 = (_QWORD *)Value[1];
    if ( (unsigned __int64)v9 < Value[3] )
    {
      *v9 = "TtSetSurfVel";
      v10 = __rdtsc();
      v11 = v9 + 2;
      *((_DWORD *)v11 - 2) = v10;
      Value[1] = v11;
    }
    m_quad = velWorld->m_quad;
    if ( *(hkpRigidBody **)(v7 + 40) == body )
      m_quad = _mm_xor_ps(m_quad, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
    Modifier = hkpWorldConstraintUtil::findModifier((hkpConstraintInstance *)v7, (hkpConstraintAtom::AtomType)33);
    if ( Modifier )
    {
      *(__m128 *)&Modifier[1].m_type.m_storage = m_quad;
    }
    else
    {
      v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v15 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v14[11] + 8i64))(v14[11], 64i64);
      if ( v15 )
      {
        *(_WORD *)v15 = 33;
        *(_WORD *)(v15 + 16) = 64;
      }
      *(__m128 *)(v15 + 48) = m_quad;
      hkpWorldConstraintUtil::addModifier(
        (hkpConstraintInstance *)v7,
        constraintOwner,
        (hkpModifierConstraintAtom *)v15);
    }
    v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v17 = (_QWORD *)v16[1];
    if ( (unsigned __int64)v17 < v16[3] )
    {
      *v17 = "Et";
      v18 = __rdtsc();
      v19 = v17 + 2;
      *((_DWORD *)v19 - 2) = v18;
      v16[1] = v19;
    }
  }
}

// File Line: 283
// RVA: 0xD695E0
void __fastcall hkpResponseModifier::clearSurfaceVelocity(
        hkpDynamicsContactMgr *manager,
        hkpConstraintOwner *constraintOwner,
        hkpRigidBody *body)
{
  hkpConstraintInstance *v4; // rdi
  _QWORD *Value; // r8
  _QWORD *v6; // rcx
  unsigned __int64 v7; // rax
  _QWORD *v8; // rcx
  _QWORD *v9; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx

  v4 = (hkpConstraintInstance *)((__int64 (__fastcall *)(hkpDynamicsContactMgr *, hkpConstraintOwner *, hkpRigidBody *))manager->vfptr[8].__vecDelDtor)(
                                  manager,
                                  constraintOwner,
                                  body);
  if ( v4 )
  {
    ((void (__fastcall *)(hkpConstraintOwner *))constraintOwner->vfptr[3].__vecDelDtor)(constraintOwner);
    Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v6 = (_QWORD *)Value[1];
    if ( (unsigned __int64)v6 < Value[3] )
    {
      *v6 = "TtClrSurfVel";
      v7 = __rdtsc();
      v8 = v6 + 2;
      *((_DWORD *)v8 - 2) = v7;
      Value[1] = v8;
    }
    hkpWorldConstraintUtil::removeAndDeleteModifier(v4, constraintOwner, (hkpConstraintAtom::AtomType)33);
    v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v10 = (_QWORD *)v9[1];
    if ( (unsigned __int64)v10 < v9[3] )
    {
      *v10 = "Et";
      v11 = __rdtsc();
      v12 = v10 + 2;
      *((_DWORD *)v12 - 2) = v11;
      v9[1] = v12;
    }
  }
}

// File Line: 302
// RVA: 0xD696A0
void __fastcall hkpResponseModifier::setLowSurfaceViscosity(
        hkpDynamicsContactMgr *manager,
        hkpConstraintOwner *constraintOwner)
{
  hkpConstraintInstance *v3; // rbx
  _QWORD *Value; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  _QWORD *v7; // rcx
  _QWORD **v8; // rax
  hkpModifierConstraintAtom *v9; // rax
  _QWORD *v10; // rax
  _QWORD *v11; // rcx
  _QWORD *v12; // r8
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx

  v3 = (hkpConstraintInstance *)((__int64 (__fastcall *)(hkpDynamicsContactMgr *))manager->vfptr[8].__vecDelDtor)(manager);
  if ( v3 )
  {
    ((void (__fastcall *)(hkpConstraintOwner *))constraintOwner->vfptr[3].__vecDelDtor)(constraintOwner);
    Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v5 = (_QWORD *)Value[1];
    if ( (unsigned __int64)v5 < Value[3] )
    {
      *v5 = "TtSetSurfVisc";
      v6 = __rdtsc();
      v7 = v5 + 2;
      *((_DWORD *)v7 - 2) = v6;
      Value[1] = v7;
    }
    if ( !hkpWorldConstraintUtil::findModifier(v3, (hkpConstraintAtom::AtomType)32) )
    {
      v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v9 = (hkpModifierConstraintAtom *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v8[11] + 8i64))(v8[11], 48i64);
      if ( v9 )
      {
        v9->m_type.m_storage = 32;
        v9->m_modifierAtomSize = 48;
      }
      hkpWorldConstraintUtil::addModifier(v3, constraintOwner, v9);
    }
    v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v11 = (_QWORD *)v10[1];
    v12 = v10;
    if ( (unsigned __int64)v11 < v10[3] )
    {
      *v11 = "Et";
      v13 = __rdtsc();
      v14 = v11 + 2;
      *((_DWORD *)v14 - 2) = v13;
      v12[1] = v14;
    }
  }
}

// File Line: 339
// RVA: 0xD697B0
void __fastcall hkpResponseModifier::disableConstraint(
        hkpConstraintInstance *instance,
        hkpConstraintOwner *constraintOwner)
{
  _QWORD *Value; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  _QWORD *v7; // rcx
  _QWORD **v8; // rax
  hkpModifierConstraintAtom *v9; // rax
  _QWORD *v10; // rax
  _QWORD *v11; // rcx
  _QWORD *v12; // r8
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx

  ((void (__fastcall *)(hkpConstraintOwner *))constraintOwner->vfptr[3].__vecDelDtor)(constraintOwner);
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v5 < Value[3] )
  {
    *v5 = "TtDsblConstr";
    v6 = __rdtsc();
    v7 = v5 + 2;
    *((_DWORD *)v7 - 2) = v6;
    Value[1] = v7;
  }
  if ( !hkpWorldConstraintUtil::findModifier(instance, (hkpConstraintAtom::AtomType)34) )
  {
    v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v9 = (hkpModifierConstraintAtom *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v8[11] + 8i64))(v8[11], 48i64);
    if ( v9 )
    {
      v9->m_type.m_storage = 34;
      v9->m_modifierAtomSize = 48;
    }
    hkpWorldConstraintUtil::addModifier(instance, constraintOwner, v9);
  }
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)v10[1];
  v12 = v10;
  if ( (unsigned __int64)v11 < v10[3] )
  {
    *v11 = "Et";
    v13 = __rdtsc();
    v14 = v11 + 2;
    *((_DWORD *)v14 - 2) = v13;
    v12[1] = v14;
  }
}

// File Line: 360
// RVA: 0xD698B0
void __fastcall hkpResponseModifier::enableConstraint(
        hkpConstraintInstance *instance,
        hkpConstraintOwner *constraintOwner)
{
  _QWORD *Value; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  _QWORD *v7; // rcx
  __int64 v8; // rdx
  struct hkpConstraintRuntime *m_runtime; // rbx
  __int64 v10; // rax
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  char v15; // [rsp+30h] [rbp+8h] BYREF
  unsigned int v16; // [rsp+34h] [rbp+Ch]

  ((void (__fastcall *)(hkpConstraintOwner *))constraintOwner->vfptr[3].__vecDelDtor)(constraintOwner);
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v5 < Value[3] )
  {
    *v5 = "TtEnblConstr";
    v6 = __rdtsc();
    v7 = v5 + 2;
    *((_DWORD *)v7 - 2) = v6;
    Value[1] = v7;
  }
  hkpWorldConstraintUtil::removeAndDeleteModifier(instance, constraintOwner, (hkpConstraintAtom::AtomType)34);
  m_runtime = instance->m_internal->m_runtime;
  if ( m_runtime )
  {
    LOBYTE(v8) = 1;
    ((void (__fastcall *)(hkpConstraintData *, __int64, char *))instance->m_data->vfptr[8].__first_virtual_table_function__)(
      instance->m_data,
      v8,
      &v15);
    v10 = v16;
    if ( (int)v16 > 0 )
    {
      do
      {
        *(_QWORD *)m_runtime = 0i64;
        m_runtime = (struct hkpConstraintRuntime *)((char *)m_runtime + 8);
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
    v14 = v12 + 2;
    *((_DWORD *)v14 - 2) = v13;
    v11[1] = v14;
  }
}

