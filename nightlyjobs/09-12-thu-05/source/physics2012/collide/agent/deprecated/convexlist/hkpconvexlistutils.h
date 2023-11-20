// File Line: 31
// RVA: 0xD280C0
void __fastcall hkpProcessCollisionOutputBackup::hkpProcessCollisionOutputBackup(hkpProcessCollisionOutputBackup *this, hkpProcessCollisionOutput *output)
{
  hkpProcessCollisionOutput::PotentialInfo *v2; // rdx
  hkpProcessCollisionOutput::PotentialInfo *v3; // rcx
  signed __int64 v4; // rax
  __int128 v5; // xmm0

  this->m_firstPoint = output->m_firstFreeContactPoint.m_storage;
  this->m_toi.m_contactPoint.m_position = output->m_toi.m_contactPoint.m_position;
  this->m_toi.m_contactPoint.m_separatingNormal = output->m_toi.m_contactPoint.m_separatingNormal;
  *(_OWORD *)&this->m_toi.m_time.m_storage = *(_OWORD *)&output->m_toi.m_time.m_storage;
  *(_OWORD *)this->m_toi.m_gskCache.m_vertices = *(_OWORD *)output->m_toi.m_gskCache.m_vertices;
  *(_OWORD *)&this->m_toi.m_properties.m_impulseApplied = *(_OWORD *)&output->m_toi.m_properties.m_impulseApplied;
  *(_OWORD *)&this->m_toi.m_properties.m_friction.m_value = *(_OWORD *)&output->m_toi.m_properties.m_friction.m_value;
  *(_OWORD *)this->m_toi.m_properties.m_extendedUserDatas = *(_OWORD *)output->m_toi.m_properties.m_extendedUserDatas;
  *(_OWORD *)&this->m_toi.m_properties.m_extendedUserDatas[4] = *(_OWORD *)&output->m_toi.m_properties.m_extendedUserDatas[4];
  v2 = output->m_potentialContacts.m_storage;
  if ( v2 )
  {
    v3 = &this->m_weldingInformation;
    if ( ((unsigned __int8)v3 | (unsigned __int8)v2) & 0xF )
    {
      memmove(v3, v2, 0x2010ui64);
    }
    else
    {
      v4 = 64i64;
      do
      {
        v5 = *(_OWORD *)&v2->m_firstFreePotentialContact;
        v3 = (hkpProcessCollisionOutput::PotentialInfo *)((char *)v3 + 128);
        v2 = (hkpProcessCollisionOutput::PotentialInfo *)((char *)v2 + 128);
        *(_OWORD *)&v3[-1].m_potentialContacts[250].m_agentData = v5;
        *(_OWORD *)&v3[-1].m_potentialContacts[251].m_agentEntry = *(_OWORD *)&v2[-1].m_potentialContacts[251].m_agentEntry;
        *(_OWORD *)&v3[-1].m_potentialContacts[252].m_contactPoint = *(_OWORD *)&v2[-1].m_potentialContacts[252].m_contactPoint;
        *(_OWORD *)&v3[-1].m_potentialContacts[252].m_agentData = *(_OWORD *)&v2[-1].m_potentialContacts[252].m_agentData;
        *(_OWORD *)&v3[-1].m_potentialContacts[253].m_agentEntry = *(_OWORD *)&v2[-1].m_potentialContacts[253].m_agentEntry;
        *(_OWORD *)&v3[-1].m_potentialContacts[254].m_contactPoint = *(_OWORD *)&v2[-1].m_potentialContacts[254].m_contactPoint;
        *(_OWORD *)&v3[-1].m_potentialContacts[254].m_agentData = *(_OWORD *)&v2[-1].m_potentialContacts[254].m_agentData;
        *(_OWORD *)&v3[-1].m_potentialContacts[255].m_agentEntry = *(_OWORD *)&v2[-1].m_potentialContacts[255].m_agentEntry;
        --v4;
      }
      while ( v4 );
      *(_OWORD *)&v3->m_firstFreePotentialContact = *(_OWORD *)&v2->m_firstFreePotentialContact;
    }
  }
}

// File Line: 41
// RVA: 0xD28770
void __fastcall hkpProcessCollisionOutputBackup::rollbackOutput(hkpProcessCollisionOutputBackup *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpProcessCollisionOutput *output, hkpContactMgr *mgr)
{
  hkpProcessCollisionOutput *v5; // rbx
  hkpProcessCollisionOutputBackup *v6; // rdi
  hkpProcessCollisionOutput::PotentialInfo *v7; // rcx
  hkpProcessCollisionOutput::PotentialInfo *v8; // rdx
  signed __int64 v9; // rax
  __int128 v10; // xmm0

  v5 = output;
  v6 = this;
  if ( this->m_toi.m_time.m_storage != output->m_toi.m_time.m_storage )
  {
    ((void (__fastcall *)(hkpContactMgr *, hkpConstraintOwner *, hkContactPointPropertiesWithExtendedUserData16 *))mgr->vfptr[4].__vecDelDtor)(
      mgr,
      output->m_constraintOwner.m_storage,
      &output->m_toi.m_properties);
    v5->m_toi.m_contactPoint.m_position = v6->m_toi.m_contactPoint.m_position;
    v5->m_toi.m_contactPoint.m_separatingNormal = v6->m_toi.m_contactPoint.m_separatingNormal;
    v5->m_toi.m_time.m_storage = v6->m_toi.m_time.m_storage;
    v5->m_toi.m_seperatingVelocity.m_storage = v6->m_toi.m_seperatingVelocity.m_storage;
    *(_QWORD *)v5->m_toi.m_gskCache.m_vertices = *(_QWORD *)v6->m_toi.m_gskCache.m_vertices;
    *(_QWORD *)&v5->m_toi.m_gskCache.m_dimA = *(_QWORD *)&v6->m_toi.m_gskCache.m_dimA;
    v5->m_toi.m_properties.0 = v6->m_toi.m_properties.0;
    v5->m_toi.m_properties.m_userData = v6->m_toi.m_properties.m_userData;
    *(_QWORD *)&v5->m_toi.m_properties.m_friction.m_value = *(_QWORD *)&v6->m_toi.m_properties.m_friction.m_value;
    *(_QWORD *)&v5->m_toi.m_properties.m_internalDataA = *(_QWORD *)&v6->m_toi.m_properties.m_internalDataA;
    *(_QWORD *)v5->m_toi.m_properties.m_extendedUserDatas = *(_QWORD *)v6->m_toi.m_properties.m_extendedUserDatas;
    *(_QWORD *)&v5->m_toi.m_properties.m_extendedUserDatas[2] = *(_QWORD *)&v6->m_toi.m_properties.m_extendedUserDatas[2];
    *(_QWORD *)&v5->m_toi.m_properties.m_extendedUserDatas[4] = *(_QWORD *)&v6->m_toi.m_properties.m_extendedUserDatas[4];
    *(_QWORD *)&v5->m_toi.m_properties.m_extendedUserDatas[6] = *(_QWORD *)&v6->m_toi.m_properties.m_extendedUserDatas[6];
  }
  v7 = v5->m_potentialContacts.m_storage;
  v5->m_firstFreeContactPoint.m_storage = v6->m_firstPoint;
  if ( v7 )
  {
    v8 = &v6->m_weldingInformation;
    if ( ((unsigned __int8)v7 | (unsigned __int8)((_BYTE)v6 + 8)) & 0xF )
    {
      memmove(v7, v8, 0x2010ui64);
    }
    else
    {
      v9 = 64i64;
      do
      {
        v10 = *(_OWORD *)&v8->m_firstFreePotentialContact;
        v7 = (hkpProcessCollisionOutput::PotentialInfo *)((char *)v7 + 128);
        v8 = (hkpProcessCollisionOutput::PotentialInfo *)((char *)v8 + 128);
        *(_OWORD *)&v7[-1].m_potentialContacts[250].m_agentData = v10;
        *(_OWORD *)&v7[-1].m_potentialContacts[251].m_agentEntry = *(_OWORD *)&v8[-1].m_potentialContacts[251].m_agentEntry;
        *(_OWORD *)&v7[-1].m_potentialContacts[252].m_contactPoint = *(_OWORD *)&v8[-1].m_potentialContacts[252].m_contactPoint;
        *(_OWORD *)&v7[-1].m_potentialContacts[252].m_agentData = *(_OWORD *)&v8[-1].m_potentialContacts[252].m_agentData;
        *(_OWORD *)&v7[-1].m_potentialContacts[253].m_agentEntry = *(_OWORD *)&v8[-1].m_potentialContacts[253].m_agentEntry;
        *(_OWORD *)&v7[-1].m_potentialContacts[254].m_contactPoint = *(_OWORD *)&v8[-1].m_potentialContacts[254].m_contactPoint;
        *(_OWORD *)&v7[-1].m_potentialContacts[254].m_agentData = *(_OWORD *)&v8[-1].m_potentialContacts[254].m_agentData;
        *(_OWORD *)&v7[-1].m_potentialContacts[255].m_agentEntry = *(_OWORD *)&v8[-1].m_potentialContacts[255].m_agentEntry;
        --v9;
      }
      while ( v9 );
      *(_OWORD *)&v7->m_firstFreePotentialContact = *(_OWORD *)&v8->m_firstFreePotentialContact;
    }
  }
}

// File Line: 74
// RVA: 0xD281E0
signed __int64 __fastcall hkpMapPointsToSubShapeContactMgr::addContactPointImpl(hkpMapPointsToSubShapeContactMgr *this, hkpCdBody *a, hkpCdBody *b, hkpProcessCollisionInput *input, hkpProcessCollisionOutput *output, hkpGskCache *contactCache, hkContactPoint *cp)
{
  hkpMapPointsToSubShapeContactMgr *v7; // rsi
  hkpShape *v8; // rcx
  hkpProcessCollisionInput *v9; // rbp
  hkpCdBody *v10; // r14
  hkpCdBody *v11; // r15
  signed __int64 v12; // r8
  int v13; // edi
  signed __int64 v14; // rdx
  __int64 v15; // rax
  __int64 v16; // rcx
  __int64 v17; // rcx
  unsigned int v18; // edi
  __int64 v19; // rdx
  __int64 v20; // rcx
  __int64 v21; // rax
  __int64 v22; // rcx
  __int64 v24; // [rsp+40h] [rbp-258h]
  unsigned int v25; // [rsp+48h] [rbp-250h]
  __int64 v26; // [rsp+50h] [rbp-248h]
  hkpCdBody *v27; // [rsp+58h] [rbp-240h]
  __int64 v28; // [rsp+60h] [rbp-238h]
  int v29; // [rsp+68h] [rbp-230h]
  __int64 v30; // [rsp+70h] [rbp-228h]
  hkpCdBody *v31; // [rsp+78h] [rbp-220h]
  char v32; // [rsp+80h] [rbp-218h]

  v7 = this;
  v8 = a->m_shape;
  v9 = input;
  v10 = b;
  v11 = a;
  if ( a->m_shape->m_type.m_storage == 26 )
  {
    v12 = (unsigned __int8)contactCache->m_dimA;
    v13 = HIBYTE(contactCache->m_vertices[0]);
    v14 = 1i64;
    if ( v12 > 1 )
    {
      while ( HIBYTE(contactCache->m_vertices[v14]) == v13 )
      {
        if ( ++v14 >= v12 )
          goto LABEL_5;
      }
      goto LABEL_13;
    }
LABEL_5:
    v15 = (*(__int64 (__fastcall **)(unsigned __int16 *, _QWORD, char *))(*(_QWORD *)&v8[1].m_memSizeAndFlags + 40i64))(
            &v8[1].m_memSizeAndFlags,
            HIBYTE(contactCache->m_vertices[0]),
            &v32);
    v16 = (__int64)v11->m_motion;
    v31 = v11;
    v30 = v16;
    v28 = v15;
    v29 = v13;
    v11 = (hkpCdBody *)&v28;
  }
  if ( v10->m_shape->m_type.m_storage != 26 )
    return ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, hkpGskCache *, hkContactPoint *))v7->m_contactMgr->vfptr[1].__first_virtual_table_function__)(
             v7->m_contactMgr,
             v11,
             v10,
             v9,
             output,
             contactCache,
             cp);
  v17 = (unsigned __int8)contactCache->m_dimA;
  v18 = HIBYTE(contactCache->m_vertices[v17]);
  v19 = (signed int)v17 + 1;
  v20 = (signed int)(v17 + (unsigned __int8)contactCache->m_dimB);
  if ( v19 >= v20 )
  {
LABEL_10:
    v21 = (*(__int64 (__fastcall **)(unsigned __int16 *, _QWORD, char *))(*(_QWORD *)&v10->m_shape[1].m_memSizeAndFlags
                                                                        + 40i64))(
            &v10->m_shape[1].m_memSizeAndFlags,
            v18,
            &v32);
    v22 = (__int64)v10->m_motion;
    v27 = v10;
    v26 = v22;
    v24 = v21;
    v25 = v18;
    v10 = (hkpCdBody *)&v24;
    return ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, hkpGskCache *, hkContactPoint *))v7->m_contactMgr->vfptr[1].__first_virtual_table_function__)(
             v7->m_contactMgr,
             v11,
             v10,
             v9,
             output,
             contactCache,
             cp);
  }
  while ( HIBYTE(contactCache->m_vertices[v19]) == v18 )
  {
    if ( ++v19 >= v20 )
      goto LABEL_10;
  }
LABEL_13:
  v7->m_invalidPointHit.m_bool = 1;
  return 0xFFFFi64;
}

// File Line: 122
// RVA: 0xD28750
hkResult *__fastcall hkpMapPointsToSubShapeContactMgr::reserveContactPointsImpl(hkpMapPointsToSubShapeContactMgr *this, hkResult *result, __int64 numPoints)
{
  hkResult *v3; // rbx

  v3 = result;
  ((void (__fastcall *)(hkpContactMgr *, hkResult *, __int64))this->m_contactMgr->vfptr[2].__vecDelDtor)(
    this->m_contactMgr,
    result,
    numPoints);
  return v3;
}

// File Line: 127
// RVA: 0xD28730
void __fastcall hkpMapPointsToSubShapeContactMgr::removeContactPointImpl(hkpMapPointsToSubShapeContactMgr *this, __int64 cpId, hkpConstraintOwner *constraintOwner)
{
  ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))this->m_contactMgr->vfptr[2].__first_virtual_table_function__)(
    this->m_contactMgr,
    cpId,
    constraintOwner);
}

// File Line: 144
// RVA: 0xD28350
__int64 __fastcall hkpMapPointsToSubShapeContactMgr::addToiImpl(hkpMapPointsToSubShapeContactMgr *this, hkpCdBody *a, hkpCdBody *b, hkpProcessCollisionInput *input, hkpProcessCollisionOutput *output, float toi, hkContactPoint *cp, hkpGskCache *gskCache, float *projectedVelocity, hkpContactPointProperties *propertiesOut)
{
  hkpMapPointsToSubShapeContactMgr *v10; // rsi
  hkpShape *v11; // rcx
  hkpProcessCollisionInput *v12; // rbp
  hkpCdBody *v13; // r14
  hkpCdBody *v14; // r15
  signed __int64 v15; // r8
  int v16; // edi
  signed __int64 v17; // rdx
  __int64 v18; // rax
  __int64 v19; // rcx
  __int64 v20; // rcx
  unsigned int v21; // edi
  __int64 v22; // rdx
  __int64 v23; // rcx
  __int64 v24; // rax
  __int64 v25; // rcx
  float v26; // ST28_4
  __int64 v28; // [rsp+50h] [rbp-258h]
  unsigned int v29; // [rsp+58h] [rbp-250h]
  __int64 v30; // [rsp+60h] [rbp-248h]
  hkpCdBody *v31; // [rsp+68h] [rbp-240h]
  __int64 v32; // [rsp+70h] [rbp-238h]
  int v33; // [rsp+78h] [rbp-230h]
  __int64 v34; // [rsp+80h] [rbp-228h]
  hkpCdBody *v35; // [rsp+88h] [rbp-220h]
  char v36; // [rsp+90h] [rbp-218h]

  v10 = this;
  v11 = a->m_shape;
  v12 = input;
  v13 = b;
  v14 = a;
  if ( a->m_shape->m_type.m_storage == 26 )
  {
    v15 = (unsigned __int8)gskCache->m_dimA;
    v16 = HIBYTE(gskCache->m_vertices[0]);
    v17 = 1i64;
    if ( v15 > 1 )
    {
      while ( HIBYTE(gskCache->m_vertices[v17]) == v16 )
      {
        if ( ++v17 >= v15 )
          goto LABEL_5;
      }
      goto LABEL_13;
    }
LABEL_5:
    v18 = (*(__int64 (__fastcall **)(unsigned __int16 *, _QWORD, char *))(*(_QWORD *)&v11[1].m_memSizeAndFlags + 40i64))(
            &v11[1].m_memSizeAndFlags,
            HIBYTE(gskCache->m_vertices[0]),
            &v36);
    v19 = (__int64)v14->m_motion;
    v35 = v14;
    v34 = v19;
    v32 = v18;
    v33 = v16;
    v14 = (hkpCdBody *)&v32;
  }
  if ( v13->m_shape->m_type.m_storage != 26 )
  {
LABEL_11:
    v26 = toi;
    return ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, float, hkContactPoint *, hkpGskCache *, float *, hkpContactPointProperties *, __int64, _QWORD, __int64, hkpCdBody *, __int64, _QWORD, __int64, hkpCdBody *))v10->m_contactMgr->vfptr[3].__first_virtual_table_function__)(
             v10->m_contactMgr,
             v14,
             v13,
             v12,
             output,
             COERCE_FLOAT(LODWORD(v26)),
             cp,
             gskCache,
             projectedVelocity,
             propertiesOut,
             v28,
             *(_QWORD *)&v29,
             v30,
             v31,
             v32,
             *(_QWORD *)&v33,
             v34,
             v35);
  }
  v20 = (unsigned __int8)gskCache->m_dimA;
  v21 = HIBYTE(gskCache->m_vertices[v20]);
  v22 = (signed int)v20 + 1;
  v23 = (signed int)(v20 + (unsigned __int8)gskCache->m_dimB);
  if ( v22 >= v23 )
  {
LABEL_10:
    v24 = (*(__int64 (__fastcall **)(unsigned __int16 *, _QWORD, char *))(*(_QWORD *)&v13->m_shape[1].m_memSizeAndFlags
                                                                        + 40i64))(
            &v13->m_shape[1].m_memSizeAndFlags,
            v21,
            &v36);
    v25 = (__int64)v13->m_motion;
    v31 = v13;
    v30 = v25;
    v28 = v24;
    v29 = v21;
    v13 = (hkpCdBody *)&v28;
    goto LABEL_11;
  }
  while ( HIBYTE(gskCache->m_vertices[v22]) == v21 )
  {
    if ( ++v22 >= v23 )
      goto LABEL_10;
  }
LABEL_13:
  v10->m_invalidPointHit.m_bool = 1;
  return 1i64;
}

// File Line: 192
// RVA: 0xD28740
void __fastcall hkpMapPointsToSubShapeContactMgr::removeToiImpl(hkpMapPointsToSubShapeContactMgr *this, hkpConstraintOwner *constraintOwner, hkpContactPointProperties *properties)
{
  ((void (__fastcall *)(hkpContactMgr *, hkpConstraintOwner *, hkpContactPointProperties *))this->m_contactMgr->vfptr[4].__vecDelDtor)(
    this->m_contactMgr,
    constraintOwner,
    properties);
}

