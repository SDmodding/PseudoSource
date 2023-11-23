// File Line: 31
// RVA: 0xD280C0
void __fastcall hkpProcessCollisionOutputBackup::hkpProcessCollisionOutputBackup(
        hkpProcessCollisionOutputBackup *this,
        hkpProcessCollisionOutput *output)
{
  hkpProcessCollisionOutput::PotentialInfo *m_storage; // rdx
  hkpProcessCollisionOutput::PotentialInfo *p_m_weldingInformation; // rcx
  __int64 v4; // rax
  __int128 v5; // xmm0

  this->m_firstPoint = output->m_firstFreeContactPoint.m_storage;
  this->m_toi = output->m_toi;
  m_storage = output->m_potentialContacts.m_storage;
  if ( m_storage )
  {
    p_m_weldingInformation = &this->m_weldingInformation;
    if ( (((unsigned __int8)p_m_weldingInformation | (unsigned __int8)m_storage) & 0xF) != 0 )
    {
      memmove(p_m_weldingInformation, m_storage, 0x2010ui64);
    }
    else
    {
      v4 = 64i64;
      do
      {
        v5 = *(_OWORD *)&m_storage->m_firstFreePotentialContact;
        p_m_weldingInformation = (hkpProcessCollisionOutput::PotentialInfo *)((char *)p_m_weldingInformation + 128);
        m_storage = (hkpProcessCollisionOutput::PotentialInfo *)((char *)m_storage + 128);
        *(_OWORD *)&p_m_weldingInformation[-1].m_potentialContacts[250].m_agentData = v5;
        *(_OWORD *)&p_m_weldingInformation[-1].m_potentialContacts[251].m_agentEntry = *(_OWORD *)&m_storage[-1].m_potentialContacts[251].m_agentEntry;
        *(_OWORD *)&p_m_weldingInformation[-1].m_potentialContacts[252].m_contactPoint = *(_OWORD *)&m_storage[-1].m_potentialContacts[252].m_contactPoint;
        *(_OWORD *)&p_m_weldingInformation[-1].m_potentialContacts[252].m_agentData = *(_OWORD *)&m_storage[-1].m_potentialContacts[252].m_agentData;
        *(_OWORD *)&p_m_weldingInformation[-1].m_potentialContacts[253].m_agentEntry = *(_OWORD *)&m_storage[-1].m_potentialContacts[253].m_agentEntry;
        *(_OWORD *)&p_m_weldingInformation[-1].m_potentialContacts[254].m_contactPoint = *(_OWORD *)&m_storage[-1].m_potentialContacts[254].m_contactPoint;
        *(_OWORD *)&p_m_weldingInformation[-1].m_potentialContacts[254].m_agentData = *(_OWORD *)&m_storage[-1].m_potentialContacts[254].m_agentData;
        *(_OWORD *)&p_m_weldingInformation[-1].m_potentialContacts[255].m_agentEntry = *(_OWORD *)&m_storage[-1].m_potentialContacts[255].m_agentEntry;
        --v4;
      }
      while ( v4 );
      *(_OWORD *)&p_m_weldingInformation->m_firstFreePotentialContact = *(_OWORD *)&m_storage->m_firstFreePotentialContact;
    }
  }
}

// File Line: 41
// RVA: 0xD28770
void __fastcall hkpProcessCollisionOutputBackup::rollbackOutput(
        hkpProcessCollisionOutputBackup *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpProcessCollisionOutput *output,
        hkpContactMgr *mgr)
{
  hkpProcessCollisionOutput::PotentialInfo *m_storage; // rcx
  hkpProcessCollisionOutput::PotentialInfo *p_m_weldingInformation; // rdx
  __int64 v9; // rax
  __int128 v10; // xmm0

  if ( this->m_toi.m_time.m_storage != output->m_toi.m_time.m_storage )
  {
    ((void (__fastcall *)(hkpContactMgr *, hkpConstraintOwner *, hkContactPointPropertiesWithExtendedUserData16 *))mgr->vfptr[4].__vecDelDtor)(
      mgr,
      output->m_constraintOwner.m_storage,
      &output->m_toi.m_properties);
    output->m_toi.m_contactPoint.m_position = this->m_toi.m_contactPoint.m_position;
    output->m_toi.m_contactPoint.m_separatingNormal = this->m_toi.m_contactPoint.m_separatingNormal;
    output->m_toi.m_time.m_storage = this->m_toi.m_time.m_storage;
    output->m_toi.m_seperatingVelocity.m_storage = this->m_toi.m_seperatingVelocity.m_storage;
    *(_QWORD *)output->m_toi.m_gskCache.m_vertices = *(_QWORD *)this->m_toi.m_gskCache.m_vertices;
    *(_QWORD *)&output->m_toi.m_gskCache.m_dimA = *(_QWORD *)&this->m_toi.m_gskCache.m_dimA;
    output->m_toi.m_properties.hkpSolverResults = this->m_toi.m_properties.hkpSolverResults;
    output->m_toi.m_properties.m_userData = this->m_toi.m_properties.m_userData;
    *(_QWORD *)&output->m_toi.m_properties.m_friction.m_value = *(_QWORD *)&this->m_toi.m_properties.m_friction.m_value;
    *(_QWORD *)&output->m_toi.m_properties.m_internalDataA = *(_QWORD *)&this->m_toi.m_properties.m_internalDataA;
    *(_QWORD *)output->m_toi.m_properties.m_extendedUserDatas = *(_QWORD *)this->m_toi.m_properties.m_extendedUserDatas;
    *(_QWORD *)&output->m_toi.m_properties.m_extendedUserDatas[2] = *(_QWORD *)&this->m_toi.m_properties.m_extendedUserDatas[2];
    *(_QWORD *)&output->m_toi.m_properties.m_extendedUserDatas[4] = *(_QWORD *)&this->m_toi.m_properties.m_extendedUserDatas[4];
    *(_QWORD *)&output->m_toi.m_properties.m_extendedUserDatas[6] = *(_QWORD *)&this->m_toi.m_properties.m_extendedUserDatas[6];
  }
  m_storage = output->m_potentialContacts.m_storage;
  output->m_firstFreeContactPoint.m_storage = this->m_firstPoint;
  if ( m_storage )
  {
    p_m_weldingInformation = &this->m_weldingInformation;
    if ( (((unsigned __int8)m_storage | (unsigned __int8)((_BYTE)this + 8)) & 0xF) != 0 )
    {
      memmove(m_storage, p_m_weldingInformation, 0x2010ui64);
    }
    else
    {
      v9 = 64i64;
      do
      {
        v10 = *(_OWORD *)&p_m_weldingInformation->m_firstFreePotentialContact;
        m_storage = (hkpProcessCollisionOutput::PotentialInfo *)((char *)m_storage + 128);
        p_m_weldingInformation = (hkpProcessCollisionOutput::PotentialInfo *)((char *)p_m_weldingInformation + 128);
        *(_OWORD *)&m_storage[-1].m_potentialContacts[250].m_agentData = v10;
        *(_OWORD *)&m_storage[-1].m_potentialContacts[251].m_agentEntry = *(_OWORD *)&p_m_weldingInformation[-1].m_potentialContacts[251].m_agentEntry;
        *(_OWORD *)&m_storage[-1].m_potentialContacts[252].m_contactPoint = *(_OWORD *)&p_m_weldingInformation[-1].m_potentialContacts[252].m_contactPoint;
        *(_OWORD *)&m_storage[-1].m_potentialContacts[252].m_agentData = *(_OWORD *)&p_m_weldingInformation[-1].m_potentialContacts[252].m_agentData;
        *(_OWORD *)&m_storage[-1].m_potentialContacts[253].m_agentEntry = *(_OWORD *)&p_m_weldingInformation[-1].m_potentialContacts[253].m_agentEntry;
        *(_OWORD *)&m_storage[-1].m_potentialContacts[254].m_contactPoint = *(_OWORD *)&p_m_weldingInformation[-1].m_potentialContacts[254].m_contactPoint;
        *(_OWORD *)&m_storage[-1].m_potentialContacts[254].m_agentData = *(_OWORD *)&p_m_weldingInformation[-1].m_potentialContacts[254].m_agentData;
        *(_OWORD *)&m_storage[-1].m_potentialContacts[255].m_agentEntry = *(_OWORD *)&p_m_weldingInformation[-1].m_potentialContacts[255].m_agentEntry;
        --v9;
      }
      while ( v9 );
      *(_OWORD *)&m_storage->m_firstFreePotentialContact = *(_OWORD *)&p_m_weldingInformation->m_firstFreePotentialContact;
    }
  }
}

// File Line: 74
// RVA: 0xD281E0
__int64 __fastcall hkpMapPointsToSubShapeContactMgr::addContactPointImpl(
        hkpMapPointsToSubShapeContactMgr *this,
        hkpCdBody *a,
        hkpCdBody *b,
        hkpProcessCollisionInput *input,
        hkpProcessCollisionOutput *output,
        hkpGskCache *contactCache,
        hkContactPoint *cp)
{
  hkpShape *m_shape; // rcx
  __int64 *v11; // r15
  int v12; // edi
  __int64 v13; // rdx
  __int64 v14; // rax
  __int64 v15; // rcx
  __int64 m_dimA; // rcx
  unsigned int v17; // edi
  __int64 v18; // rdx
  __int64 v19; // rcx
  __int64 v20; // rax
  const void *m_motion; // rcx
  __int64 v23; // [rsp+40h] [rbp-258h] BYREF
  unsigned int v24; // [rsp+48h] [rbp-250h]
  const void *v25; // [rsp+50h] [rbp-248h]
  hkpCdBody *v26; // [rsp+58h] [rbp-240h]
  __int64 v27; // [rsp+60h] [rbp-238h] BYREF
  int v28; // [rsp+68h] [rbp-230h]
  __int64 v29; // [rsp+70h] [rbp-228h]
  __int64 *v30; // [rsp+78h] [rbp-220h]
  char v31[512]; // [rsp+80h] [rbp-218h] BYREF

  m_shape = a->m_shape;
  v11 = (__int64 *)a;
  if ( a->m_shape->m_type.m_storage == 26 )
  {
    v12 = HIBYTE(contactCache->m_vertices[0]);
    v13 = 1i64;
    if ( (unsigned __int8)contactCache->m_dimA > 1ui64 )
    {
      while ( HIBYTE(contactCache->m_vertices[v13]) == v12 )
      {
        if ( ++v13 >= (unsigned __int8)contactCache->m_dimA )
          goto LABEL_5;
      }
      goto LABEL_12;
    }
LABEL_5:
    v14 = (*(__int64 (__fastcall **)(unsigned __int16 *, _QWORD, char *))(*(_QWORD *)&m_shape[1].m_memSizeAndFlags
                                                                        + 40i64))(
            &m_shape[1].m_memSizeAndFlags,
            HIBYTE(contactCache->m_vertices[0]),
            v31);
    v15 = v11[2];
    v30 = v11;
    v29 = v15;
    v27 = v14;
    v28 = v12;
    v11 = &v27;
  }
  if ( b->m_shape->m_type.m_storage != 26 )
    return ((__int64 (__fastcall *)(hkpContactMgr *, __int64 *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, hkpGskCache *, hkContactPoint *))this->m_contactMgr->vfptr[1].__first_virtual_table_function__)(
             this->m_contactMgr,
             v11,
             b,
             input,
             output,
             contactCache,
             cp);
  m_dimA = (unsigned __int8)contactCache->m_dimA;
  v17 = HIBYTE(contactCache->m_vertices[m_dimA]);
  v18 = (int)m_dimA + 1;
  v19 = (int)(m_dimA + (unsigned __int8)contactCache->m_dimB);
  if ( v18 >= v19 )
  {
LABEL_10:
    v20 = (*(__int64 (__fastcall **)(unsigned __int16 *, _QWORD, char *))(*(_QWORD *)&b->m_shape[1].m_memSizeAndFlags
                                                                        + 40i64))(
            &b->m_shape[1].m_memSizeAndFlags,
            v17,
            v31);
    m_motion = b->m_motion;
    v26 = b;
    v25 = m_motion;
    v23 = v20;
    v24 = v17;
    b = (hkpCdBody *)&v23;
    return ((__int64 (__fastcall *)(hkpContactMgr *, __int64 *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, hkpGskCache *, hkContactPoint *))this->m_contactMgr->vfptr[1].__first_virtual_table_function__)(
             this->m_contactMgr,
             v11,
             b,
             input,
             output,
             contactCache,
             cp);
  }
  while ( HIBYTE(contactCache->m_vertices[v18]) == v17 )
  {
    if ( ++v18 >= v19 )
      goto LABEL_10;
  }
LABEL_12:
  this->m_invalidPointHit.m_bool = 1;
  return 0xFFFFi64;
}

// File Line: 122
// RVA: 0xD28750
hkResult *__fastcall hkpMapPointsToSubShapeContactMgr::reserveContactPointsImpl(
        hkpMapPointsToSubShapeContactMgr *this,
        hkResult *result,
        __int64 numPoints)
{
  ((void (__fastcall *)(hkpContactMgr *, hkResult *, __int64))this->m_contactMgr->vfptr[2].__vecDelDtor)(
    this->m_contactMgr,
    result,
    numPoints);
  return result;
}

// File Line: 127
// RVA: 0xD28730
void __fastcall hkpMapPointsToSubShapeContactMgr::removeContactPointImpl(
        hkpMapPointsToSubShapeContactMgr *this,
        __int64 cpId,
        hkpConstraintOwner *constraintOwner)
{
  ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))this->m_contactMgr->vfptr[2].__first_virtual_table_function__)(
    this->m_contactMgr,
    cpId,
    constraintOwner);
}

// File Line: 144
// RVA: 0xD28350
__int64 __fastcall hkpMapPointsToSubShapeContactMgr::addToiImpl(
        hkpMapPointsToSubShapeContactMgr *this,
        hkpCdBody *a,
        hkpCdBody *b,
        hkpProcessCollisionInput *input,
        hkpProcessCollisionOutput *output,
        float toi,
        hkContactPoint *cp,
        hkpGskCache *gskCache,
        float *projectedVelocity,
        hkpContactPointProperties *propertiesOut)
{
  hkpShape *m_shape; // rcx
  __int64 *v14; // r15
  int v15; // edi
  __int64 v16; // rdx
  __int64 v17; // rax
  __int64 v18; // rcx
  __int64 m_dimA; // rcx
  unsigned int v20; // edi
  __int64 v21; // rdx
  __int64 v22; // rcx
  __int64 v23; // rax
  const void *m_motion; // rcx
  __int64 v26; // [rsp+50h] [rbp-258h] BYREF
  unsigned int v27; // [rsp+58h] [rbp-250h]
  const void *v28; // [rsp+60h] [rbp-248h]
  hkpCdBody *v29; // [rsp+68h] [rbp-240h]
  __int64 v30; // [rsp+70h] [rbp-238h] BYREF
  int v31; // [rsp+78h] [rbp-230h]
  __int64 v32; // [rsp+80h] [rbp-228h]
  __int64 *v33; // [rsp+88h] [rbp-220h]
  char v34[512]; // [rsp+90h] [rbp-218h] BYREF

  m_shape = a->m_shape;
  v14 = (__int64 *)a;
  if ( a->m_shape->m_type.m_storage == 26 )
  {
    v15 = HIBYTE(gskCache->m_vertices[0]);
    v16 = 1i64;
    if ( (unsigned __int8)gskCache->m_dimA > 1ui64 )
    {
      while ( HIBYTE(gskCache->m_vertices[v16]) == v15 )
      {
        if ( ++v16 >= (unsigned __int8)gskCache->m_dimA )
          goto LABEL_5;
      }
      goto LABEL_12;
    }
LABEL_5:
    v17 = (*(__int64 (__fastcall **)(unsigned __int16 *, _QWORD, char *))(*(_QWORD *)&m_shape[1].m_memSizeAndFlags
                                                                        + 40i64))(
            &m_shape[1].m_memSizeAndFlags,
            HIBYTE(gskCache->m_vertices[0]),
            v34);
    v18 = v14[2];
    v33 = v14;
    v32 = v18;
    v30 = v17;
    v31 = v15;
    v14 = &v30;
  }
  if ( b->m_shape->m_type.m_storage != 26 )
    return ((__int64 (__fastcall *)(hkpContactMgr *, __int64 *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, _DWORD, hkContactPoint *, hkpGskCache *, float *, hkpContactPointProperties *, __int64, unsigned int, const void *, hkpCdBody *, __int64, int, __int64, __int64 *))this->m_contactMgr->vfptr[3].__first_virtual_table_function__)(
             this->m_contactMgr,
             v14,
             b,
             input,
             output,
             LODWORD(toi),
             cp,
             gskCache,
             projectedVelocity,
             propertiesOut,
             v26,
             v27,
             v28,
             v29,
             v30,
             v31,
             v32,
             v33);
  m_dimA = (unsigned __int8)gskCache->m_dimA;
  v20 = HIBYTE(gskCache->m_vertices[m_dimA]);
  v21 = (int)m_dimA + 1;
  v22 = (int)(m_dimA + (unsigned __int8)gskCache->m_dimB);
  if ( v21 >= v22 )
  {
LABEL_10:
    v23 = (*(__int64 (__fastcall **)(unsigned __int16 *, _QWORD, char *))(*(_QWORD *)&b->m_shape[1].m_memSizeAndFlags
                                                                        + 40i64))(
            &b->m_shape[1].m_memSizeAndFlags,
            v20,
            v34);
    m_motion = b->m_motion;
    v29 = b;
    v28 = m_motion;
    v26 = v23;
    v27 = v20;
    b = (hkpCdBody *)&v26;
    return ((__int64 (__fastcall *)(hkpContactMgr *, __int64 *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, _DWORD, hkContactPoint *, hkpGskCache *, float *, hkpContactPointProperties *, __int64, unsigned int, const void *, hkpCdBody *, __int64, int, __int64, __int64 *))this->m_contactMgr->vfptr[3].__first_virtual_table_function__)(
             this->m_contactMgr,
             v14,
             b,
             input,
             output,
             LODWORD(toi),
             cp,
             gskCache,
             projectedVelocity,
             propertiesOut,
             v26,
             v27,
             v28,
             v29,
             v30,
             v31,
             v32,
             v33);
  }
  while ( HIBYTE(gskCache->m_vertices[v21]) == v20 )
  {
    if ( ++v21 >= v22 )
      goto LABEL_10;
  }
LABEL_12:
  this->m_invalidPointHit.m_bool = 1;
  return 1i64;
}

// File Line: 192
// RVA: 0xD28740
void __fastcall hkpMapPointsToSubShapeContactMgr::removeToiImpl(
        hkpMapPointsToSubShapeContactMgr *this,
        hkpConstraintOwner *constraintOwner,
        hkpContactPointProperties *properties)
{
  ((void (__fastcall *)(hkpContactMgr *, hkpConstraintOwner *, hkpContactPointProperties *))this->m_contactMgr->vfptr[4].__vecDelDtor)(
    this->m_contactMgr,
    constraintOwner,
    properties);
}

