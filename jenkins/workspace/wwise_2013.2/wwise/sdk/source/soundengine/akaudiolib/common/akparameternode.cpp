// File Line: 68
// RVA: 0xA6B230
void __fastcall CAkParameterNode::CAkParameterNode(CAkParameterNode *this, unsigned int in_ulID)
{
  CAkParameterNode *v2; // rbx

  v2 = this;
  CAkParameterNodeBase::CAkParameterNodeBase((CAkParameterNodeBase *)&this->vfptr, in_ulID);
  v2->vfptr = (CAkIndexableVtbl *)&CAkParameterNode::`vftable';
  v2->m_pMapSIS = 0i64;
  v2->m_p3DParameters = 0i64;
  v2->m_ranges.m_pProps = 0i64;
  *((_BYTE *)v2 + 144) &= 0x80u;
  *((_BYTE *)v2 + 146) &= 0xF8u;
  v2->m_pAssociatedLayers = 0i64;
  v2->m_pAuxChunk = 0i64;
  *((_BYTE *)v2 + 145) = 4;
}

// File Line: 72
// RVA: 0xA6B290
void __fastcall CAkParameterNode::~CAkParameterNode(CAkParameterNode *this)
{
  CAkParameterNode *v1; // rdi
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *v2; // rcx
  MapStruct<CAkRegisteredObj *,CAkSIS *> *v3; // rbx
  CAkSIS *v4; // rsi
  int v5; // ebp
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *v6; // rbx
  MapStruct<CAkRegisteredObj *,CAkSIS *> *v7; // rdx
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *v8; // rdx
  CAkGen3DParamsEx *v9; // rcx
  CAkGen3DParamsEx *v10; // rbx
  int v11; // esi
  CAkGen3DParamsEx *v12; // rcx
  AkArray<CAkLayer *,CAkLayer *,ArrayPoolDefault,4,AkArrayAllocatorDefault> *v13; // rbx
  CAkLayer **v14; // rdx
  AkArray<CAkLayer *,CAkLayer *,ArrayPoolDefault,4,AkArrayAllocatorDefault> *v15; // rdx
  CAkParameterNode::AuxChunk *v16; // rdx
  char *v17; // rdx

  v1 = this;
  this->vfptr = (CAkIndexableVtbl *)&CAkParameterNode::`vftable';
  v2 = this->m_pMapSIS;
  if ( v2 )
  {
    v3 = v2->m_pItems;
    if ( v2->m_pItems != &v2->m_pItems[v2->m_uLength] )
    {
      do
      {
        v4 = v3->item;
        v5 = g_DefaultPoolId;
        if ( v4 )
        {
          CAkSIS::~CAkSIS(v3->item);
          AK::MemoryMgr::Free(v5, v4);
        }
        ++v3;
      }
      while ( v3 != &v1->m_pMapSIS->m_pItems[v1->m_pMapSIS->m_uLength] );
    }
    v6 = v1->m_pMapSIS;
    v7 = v6->m_pItems;
    if ( v6->m_pItems )
    {
      v6->m_uLength = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, v7);
      v6->m_pItems = 0i64;
      v6->m_ulReserved = 0;
    }
    v8 = v1->m_pMapSIS;
    if ( v8 )
      AK::MemoryMgr::Free(g_DefaultPoolId, v8);
    v1->m_pMapSIS = 0i64;
  }
  v9 = v1->m_p3DParameters;
  if ( v9 )
  {
    CAkGen3DParamsEx::FreePathInfo(v9);
    CAkGen3DParams::Term((CAkGen3DParams *)&v1->m_p3DParameters->vfptr);
    v10 = v1->m_p3DParameters;
    v11 = g_DefaultPoolId;
    if ( v10 )
    {
      v10->vfptr->__vecDelDtor((CAkGen3DParams *)&v1->m_p3DParameters->vfptr, 0);
      AK::MemoryMgr::Free(v11, v10);
    }
    v1->m_p3DParameters = 0i64;
  }
  v12 = v1->m_p3DParameters;
  if ( v12 )
    CAkGen3DParamsEx::FreePathInfo(v12);
  v13 = v1->m_pAssociatedLayers;
  if ( v13 )
  {
    v14 = v13->m_pItems;
    if ( v13->m_pItems )
    {
      v13->m_uLength = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, v14);
      v13->m_pItems = 0i64;
      v13->m_ulReserved = 0;
    }
    v15 = v1->m_pAssociatedLayers;
    if ( v15 )
      AK::MemoryMgr::Free(g_DefaultPoolId, v15);
  }
  v16 = v1->m_pAuxChunk;
  if ( v16 )
    AK::MemoryMgr::Free(g_DefaultPoolId, v16);
  v17 = v1->m_ranges.m_pProps;
  if ( v17 )
    AK::MemoryMgr::Free(g_DefaultPoolId, v17);
  v1->m_ranges.m_pProps = 0i64;
  CAkParameterNodeBase::~CAkParameterNodeBase((CAkParameterNodeBase *)&v1->vfptr);
}

// File Line: 102
// RVA: 0xA6E870
void __fastcall CAkParameterNode::SetAkProp(CAkParameterNode *this, AkPropID in_eProp, float in_fValue, float in_fMin, float in_fMax)
{
  float v5; // xmm9_4
  __int64 v6; // rdi
  int v7; // ebx
  CAkParameterNode *v8; // rsi
  char *v9; // r8
  unsigned int v10; // er9
  __int64 v11; // rcx
  __int64 v12; // rdx
  signed __int64 v13; // rdx
  AkPropValue *v14; // rax
  char *v15; // r8
  unsigned int v16; // er9
  __int64 v17; // rcx
  __int64 v18; // rdx
  signed __int64 v19; // rdx
  AkPropValue *v20; // rax
  char *v21; // rdx
  unsigned int v22; // er8
  __int64 v23; // rcx
  AkPropValue in_Value; // [rsp+A8h] [rbp+10h]

  v5 = in_fMax;
  v6 = in_eProp;
  v7 = 0;
  v8 = this;
  if ( (unsigned int)in_eProp <= 4 || (unsigned int)(in_eProp - 8) <= 1 || (unsigned int)(in_eProp - 18) <= 6 )
  {
    v15 = this->m_props.m_pProps;
    in_Value.fValue = 0.0;
    if ( v15 )
    {
      v16 = (unsigned __int8)*v15;
      v17 = 0i64;
      while ( 1 )
      {
        v18 = (unsigned int)(v17 + 1);
        if ( v15[v18] == (_BYTE)v6 )
          break;
        v17 = (unsigned int)v18;
        if ( (unsigned int)v18 >= v16 )
          goto LABEL_20;
      }
      v19 = (signed __int64)&v15[4 * v17 + ((v16 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_20:
      v19 = 0i64;
    }
    v20 = &in_Value;
    if ( v19 )
      v20 = (AkPropValue *)v19;
    in_Value.fValue = v20->fValue;
    if ( (float)(in_fValue - in_Value.fValue) != 0.0 )
    {
      ((void (__fastcall *)(CAkParameterNode *, _QWORD, CAkIndexableVtbl *, _QWORD, _QWORD))v8->vfptr[5].Release)(
        v8,
        (unsigned int)g_AkPropRTPCID[v6],
        v8->vfptr,
        0i64,
        0i64);
      goto LABEL_25;
    }
  }
  else
  {
    if ( (unsigned int)(in_eProp - 11) > 2 )
    {
      CAkParameterNodeBase::SetAkProp((CAkParameterNodeBase *)&this->vfptr, in_eProp, in_fValue, in_fMin, in_fMax);
      goto LABEL_26;
    }
    v9 = this->m_props.m_pProps;
    in_Value.fValue = 0.0;
    if ( v9 )
    {
      v10 = (unsigned __int8)*v9;
      v11 = 0i64;
      while ( 1 )
      {
        v12 = (unsigned int)(v11 + 1);
        if ( v9[v12] == (_BYTE)v6 )
          break;
        v11 = (unsigned int)v12;
        if ( (unsigned int)v12 >= v10 )
          goto LABEL_9;
      }
      v13 = (signed __int64)&v9[4 * v11 + ((v10 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_9:
      v13 = 0i64;
    }
    v14 = &in_Value;
    if ( v13 )
      v14 = (AkPropValue *)v13;
    in_Value.fValue = v14->fValue;
    if ( (float)(in_fValue - in_Value.fValue) != 0.0 )
    {
      ((void (__fastcall *)(CAkParameterNode *, CAkIndexableVtbl *, _QWORD, _QWORD, _QWORD))v8->vfptr[17].Release)(
        v8,
        v8->vfptr,
        (unsigned int)g_AkPropRTPCID[v6],
        0i64,
        0i64);
LABEL_25:
      in_Value.fValue = in_fValue;
      AkPropBundle<AkPropValue>::SetAkProp(&v8->m_props, v6, LODWORD(in_fValue));
      goto LABEL_26;
    }
  }
LABEL_26:
  if ( in_fMin != 0.0 || v5 != 0.0 )
    goto LABEL_38;
  v21 = v8->m_ranges.m_pProps;
  if ( v21 )
  {
    v22 = (unsigned __int8)*v21;
    while ( 1 )
    {
      v23 = (unsigned int)(v7 + 1);
      if ( v21[v23] == (_BYTE)v6 )
        break;
      ++v7;
      if ( (unsigned int)v23 >= v22 )
        return;
    }
    if ( &v21[8 * v7 + ((v22 + 4) & 0xFFFFFFFC)] )
LABEL_38:
      AkPropBundle<RANGED_MODIFIERS<AkPropValue>>::SetAkProp(
        &v8->m_ranges,
        v6,
        (RANGED_MODIFIERS<AkPropValue>)__PAIR__(LODWORD(v5), LODWORD(in_fMin)));
  }
}

// File Line: 151
// RVA: 0xA6E7D0
void __fastcall CAkParameterNode::SetAkProp(CAkParameterNode *this, AkPropID in_eProp, int in_iValue, int in_iMin, int in_iMax)
{
  int v5; // ebp
  char v6; // bl
  CAkParameterNode *v7; // rsi
  char *v8; // r8
  unsigned int v9; // er9
  __int64 v10; // rcx
  __int64 v11; // rdx

  v5 = in_iMin;
  v6 = in_eProp;
  v7 = this;
  CAkParameterNodeBase::SetAkProp((CAkParameterNodeBase *)&this->vfptr, in_eProp, in_iValue, in_iMin, in_iMax);
  if ( v5 || in_iMax )
    goto LABEL_12;
  v8 = v7->m_ranges.m_pProps;
  if ( v8 )
  {
    v9 = (unsigned __int8)*v8;
    v10 = 0i64;
    while ( 1 )
    {
      v11 = (unsigned int)(v10 + 1);
      if ( v8[v11] == v6 )
        break;
      v10 = (unsigned int)v11;
      if ( (unsigned int)v11 >= v9 )
        return;
    }
    if ( &v8[8 * v10 + ((v9 + 4) & 0xFFFFFFFC)] )
LABEL_12:
      AkPropBundle<RANGED_MODIFIERS<AkPropValue>>::SetAkProp(
        &v7->m_ranges,
        v6,
        (RANGED_MODIFIERS<AkPropValue>)__PAIR__(in_iMax, v5));
  }
}

// File Line: 178
// RVA: 0xA6C170
void __fastcall CAkParameterNode::Get3DParams(CAkParameterNode *this, CAkGen3DParams **out_rp3DParams, CAkRegisteredObj *in_GameObj, AkPannerType *out_ePannerType, AkPositionSourceType *out_ePosType, BaseGenParams *io_pBasePosParams)
{
  CAkParameterNodeBase *v6; // rax
  AkPannerType *v7; // rsi
  CAkRegisteredObj *v8; // rdi
  CAkParameterNode *i; // rbx

  v6 = this->m_pParentNode;
  v7 = out_ePannerType;
  v8 = in_GameObj;
  for ( i = this; !(*((_BYTE *)&i->0 + 83) & 0x10); v6 = v6->m_pParentNode )
  {
    if ( !v6 )
      break;
    i = (CAkParameterNode *)v6;
  }
  CAkParameterNode::Get3DCloneForObject(i, out_rp3DParams, out_ePosType);
  *v7 = *((_BYTE *)i + 145) & 3;
  if ( ((unsigned __int64)LODWORD(i->m_RTPCBitArray.m_iBitArray) >> 10) & 1 )
    *v7 = (signed int)CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, i, 0xAu, v8);
  CAkParameterNodeBase::Get2DParams((CAkParameterNodeBase *)&i->vfptr, v8, io_pBasePosParams);
}

// File Line: 279
// RVA: 0xA6F750
void __fastcall CAkParameterNode::UpdateBaseParams(CAkParameterNode *this, CAkRegisteredObj *in_GameObj, BaseGenParams *io_pBasePosParams, CAkGen3DParams *io_p3DParams)
{
  CAkGen3DParams *v4; // rdi
  CAkRegisteredObj *v5; // rsi
  CAkParameterNode *v6; // rbx
  bool v7; // al

  v4 = io_p3DParams;
  v5 = in_GameObj;
  do
  {
    v6 = this;
    this = (CAkParameterNode *)this->m_pParentNode;
  }
  while ( !(*((_BYTE *)&v6->0 + 83) & 0x10) && this );
  CAkParameterNodeBase::Get2DParams((CAkParameterNodeBase *)&v6->vfptr, in_GameObj, io_pBasePosParams);
  if ( v4 )
  {
    v7 = CAkParameterNodeBase::Get3DPanning((CAkParameterNodeBase *)&v6->vfptr, v5, &v4->m_Params.m_Position);
    *((_BYTE *)&v4->m_Params + 68) &= 0xFBu;
    *((_BYTE *)&v4->m_Params + 68) |= 4 * v7;
  }
}

// File Line: 306
// RVA: 0xA6D600
__int64 __fastcall CAkParameterNode::GetMaxRadius(CAkParameterNode *this, float *out_fRadius)
{
  float *v2; // rdi
  CAkParameterNode *v3; // rax
  CAkGen3DParamsEx *v4; // rdx
  unsigned __int8 v5; // bl
  CAkIndexable *v6; // rax
  CAkIndexable *v7; // r8
  unsigned __int8 v8; // al
  signed __int64 v9; // rdx

  v2 = out_fRadius;
  *out_fRadius = 0.0;
  do
  {
    v3 = this;
    this = (CAkParameterNode *)this->m_pParentNode;
  }
  while ( !(*((_BYTE *)&v3->0 + 83) & 0x10) && this );
  v4 = v3->m_p3DParameters;
  v5 = 0;
  if ( v4 )
  {
    v6 = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
           (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxAttenuations,
           v4->m_Params.m_uAttenuationID);
    v7 = v6;
    if ( v6 )
    {
      v8 = (unsigned __int8)v6[5].vfptr;
      if ( v8 != -1 )
      {
        v9 = (signed __int64)(&v7[1].key + 4 * v8);
        if ( *(_QWORD *)v9 )
        {
          if ( v9 )
          {
            v5 = 1;
            *v2 = *(float *)(*(_QWORD *)v9 + 12i64 * (unsigned int)(*(_DWORD *)(v9 + 8) - 1));
          }
        }
      }
      v7->vfptr->Release(v7);
    }
  }
  return v5;
}

// File Line: 346
// RVA: 0xA6C210
signed __int64 __fastcall CAkParameterNode::GetAudioParameters(CAkParameterNode *this, AkSoundParamsEx *io_Parameters, unsigned int in_ulParamSelect, CAkKeyArray<AkMutedMapItem,float,2> *io_rMutedMap, CAkRegisteredObj *in_GameObjPtr, bool in_bIncludeRange, AkPBIModValues *io_Ranges, bool in_bDoBusCheck)
{
  CAkKeyArray<AkMutedMapItem,float,2> *v8; // rdi
  unsigned int v9; // ebx
  AkSoundParamsEx *v10; // r14
  CAkParameterNode *v11; // rsi
  CAkRegisteredObj *v12; // r13
  signed __int64 v13; // r12
  float v14; // xmm7_4
  char *v15; // r8
  unsigned int v16; // er9
  __int64 v17; // rcx
  __int64 v18; // rdx
  signed __int64 v19; // rdx
  int *v20; // rax
  unsigned __int64 v21; // rax
  char v22; // cl
  char v23; // al
  char *v24; // r8
  unsigned int v25; // er9
  __int64 v26; // rcx
  __int64 v27; // rdx
  signed __int64 v28; // rdx
  int *v29; // rax
  unsigned __int64 v30; // rax
  char *v31; // r8
  unsigned int v32; // er9
  __int64 v33; // rcx
  __int64 v34; // rdx
  signed __int64 v35; // rdx
  int *v36; // rax
  unsigned __int64 v37; // rax
  char *v38; // r8
  unsigned int v39; // er9
  __int64 v40; // rcx
  __int64 v41; // rdx
  signed __int64 v42; // rdx
  int *v43; // rax
  unsigned __int64 v44; // rax
  unsigned __int64 v45; // rax
  char *v46; // r8
  unsigned int v47; // er9
  __int64 v48; // rcx
  __int64 v49; // rdx
  signed __int64 v50; // rdx
  int *v51; // rax
  CAkSIS *v52; // r8
  char *v53; // r8
  unsigned int v54; // er9
  int v55; // ecx
  __int64 v56; // rdx
  float *v57; // rdx
  char *v58; // r8
  unsigned int v59; // er9
  int v60; // ecx
  __int64 v61; // rdx
  float *v62; // rdx
  char *v63; // r8
  unsigned int v64; // er9
  int v65; // ecx
  __int64 v66; // rdx
  float *v67; // rdx
  char *v68; // r8
  unsigned int v69; // er9
  int v70; // ecx
  __int64 v71; // rdx
  float *v72; // rdx
  float v73; // xmm2_4
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *v74; // rcx
  CAkRegisteredObj **v75; // rax
  signed __int64 v76; // rcx
  signed __int64 v77; // rax
  __int64 v78; // r10
  unsigned __int8 *v79; // r8
  unsigned int v80; // er9
  int v81; // ecx
  __int64 v82; // rdx
  float *v83; // rdx
  unsigned __int8 *v84; // r8
  unsigned int v85; // er9
  int v86; // ecx
  __int64 v87; // rdx
  float *v88; // rdx
  unsigned __int8 *v89; // r8
  unsigned int v90; // er9
  int v91; // ecx
  __int64 v92; // rdx
  float *v93; // rdx
  unsigned __int8 *v94; // r8
  unsigned int v95; // er9
  int v96; // ecx
  __int64 v97; // rdx
  float *v98; // rdx
  float v99; // xmm2_4
  bool v100; // r15
  AkPBIModValues *v101; // rdi
  char *v102; // r8
  unsigned int v103; // er9
  __int64 v104; // rcx
  __int64 v105; // rdx
  float *v106; // rbx
  float v107; // xmm0_4
  float v108; // xmm6_4
  char *v109; // r8
  unsigned int v110; // er9
  __int64 v111; // rcx
  __int64 v112; // rdx
  float *v113; // rbx
  float v114; // xmm0_4
  float v115; // xmm6_4
  char *v116; // r8
  unsigned int v117; // er9
  __int64 v118; // rcx
  __int64 v119; // rdx
  float *v120; // rbx
  float v121; // xmm6_4
  char *v122; // r8
  unsigned int v123; // er9
  __int64 v124; // rcx
  __int64 v125; // rdx
  signed __int64 v126; // rdx
  bool *v127; // rax
  unsigned __int64 v128; // rax
  char *v129; // r8
  unsigned int v130; // er9
  __int64 v131; // rcx
  __int64 v132; // rdx
  signed __int64 v133; // rdx
  bool *v134; // rax
  unsigned __int64 v135; // rax
  char *v136; // r8
  unsigned int v137; // er9
  __int64 v138; // rcx
  __int64 v139; // rdx
  signed __int64 v140; // rdx
  bool *v141; // rax
  unsigned __int64 v142; // rax
  char *v143; // r8
  unsigned int v144; // er9
  __int64 v145; // rcx
  __int64 v146; // rdx
  signed __int64 v147; // rdx
  bool *v148; // rax
  unsigned __int64 v149; // rax
  char *v150; // r8
  unsigned int v151; // er9
  __int64 v152; // rcx
  __int64 v153; // rdx
  signed __int64 v154; // rdx
  bool *v155; // rax
  unsigned __int64 v156; // rax
  char *v157; // r8
  unsigned int v158; // er9
  __int64 v159; // rcx
  __int64 v160; // rdx
  signed __int64 v161; // rdx
  bool *v162; // rax
  unsigned __int64 v163; // rax
  char *v164; // r8
  unsigned int v165; // er9
  __int64 v166; // rcx
  __int64 v167; // rdx
  bool *v168; // rax
  unsigned __int64 v169; // rax
  CAkParameterNodeBase *v170; // rcx
  CAkKeyArray<AkMutedMapItem,float,2> *v171; // r12
  CAkParameterNodeBase *v172; // rcx
  AkArray<CAkLayer *,CAkLayer *,ArrayPoolDefault,4,AkArrayAllocatorDefault> *v173; // rax
  CAkLayer **v174; // rbx
  signed __int64 v175; // rdi
  unsigned int v176; // er15
  CAkRegisteredObj *v178; // [rsp+28h] [rbp-48h]
  __int64 v179; // [rsp+38h] [rbp-38h]
  __m128i v180; // [rsp+40h] [rbp-30h]
  float v181; // [rsp+B0h] [rbp+40h]
  unsigned int in_ulParamSelecta; // [rsp+C0h] [rbp+50h]
  CAkKeyArray<AkMutedMapItem,float,2> *v183; // [rsp+C8h] [rbp+58h]

  v183 = io_rMutedMap;
  in_ulParamSelecta = in_ulParamSelect;
  v8 = io_rMutedMap;
  v9 = in_ulParamSelect;
  v10 = io_Parameters;
  v11 = this;
  CAkParameterNodeBase::GetAudioStateParams(
    (CAkParameterNodeBase *)&this->vfptr,
    (AkSoundParams *)&io_Parameters->Volume,
    in_ulParamSelect);
  v12 = in_GameObjPtr;
  v13 = 0i64;
  v14 = 0.0;
  if ( v9 & 1 )
  {
    v15 = v11->m_props.m_pProps;
    v181 = 0.0;
    if ( v15 )
    {
      v16 = (unsigned __int8)*v15;
      v17 = 0i64;
      while ( 1 )
      {
        v18 = (unsigned int)(v17 + 1);
        if ( !v15[v18] )
          break;
        v17 = (unsigned int)v18;
        if ( (unsigned int)v18 >= v16 )
          goto LABEL_6;
      }
      v19 = (signed __int64)&v15[4 * v17 + ((v16 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_6:
      v19 = 0i64;
    }
    v20 = (int *)&v181;
    if ( v19 )
      v20 = (int *)v19;
    v181 = *(float *)v20;
    v10->Volume = v181 + v10->Volume;
    v21 = v11->m_RTPCBitArray.m_iBitArray;
    if ( _bittest64((const signed __int64 *)&v21, (unsigned int)g_AkPropRTPCID[0]) )
      v10->Volume = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v11, g_AkPropRTPCID[0], v12) + v10->Volume;
    v22 = *((_BYTE *)&v10->normalization + 4);
    if ( !(v22 & 2) )
    {
      v23 = *((_BYTE *)v11 + 146);
      if ( v23 & 1 || !v11->m_pParentNode )
        *((_BYTE *)&v10->normalization + 4) = v22 & 0xFE | ((unsigned __int8)(v23 & 2 | 4) >> 1);
    }
    v24 = v11->m_props.m_pProps;
    v181 = 0.0;
    if ( v24 )
    {
      v25 = (unsigned __int8)*v24;
      v26 = 0i64;
      while ( 1 )
      {
        v27 = (unsigned int)(v26 + 1);
        if ( v24[v27] == 33 )
          break;
        v26 = (unsigned int)v27;
        if ( (unsigned int)v27 >= v25 )
          goto LABEL_19;
      }
      v28 = (signed __int64)&v24[4 * v26 + ((v25 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_19:
      v28 = 0i64;
    }
    v29 = (int *)&v181;
    if ( v28 )
      v29 = (int *)v28;
    v181 = *(float *)v29;
    v10->normalization.fMakeUpGain = v181 + v10->normalization.fMakeUpGain;
    v30 = v11->m_RTPCBitArray.m_iBitArray;
    if ( _bittest64((const signed __int64 *)&v30, 0x24ui64) )
      v10->normalization.fMakeUpGain = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v11, 0x24u, v12)
                                     + v10->normalization.fMakeUpGain;
  }
  if ( v9 & 2 )
  {
    v31 = v11->m_props.m_pProps;
    v181 = 0.0;
    if ( v31 )
    {
      v32 = (unsigned __int8)*v31;
      v33 = 0i64;
      while ( 1 )
      {
        v34 = (unsigned int)(v33 + 1);
        if ( v31[v34] == 2 )
          break;
        v33 = (unsigned int)v34;
        if ( (unsigned int)v34 >= v32 )
          goto LABEL_29;
      }
      v35 = (signed __int64)&v31[4 * v33 + ((v32 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_29:
      v35 = 0i64;
    }
    v36 = (int *)&v181;
    if ( v35 )
      v36 = (int *)v35;
    v181 = *(float *)v36;
    v10->Pitch = v181 + v10->Pitch;
    v37 = v11->m_RTPCBitArray.m_iBitArray;
    if ( _bittest64((const signed __int64 *)&v37, 2ui64) )
      v10->Pitch = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v11, 2u, v12) + v10->Pitch;
  }
  if ( v9 & 4 )
  {
    v38 = v11->m_props.m_pProps;
    v181 = 0.0;
    if ( v38 )
    {
      v39 = (unsigned __int8)*v38;
      v40 = 0i64;
      while ( 1 )
      {
        v41 = (unsigned int)(v40 + 1);
        if ( v38[v41] == 3 )
          break;
        v40 = (unsigned int)v41;
        if ( (unsigned int)v41 >= v39 )
          goto LABEL_39;
      }
      v42 = (signed __int64)&v38[4 * v40 + ((v39 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_39:
      v42 = 0i64;
    }
    v43 = (int *)&v181;
    if ( v42 )
      v43 = (int *)v42;
    v181 = *(float *)v43;
    v10->LPF = v181 + v10->LPF;
    v44 = v11->m_RTPCBitArray.m_iBitArray;
    if ( _bittest64((const signed __int64 *)&v44, 3ui64) )
      v10->LPF = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v11, 3u, v12) + v10->LPF;
  }
  if ( v9 & 0x10 && !(*((_BYTE *)&v10->hdr + 4) & 1) && (*((_BYTE *)v11 + 145) < 0 || !v11->m_pParentNode) )
  {
    v45 = v11->m_RTPCBitArray.m_iBitArray;
    if ( _bittest64((const signed __int64 *)&v45, 0x23ui64) )
    {
      v10->hdr.fActiveRange = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v11, 0x23u, v12);
    }
    else
    {
      v46 = v11->m_props.m_pProps;
      v181 = g_AkPropDefault[32].fValue;
      if ( v46 )
      {
        v47 = (unsigned __int8)*v46;
        v48 = 0i64;
        while ( 1 )
        {
          v49 = (unsigned int)(v48 + 1);
          if ( v46[v49] == 32 )
            break;
          v48 = (unsigned int)v49;
          if ( (unsigned int)v49 >= v47 )
            goto LABEL_58;
        }
        v50 = (signed __int64)&v46[4 * v48 + ((v47 + 4) & 0xFFFFFFFC)];
      }
      else
      {
LABEL_58:
        v50 = 0i64;
      }
      v51 = (int *)&v181;
      if ( v50 )
        v51 = (int *)v50;
      LODWORD(v10->hdr.fActiveRange) = *v51;
    }
    *((_BYTE *)&v10->hdr + 4) = *((_BYTE *)&v10->hdr + 4) ^ (*((_BYTE *)&v10->hdr + 4) ^ (*((_BYTE *)v11 + 146) >> 1)) & 2 | 1;
  }
  v52 = v11->m_pGlobalSIS;
  if ( v52 )
  {
    v53 = v52->m_values.m_pProps;
    if ( v53 )
    {
      v54 = (unsigned __int8)*v53;
      v55 = 0;
      while ( 1 )
      {
        v56 = (unsigned int)(v55 + 1);
        if ( !v53[v56] )
          break;
        v55 = v56;
        if ( (unsigned int)v56 >= v54 )
          goto LABEL_72;
      }
      v57 = (float *)&v53[16 * v55 + ((v54 + 4) & 0xFFFFFFFC)];
      if ( v57 )
        v10->Volume = *v57 + v10->Volume;
    }
LABEL_72:
    v58 = v11->m_pGlobalSIS->m_values.m_pProps;
    if ( v58 )
    {
      v59 = (unsigned __int8)*v58;
      v60 = 0;
      while ( 1 )
      {
        v61 = (unsigned int)(v60 + 1);
        if ( v58[v61] == 2 )
          break;
        v60 = v61;
        if ( (unsigned int)v61 >= v59 )
          goto LABEL_79;
      }
      v62 = (float *)&v58[16 * v60 + ((v59 + 4) & 0xFFFFFFFC)];
      if ( v62 )
        v10->Pitch = v10->Pitch + *v62;
    }
LABEL_79:
    v63 = v11->m_pGlobalSIS->m_values.m_pProps;
    if ( v63 )
    {
      v64 = (unsigned __int8)*v63;
      v65 = 0;
      while ( 1 )
      {
        v66 = (unsigned int)(v65 + 1);
        if ( v63[v66] == 3 )
          break;
        v65 = v66;
        if ( (unsigned int)v66 >= v64 )
          goto LABEL_86;
      }
      v67 = (float *)&v63[16 * v65 + ((v64 + 4) & 0xFFFFFFFC)];
      if ( v67 )
        v10->LPF = v10->LPF + *v67;
    }
LABEL_86:
    v68 = v11->m_pGlobalSIS->m_values.m_pProps;
    if ( v68 )
    {
      v69 = (unsigned __int8)*v68;
      v70 = 0;
      while ( 1 )
      {
        v71 = (unsigned int)(v70 + 1);
        if ( v68[v71] == 10 )
          break;
        v70 = v71;
        if ( (unsigned int)v71 >= v69 )
          goto LABEL_94;
      }
      v72 = (float *)&v68[16 * v70 + ((v69 + 4) & 0xFFFFFFFC)];
      if ( v72 )
      {
        v73 = *v72;
        if ( *v72 != 1.0 )
        {
          v180.m128i_i64[0] = (__int64)v11;
          v180.m128i_i32[2] = v180.m128i_i32[2] & 0xFFFFFFFD | 1;
          _mm_store_si128(&v180, v180);
          CAkKeyArray<AkMutedMapItem,float,2>::Set(v8, (AkMutedMapItem *)&v180, v73);
        }
      }
    }
  }
LABEL_94:
  v74 = v11->m_pMapSIS;
  if ( v74 )
  {
    v75 = &v74->m_pItems->key;
    v76 = (signed __int64)&v74->m_pItems[v74->m_uLength];
    if ( v75 != (CAkRegisteredObj **)v76 )
    {
      do
      {
        if ( *v75 == v12 )
          break;
        v75 += 2;
      }
      while ( v75 != (CAkRegisteredObj **)v76 );
      if ( v75 != (CAkRegisteredObj **)v76 )
      {
        v77 = (signed __int64)(v75 + 1);
        if ( v77 )
        {
          v78 = *(_QWORD *)v77;
          v79 = *(unsigned __int8 **)(*(_QWORD *)v77 + 24i64);
          if ( v79 )
          {
            v80 = *v79;
            v81 = 0;
            while ( 1 )
            {
              v82 = (unsigned int)(v81 + 1);
              if ( !v79[v82] )
                break;
              v81 = v82;
              if ( (unsigned int)v82 >= v80 )
                goto LABEL_107;
            }
            v83 = (float *)&v79[16 * v81 + ((v80 + 4) & 0xFFFFFFFC)];
            if ( v83 )
              v10->Volume = *v83 + v10->Volume;
          }
LABEL_107:
          v84 = *(unsigned __int8 **)(v78 + 24);
          if ( v84 )
          {
            v85 = *v84;
            v86 = 0;
            while ( 1 )
            {
              v87 = (unsigned int)(v86 + 1);
              if ( v84[v87] == 2 )
                break;
              v86 = v87;
              if ( (unsigned int)v87 >= v85 )
                goto LABEL_114;
            }
            v88 = (float *)&v84[16 * v86 + ((v85 + 4) & 0xFFFFFFFC)];
            if ( v88 )
              v10->Pitch = *v88 + v10->Pitch;
          }
LABEL_114:
          v89 = *(unsigned __int8 **)(v78 + 24);
          if ( v89 )
          {
            v90 = *v89;
            v91 = 0;
            while ( 1 )
            {
              v92 = (unsigned int)(v91 + 1);
              if ( v89[v92] == 3 )
                break;
              v91 = v92;
              if ( (unsigned int)v92 >= v90 )
                goto LABEL_121;
            }
            v93 = (float *)&v89[16 * v91 + ((v90 + 4) & 0xFFFFFFFC)];
            if ( v93 )
              v10->LPF = v10->LPF + *v93;
          }
LABEL_121:
          v94 = *(unsigned __int8 **)(v78 + 24);
          if ( v94 )
          {
            v95 = *v94;
            v96 = 0;
            while ( 1 )
            {
              v97 = (unsigned int)(v96 + 1);
              if ( v94[v97] == 10 )
                break;
              v96 = v97;
              if ( (unsigned int)v97 >= v95 )
                goto LABEL_129;
            }
            v98 = (float *)&v94[16 * v96 + ((v95 + 4) & 0xFFFFFFFC)];
            if ( v98 )
            {
              v99 = *v98;
              if ( *v98 != 1.0 )
              {
                v180.m128i_i32[2] &= 0xFFFFFFFC;
                v180.m128i_i64[0] = (__int64)v11;
                _mm_store_si128(&v180, v180);
                CAkKeyArray<AkMutedMapItem,float,2>::Set(v8, (AkMutedMapItem *)&v180, v99);
              }
            }
          }
        }
      }
    }
  }
LABEL_129:
  v100 = in_bIncludeRange;
  v101 = io_Ranges;
  if ( in_bIncludeRange )
  {
    v102 = v11->m_ranges.m_pProps;
    if ( v102 )
    {
      v103 = (unsigned __int8)*v102;
      v104 = 0i64;
      while ( 1 )
      {
        v105 = (unsigned int)(v104 + 1);
        if ( !v102[v105] )
          break;
        v104 = (unsigned int)v105;
        if ( (unsigned int)v105 >= v103 )
          goto LABEL_139;
      }
      v106 = (float *)&v102[8 * v104 + ((v103 + 4) & 0xFFFFFFFC)];
      if ( v106 )
      {
        v107 = 0.0;
        v108 = v106[1] - *v106;
        if ( v108 != 0.0 )
          v107 = (double)rand() * 0.00003051850947599719 * v108;
        v101->VolumeOffset = (float)(v107 + *v106) + v101->VolumeOffset;
      }
LABEL_139:
      v109 = v11->m_ranges.m_pProps;
      if ( v109 )
      {
        v110 = (unsigned __int8)*v109;
        v111 = 0i64;
        while ( 1 )
        {
          v112 = (unsigned int)(v111 + 1);
          if ( v109[v112] == 2 )
            break;
          v111 = (unsigned int)v112;
          if ( (unsigned int)v112 >= v110 )
            goto LABEL_148;
        }
        v113 = (float *)&v109[8 * v111 + ((v110 + 4) & 0xFFFFFFFC)];
        if ( v113 )
        {
          v114 = 0.0;
          v115 = v113[1] - *v113;
          if ( v115 != 0.0 )
            v114 = (double)rand() * 0.00003051850947599719 * v115;
          v101->PitchOffset = (float)(v114 + *v113) + v101->PitchOffset;
        }
      }
LABEL_148:
      v116 = v11->m_ranges.m_pProps;
      if ( v116 )
      {
        v117 = (unsigned __int8)*v116;
        v118 = 0i64;
        while ( 1 )
        {
          v119 = (unsigned int)(v118 + 1);
          if ( v116[v119] == 3 )
            break;
          v118 = (unsigned int)v119;
          if ( (unsigned int)v119 >= v117 )
            goto LABEL_157;
        }
        v120 = (float *)&v116[8 * v118 + ((v117 + 4) & 0xFFFFFFFC)];
        if ( v120 )
        {
          v121 = v120[1] - *v120;
          if ( v121 != 0.0 )
            v14 = (double)rand() * 0.00003051850947599719 * v121;
          v101->LPFOffset = (float)(v14 + *v120) + v101->LPFOffset;
        }
      }
LABEL_157:
      v9 = in_ulParamSelecta;
    }
  }
  if ( !v10->bUserDefinedServiced && (*((_BYTE *)v11 + 145) & 0x40 || !v11->m_pParentNode) )
  {
    v10->bUserDefinedServiced = 1;
    if ( v11->m_pAuxChunk )
    {
      v122 = v11->m_props.m_pProps;
      *(_DWORD *)&in_bIncludeRange = 0;
      if ( v122 )
      {
        v123 = (unsigned __int8)*v122;
        v124 = 0i64;
        while ( 1 )
        {
          v125 = (unsigned int)(v124 + 1);
          if ( v122[v125] == 18 )
            break;
          v124 = (unsigned int)v125;
          if ( (unsigned int)v125 >= v123 )
            goto LABEL_166;
        }
        v126 = (signed __int64)&v122[4 * v124 + ((v123 + 4) & 0xFFFFFFFC)];
      }
      else
      {
LABEL_166:
        v126 = 0i64;
      }
      v127 = &in_bIncludeRange;
      if ( v126 )
        v127 = (bool *)v126;
      *(_DWORD *)&in_bIncludeRange = *(_DWORD *)v127;
      v10->aUserAuxSendVolume[0] = *(float *)&in_bIncludeRange + v10->aUserAuxSendVolume[0];
      v128 = v11->m_RTPCBitArray.m_iBitArray;
      if ( _bittest64((const signed __int64 *)&v128, 0xFui64) )
        v10->aUserAuxSendVolume[0] = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v11, 0xFu, v12)
                                   + v10->aUserAuxSendVolume[0];
      v129 = v11->m_props.m_pProps;
      *(_DWORD *)&in_bIncludeRange = 0;
      if ( v129 )
      {
        v130 = (unsigned __int8)*v129;
        v131 = 0i64;
        while ( 1 )
        {
          v132 = (unsigned int)(v131 + 1);
          if ( v129[v132] == 19 )
            break;
          v131 = (unsigned int)v132;
          if ( (unsigned int)v132 >= v130 )
            goto LABEL_175;
        }
        v133 = (signed __int64)&v129[4 * v131 + ((v130 + 4) & 0xFFFFFFFC)];
      }
      else
      {
LABEL_175:
        v133 = 0i64;
      }
      v134 = &in_bIncludeRange;
      if ( v133 )
        v134 = (bool *)v133;
      *(_DWORD *)&in_bIncludeRange = *(_DWORD *)v134;
      v10->aUserAuxSendVolume[1] = *(float *)&in_bIncludeRange + v10->aUserAuxSendVolume[1];
      v135 = v11->m_RTPCBitArray.m_iBitArray;
      if ( _bittest64((const signed __int64 *)&v135, 0x10ui64) )
        v10->aUserAuxSendVolume[1] = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v11, 0x10u, v12)
                                   + v10->aUserAuxSendVolume[1];
      v136 = v11->m_props.m_pProps;
      *(_DWORD *)&in_bIncludeRange = 0;
      if ( v136 )
      {
        v137 = (unsigned __int8)*v136;
        v138 = 0i64;
        while ( 1 )
        {
          v139 = (unsigned int)(v138 + 1);
          if ( v136[v139] == 20 )
            break;
          v138 = (unsigned int)v139;
          if ( (unsigned int)v139 >= v137 )
            goto LABEL_184;
        }
        v140 = (signed __int64)&v136[4 * v138 + ((v137 + 4) & 0xFFFFFFFC)];
      }
      else
      {
LABEL_184:
        v140 = 0i64;
      }
      v141 = &in_bIncludeRange;
      if ( v140 )
        v141 = (bool *)v140;
      *(_DWORD *)&in_bIncludeRange = *(_DWORD *)v141;
      v10->aUserAuxSendVolume[2] = *(float *)&in_bIncludeRange + v10->aUserAuxSendVolume[2];
      v142 = v11->m_RTPCBitArray.m_iBitArray;
      if ( _bittest64((const signed __int64 *)&v142, 0x11ui64) )
        v10->aUserAuxSendVolume[2] = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v11, 0x11u, v12)
                                   + v10->aUserAuxSendVolume[2];
      v143 = v11->m_props.m_pProps;
      *(_DWORD *)&in_bIncludeRange = 0;
      if ( v143 )
      {
        v144 = (unsigned __int8)*v143;
        v145 = 0i64;
        while ( 1 )
        {
          v146 = (unsigned int)(v145 + 1);
          if ( v143[v146] == 21 )
            break;
          v145 = (unsigned int)v146;
          if ( (unsigned int)v146 >= v144 )
            goto LABEL_193;
        }
        v147 = (signed __int64)&v143[4 * v145 + ((v144 + 4) & 0xFFFFFFFC)];
      }
      else
      {
LABEL_193:
        v147 = 0i64;
      }
      v148 = &in_bIncludeRange;
      if ( v147 )
        v148 = (bool *)v147;
      *(_DWORD *)&in_bIncludeRange = *(_DWORD *)v148;
      v10->aUserAuxSendVolume[3] = *(float *)&in_bIncludeRange + v10->aUserAuxSendVolume[3];
      v149 = v11->m_RTPCBitArray.m_iBitArray;
      if ( _bittest64((const signed __int64 *)&v149, 0x12ui64) )
        v10->aUserAuxSendVolume[3] = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v11, 0x12u, v12)
                                   + v10->aUserAuxSendVolume[3];
      v10->aAuxSend[0] = v11->m_pAuxChunk->aAux[0];
      v10->aAuxSend[1] = v11->m_pAuxChunk->aAux[1];
      v10->aAuxSend[2] = v11->m_pAuxChunk->aAux[2];
      v10->aAuxSend[3] = v11->m_pAuxChunk->aAux[3];
    }
  }
  if ( !v10->bGameDefinedServiced && (*((_BYTE *)v11 + 145) & 0x10 || !v11->m_pParentNode) )
  {
    v10->bGameDefinedServiced = 1;
    v150 = v11->m_props.m_pProps;
    *(_DWORD *)&in_bIncludeRange = 0;
    if ( v150 )
    {
      v151 = (unsigned __int8)*v150;
      v152 = 0i64;
      while ( 1 )
      {
        v153 = (unsigned int)(v152 + 1);
        if ( v150[v153] == 22 )
          break;
        v152 = (unsigned int)v153;
        if ( (unsigned int)v153 >= v151 )
          goto LABEL_206;
      }
      v154 = (signed __int64)&v150[4 * v152 + ((v151 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_206:
      v154 = 0i64;
    }
    v155 = &in_bIncludeRange;
    if ( v154 )
      v155 = (bool *)v154;
    *(_DWORD *)&in_bIncludeRange = *(_DWORD *)v155;
    v10->fGameAuxSendVolume = *(float *)&in_bIncludeRange + v10->fGameAuxSendVolume;
    v156 = v11->m_RTPCBitArray.m_iBitArray;
    if ( _bittest64((const signed __int64 *)&v156, 0x13ui64) )
      v10->fGameAuxSendVolume = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v11, 0x13u, v12) + v10->fGameAuxSendVolume;
    v10->bGameDefinedAuxEnabled = (*((_BYTE *)v11 + 145) >> 5) & 1;
  }
  if ( in_bDoBusCheck && v11->m_pBusOutputNode )
  {
    v157 = v11->m_props.m_pProps;
    *(_DWORD *)&in_bIncludeRange = 0;
    if ( v157 )
    {
      v158 = (unsigned __int8)*v157;
      v159 = 0i64;
      while ( 1 )
      {
        v160 = (unsigned int)(v159 + 1);
        if ( v157[v160] == 23 )
          break;
        v159 = (unsigned int)v160;
        if ( (unsigned int)v160 >= v158 )
          goto LABEL_218;
      }
      v161 = (signed __int64)&v157[4 * v159 + ((v158 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_218:
      v161 = 0i64;
    }
    v162 = &in_bIncludeRange;
    if ( v161 )
      v162 = (bool *)v161;
    *(_DWORD *)&in_bIncludeRange = *(_DWORD *)v162;
    v10->fOutputBusVolume = *(float *)&in_bIncludeRange + v10->fOutputBusVolume;
    v163 = v11->m_RTPCBitArray.m_iBitArray;
    if ( _bittest64((const signed __int64 *)&v163, 0x16ui64) )
      v10->fOutputBusVolume = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v11, 0x16u, v12) + v10->fOutputBusVolume;
    v164 = v11->m_props.m_pProps;
    *(_DWORD *)&in_bIncludeRange = 0;
    if ( v164 )
    {
      v165 = (unsigned __int8)*v164;
      v166 = 0i64;
      while ( 1 )
      {
        v167 = (unsigned int)(v166 + 1);
        if ( v164[v167] == 24 )
          break;
        v166 = (unsigned int)v167;
        if ( (unsigned int)v167 >= v165 )
          goto LABEL_235;
      }
      v13 = (signed __int64)&v164[4 * v166 + ((v165 + 4) & 0xFFFFFFFC)];
    }
LABEL_235:
    v168 = &in_bIncludeRange;
    if ( v13 )
      v168 = (bool *)v13;
    *(_DWORD *)&in_bIncludeRange = *(_DWORD *)v168;
    v10->fOutputBusLPF = *(float *)&in_bIncludeRange + v10->fOutputBusLPF;
    v169 = v11->m_RTPCBitArray.m_iBitArray;
    if ( _bittest64((const signed __int64 *)&v169, 0x17ui64) )
      v10->fOutputBusLPF = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v11, 0x17u, v12) + v10->fOutputBusLPF;
    v170 = v11->m_pParentNode;
    v171 = v183;
    if ( v170 )
      ((void (__fastcall *)(CAkParameterNodeBase *, AkSoundParamsEx *, _QWORD, CAkKeyArray<AkMutedMapItem,float,2> *, CAkRegisteredObj *, bool, AkPBIModValues *, _BYTE))v170->vfptr[10].Release)(
        v170,
        v10,
        v9,
        v183,
        v12,
        v100,
        v101,
        0);
    v172 = v11->m_pBusOutputNode;
    LOBYTE(v179) = 0;
    goto LABEL_244;
  }
  v172 = v11->m_pParentNode;
  v171 = v183;
  if ( v172 )
  {
    LOBYTE(v179) = in_bDoBusCheck;
LABEL_244:
    LOBYTE(v178) = v100;
    ((void (__fastcall *)(CAkParameterNodeBase *, AkSoundParamsEx *, _QWORD, CAkKeyArray<AkMutedMapItem,float,2> *, CAkRegisteredObj *, CAkRegisteredObj *, AkPBIModValues *, __int64))v172->vfptr[10].Release)(
      v172,
      v10,
      v9,
      v171,
      v12,
      v178,
      v101,
      v179);
  }
  v173 = v11->m_pAssociatedLayers;
  if ( v173 )
  {
    v174 = v173->m_pItems;
    v175 = (signed __int64)&v173->m_pItems[v173->m_uLength];
    if ( v173->m_pItems != (CAkLayer **)v175 )
    {
      v176 = in_ulParamSelecta;
      do
      {
        CAkLayer::GetAudioParameters(*v174, v11, (AkSoundParams *)&v10->Volume, v176, v171, v12);
        ++v174;
      }
      while ( v174 != (CAkLayer **)v175 );
    }
  }
  return 1i64;
}

// File Line: 499
// RVA: 0xA6EAE0
void __fastcall CAkParameterNode::SetAkProp(CAkParameterNode *this, AkPropID in_eProp, CAkRegisteredObj *in_GameObjPtr, AkValueMeaning in_eValueMeaning, float in_fTargetValue, AkCurveInterpolation in_eFadeCurve, int in_lTransitionTime)
{
  AkPropID v7; // esi
  AkValueMeaning v8; // edi
  CAkParameterNode *v9; // rbx
  CAkSIS *v10; // rax

  v7 = in_eProp;
  v8 = in_eValueMeaning;
  v9 = this;
  v10 = (CAkSIS *)this->vfptr[19].__vecDelDtor((CAkIndexable *)this, (unsigned int)in_GameObjPtr);
  if ( v10 )
    CAkParameterNodeBase::StartSISTransition(
      (CAkParameterNodeBase *)&v9->vfptr,
      v10,
      v7,
      in_fTargetValue,
      v8,
      in_eFadeCurve,
      in_lTransitionTime);
}

// File Line: 551
// RVA: 0xA6DD60
void __fastcall CAkParameterNode::Mute(CAkParameterNode *this, CAkRegisteredObj *in_GameObjPtr, AkCurveInterpolation in_eFadeCurve, int in_lTransitionTime)
{
  int v4; // edi
  AkCurveInterpolation v5; // esi
  CAkParameterNode *v6; // rbx
  CAkSIS *v7; // rax

  v4 = in_lTransitionTime;
  v5 = in_eFadeCurve;
  v6 = this;
  v7 = (CAkSIS *)this->vfptr[19].__vecDelDtor((CAkIndexable *)this, (unsigned int)in_GameObjPtr);
  if ( v7 )
    CAkParameterNodeBase::StartSisMuteTransitions((CAkParameterNodeBase *)&v6->vfptr, v7, 0.0, v5, v4);
}

// File Line: 562
// RVA: 0xA6F3A0
void __fastcall CAkParameterNode::Unmute(CAkParameterNode *this, CAkRegisteredObj *in_GameObjPtr, AkCurveInterpolation in_eFadeCurve, int in_lTransitionTime)
{
  int v4; // edi
  AkCurveInterpolation v5; // esi
  CAkParameterNode *v6; // rbx
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *v7; // r10
  MapStruct<CAkRegisteredObj *,CAkSIS *> *v8; // rax
  signed __int64 v9; // rcx
  CAkSIS *v10; // rdx
  CAkSIS *v11; // r8
  char *v12; // r8
  unsigned int v13; // er9
  int v14; // ecx
  __int64 v15; // rdx
  float *v16; // rdx

  v4 = in_lTransitionTime;
  v5 = in_eFadeCurve;
  v6 = this;
  if ( in_GameObjPtr )
  {
    v7 = this->m_pMapSIS;
    if ( v7 )
    {
      v8 = v7->m_pItems;
      v9 = (signed __int64)&v7->m_pItems[v7->m_uLength];
      if ( v7->m_pItems != (MapStruct<CAkRegisteredObj *,CAkSIS *> *)v9 )
      {
        do
        {
          if ( v8->key == in_GameObjPtr )
            break;
          ++v8;
        }
        while ( v8 != (MapStruct<CAkRegisteredObj *,CAkSIS *> *)v9 );
        if ( v8 != (MapStruct<CAkRegisteredObj *,CAkSIS *> *)v9 && v8 != (MapStruct<CAkRegisteredObj *,CAkSIS *> *)-8i64 )
        {
          v10 = v8->item;
          goto LABEL_18;
        }
      }
    }
  }
  else
  {
    v11 = this->m_pGlobalSIS;
    if ( v11 )
    {
      v12 = v11->m_values.m_pProps;
      if ( v12 )
      {
        v13 = (unsigned __int8)*v12;
        v14 = 0;
        while ( 1 )
        {
          v15 = (unsigned int)(v14 + 1);
          if ( v12[v15] == 10 )
            break;
          ++v14;
          if ( (unsigned int)v15 >= v13 )
            return;
        }
        v16 = (float *)&v12[16 * v14 + ((v13 + 4) & 0xFFFFFFFC)];
        if ( v16 )
        {
          if ( 1.0 != *v16 )
          {
            CAkRegistryMgr::SetNodeIDAsModified(g_pRegistryMgr, (CAkParameterNodeBase *)&v6->vfptr);
            v10 = v6->m_pGlobalSIS;
LABEL_18:
            if ( v10 )
              CAkParameterNodeBase::StartSisMuteTransitions((CAkParameterNodeBase *)&v6->vfptr, v10, 1.0, v5, v4);
            return;
          }
        }
      }
    }
  }
}

// File Line: 598
// RVA: 0xA6F500
void __fastcall CAkParameterNode::UnmuteAllObj(CAkParameterNode *this, AkCurveInterpolation in_eFadeCurve, int in_lTransitionTime)
{
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *v3; // r9
  unsigned int v4; // esi
  AkCurveInterpolation v5; // ebp
  CAkParameterNode *v6; // rdi
  MapStruct<CAkRegisteredObj *,CAkSIS *> *v7; // rbx
  CAkSIS *v8; // r10
  char *v9; // r8
  unsigned int v10; // er9
  int v11; // ecx
  __int64 v12; // rdx
  float *v13; // r9

  v3 = this->m_pMapSIS;
  v4 = in_lTransitionTime;
  v5 = in_eFadeCurve;
  v6 = this;
  if ( v3 )
  {
    v7 = v3->m_pItems;
    if ( v3->m_pItems != &v3->m_pItems[v3->m_uLength] )
    {
      do
      {
        v8 = v7->item;
        v9 = v8->m_values.m_pProps;
        if ( v9 )
        {
          v10 = (unsigned __int8)*v9;
          v11 = 0;
          while ( 1 )
          {
            v12 = (unsigned int)(v11 + 1);
            if ( v9[v12] == 10 )
              break;
            v11 = v12;
            if ( (unsigned int)v12 >= v10 )
              goto LABEL_11;
          }
          v13 = (float *)&v9[16 * v11 + ((v10 + 4) & 0xFFFFFFFC)];
          if ( v13 )
          {
            if ( 1.0 != *v13 )
              ((void (__fastcall *)(CAkParameterNode *, CAkRegisteredObj *, _QWORD, _QWORD))v6->vfptr[12].AddRef)(
                v6,
                v8->m_pGameObj,
                (unsigned int)v5,
                v4);
          }
        }
LABEL_11:
        ++v7;
      }
      while ( v7 != &v6->m_pMapSIS->m_pItems[v6->m_pMapSIS->m_uLength] );
    }
  }
}

// File Line: 613
// RVA: 0xA6F4B0
void __fastcall CAkParameterNode::UnmuteAll(CAkParameterNode *this, AkCurveInterpolation in_eFadeCurve, int in_lTransitionTime)
{
  unsigned int v3; // ebx
  AkCurveInterpolation v4; // edi
  CAkParameterNode *v5; // rsi

  v3 = in_lTransitionTime;
  v4 = in_eFadeCurve;
  v5 = this;
  ((void (__fastcall *)(CAkParameterNode *, _QWORD, _QWORD, _QWORD))this->vfptr[12].AddRef)(
    this,
    0i64,
    (unsigned int)in_eFadeCurve,
    (unsigned int)in_lTransitionTime);
  ((void (__fastcall *)(CAkParameterNode *, _QWORD, _QWORD))v5->vfptr[20].__vecDelDtor)(v5, (unsigned int)v4, v3);
}

// File Line: 619
// RVA: 0xA6F5F0
void __fastcall CAkParameterNode::Unregister(CAkParameterNode *this, CAkRegisteredObj *in_GameObjPtr)
{
  CAkParameterNode *v2; // rbp
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *v3; // rcx
  CAkRegisteredObj *v4; // r14
  CAkSIS **v5; // rbx
  CAkSIS *v6; // rsi
  int v7; // edi
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *v8; // rdx
  unsigned __int64 v9; // rcx

  v2 = this;
  v3 = this->m_pMapSIS;
  v4 = in_GameObjPtr;
  if ( v3 )
  {
    v5 = (CAkSIS **)v3->m_pItems;
    if ( v3->m_pItems != &v3->m_pItems[v3->m_uLength] )
    {
      do
      {
        if ( *v5 == (CAkSIS *)v4 )
        {
          v6 = v5[1];
          if ( v6 )
          {
            v7 = g_DefaultPoolId;
            CAkSIS::~CAkSIS(v5[1]);
            AK::MemoryMgr::Free(v7, v6);
          }
          v8 = v2->m_pMapSIS;
          v9 = (unsigned __int64)&v8->m_pItems[v8->m_uLength - 1];
          if ( (unsigned __int64)v5 < v9 )
            qmemcpy(
              v5,
              v5 + 2,
              8 * (((((v9 - (unsigned __int64)v5 - 1) >> 3) & 0xFFFFFFFFFFFFFFFEui64) + 2) & 0x1FFFFFFFFFFFFFFEi64));
          --v8->m_uLength;
        }
        else
        {
          v5 += 2;
        }
      }
      while ( v5 != (CAkSIS **)&v2->m_pMapSIS->m_pItems[v2->m_pMapSIS->m_uLength] );
    }
  }
}

// File Line: 646
// RVA: 0xA6E200
void __fastcall CAkParameterNode::ResetAkProp(CAkParameterNode *this, AkPropID in_eProp, AkCurveInterpolation in_eFadeCurve, int in_lTransitionTime)
{
  AkPropID v4; // esi
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *v5; // rdx
  int v6; // edi
  int v7; // ebp
  AkCurveInterpolation v8; // er15
  CAkParameterNode *v9; // r14
  MapStruct<CAkRegisteredObj *,CAkSIS *> *v10; // rbx
  CAkSIS *v11; // r10
  char *v12; // r8
  unsigned int v13; // er9
  int v14; // ecx
  __int64 v15; // rdx
  float *v16; // rdx
  CAkSIS *v17; // rdx
  char *v18; // rdx
  unsigned int v19; // er8
  __int64 v20; // rcx
  float *v21; // rcx
  __int64 v22; // [rsp+20h] [rbp-48h]
  __int64 v23; // [rsp+28h] [rbp-40h]
  __int64 v24[2]; // [rsp+30h] [rbp-38h]

  v4 = in_eProp;
  v5 = this->m_pMapSIS;
  v6 = 0;
  v7 = in_lTransitionTime;
  v8 = in_eFadeCurve;
  v9 = this;
  if ( v5 )
  {
    v10 = v5->m_pItems;
    if ( v5->m_pItems != &v5->m_pItems[v5->m_uLength] )
    {
      do
      {
        v11 = v10->item;
        v12 = v11->m_values.m_pProps;
        if ( v12 )
        {
          v13 = (unsigned __int8)*v12;
          v14 = 0;
          while ( 1 )
          {
            v15 = (unsigned int)(v14 + 1);
            if ( v12[v15] == (_BYTE)v4 )
              break;
            ++v14;
            if ( (unsigned int)v15 >= v13 )
              goto LABEL_11;
          }
          v16 = (float *)&v12[16 * v14 + ((v13 + 4) & 0xFFFFFFFC)];
          if ( v16 && 0.0 != *v16 )
          {
            LODWORD(v24[0]) = 0;
            LODWORD(v23) = 4;
            LODWORD(v22) = 0;
            ((void (__fastcall *)(CAkParameterNode *, _QWORD, CAkRegisteredObj *, _QWORD, __int64, __int64, __int64))v9->vfptr[11].Release)(
              v9,
              (unsigned int)v4,
              v11->m_pGameObj,
              0i64,
              v22,
              v23,
              v24[0]);
          }
        }
LABEL_11:
        ++v10;
      }
      while ( v10 != &v9->m_pMapSIS->m_pItems[v9->m_pMapSIS->m_uLength] );
    }
  }
  v17 = v9->m_pGlobalSIS;
  if ( v17 )
  {
    v18 = v17->m_values.m_pProps;
    if ( v18 )
    {
      v19 = (unsigned __int8)*v18;
      while ( 1 )
      {
        v20 = (unsigned int)(v6 + 1);
        if ( v18[v20] == (_BYTE)v4 )
          break;
        ++v6;
        if ( (unsigned int)v20 >= v19 )
          return;
      }
      v21 = (float *)&v18[16 * v6 + ((v19 + 4) & 0xFFFFFFFC)];
      if ( v21 )
      {
        if ( 0.0 != *v21 )
        {
          LODWORD(v24[0]) = v7;
          LODWORD(v23) = v8;
          LODWORD(v22) = 0;
          ((void (__fastcall *)(CAkParameterNode *, _QWORD, _QWORD, _QWORD, __int64, __int64, __int64))v9->vfptr[11].Release)(
            v9,
            (unsigned int)v4,
            0i64,
            0i64,
            v22,
            v23,
            v24[0]);
        }
      }
    }
  }
}

// File Line: 670
// RVA: 0xA6B910
CAkActionPlayAndContinue *__fastcall CreateDelayedAction(ContParams *in_pContinuousParams, AkPBIParams *in_rPBIParams, unsigned int in_uTargetElementID)
{
  unsigned int v3; // ebp
  AkPBIParams *v4; // rdi
  ContParams *v5; // rsi
  CAkActionPlayAndContinue *result; // rax
  CAkActionPlayAndContinue *v7; // rbx
  __int64 v8; // [rsp+30h] [rbp+8h]

  v3 = in_uTargetElementID;
  v4 = in_rPBIParams;
  v5 = in_pContinuousParams;
  result = CAkActionPlayAndContinue::Create(AkActionType_PlayAndContinue, 0, &in_pContinuousParams->spContList);
  v7 = result;
  if ( result )
  {
    result->m_ulPauseCount = v5->ulPauseCount;
    CAkActionPlayAndContinue::SetHistory(result, &v4->playHistory);
    LODWORD(v8) = v3;
    BYTE4(v8) = 0;
    ((void (__fastcall *)(CAkActionPlayAndContinue *, __int64))v7->vfptr[1].AddRef)(v7, v8);
    CAkActionPlayAndContinue::SetInstigator(v7, v4->pInstigator);
    CAkActionPlayAndContinue::SetSAInfo(v7, v4->sequenceID);
    CAkActionPlayAndContinue::SetIsFirstPlay(v7, v4->bIsFirst);
    CAkActionPlayAndContinue::SetInitialPlaybackState(v7, v4->ePlaybackState);
    result = v7;
  }
  return result;
}

// File Line: 687
// RVA: 0xA6B9D0
signed __int64 __fastcall CreateDelayedPendingAction(ContParams *in_pContinuousParams, AkPBIParams *in_rPBIParams, int iDelaySamples, CAkActionPlayAndContinue *in_pAction)
{
  ContParams *v4; // rsi
  AkPBIParams *v5; // rbp
  CAkActionPlayAndContinue *v6; // rbx
  unsigned int v7; // er14
  AkPendingAction *v8; // rax
  AkPendingAction *v9; // rax
  AkPendingAction *v10; // rdi
  unsigned int v11; // esi
  int v13; // ebx
  int v14; // ebx

  v4 = in_pContinuousParams;
  v5 = in_rPBIParams;
  v6 = in_pAction;
  v7 = iDelaySamples;
  v8 = (AkPendingAction *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
  if ( !v8 )
    return 52i64;
  AkPendingAction::AkPendingAction(v8, v5->pGameObj);
  v10 = v9;
  if ( !v9 )
    return 52i64;
  if ( CAkActionPlayAndContinue::SetPlayStopTransition(v6, v4->pPlayStopTransition, v4->bIsPlayStopTransitionFading, v9) != 1
    || CAkActionPlayAndContinue::SetPauseResumeTransition(
         v6,
         v4->pPauseResumeTransition,
         v4->bIsPauseResumeTransitionFading,
         v10) != 1 )
  {
    v14 = g_DefaultPoolId;
    ((void (__fastcall *)(AkPendingAction *, _QWORD))v10->vfptr[1].TransUpdateValue)(v10, 0i64);
    AK::MemoryMgr::Free(v14, v10);
    return 52i64;
  }
  CAkActionPlayAndContinue::SetPathInfo(v6, v4->pPathInfo);
  v11 = ((__int64 (__fastcall *)(CAkActionPlayAndContinue *, signed __int64, _QWORD))v6->vfptr[1].Release)(
          v6,
          14i64,
          v7);
  if ( v11 == 1 )
  {
    v10->pAction = (CAkAction *)&v6->vfptr;
    UserParams::operator=(&v10->UserParam, &v5->userParams);
    CAkAudioMgr::EnqueueOrExecuteAction(g_pAudioMgr, v10);
  }
  else
  {
    v13 = g_DefaultPoolId;
    ((void (__fastcall *)(AkPendingAction *, _QWORD))v10->vfptr[1].TransUpdateValue)(v10, 0i64);
    AK::MemoryMgr::Free(v13, v10);
  }
  return v11;
}

// File Line: 726
// RVA: 0xA6BD00
signed __int64 __fastcall CAkParameterNode::DelayPlayback(CAkParameterNode *this, float in_fDelay, AkPBIParams *in_rPBIParams)
{
  CAkParameterNode *v3; // rdi
  AkPBIParams *v4; // r14
  unsigned int v5; // esi
  CAkContinuationList *v6; // rax
  CAkContinuationList *v7; // rcx
  ContParams *v8; // rbx
  CAkContinuationList *v9; // rax
  CAkContinuationList *v10; // rcx
  CAkActionPlayAndContinue *v11; // rax
  CAkActionPlayAndContinue *v12; // rdi
  double v13; // xmm2_8
  double v14; // xmm0_8
  __int64 v16; // [rsp+20h] [rbp-58h]
  int v17; // [rsp+28h] [rbp-50h]
  __int64 v18; // [rsp+30h] [rbp-48h]
  __int64 v19; // [rsp+38h] [rbp-40h]
  __int64 *v20; // [rsp+40h] [rbp-38h]
  __int16 v21; // [rsp+48h] [rbp-30h]
  CAkContinuationList *v22; // [rsp+50h] [rbp-28h]
  int v23; // [rsp+58h] [rbp-20h]

  v3 = this;
  v18 = 0i64;
  v19 = 0i64;
  v16 = 0i64;
  v17 = 0;
  v4 = in_rPBIParams;
  v5 = 52;
  v21 = 0;
  v22 = 0i64;
  v20 = &v16;
  v23 = 0;
  v6 = CAkContinuationList::Create();
  v7 = v22;
  v22 = v6;
  if ( v7 )
  {
    CAkContinuationList::Release(v7);
    v6 = v22;
  }
  if ( !v6 )
    return 2i64;
  v8 = v4->pContinuousParams;
  if ( !v8 )
  {
    v9 = CAkContinuationList::Create();
    v10 = v22;
    v22 = v9;
    if ( v10 )
    {
      CAkContinuationList::Release(v10);
      v9 = v22;
    }
    if ( v9 )
    {
      v8 = (ContParams *)&v18;
      goto LABEL_9;
    }
    return 2i64;
  }
LABEL_9:
  v11 = CreateDelayedAction(v8, v4, v3->key);
  v12 = v11;
  if ( v11 )
  {
    v11->m_bSkipDelay = 1;
    v11->m_ePBIType = v4->eType;
    v13 = (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency * in_fDelay;
    if ( v13 <= 0.0 )
      v14 = DOUBLE_N0_5;
    else
      v14 = DOUBLE_0_5;
    v5 = CreateDelayedPendingAction(v8, v4, (signed int)(v14 + v13), v11);
    v12->vfptr->Release((CAkIndexable *)&v12->vfptr);
  }
  if ( v22 )
    CAkContinuationList::Release(v22);
  return v5;
}

// File Line: 766
// RVA: 0xA6DE40
signed __int64 __fastcall CAkParameterNode::PlayAndContinueAlternate(CAkParameterNode *this, AkPBIParams *in_rPBIParams)
{
  ContParams *v2; // rax
  AkPBIParams *v3; // rdi
  unsigned int v4; // ebp
  unsigned int v5; // edx
  __int64 v6; // rcx
  CAkSmartPtr<CAkContinuationList> *v7; // rdx
  CAkSmartPtr<CAkContinuationList> v8; // rcx
  signed __int64 v9; // rax
  CAkContinueListItem *v10; // rsi
  signed __int64 v11; // rbx
  CAkMultiPlayNode *v12; // rcx
  CAkParameterNodeBase *v13; // rdx
  bool v14; // zf
  unsigned int v15; // edx
  __int64 v16; // rcx
  CAkContinuationList *v17; // rbx
  CAkContinuationList *v18; // rbx
  ContParams *v19; // rdx
  unsigned int v20; // er15
  AkTransitionMode v21; // er14
  float v22; // xmm0_4
  CAkActionPlayAndContinue *v23; // rbx
  double v24; // xmm1_8
  double v25; // xmm0_8
  int v26; // er8
  ContParams *v27; // rdx
  CAkContinuationList *v28; // rcx
  unsigned __int16 out_rwPositionSelected; // [rsp+78h] [rbp+10h]
  unsigned int out_uSelectedNodeID; // [rsp+80h] [rbp+18h]

  v2 = in_rPBIParams->pContinuousParams;
  v3 = in_rPBIParams;
  v4 = 2;
  if ( !v2 || !v2->spContList.m_pT )
    return 2i64;
  if ( in_rPBIParams->playHistory.HistArray.uiArraySize )
  {
    do
    {
      v5 = v3->playHistory.HistArray.uiArraySize - 1;
      if ( v5 < 0x20 )
      {
        v6 = v3->playHistory.arrayIsContinuous.m_iBitArray;
        if ( _bittest64(&v6, v5) )
          break;
      }
      v3->playHistory.HistArray.uiArraySize = v5;
    }
    while ( v5 );
  }
  v7 = &v3->pContinuousParams->spContList;
  out_rwPositionSelected = 0;
  v8.m_pT = v7->m_pT;
  if ( v7->m_pT->m_listItems.m_uLength )
  {
    do
    {
      v9 = v8.m_pT->m_listItems.m_uLength;
      v10 = v8.m_pT->m_listItems.m_pItems;
      v11 = v9;
      v12 = (CAkMultiPlayNode *)*((_QWORD *)&v8.m_pT->m_listItems.m_pItems[v9] - 2);
      if ( v12 )
      {
        CAkMultiPlayNode::ContGetList(v12, *((CAkContinuationList **)&v10[v9] - 1), v7);
        v18 = v3->pContinuousParams->spContList.m_pT;
        CAkContinueListItem::~CAkContinueListItem((CAkContinueListItem *)((char *)v18->m_listItems.m_pItems
                                                                        + 8 * (5i64 * v18->m_listItems.m_uLength - 5)));
        --v18->m_listItems.m_uLength;
        if ( !v3->pContinuousParams->spContList.m_pT )
        {
          v4 = 3;
          break;
        }
      }
      else
      {
        v13 = CAkRanSeqCntr::GetNextToPlayContinuous(
                v10[v9 - 1].m_pContainer.m_pT,
                v3->pGameObj,
                &out_rwPositionSelected,
                &out_uSelectedNodeID,
                (CAkContainerBaseInfo **)&v10->m_pContainer.m_pT + 5 * v9 - 4,
                (AkLoop *)&v10->m_pContainer.m_pT + 2 * (5 * v9 - 3));
        if ( v13 )
        {
          v3->playHistory.HistArray.aCntrHist[v3->playHistory.HistArray.uiArraySize - 1] = out_rwPositionSelected;
          v20 = v13->key;
          v13->vfptr->Release((CAkIndexable *)&v13->vfptr);
          v21 = CAkRanSeqCntr::TransitionMode(v10[v11 - 1].m_pContainer.m_pT);
          v22 = CAkRanSeqCntr::TransitionTime(v10[v11 - 1].m_pContainer.m_pT, v3->pGameObj);
          if ( v20 )
          {
            v23 = CreateDelayedAction(v3->pContinuousParams, v3, v20);
            if ( v23 )
            {
              if ( v21 != 3
                || ((v24 = (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency * v22 * 0.001, v24 <= 0.0) ? (v25 = DOUBLE_N0_5) : (v25 = DOUBLE_0_5),
                    v26 = (signed int)(v25 + v24),
                    v26 < 10240) )
              {
                v26 = 10240;
              }
              v4 = CreateDelayedPendingAction(v3->pContinuousParams, v3, v26, v23);
              v23->vfptr->Release((CAkIndexable *)&v23->vfptr);
            }
          }
          break;
        }
        v14 = v3->playHistory.HistArray.uiArraySize-- == 1;
        if ( !v14 )
        {
          do
          {
            v15 = v3->playHistory.HistArray.uiArraySize - 1;
            if ( v15 < 0x20 )
            {
              v16 = v3->playHistory.arrayIsContinuous.m_iBitArray;
              if ( _bittest64(&v16, v15) )
                break;
            }
            v3->playHistory.HistArray.uiArraySize = v15;
          }
          while ( v15 );
        }
        v17 = v3->pContinuousParams->spContList.m_pT;
        CAkContinueListItem::~CAkContinueListItem((CAkContinueListItem *)((char *)v17->m_listItems.m_pItems
                                                                        + 8 * (5i64 * v17->m_listItems.m_uLength - 5)));
        --v17->m_listItems.m_uLength;
      }
      v19 = v3->pContinuousParams;
      v8.m_pT = v19->spContList.m_pT;
      v7 = &v19->spContList;
    }
    while ( v8.m_pT->m_listItems.m_uLength );
  }
  v27 = v3->pContinuousParams;
  if ( v27->spContList.m_pT && (v4 - 1) & 0xFFFFFFFD )
  {
    v28 = v27->spContList.m_pT;
    v27->spContList.m_pT = 0i64;
    if ( v28 )
      CAkContinuationList::Release(v28);
  }
  return v4;
}

// File Line: 882
// RVA: 0xA6C010
signed __int64 __fastcall CAkParameterNode::ExecuteActionExceptParentCheck(CAkParameterNode *this, ActionParamsExcept *in_rAction)
{
  CAkParameterNodeBase *v2; // rbx
  ActionParamsExcept *v3; // rdi
  CAkParameterNode *v4; // rsi

  v2 = this->m_pParentNode;
  v3 = in_rAction;
  v4 = this;
  if ( !v2 )
    return ((__int64 (__fastcall *)(CAkParameterNode *, ActionParamsExcept *))v4->vfptr[4].AddRef)(v4, v3);
  while ( !CAkParameterNodeBase::IsException(v2, v3->pExeceptionList) )
  {
    v2 = v2->m_pParentNode;
    if ( !v2 )
      return ((__int64 (__fastcall *)(CAkParameterNode *, ActionParamsExcept *))v4->vfptr[4].AddRef)(v4, v3);
  }
  return 1i64;
}

// File Line: 901
// RVA: 0xA6EF90
signed __int64 __fastcall CAkParameterNode::SetInitialParams(CAkParameterNode *this, char **io_rpData, unsigned int *io_rulDataSize)
{
  CAkParameterNode *v3; // rbx
  unsigned int *v4; // rdi
  char **v5; // rsi
  signed __int64 result; // rax

  v3 = this;
  v4 = io_rulDataSize;
  v5 = io_rpData;
  if ( (unsigned int)AkPropBundle<AkPropValue>::SetInitialParams(&this->m_props, io_rpData, io_rulDataSize) != 1 )
    return 2i64;
  result = AkPropBundle<RANGED_MODIFIERS<AkPropValue>>::SetInitialParams(&v3->m_ranges, v5, v4);
  if ( (_DWORD)result != 1 )
    return 2i64;
  *((_BYTE *)&v3->0 + 82) |= 0x80u;
  return result;
}

// File Line: 917
// RVA: 0xA6ECE0
signed __int64 __fastcall CAkParameterNode::SetInitialFxParams(CAkParameterNode *this, char **io_rpData, unsigned int *io_rulDataSize, bool in_bPartialLoadOnly)
{
  CAkParameterNode *v4; // rbp
  bool v5; // r13
  char v6; // cl
  char **v7; // rsi
  AKRESULT v8; // er14
  char *v9; // rax
  unsigned int v10; // ecx
  unsigned int v11; // er12
  int v12; // edi
  char *v13; // rax
  unsigned int v14; // ecx
  unsigned int v15; // er15
  char v16; // dl
  char v17; // bl
  unsigned int in_bitsFXBypass; // [rsp+20h] [rbp-48h]
  unsigned int in_uFXIndex; // [rsp+78h] [rbp+10h]
  char v21; // [rsp+88h] [rbp+20h]

  v4 = this;
  v5 = in_bPartialLoadOnly;
  v6 = **io_rpData;
  v7 = io_rpData;
  v8 = 1;
  ++*io_rpData;
  if ( !in_bPartialLoadOnly )
  {
    *((_BYTE *)&v4->0 + 83) &= 0xBFu;
    *((_BYTE *)&v4->0 + 83) |= (v6 != 0) << 6;
  }
  v9 = *io_rpData + 1;
  v10 = (unsigned __int8)**io_rpData;
  *io_rpData = v9;
  v11 = v10;
  if ( (_BYTE)v10 )
  {
    v12 = 0;
    in_bitsFXBypass = (unsigned __int8)*v9;
    *io_rpData = v9 + 1;
    if ( v10 )
    {
      while ( 1 )
      {
        v13 = *v7 + 1;
        v14 = (unsigned __int8)**v7;
        *v7 = v13;
        v13 += 4;
        v15 = *((_DWORD *)v13 - 1);
        *v7 = v13;
        v16 = *v13++;
        v21 = v16;
        in_uFXIndex = v14;
        *v7 = v13;
        v17 = *v13;
        *v7 = v13 + 1;
        CAkParameterNodeBase::RenderedFX((CAkParameterNodeBase *)&v4->vfptr, v14, v17 != 0);
        if ( !v17 )
        {
          if ( v15 )
          {
            if ( !v5 )
            {
              v8 = CAkParameterNodeBase::SetFX((CAkParameterNodeBase *)&v4->vfptr, in_uFXIndex, v15, v21 != 0);
              if ( v8 != 1 )
                break;
            }
          }
        }
        if ( ++v12 >= v11 )
          goto LABEL_10;
      }
    }
    else
    {
LABEL_10:
      if ( v5 )
        return (unsigned int)v8;
    }
    CAkParameterNodeBase::MainBypassFX((CAkParameterNodeBase *)&v4->vfptr, in_bitsFXBypass, 0xFFFFFFFF);
    return (unsigned int)v8;
  }
  return 1i64;
}

// File Line: 980
// RVA: 0xA6BF80
signed __int64 __fastcall CAkParameterNode::Enable3DPosParams(CAkParameterNode *this)
{
  CAkParameterNode *v1; // rbx
  CAkGen3DParams *v2; // rax
  CAkGen3DParamsEx *v3; // rdi
  signed __int64 result; // rax

  v1 = this;
  if ( this->m_p3DParameters )
    return 1i64;
  *((_BYTE *)&this->0 + 83) |= 0x10u;
  v2 = (CAkGen3DParams *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x68ui64);
  v3 = (CAkGen3DParamsEx *)v2;
  if ( !v2 )
    return 52i64;
  CAkGen3DParams::CAkGen3DParams(v2);
  result = 1i64;
  v3->vfptr = (CAkGen3DParamsVtbl *)&CAkGen3DParamsEx::`vftable';
  v3->m_PathState.ulCurrentListIndex = 0;
  v3->m_PathState.pbPlayed = 0i64;
  v3->m_Params.m_ID = v1->key;
  v1->m_p3DParameters = v3;
  return result;
}

// File Line: 1006
// RVA: 0xA6BE70
void __fastcall CAkParameterNode::DisablePosParams(CAkParameterNode *this)
{
  CAkParameterNode *v1; // rbx
  CAkGen3DParamsEx *v2; // rcx
  CAkGen3DParamsEx *v3; // rdi
  int v4; // esi

  v1 = this;
  v2 = this->m_p3DParameters;
  if ( v2 )
  {
    CAkGen3DParamsEx::FreePathInfo(v2);
    CAkGen3DParams::Term((CAkGen3DParams *)&v1->m_p3DParameters->vfptr);
    v3 = v1->m_p3DParameters;
    v4 = g_DefaultPoolId;
    if ( v3 )
    {
      v3->vfptr->__vecDelDtor((CAkGen3DParams *)&v3->vfptr, 0);
      AK::MemoryMgr::Free(v4, v3);
    }
    v1->m_p3DParameters = 0i64;
  }
}

// File Line: 1022
// RVA: 0xA6E130
void __fastcall CAkParameterNode::PosSetPositioningType(CAkParameterNode *this, bool in_bOverride, bool in_bRTPC, AkPannerType in_ePanner, AkPositionSourceType in_ePosSource)
{
  char v5; // di
  bool v6; // si
  CAkParameterNode *v7; // rbx
  __int128 v8; // xmm1

  *((_BYTE *)&this->0 + 83) &= 0xEFu;
  v5 = in_ePanner;
  v6 = in_bRTPC;
  v7 = this;
  *((_BYTE *)&this->0 + 83) |= 16 * in_bOverride;
  if ( in_bOverride )
  {
    CAkParameterNode::Enable3DPosParams(this);
    *((_BYTE *)v7 + 145) &= 0xF0u;
    *((_BYTE *)v7 + 145) |= v5 & 3 | (unsigned __int8)(4 * (in_ePosSource & 3));
  }
  else
  {
    CAkParameterNode::DisablePosParams(this);
    *((_BYTE *)v7 + 145) &= 0xFCu;
  }
  if ( !v6 )
  {
    v8 = COERCE_UNSIGNED_INT((float)(*((_BYTE *)v7 + 145) & 3));
    ((void (__fastcall *)(CAkParameterNode *, CAkIndexableVtbl *, signed __int64))v7->vfptr[17].Release)(
      v7,
      v7->vfptr,
      10i64);
  }
}

// File Line: 1206
// RVA: 0xA6C0B0
void __fastcall CAkParameterNode::Get3DCloneForObject(CAkParameterNode *this, CAkGen3DParams **in_rp3DParams, AkPositionSourceType *out_ePosType)
{
  CAkGen3DParams **v3; // rbx
  CAkParameterNode *v4; // rdi
  CAkGen3DParams *v5; // rax
  CAkGen3DParamsEx *v6; // rcx
  CAkGen3DParams *v7; // rdx

  v3 = in_rp3DParams;
  v4 = this;
  *out_ePosType = ((unsigned int)*((unsigned __int8 *)this + 145) >> 2) & 3;
  if ( this->m_p3DParameters )
  {
    if ( *in_rp3DParams )
      goto LABEL_9;
    v5 = (CAkGen3DParams *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x58ui64);
    if ( v5 )
      CAkGen3DParams::CAkGen3DParams(v5);
    *v3 = v5;
    if ( v5 )
    {
LABEL_9:
      v6 = v4->m_p3DParameters;
      v7 = *v3;
      *(_QWORD *)&v7->m_Params.m_ID = *(_QWORD *)&v6->m_Params.m_ID;
      *(_QWORD *)&v7->m_Params.m_fConeOutsideVolume = *(_QWORD *)&v6->m_Params.m_fConeOutsideVolume;
      *(_QWORD *)&v7->m_Params.m_Position.X = *(_QWORD *)&v6->m_Params.m_Position.X;
      *(_QWORD *)&v7->m_Params.m_Position.Z = *(_QWORD *)&v6->m_Params.m_Position.Z;
      *(_QWORD *)&v7->m_Params.m_TransitionTime = *(_QWORD *)&v6->m_Params.m_TransitionTime;
      v7->m_Params.m_pArrayVertex = v6->m_Params.m_pArrayVertex;
      *(_QWORD *)&v7->m_Params.m_ulNumVertices = *(_QWORD *)&v6->m_Params.m_ulNumVertices;
      v7->m_Params.m_pArrayPlaylist = v6->m_Params.m_pArrayPlaylist;
      *(_QWORD *)&v7->m_Params.m_ulNumPlaylistItem = *(_QWORD *)&v6->m_Params.m_ulNumPlaylistItem;
      v7->m_Params.m_pAttenuation = v6->m_Params.m_pAttenuation;
    }
  }
}

// File Line: 1224
// RVA: 0xA6D6D0
CAkSIS *__fastcall CAkParameterNode::GetSIS(CAkParameterNode *this, CAkRegisteredObj *in_GameObjPtr)
{
  CAkRegisteredObj *v2; // rbp
  CAkParameterNode *v3; // rbx
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *v4; // rcx
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *v5; // rax
  MapStruct<CAkRegisteredObj *,CAkSIS *> *v7; // rax
  signed __int64 v8; // rcx
  CAkSIS *v9; // rdi
  CAkParameterNodeBase::FXChunk *v10; // rax
  char v11; // r14
  CAkSIS *v12; // rax
  int v13; // ebx
  CAkParameterNodeBase::FXChunk *v14; // rax
  char v15; // di
  CAkSIS *v16; // rax

  v2 = in_GameObjPtr;
  v3 = this;
  if ( !in_GameObjPtr )
  {
    CAkRegistryMgr::SetNodeIDAsModified(g_pRegistryMgr, (CAkParameterNodeBase *)&this->vfptr);
    if ( !v3->m_pGlobalSIS )
    {
      v14 = v3->m_pFXChunk;
      if ( v14 )
        v15 = v14->bitsMainFXBypass;
      else
        v15 = 0;
      v16 = (CAkSIS *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x28ui64);
      if ( v16 )
      {
        v16->m_pParamNode = (CAkParameterNodeBase *)&v3->vfptr;
        v16->m_pGameObj = 0i64;
        v16->vfptr = (ITransitionableVtbl *)&CAkSIS::`vftable';
        v16->m_values.m_pProps = 0i64;
        v16->m_bitsFXBypass = v15;
      }
      else
      {
        v16 = 0i64;
      }
      v3->m_pGlobalSIS = v16;
    }
    return v3->m_pGlobalSIS;
  }
  v4 = this->m_pMapSIS;
  if ( !v4 )
  {
    v5 = (CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x10ui64);
    v3->m_pMapSIS = v5;
    if ( v5 )
    {
      v5->m_pItems = 0i64;
      *(_QWORD *)&v5->m_uLength = 0i64;
    }
    v4 = v3->m_pMapSIS;
    if ( !v4 )
      return 0i64;
  }
  v7 = v4->m_pItems;
  v8 = (signed __int64)&v4->m_pItems[v4->m_uLength];
  if ( v7 == (MapStruct<CAkRegisteredObj *,CAkSIS *> *)v8 )
    goto LABEL_34;
  do
  {
    if ( v7->key == v2 )
      break;
    ++v7;
  }
  while ( v7 != (MapStruct<CAkRegisteredObj *,CAkSIS *> *)v8 );
  if ( v7 == (MapStruct<CAkRegisteredObj *,CAkSIS *> *)v8 || v7 == (MapStruct<CAkRegisteredObj *,CAkSIS *> *)-8i64 )
  {
LABEL_34:
    v10 = v3->m_pFXChunk;
    if ( v10 )
      v11 = v10->bitsMainFXBypass;
    else
      v11 = 0;
    v12 = (CAkSIS *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x28ui64);
    v9 = v12;
    if ( v12 )
    {
      v12->m_pParamNode = (CAkParameterNodeBase *)&v3->vfptr;
      v12->m_pGameObj = v2;
      v12->vfptr = (ITransitionableVtbl *)&CAkSIS::`vftable';
      v12->m_values.m_pProps = 0i64;
      v12->m_bitsFXBypass = v11;
      if ( CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4>::Set(
             (CAkKeyArray<CAkRSSub *,CAkContainerBaseInfo *,4> *)v3->m_pMapSIS,
             (CAkRSSub *)v2,
             (CAkContainerBaseInfo *)v12) )
      {
        if ( (unsigned int)CAkRegisteredObj::SetNodeAsModified(v2, (CAkParameterNodeBase *)&v3->vfptr) == 1 )
          return v9;
        CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4>::Unset(v3->m_pMapSIS, v2);
      }
      v13 = g_DefaultPoolId;
      CAkSIS::~CAkSIS(v9);
      AK::MemoryMgr::Free(v13, v9);
    }
    return 0i64;
  }
  return v7->item;
}

// File Line: 1280
// RVA: 0xA6D890
__int64 __fastcall CAkParameterNode::GetVirtualBehavior(CAkParameterNode *this, AkVirtualQueueBehavior *out_Behavior)
{
  CAkParameterNodeBase *v2; // rax

  if ( !(*((_BYTE *)&this->0 + 82) & 4) )
  {
    do
    {
      v2 = this->m_pParentNode;
      if ( !v2 )
        break;
      this = (CAkParameterNode *)this->m_pParentNode;
    }
    while ( !(*((_BYTE *)v2 + 82) & 4) );
  }
  *out_Behavior = *((_BYTE *)this + 144) & 7;
  return ((unsigned int)*((unsigned __int8 *)this + 144) >> 3) & 0xF;
}

// File Line: 1293
// RVA: 0xA6DA90
bool __fastcall CAkParameterNode::Has3DParams(CAkParameterNode *this)
{
  return this->m_p3DParameters != 0i64;
}

// File Line: 1298
// RVA: 0xA6F000
signed __int64 __fastcall CAkParameterNode::SetPositioningParams(CAkParameterNode *this, char **io_rpData, unsigned int *io_rulDataSize)
{
  char **v3; // rdi
  CAkParameterNode *v4; // rbx
  char v5; // r8
  char *v6; // rax
  char v7; // cl
  char *v8; // rax
  char v9; // dl
  char v10; // cl
  signed __int64 result; // rax
  AKRESULT v12; // er8
  CAkGen3DParamsEx *v13; // rdx
  int v14; // ecx
  unsigned int v15; // ecx
  _DWORD *v16; // rax
  char v17; // cl
  AkPathMode v18; // ecx
  int v19; // ecx
  unsigned int v20; // esi
  AkPathVertex *v21; // rdx
  unsigned int v22; // er10
  signed __int64 v23; // rcx
  unsigned int v24; // ebp
  __int64 in_ulNumPlaylistItem; // r14
  AkPathListItemOffset *v26; // r9
  CAkGen3DParams *v27; // rcx
  signed __int64 v28; // r10
  __int64 v29; // rdx
  signed __int64 v30; // rax
  float v31; // xmm0_4
  float v32; // xmm1_4
  CAkGen3DParamsEx *v33; // rax
  signed __int64 v34; // rax
  CAkGen3DParamsEx *v35; // rcx
  float v36; // xmm1_4
  signed __int64 v37; // rax
  float v38; // xmm0_4
  float v39; // xmm1_4
  CAkGen3DParamsEx *v40; // rax
  signed __int64 v41; // rax
  CAkGen3DParamsEx *v42; // rcx
  float v43; // xmm1_4
  signed __int64 v44; // rdx
  signed __int64 v45; // rax
  float v46; // xmm0_4
  float v47; // xmm1_4
  CAkGen3DParamsEx *v48; // rax

  v3 = io_rpData;
  v4 = this;
  v5 = *(*io_rpData)++;
  *((_BYTE *)&this->0 + 83) &= 0xEFu;
  *((_BYTE *)&this->0 + 83) |= 16 * (v5 != 0);
  if ( !(*((_BYTE *)&this->0 + 83) & 0x10) )
    return 1i64;
  v6 = *io_rpData + 1;
  v7 = **io_rpData;
  *io_rpData = v6;
  v8 = v6 + 1;
  v9 = *(v8 - 1);
  *v3 = v8;
  if ( v7 )
  {
    v10 = *v8;
    *v3 = v8 + 1;
    *((_BYTE *)&v4->0 + 83) &= 0xDFu;
    *((_BYTE *)&v4->0 + 83) |= 32 * (v10 != 0);
    *((_BYTE *)v4 + 145) &= 0xFCu;
  }
  if ( !v9 )
    return 1i64;
  result = CAkParameterNode::Enable3DPosParams(v4);
  *((_BYTE *)v4 + 145) &= 0xFDu;
  *((_BYTE *)v4 + 145) |= 1u;
  v12 = (signed int)result;
  if ( (_DWORD)result == 1 )
  {
    v13 = v4->m_p3DParameters;
    v14 = *(_DWORD *)*v3;
    *v3 += 4;
    *((_BYTE *)v4 + 145) &= 0xF3u;
    *((_BYTE *)v4 + 145) |= 4 * (v14 & 3);
    v15 = *(_DWORD *)*v3;
    *v3 += 4;
    v13->m_Params.m_uAttenuationID = v15;
    LOBYTE(v15) = *(*v3)++;
    *((_BYTE *)&v13->m_Params + 68) &= 0xFEu;
    *((_BYTE *)&v13->m_Params + 68) |= (_BYTE)v15 != 0;
    v16 = *v3;
    if ( (*((_BYTE *)v4 + 145) & 0xC) == 4 )
    {
      v17 = *(_BYTE *)v16;
      *v3 = (char *)v16 + 1;
      *((_BYTE *)&v13->m_Params + 68) &= 0xF7u;
      *((_BYTE *)&v13->m_Params + 68) |= 8 * (v12 & (v17 != 0));
      result = (unsigned int)v12;
    }
    else
    {
      v18 = *v16;
      *v3 = (char *)(v16 + 1);
      v13->m_Params.m_ePathMode = v18;
      LOBYTE(v18) = *(*v3)++;
      *((_BYTE *)&v13->m_Params + 68) &= 0xDFu;
      *((_BYTE *)&v13->m_Params + 68) |= 32 * ((_BYTE)v18 != 0);
      v19 = *(_DWORD *)*v3;
      *v3 += 4;
      v13->m_Params.m_TransitionTime = v19;
      LOBYTE(v19) = *(*v3)++;
      *((_BYTE *)&v13->m_Params + 68) &= 0xEFu;
      v20 = 0;
      *((_BYTE *)&v13->m_Params + 68) |= 16 * ((_BYTE)v19 != 0);
      v21 = 0i64;
      v22 = *(_DWORD *)*v3;
      v23 = (signed __int64)(*v3 + 4);
      *v3 = (char *)v23;
      if ( v22 )
      {
        v21 = (AkPathVertex *)v23;
        *v3 = (char *)(v23 + 16i64 * v22);
      }
      v24 = 2;
      in_ulNumPlaylistItem = *(unsigned int *)*v3;
      v26 = (AkPathListItemOffset *)(*v3 + 4);
      *v3 = (char *)v26;
      if ( (_DWORD)in_ulNumPlaylistItem )
      {
        *v3 = (char *)&v26[in_ulNumPlaylistItem];
        if ( v22 )
        {
          v27 = (CAkGen3DParams *)&v4->m_p3DParameters->vfptr;
          if ( v27 )
            v12 = CAkGen3DParams::SetPath(v27, v21, v22, v26, in_ulNumPlaylistItem);
          else
            v12 = 2;
        }
      }
      v28 = 0i64;
      if ( (signed int)in_ulNumPlaylistItem >= 4 )
      {
        v29 = 0i64;
        v28 = 4i64 * (((unsigned int)(in_ulNumPlaylistItem - 4) >> 2) + 1);
        do
        {
          v30 = (signed __int64)(*v3 + 8);
          *v3 = (char *)v30;
          v31 = *(float *)(v30 - 8);
          v32 = *(float *)(v30 - 4);
          v33 = v4->m_p3DParameters;
          if ( v33 && v20 < v33->m_Params.m_ulNumPlaylistItem )
          {
            v33->m_Params.m_pArrayPlaylist[v29].fRangeX = v31;
            v4->m_p3DParameters->m_Params.m_pArrayPlaylist[v29].fRangeY = v32;
          }
          v34 = (signed __int64)(*v3 + 8);
          *v3 = (char *)v34;
          v35 = v4->m_p3DParameters;
          v36 = *(float *)(v34 - 4);
          if ( v35 && v24 - 1 < v35->m_Params.m_ulNumPlaylistItem )
          {
            v35->m_Params.m_pArrayPlaylist[v29 + 1].fRangeX = *(float *)(v34 - 8);
            v4->m_p3DParameters->m_Params.m_pArrayPlaylist[v29 + 1].fRangeY = v36;
          }
          v37 = (signed __int64)(*v3 + 8);
          *v3 = (char *)v37;
          v38 = *(float *)(v37 - 8);
          v39 = *(float *)(v37 - 4);
          v40 = v4->m_p3DParameters;
          if ( v40 && v24 < v40->m_Params.m_ulNumPlaylistItem )
          {
            v40->m_Params.m_pArrayPlaylist[v29 + 2].fRangeX = v38;
            v4->m_p3DParameters->m_Params.m_pArrayPlaylist[v29 + 2].fRangeY = v39;
          }
          v41 = (signed __int64)(*v3 + 8);
          *v3 = (char *)v41;
          v42 = v4->m_p3DParameters;
          v43 = *(float *)(v41 - 4);
          if ( v42 && v24 + 1 < v42->m_Params.m_ulNumPlaylistItem )
          {
            v42->m_Params.m_pArrayPlaylist[v29 + 3].fRangeX = *(float *)(v41 - 8);
            v4->m_p3DParameters->m_Params.m_pArrayPlaylist[v29 + 3].fRangeY = v43;
          }
          v20 += 4;
          v29 += 4i64;
          v24 += 4;
        }
        while ( v20 < (signed int)in_ulNumPlaylistItem - 3 );
      }
      if ( v20 < (unsigned int)in_ulNumPlaylistItem )
      {
        v44 = v28;
        do
        {
          v45 = (signed __int64)(*v3 + 8);
          *v3 = (char *)v45;
          v46 = *(float *)(v45 - 8);
          v47 = *(float *)(v45 - 4);
          v48 = v4->m_p3DParameters;
          if ( v48 )
          {
            if ( v20 < v48->m_Params.m_ulNumPlaylistItem )
            {
              v48->m_Params.m_pArrayPlaylist[v44].fRangeX = v46;
              v4->m_p3DParameters->m_Params.m_pArrayPlaylist[v44].fRangeY = v47;
            }
          }
          ++v20;
          ++v44;
        }
        while ( v20 < (unsigned int)in_ulNumPlaylistItem );
      }
      result = (unsigned int)v12;
    }
  }
  return result;
}

// File Line: 1379
// RVA: 0xA6EC00
signed __int64 __fastcall CAkParameterNode::SetAuxParams(CAkParameterNode *this, char **io_rpData, unsigned int *io_rulDataSize)
{
  CAkParameterNode *v3; // rsi
  char **v4; // rdi
  char v5; // r8
  char v6; // cl
  char v7; // cl
  char v8; // cl
  bool v9; // bp
  signed int v10; // ebx
  unsigned int v11; // edx
  signed __int64 result; // rax

  v3 = this;
  v4 = io_rpData;
  v5 = *(*io_rpData)++;
  *((_BYTE *)this + 145) &= 0xEFu;
  *((_BYTE *)this + 145) |= 16 * (v5 != 0);
  v6 = *(*io_rpData)++;
  *((_BYTE *)v3 + 145) &= 0xDFu;
  *((_BYTE *)v3 + 145) |= 32 * (v6 != 0);
  v7 = *(*io_rpData)++;
  *((_BYTE *)v3 + 145) &= 0xBFu;
  *((_BYTE *)v3 + 145) |= (v7 != 0) << 6;
  v8 = *(*io_rpData)++;
  v9 = v8 != 0;
  v10 = 0;
  do
  {
    v11 = 0;
    if ( v9 )
    {
      v11 = *(_DWORD *)*v4;
      *v4 += 4;
    }
    result = CAkParameterNode::SetAuxBusSend(v3, v11, v10);
    if ( (_DWORD)result != 1 )
      break;
    ++v10;
  }
  while ( v10 < 4 );
  return result;
}

// File Line: 1403
// RVA: 0xA6E520
signed __int64 __fastcall CAkParameterNode::SetAdvSettingsParams(CAkParameterNode *this, char **io_rpData, unsigned int *io_rulDataSize)
{
  CAkParameterNode *v3; // r14
  char v4; // r10
  char *v5; // rax
  char v6; // r9
  char v7; // bp
  unsigned __int16 v8; // r8
  char v9; // cl
  char v10; // si
  char *v11; // rax
  char v12; // bl
  char v13; // di
  char v14; // cl
  char v15; // cl
  char v16; // cl
  char v17; // cl

  v3 = this;
  v4 = **io_rpData;
  v5 = *io_rpData + 1;
  *io_rpData = v5;
  v6 = *v5++;
  *io_rpData = v5;
  v7 = *v5++;
  *io_rpData = v5;
  v8 = *(_WORD *)v5;
  *io_rpData = v5 + 2;
  this->m_u16MaxNumInstance = v8;
  v9 = *(*io_rpData)++;
  *((_BYTE *)&v3->0 + 82) &= 0xEFu;
  *((_BYTE *)&v3->0 + 82) |= 16 * (v9 != 0);
  v10 = **io_rpData;
  v11 = *io_rpData + 1;
  *io_rpData = v11;
  v12 = *v11++;
  *io_rpData = v11;
  v13 = *v11++;
  *io_rpData = v11;
  v14 = *v11;
  *io_rpData = v11 + 1;
  *((_BYTE *)v3 + 145) &= 0x7Fu;
  *((_BYTE *)v3 + 145) |= v14 << 7;
  v15 = *(*io_rpData)++;
  *((_BYTE *)v3 + 146) &= 0xFEu;
  *((_BYTE *)v3 + 146) |= v15 & 1;
  v16 = *(*io_rpData)++;
  *((_BYTE *)v3 + 146) &= 0xFDu;
  *((_BYTE *)v3 + 146) |= 2 * (v16 & 1);
  v17 = *(*io_rpData)++;
  *((_BYTE *)v3 + 146) &= 0xFBu;
  *((_BYTE *)v3 + 144) &= 0xF8u;
  *((_BYTE *)v3 + 144) |= v4 & 7;
  *((_BYTE *)v3 + 146) |= 4 * (v17 & 1);
  CAkParameterNodeBase::SetMaxReachedBehavior((CAkParameterNodeBase *)&v3->vfptr, v6 != 0);
  CAkParameterNodeBase::SetOverLimitBehavior((CAkParameterNodeBase *)&v3->vfptr, v7 != 0);
  *((_BYTE *)v3 + 144) ^= (*((_BYTE *)v3 + 144) ^ 8 * v10) & 0x78;
  CAkParameterNodeBase::SetMaxNumInstOverrideParent((CAkParameterNodeBase *)&v3->vfptr, v12 != 0);
  CAkParameterNodeBase::SetVVoicesOptOverrideParent((CAkParameterNodeBase *)&v3->vfptr, v13 != 0);
  return 1i64;
}

// File Line: 1436
// RVA: 0xA6D320
void __fastcall CAkParameterNode::GetFX(CAkParameterNode *this, unsigned int in_uFXIndex, AkFXDesc *out_rFXInfo, CAkRegisteredObj *in_GameObj)
{
  CAkRegisteredObj *v4; // rbp
  AkFXDesc *v5; // rbx
  __int64 v6; // rsi
  CAkParameterNode *v7; // rdi
  CAkParameterNodeBase *v8; // rcx
  CAkParameterNodeBase::FXChunk *v9; // rcx
  unsigned int v10; // edx
  CAkIndexable *v11; // rax
  CAkFxBase *v12; // rcx
  CAkFxBase *v13; // rcx

  v4 = in_GameObj;
  v5 = out_rFXInfo;
  v6 = in_uFXIndex;
  v7 = this;
  if ( *((_BYTE *)&this->0 + 83) & 0x40 || (v8 = this->m_pParentNode) == 0i64 )
  {
    v9 = v7->m_pFXChunk;
    if ( v9 )
    {
      v10 = v9->aFX[in_uFXIndex].id;
      if ( v10 )
      {
        if ( v9->aFX[v6].bShareSet )
          v11 = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(&g_pIndex->m_idxFxShareSets, v10);
        else
          v11 = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                  (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxFxCustom,
                  v10);
        v12 = v5->pFx.m_pT;
        v5->pFx.m_pT = (CAkFxBase *)v11;
      }
      else
      {
        v12 = out_rFXInfo->pFx.m_pT;
        out_rFXInfo->pFx.m_pT = 0i64;
      }
      if ( v12 )
        ((void (*)(void))v12->vfptr->Release)();
      v5->bIsBypassed = CAkParameterNode::GetBypassFX(v7, v6, v4);
    }
    else
    {
      v13 = out_rFXInfo->pFx.m_pT;
      out_rFXInfo->pFx.m_pT = 0i64;
      if ( v13 )
        ((void (*)(void))v13->vfptr->Release)();
      v5->bIsBypassed = 0;
    }
  }
  else
  {
    v8->vfptr[14].__vecDelDtor((CAkIndexable *)&v8->vfptr, in_uFXIndex);
  }
}

// File Line: 1475
// RVA: 0xA6D400
void __fastcall CAkParameterNode::GetFXDataID(CAkParameterNode *this, unsigned int in_uFXIndex, unsigned int in_uDataIndex, unsigned int *out_rDataID)
{
  unsigned int *v4; // rdi
  unsigned int v5; // ebx
  __int64 v6; // r11
  CAkParameterNodeBase *v7; // r10
  CAkParameterNodeBase::FXChunk *v8; // rdx
  bool v9; // zf
  unsigned int v10; // edx
  CAkIndexable *v11; // rax
  unsigned int *v12; // rdx
  _DWORD *v13; // rax
  signed __int64 v14; // rcx
  unsigned int *v15; // rax
  unsigned int v16; // ecx

  v4 = out_rDataID;
  v5 = in_uDataIndex;
  v6 = in_uFXIndex;
  if ( *((_BYTE *)&this->0 + 83) & 0x40 || (v7 = this->m_pParentNode) == 0i64 )
  {
    *out_rDataID = -1;
    v8 = this->m_pFXChunk;
    if ( v8 )
    {
      v9 = v8->aFX[v6].bShareSet == 0;
      v10 = v8->aFX[v6].id;
      v11 = v9 ? CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                   (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxFxCustom,
                   v10) : CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(&g_pIndex->m_idxFxShareSets, v10);
      v12 = (unsigned int *)v11;
      if ( v11 )
      {
        v13 = *(_DWORD **)&v11[1].key;
        v14 = (signed __int64)&v13[2 * v12[12]];
        if ( v13 == (_DWORD *)v14 )
          goto LABEL_19;
        do
        {
          if ( *v13 == v5 )
            break;
          v13 += 2;
        }
        while ( v13 != (_DWORD *)v14 );
        if ( v13 != (_DWORD *)v14 && (v15 = v13 + 1) != 0i64 )
          v16 = *v15;
        else
LABEL_19:
          v16 = 0;
        *v4 = v16;
        (*(void (__fastcall **)(unsigned int *))(*(_QWORD *)v12 + 16i64))(v12);
      }
    }
  }
  else
  {
    ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD))v7->vfptr[14].AddRef)(this->m_pParentNode, in_uFXIndex);
  }
}

// File Line: 1508
// RVA: 0xA6D0E0
bool __fastcall CAkParameterNode::GetBypassFX(CAkParameterNode *this, unsigned int in_uFXIndex, CAkRegisteredObj *in_GameObjPtr)
{
  CAkParameterNodeBase::FXChunk *v3; // r9
  CAkParameterNode *v4; // r10
  unsigned __int64 v5; // rax
  CAkSIS *v6; // rax
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *v7; // rcx
  CAkRegisteredObj **v8; // rax
  signed __int64 v9; // rcx
  CAkSIS **v10; // rax

  v3 = this->m_pFXChunk;
  v4 = this;
  if ( !v3 )
    goto LABEL_6;
  if ( v3->aFX[in_uFXIndex].id )
  {
    v5 = this->m_RTPCBitArray.m_iBitArray;
    if ( _bittest64((const signed __int64 *)&v5, (unsigned __int8)(in_uFXIndex + 24)) )
    {
      if ( CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, in_uFXIndex + 24, in_GameObjPtr) != 0.0 )
      {
        LOBYTE(v6) = 1;
        return (char)v6;
      }
LABEL_6:
      LOBYTE(v6) = 0;
      return (char)v6;
    }
  }
  v7 = this->m_pMapSIS;
  if ( !v7 )
    goto LABEL_20;
  v8 = &v7->m_pItems->key;
  v9 = (signed __int64)&v7->m_pItems[v7->m_uLength];
  if ( v8 == (CAkRegisteredObj **)v9 )
    goto LABEL_20;
  do
  {
    if ( *v8 == in_GameObjPtr )
      break;
    v8 += 2;
  }
  while ( v8 != (CAkRegisteredObj **)v9 );
  if ( v8 != (CAkRegisteredObj **)v9 && (v10 = (CAkSIS **)(v8 + 1)) != 0i64 )
  {
    v6 = *v10;
  }
  else
  {
LABEL_20:
    v6 = v4->m_pGlobalSIS;
    if ( !v6 )
      return ((unsigned __int8)v3->bitsMainFXBypass >> in_uFXIndex) & 1;
  }
  LOBYTE(v6) = ((unsigned __int8)v6->m_bitsFXBypass >> in_uFXIndex) & 1;
  return (char)v6;
}

// File Line: 1547
// RVA: 0xA6CFF0
__int64 __fastcall CAkParameterNode::GetBypassAllFX(CAkParameterNode *this, CAkRegisteredObj *in_GameObjPtr)
{
  CAkRegisteredObj *v2; // r8
  CAkParameterNode *v3; // r10
  CAkParameterNodeBase *v4; // rcx
  __int64 result; // rax
  unsigned __int8 v6; // dl
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *v7; // rcx
  CAkRegisteredObj **v8; // rax
  signed __int64 v9; // rcx
  signed __int64 v10; // rax
  CAkSIS *v11; // rax

  v2 = in_GameObjPtr;
  v3 = this;
  if ( !(*((_BYTE *)&this->0 + 83) & 0x40) )
  {
    v4 = this->m_pParentNode;
    if ( v4 )
      return ((__int64 (__fastcall *)(CAkParameterNodeBase *, CAkRegisteredObj *, CAkRegisteredObj *))v4->vfptr[14].Release)(
               v4,
               in_GameObjPtr,
               in_GameObjPtr);
  }
  result = (__int64)v3->m_pFXChunk;
  if ( result )
  {
    v6 = (*(_BYTE *)(result + 32) >> 4) & 1;
    if ( ((unsigned __int64)LODWORD(v3->m_RTPCBitArray.m_iBitArray) >> 28) & 1 )
    {
      result = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v3, 0x1Cu, v2) != 0.0;
    }
    else
    {
      v7 = v3->m_pMapSIS;
      if ( !v7 )
        goto LABEL_19;
      v8 = &v7->m_pItems->key;
      v9 = (signed __int64)&v7->m_pItems[v7->m_uLength];
      if ( v8 == (CAkRegisteredObj **)v9 )
        goto LABEL_19;
      do
      {
        if ( *v8 == v2 )
          break;
        v8 += 2;
      }
      while ( v8 != (CAkRegisteredObj **)v9 );
      if ( v8 != (CAkRegisteredObj **)v9 && (v10 = (signed __int64)(v8 + 1)) != 0 )
      {
        result = (*(_BYTE *)(*(_QWORD *)v10 + 32i64) >> 4) & 1;
      }
      else
      {
LABEL_19:
        v11 = v3->m_pGlobalSIS;
        if ( v11 )
          v6 = ((unsigned __int8)v11->m_bitsFXBypass >> 4) & 1;
        result = v6;
      }
    }
  }
  return result;
}

// File Line: 1589
// RVA: 0xA6E370
void __fastcall CAkParameterNode::ResetFXBypass(CAkParameterNode *this, unsigned int in_bitsFXBypass, unsigned int in_uTargetMask)
{
  CAkParameterNode *v3; // r11
  CAkSIS *v4; // rcx
  char v5; // bl
  char v6; // r10
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *v7; // rdx
  MapStruct<CAkRegisteredObj *,CAkSIS *> *v8; // rax
  char v9; // r8
  char v10; // r10
  CAkSIS *v11; // rdx

  v3 = this;
  v4 = this->m_pGlobalSIS;
  v5 = in_uTargetMask;
  v6 = in_bitsFXBypass;
  if ( v4 )
    v4->m_bitsFXBypass = in_uTargetMask & in_bitsFXBypass | v4->m_bitsFXBypass & ~(_BYTE)in_uTargetMask;
  v7 = v3->m_pMapSIS;
  if ( v7 )
  {
    v8 = v7->m_pItems;
    if ( v7->m_pItems != &v7->m_pItems[v7->m_uLength] )
    {
      v9 = ~(_BYTE)in_uTargetMask;
      v10 = v5 & v6;
      do
      {
        v11 = v8->item;
        ++v8;
        v11->m_bitsFXBypass = v10 | v9 & v11->m_bitsFXBypass;
      }
      while ( v8 != &v3->m_pMapSIS->m_pItems[v3->m_pMapSIS->m_uLength] );
    }
  }
}

// File Line: 1605
// RVA: 0xA6B850
signed __int64 __fastcall CAkParameterNode::AssociateLayer(CAkParameterNode *this, CAkLayer *in_pLayer)
{
  ITransitionable *v2; // rdi
  CAkParameterNode *v3; // rbx
  AkArray<CAkLayer *,CAkLayer *,ArrayPoolDefault,4,AkArrayAllocatorDefault> *v4; // rax
  AkArray<ITransitionable *,ITransitionable *,ArrayPoolDefault,4,AkArrayAllocatorDefault> *v5; // rcx
  signed __int64 result; // rax
  AkArray<CAkLayer *,CAkLayer *,ArrayPoolDefault,4,AkArrayAllocatorDefault> *v7; // rdx

  v2 = (ITransitionable *)in_pLayer;
  v3 = this;
  if ( !this->m_pAssociatedLayers )
  {
    v4 = (AkArray<CAkLayer *,CAkLayer *,ArrayPoolDefault,4,AkArrayAllocatorDefault> *)AK::MemoryMgr::Malloc(
                                                                                        g_DefaultPoolId,
                                                                                        0x10ui64);
    v3->m_pAssociatedLayers = v4;
    if ( v4 )
    {
      v4->m_pItems = 0i64;
      *(_QWORD *)&v4->m_uLength = 0i64;
    }
  }
  v5 = (AkArray<ITransitionable *,ITransitionable *,ArrayPoolDefault,4,AkArrayAllocatorDefault> *)v3->m_pAssociatedLayers;
  if ( v5 && AkArray<CAkPBI *,CAkPBI *,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast(v5, v2) )
  {
    v3->vfptr[12].Category((CAkIndexable *)&v3->vfptr);
    result = 1i64;
  }
  else
  {
    v7 = v3->m_pAssociatedLayers;
    if ( v7 )
    {
      if ( !v7->m_uLength )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, v7);
        v3->m_pAssociatedLayers = 0i64;
      }
    }
    result = 52i64;
  }
  return result;
}

// File Line: 1627
// RVA: 0xA6BEE0
signed __int64 __fastcall CAkParameterNode::DissociateLayer(CAkParameterNode *this, CAkLayer *in_pLayer)
{
  AkArray<CAkLayer *,CAkLayer *,ArrayPoolDefault,4,AkArrayAllocatorDefault> *v2; // r8
  CAkLayer **v3; // rdi
  signed __int64 v4; // rax

  v2 = this->m_pAssociatedLayers;
  if ( !v2 )
    return 2i64;
  v3 = v2->m_pItems;
  v4 = (signed __int64)&v2->m_pItems[v2->m_uLength];
  if ( v2->m_pItems == (CAkLayer **)v4 )
    return 2i64;
  do
  {
    if ( *v3 == in_pLayer )
      break;
    ++v3;
  }
  while ( v3 != (CAkLayer **)v4 );
  if ( v3 == (CAkLayer **)v4 )
    return 2i64;
  if ( (unsigned __int64)v3 < v4 - 8 )
    qmemcpy(v3, v3 + 1, 8 * (((unsigned __int64)(v4 - 8 - (_QWORD)v3 - 1) >> 3) + 1));
  --v2->m_uLength;
  this->vfptr[12].Category((CAkIndexable *)this);
  return 1i64;
}

// File Line: 1659
// RVA: 0xA6DAA0
__int64 __fastcall CAkParameterNode::IncrementPlayCount(CAkParameterNode *this, CounterParameters *io_params)
{
  CounterParameters *v2; // rdi
  CAkParameterNode *v3; // rsi
  AKRESULT v4; // eax
  unsigned int v5; // ebx
  AkActivityChunk *v6; // rax
  AKRESULT v7; // eax
  unsigned __int16 v8; // ax
  bool v9; // bp
  unsigned int v10; // eax
  unsigned __int16 v11; // cx
  CAkParameterNodeBase::AkFeedbackInfo *v12; // rax
  unsigned int v13; // eax
  unsigned int v14; // eax

  v2 = io_params;
  v3 = this;
  v4 = CAkParameterNodeBase::IncrementPlayCountValue(
         (CAkParameterNodeBase *)&this->vfptr,
         io_params->uiFlagForwardToBus);
  v5 = v4;
  if ( *((_BYTE *)&v3->0 + 82) & 8 || !v3->m_pParentNode )
  {
    if ( !v2->bMaxConsidered && v4 == 1 )
    {
      v6 = v3->m_pActivityChunk;
      if ( !v6 || *((_BYTE *)v6 + 80) & 1 )
        v7 = CAkParameterNodeBase::IncrementPlayCountGlobal(
               (CAkParameterNodeBase *)&v3->vfptr,
               v2->fPriority,
               &v2->ui16NumKicked,
               &v2->pAMLimiter);
      else
        v7 = CAkParameterNodeBase::IncrementPlayCountGameObject(
               (CAkParameterNodeBase *)&v3->vfptr,
               v2->fPriority,
               &v2->ui16NumKicked,
               v2->pGameObj,
               &v2->pAMLimiter);
      v5 = v7;
    }
    v2->bMaxConsidered = 1;
  }
  v8 = v2->uiFlagForwardToBus;
  v9 = v2->bMaxConsidered;
  if ( v8 & 1 )
  {
    if ( v3->m_pBusOutputNode )
    {
      v2->bMaxConsidered = 0;
      v2->uiFlagForwardToBus = v8 & 0xFFFE;
      v10 = ((__int64 (__fastcall *)(CAkParameterNodeBase *, CounterParameters *))v3->m_pBusOutputNode->vfptr[8].Release)(
              v3->m_pBusOutputNode,
              v2);
      if ( v10 != 1 )
      {
        if ( v10 == 80 )
        {
          if ( v5 == 1 )
            v5 = 80;
        }
        else
        {
          v5 = v10;
        }
      }
    }
  }
  v11 = v2->uiFlagForwardToBus;
  if ( v11 & 2 )
  {
    v12 = v3->m_pFeedbackInfo;
    if ( v12 )
    {
      if ( v12->m_pFeedbackBus )
      {
        v2->bMaxConsidered = 0;
        v2->uiFlagForwardToBus = v11 & 0xFFFD;
        v13 = ((__int64 (__fastcall *)(CAkFeedbackBus *, CounterParameters *))v3->m_pFeedbackInfo->m_pFeedbackBus->vfptr[8].Release)(
                v3->m_pFeedbackInfo->m_pFeedbackBus,
                v2);
        if ( v13 != 1 )
        {
          if ( v13 == 80 )
          {
            if ( v5 == 1 )
              v5 = 80;
          }
          else
          {
            v5 = v13;
          }
        }
      }
    }
  }
  if ( v3->m_pParentNode )
  {
    v2->bMaxConsidered = v9;
    v14 = ((__int64 (__fastcall *)(CAkParameterNodeBase *, CounterParameters *))v3->m_pParentNode->vfptr[8].Release)(
            v3->m_pParentNode,
            v2);
    if ( v14 != 1 )
    {
      if ( v14 == 80 )
      {
        if ( v5 == 1 )
          v5 = 80;
      }
      else
      {
        v5 = v14;
      }
    }
  }
  return v5;
}

// File Line: 1724
// RVA: 0xA6BB20
void __fastcall CAkParameterNode::DecrementPlayCount(CAkParameterNode *this, CounterParameters *io_params)
{
  CounterParameters *v2; // rdi
  CAkParameterNode *v3; // rbx
  AkActivityChunk *v4; // rax
  unsigned __int16 v5; // ax
  bool v6; // si
  unsigned __int16 v7; // ax
  CAkParameterNodeBase::AkFeedbackInfo *v8; // rcx

  v2 = io_params;
  v3 = this;
  CAkParameterNodeBase::DecrementPlayCountValue((CAkParameterNodeBase *)&this->vfptr);
  if ( *((_BYTE *)&v3->0 + 82) & 8 || !v3->m_pParentNode )
  {
    if ( !v2->bMaxConsidered )
    {
      v4 = v3->m_pActivityChunk;
      if ( v4 )
      {
        if ( *((_BYTE *)v4 + 80) & 1 )
          CAkParameterNodeBase::DecrementPlayCountGlobal((CAkParameterNodeBase *)&v3->vfptr);
        else
          CAkParameterNodeBase::DecrementPlayCountGameObject((CAkParameterNodeBase *)&v3->vfptr, v2->pGameObj);
      }
    }
    v2->bMaxConsidered = 1;
  }
  v5 = v2->uiFlagForwardToBus;
  v6 = v2->bMaxConsidered;
  if ( v5 & 1 && v3->m_pBusOutputNode )
  {
    v2->bMaxConsidered = 0;
    v2->uiFlagForwardToBus = v5 & 0xFFFE;
    ((void (__fastcall *)(CAkParameterNodeBase *, CounterParameters *))v3->m_pBusOutputNode->vfptr[8].Category)(
      v3->m_pBusOutputNode,
      v2);
  }
  v7 = v2->uiFlagForwardToBus;
  if ( v7 & 2 )
  {
    v8 = v3->m_pFeedbackInfo;
    if ( v8 )
    {
      if ( v8->m_pFeedbackBus )
      {
        v2->bMaxConsidered = 0;
        v2->uiFlagForwardToBus = v7 & 0xFFFD;
        ((void (__fastcall *)(CAkFeedbackBus *, CounterParameters *))v3->m_pFeedbackInfo->m_pFeedbackBus->vfptr[8].Category)(
          v3->m_pFeedbackInfo->m_pFeedbackBus,
          v2);
      }
    }
  }
  if ( v3->m_pParentNode )
  {
    v2->bMaxConsidered = v6;
    ((void (__fastcall *)(CAkParameterNodeBase *, CounterParameters *))v3->m_pParentNode->vfptr[8].Category)(
      v3->m_pParentNode,
      v2);
  }
}

// File Line: 1779
// RVA: 0xA6DC20
void __fastcall CAkParameterNode::IncrementVirtualCount(CAkParameterNode *this, CounterParameters *io_params)
{
  CounterParameters *v2; // rbx
  CAkParameterNode *v3; // rdi
  AkActivityChunk *v4; // rcx
  unsigned __int16 v5; // ax
  bool v6; // si
  unsigned __int16 v7; // ax
  CAkParameterNodeBase::AkFeedbackInfo *v8; // rcx

  v2 = io_params;
  v3 = this;
  if ( (*((_BYTE *)&this->0 + 82) & 8 || !this->m_pParentNode) && !io_params->bMaxConsidered )
  {
    v4 = this->m_pActivityChunk;
    if ( v4 )
    {
      if ( *((_BYTE *)v4 + 80) & 1 )
      {
        if ( v4 )
          ++v4->m_iVirtualCountValid;
      }
      else
      {
        CAkParameterNodeBase::IncrementVirtualCountGameObject((CAkParameterNodeBase *)&v3->vfptr, io_params->pGameObj);
      }
    }
    v2->bMaxConsidered = 1;
  }
  v5 = v2->uiFlagForwardToBus;
  v6 = v2->bMaxConsidered;
  if ( v5 & 1 && v3->m_pBusOutputNode )
  {
    v2->bMaxConsidered = 0;
    v2->uiFlagForwardToBus = v5 & 0xFFFE;
    v3->m_pBusOutputNode->vfptr[9].__vecDelDtor((CAkIndexable *)&v3->m_pBusOutputNode->vfptr, (unsigned int)v2);
  }
  v7 = v2->uiFlagForwardToBus;
  if ( v7 & 2 )
  {
    v8 = v3->m_pFeedbackInfo;
    if ( v8 )
    {
      if ( v8->m_pFeedbackBus )
      {
        v2->bMaxConsidered = 0;
        v2->uiFlagForwardToBus = v7 & 0xFFFD;
        v3->m_pFeedbackInfo->m_pFeedbackBus->vfptr[9].__vecDelDtor(
          (CAkIndexable *)v3->m_pFeedbackInfo->m_pFeedbackBus,
          (unsigned int)v2);
      }
    }
  }
  if ( v3->m_pParentNode )
  {
    v2->bMaxConsidered = v6;
    v3->m_pParentNode->vfptr[9].__vecDelDtor((CAkIndexable *)&v3->m_pParentNode->vfptr, (unsigned int)v2);
  }
}

// File Line: 1834
// RVA: 0xA6BC10
void __fastcall CAkParameterNode::DecrementVirtualCount(CAkParameterNode *this, CounterParameters *io_params)
{
  CounterParameters *v2; // rbx
  CAkParameterNode *v3; // rdi
  AkActivityChunk *v4; // rax
  bool v5; // r8
  unsigned __int16 *v6; // rdx
  unsigned __int16 v7; // ax
  bool v8; // si
  unsigned __int16 v9; // ax
  CAkParameterNodeBase::AkFeedbackInfo *v10; // rcx

  v2 = io_params;
  v3 = this;
  if ( *((_BYTE *)&this->0 + 82) & 8 || !this->m_pParentNode )
  {
    if ( !io_params->bMaxConsidered )
    {
      v4 = this->m_pActivityChunk;
      if ( v4 )
      {
        v5 = io_params->bAllowKick;
        v6 = &io_params->ui16NumKicked;
        if ( *((_BYTE *)v4 + 80) & 1 )
          CAkParameterNodeBase::DecrementVirtualCountGlobal((CAkParameterNodeBase *)&this->vfptr, v6, v5);
        else
          CAkParameterNodeBase::DecrementVirtualCountGameObject(
            (CAkParameterNodeBase *)&this->vfptr,
            v6,
            v5,
            v2->pGameObj);
      }
    }
    v2->bMaxConsidered = 1;
  }
  v7 = v2->uiFlagForwardToBus;
  v8 = v2->bMaxConsidered;
  if ( v7 & 1 && v3->m_pBusOutputNode )
  {
    v2->bMaxConsidered = 0;
    v2->uiFlagForwardToBus = v7 & 0xFFFE;
    ((void (__fastcall *)(CAkParameterNodeBase *, CounterParameters *))v3->m_pBusOutputNode->vfptr[9].AddRef)(
      v3->m_pBusOutputNode,
      v2);
  }
  v9 = v2->uiFlagForwardToBus;
  if ( v9 & 2 )
  {
    v10 = v3->m_pFeedbackInfo;
    if ( v10 )
    {
      if ( v10->m_pFeedbackBus )
      {
        v2->bMaxConsidered = 0;
        v2->uiFlagForwardToBus = v9 & 0xFFFD;
        ((void (__fastcall *)(CAkFeedbackBus *, CounterParameters *))v3->m_pFeedbackInfo->m_pFeedbackBus->vfptr[9].AddRef)(
          v3->m_pFeedbackInfo->m_pFeedbackBus,
          v2);
      }
    }
  }
  if ( v3->m_pParentNode )
  {
    v2->bMaxConsidered = v8;
    ((void (__fastcall *)(CAkParameterNodeBase *, CounterParameters *))v3->m_pParentNode->vfptr[9].AddRef)(
      v3->m_pParentNode,
      v2);
  }
}

// File Line: 1885
// RVA: 0xA6B6A0
void __fastcall CAkParameterNode::ApplyMaxNumInstances(CAkParameterNode *this, unsigned __int16 in_u16MaxNumInstance, CAkRegisteredObj *in_pGameObj, void *in_pExceptArray, bool in_bFromRTPC)
{
  unsigned __int16 v5; // bx
  CAkParameterNode *v6; // r11
  AkActivityChunk *v7; // r10
  char v8; // al
  StructMaxInst *v9; // rax
  CAkLimiter *v10; // rax
  MapStruct<CAkRegisteredObj *,StructMaxInst> *v11; // rax
  CAkLimiter *v12; // rcx
  MapStruct<CAkRegisteredObj *,StructMaxInst> *v13; // rcx
  CAkRegisteredObj **v14; // rax
  signed __int64 v15; // r8
  CAkLimiter *v16; // rax
  AkActivityChunk *v17; // r8
  MapStruct<CAkRegisteredObj *,StructMaxInst> *v18; // rax
  CAkLimiter *v19; // rcx

  v5 = in_u16MaxNumInstance;
  v6 = this;
  if ( in_bFromRTPC )
  {
    v7 = this->m_pActivityChunk;
    if ( v7 )
    {
      v8 = *((_BYTE *)v7 + 80);
      if ( in_pGameObj )
      {
        if ( !(v8 & 1) && (*((_BYTE *)&this->0 + 82) & 8 || !this->m_pParentNode) )
        {
          v9 = CAkKeyArray<CAkRegisteredObj *,StructMaxInst,2>::Exists(
                 &this->m_pActivityChunk->m_ListPlayCountPerObj,
                 in_pGameObj);
          if ( v9 )
          {
            v10 = v9->m_pLimiter;
            if ( v10 )
              v10->m_u16LimiterMax = v5;
          }
        }
      }
      else if ( v8 & 1 )
      {
        v7->m_Limiter.m_u16LimiterMax = in_u16MaxNumInstance;
      }
      else if ( in_pExceptArray )
      {
        v13 = v7->m_ListPlayCountPerObj.m_pItems;
        if ( v7->m_ListPlayCountPerObj.m_pItems != &v7->m_ListPlayCountPerObj.m_pItems[v7->m_ListPlayCountPerObj.m_uLength] )
        {
          do
          {
            v14 = *(CAkRegisteredObj ***)in_pExceptArray;
            v15 = *(_QWORD *)in_pExceptArray + 8i64 * *((unsigned int *)in_pExceptArray + 2);
            if ( *(_QWORD *)in_pExceptArray == v15 )
            {
LABEL_22:
              v16 = v13->item.m_pLimiter;
              if ( v16 )
                v16->m_u16LimiterMax = in_u16MaxNumInstance;
            }
            else
            {
              while ( *v14 != v13->key )
              {
                ++v14;
                if ( v14 == (CAkRegisteredObj **)v15 )
                  goto LABEL_22;
              }
            }
            ++v13;
          }
          while ( v13 != &v6->m_pActivityChunk->m_ListPlayCountPerObj.m_pItems[v6->m_pActivityChunk->m_ListPlayCountPerObj.m_uLength] );
        }
      }
      else
      {
        v11 = v7->m_ListPlayCountPerObj.m_pItems;
        if ( v7->m_ListPlayCountPerObj.m_pItems != &v7->m_ListPlayCountPerObj.m_pItems[v7->m_ListPlayCountPerObj.m_uLength] )
        {
          do
          {
            v12 = v11->item.m_pLimiter;
            if ( v12 )
              v12->m_u16LimiterMax = in_u16MaxNumInstance;
            ++v11;
          }
          while ( v11 != &v6->m_pActivityChunk->m_ListPlayCountPerObj.m_pItems[v6->m_pActivityChunk->m_ListPlayCountPerObj.m_uLength] );
        }
      }
    }
  }
  else
  {
    v17 = this->m_pActivityChunk;
    if ( v17 )
    {
      if ( *((_BYTE *)v17 + 80) & 1 )
      {
        v17->m_Limiter.m_u16LimiterMax = in_u16MaxNumInstance;
        this->m_u16MaxNumInstance = in_u16MaxNumInstance;
        return;
      }
      v18 = v17->m_ListPlayCountPerObj.m_pItems;
      if ( v17->m_ListPlayCountPerObj.m_pItems != &v17->m_ListPlayCountPerObj.m_pItems[v17->m_ListPlayCountPerObj.m_uLength] )
      {
        do
        {
          v19 = v18->item.m_pLimiter;
          if ( v19 )
            v19->m_u16LimiterMax = in_u16MaxNumInstance;
          ++v18;
        }
        while ( v18 != &v6->m_pActivityChunk->m_ListPlayCountPerObj.m_pItems[v6->m_pActivityChunk->m_ListPlayCountPerObj.m_uLength] );
      }
    }
    v6->m_u16MaxNumInstance = in_u16MaxNumInstance;
  }
}

// File Line: 1972
// RVA: 0xA6DD10
bool __fastcall CAkParameterNode::IsOrIsChildOf(CAkParameterNode *this, CAkParameterNodeBase *in_pNodeToTest, bool __formal)
{
  CAkParameterNodeBase *v3; // rdi
  bool result; // al
  CAkParameterNode *v5; // rbx
  char v6; // dl
  CAkBus *v7; // rcx

  v3 = in_pNodeToTest;
  result = 0;
  v5 = this;
  v6 = 0;
  do
  {
    if ( !v5 )
      break;
    result = v3 == (CAkParameterNodeBase *)v5;
    if ( v3 != (CAkParameterNodeBase *)v5 && !v6 )
    {
      v7 = (CAkBus *)v5->m_pBusOutputNode;
      if ( v7 )
      {
        result = CAkBus::IsOrIsChildOf(v7, v3);
        v6 = 1;
      }
    }
    v5 = (CAkParameterNode *)v5->m_pParentNode;
  }
  while ( !result );
  return result;
}

// File Line: 1999
// RVA: 0xA6D6A0
AkPathState *__fastcall CAkParameterNode::GetPathState(CAkParameterNode *this)
{
  if ( this->m_p3DParameters )
    return &this->m_p3DParameters->m_PathState;
  while ( 1 )
  {
    this = (CAkParameterNode *)this->m_pParentNode;
    if ( !this )
      break;
    if ( this->m_p3DParameters )
      return &this->m_p3DParameters->m_PathState;
  }
  return 0i64;
}

// File Line: 2016
// RVA: 0xA6EB50
signed __int64 __fastcall CAkParameterNode::SetAuxBusSend(CAkParameterNode *this, unsigned int in_AuxBusID, unsigned int in_ulIndex)
{
  CAkParameterNode::AuxChunk *v3; // r9
  __int64 v4; // rsi
  unsigned int v5; // edi
  CAkParameterNode *v6; // rbx
  CAkParameterNode::AuxChunk *v7; // rax
  signed __int64 v8; // rcx

  v3 = this->m_pAuxChunk;
  v4 = in_ulIndex;
  v5 = in_AuxBusID;
  v6 = this;
  if ( !v3 )
  {
    if ( !in_AuxBusID )
      return 1i64;
    v7 = (CAkParameterNode::AuxChunk *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x10ui64);
    v6->m_pAuxChunk = v7;
    if ( v7 )
    {
      v8 = 0i64;
      do
      {
        v7->aAux[v8] = 0;
        ++v8;
      }
      while ( v8 < 4 );
    }
    v3 = v6->m_pAuxChunk;
    if ( !v3 )
      return 52i64;
  }
  v3->aAux[v4] = v5;
  v6->vfptr[12].Category((CAkIndexable *)&v6->vfptr);
  return 1i64;
}

// File Line: 2076
// RVA: 0xA6D4D0
__int64 __fastcall CAkParameterNode::GetFeedbackParameters(CAkParameterNode *this, AkFeedbackParams *io_Params, CAkSource *in_pSource, CAkRegisteredObj *in_GameObjPtr, bool in_bDoBusCheck)
{
  CAkRegisteredObj *v5; // rbx
  AkFeedbackParams *v6; // rdi
  CAkParameterNode *v7; // rsi
  AKRESULT v8; // eax
  CAkSIS *v9; // r9
  unsigned int v10; // er8
  AKRESULT v11; // er10
  char *v12; // r9
  unsigned int v13; // er11
  int v14; // ecx
  __int64 v15; // rdx
  float *v16; // rdx
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *v17; // rcx
  CAkRegisteredObj **v18; // rax
  signed __int64 v19; // rcx
  signed __int64 v20; // rax
  unsigned __int8 *v21; // rdx
  unsigned int v22; // er9
  __int64 v23; // rcx
  __int64 result; // rax
  signed __int64 v25; // rcx
  unsigned __int8 *v26; // rax
  bool v27; // zf
  float *v28; // rcx

  v5 = in_GameObjPtr;
  v6 = io_Params;
  v7 = this;
  v8 = CAkParameterNodeBase::GetFeedbackParameters(
         (CAkParameterNodeBase *)&this->vfptr,
         io_Params,
         in_pSource,
         in_GameObjPtr,
         in_bDoBusCheck);
  v9 = v7->m_pGlobalSIS;
  v10 = 0;
  v11 = v8;
  if ( v9 )
  {
    v12 = v9->m_values.m_pProps;
    if ( v12 )
    {
      v13 = (unsigned __int8)*v12;
      v14 = 0;
      while ( 1 )
      {
        v15 = (unsigned int)(v14 + 1);
        if ( v12[v15] == 8 )
          break;
        ++v14;
        if ( (unsigned int)v15 >= v13 )
          goto LABEL_9;
      }
      v16 = (float *)&v12[16 * v14 + ((v13 + 4) & 0xFFFFFFFC)];
      if ( v16 )
        v6->m_NewVolume = *v16 + v6->m_NewVolume;
    }
  }
LABEL_9:
  v17 = v7->m_pMapSIS;
  if ( !v17 )
    return (unsigned int)v11;
  v18 = &v17->m_pItems->key;
  v19 = (signed __int64)&v17->m_pItems[v17->m_uLength];
  if ( v18 == (CAkRegisteredObj **)v19 )
    return (unsigned int)v11;
  do
  {
    if ( *v18 == v5 )
      break;
    v18 += 2;
  }
  while ( v18 != (CAkRegisteredObj **)v19 );
  if ( v18 == (CAkRegisteredObj **)v19 )
    return (unsigned int)v11;
  v20 = (signed __int64)(v18 + 1);
  if ( !v20 )
    return (unsigned int)v11;
  v21 = *(unsigned __int8 **)(*(_QWORD *)v20 + 24i64);
  if ( !v21 )
    return (unsigned int)v11;
  v22 = *v21;
  while ( 1 )
  {
    v23 = v10 + 1;
    if ( v21[v23] == 8 )
      break;
    ++v10;
    if ( (unsigned int)v23 >= v22 )
      return (unsigned int)v11;
  }
  v25 = 16i64 * v10;
  v26 = &v21[(v22 + 4) & 0xFFFFFFFC];
  v27 = &v26[v25] == 0i64;
  v28 = (float *)&v26[v25];
  result = (unsigned int)v11;
  if ( !v27 )
    v6->m_NewVolume = *v28 + v6->m_NewVolume;
  return result;
}

// File Line: 2096
// RVA: 0xA6D260
float __fastcall CAkParameterNode::GetEffectiveFeedbackVolume(CAkParameterNode *this, CAkRegisteredObj *in_GameObjPtr)
{
  CAkParameterNode *v2; // rbx
  float result; // xmm0_4
  char *v4; // r8
  float v5; // xmm6_4
  unsigned int v6; // er9
  __int64 v7; // rcx
  __int64 v8; // rdx
  float *v9; // rbx
  float v10; // xmm0_4
  float v11; // xmm7_4

  v2 = this;
  result = CAkParameterNodeBase::GetEffectiveFeedbackVolume((CAkParameterNodeBase *)&this->vfptr, in_GameObjPtr);
  v4 = v2->m_ranges.m_pProps;
  v5 = result;
  if ( v4 )
  {
    v6 = (unsigned __int8)*v4;
    v7 = 0i64;
    while ( 1 )
    {
      v8 = (unsigned int)(v7 + 1);
      if ( v4[v8] == 8 )
        break;
      v7 = (unsigned int)v8;
      if ( (unsigned int)v8 >= v6 )
        return result;
    }
    v9 = (float *)&v4[8 * v7 + ((v6 + 4) & 0xFFFFFFFC)];
    if ( v9 )
    {
      v10 = 0.0;
      v11 = v9[1] - *v9;
      if ( v11 != 0.0 )
        v10 = (double)rand() * 0.00003051850947599719 * v11;
      v5 = v5 + (float)(v10 + *v9);
    }
  }
  return v5;
}

// File Line: 2104
// RVA: 0xA6D1A0
float __fastcall CAkParameterNode::GetEffectiveFeedbackLPF(CAkParameterNode *this, CAkRegisteredObj *in_GameObjPtr)
{
  CAkParameterNode *v2; // rbx
  float result; // xmm0_4
  char *v4; // r8
  float v5; // xmm6_4
  unsigned int v6; // er9
  __int64 v7; // rcx
  __int64 v8; // rdx
  float *v9; // rbx
  float v10; // xmm0_4
  float v11; // xmm7_4

  v2 = this;
  result = CAkParameterNodeBase::GetEffectiveFeedbackLPF((CAkParameterNodeBase *)&this->vfptr, in_GameObjPtr);
  v4 = v2->m_ranges.m_pProps;
  v5 = result;
  if ( v4 )
  {
    v6 = (unsigned __int8)*v4;
    v7 = 0i64;
    while ( 1 )
    {
      v8 = (unsigned int)(v7 + 1);
      if ( v4[v8] == 9 )
        break;
      v7 = (unsigned int)v8;
      if ( (unsigned int)v8 >= v6 )
        return result;
    }
    v9 = (float *)&v4[8 * v7 + ((v6 + 4) & 0xFFFFFFFC)];
    if ( v9 )
    {
      v10 = 0.0;
      v11 = v9[1] - *v9;
      if ( v11 != 0.0 )
        v10 = (double)rand() * 0.00003051850947599719 * v11;
      v5 = v5 + (float)(v10 + *v9);
    }
  }
  return v5;
}

// File Line: 2121
// RVA: 0xA6D8D0
signed __int64 __fastcall CAkParameterNode::HandleInitialDelay(CAkParameterNode *this, AkPBIParams *in_rPBIParams)
{
  AkPBIParams *v2; // rdi
  CAkParameterNode *v3; // rsi
  unsigned int v4; // ebp
  signed __int64 result; // rax
  char *v6; // r8
  int v7; // ebx
  unsigned int v8; // er9
  __int64 v9; // rcx
  __int64 v10; // rdx
  signed __int64 v11; // rdx
  float *v12; // rax
  unsigned __int64 v13; // rax
  float v14; // xmm6_4
  char *v15; // rdx
  unsigned int v16; // er8
  __int64 v17; // rcx
  float *v18; // rbx
  float v19; // xmm0_4
  float v20; // xmm7_4
  unsigned int v21; // eax
  bool v22; // zf
  float in_fDelay; // [rsp+78h] [rbp+10h]

  v2 = in_rPBIParams;
  v3 = this;
  v4 = 1;
  if ( in_rPBIParams->bSkipDelay )
  {
    in_rPBIParams->bSkipDelay = 0;
    return 1i64;
  }
  v6 = this->m_props.m_pProps;
  v7 = 0;
  in_fDelay = 0.0;
  if ( v6 )
  {
    v8 = (unsigned __int8)*v6;
    v9 = 0i64;
    while ( 1 )
    {
      v10 = (unsigned int)(v9 + 1);
      if ( v6[v10] == 25 )
        break;
      v9 = (unsigned int)v10;
      if ( (unsigned int)v10 >= v8 )
        goto LABEL_7;
    }
    v11 = (signed __int64)&v6[4 * v9 + ((v8 + 4) & 0xFFFFFFFC)];
  }
  else
  {
LABEL_7:
    v11 = 0i64;
  }
  v12 = &in_fDelay;
  if ( v11 )
    v12 = (float *)v11;
  in_fDelay = *v12;
  v13 = v3->m_RTPCBitArray.m_iBitArray;
  v14 = in_fDelay;
  if ( _bittest64((const signed __int64 *)&v13, 6ui64) )
    v14 = v14 + CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v3, 6u, v2->pGameObj);
  v15 = v3->m_ranges.m_pProps;
  if ( v15 )
  {
    v16 = (unsigned __int8)*v15;
    while ( 1 )
    {
      v17 = (unsigned int)(v7 + 1);
      if ( v15[v17] == 25 )
        break;
      ++v7;
      if ( (unsigned int)v17 >= v16 )
        goto LABEL_22;
    }
    v18 = (float *)&v15[8 * v7 + ((v16 + 4) & 0xFFFFFFFC)];
    if ( v18 )
    {
      v19 = 0.0;
      v20 = v18[1] - *v18;
      if ( v20 != 0.0 )
        v19 = (double)rand() * 0.00003051850947599719 * v20;
      v14 = v14 + (float)(v19 + *v18);
    }
  }
LABEL_22:
  if ( v14 <= 0.0 )
    return v4;
  if ( v2->sequenceID )
  {
    v2->uFrameOffset += AkTimeConv::SecondsToSamples(v14);
    return 1i64;
  }
  v21 = CAkParameterNode::DelayPlayback(v3, v14, v2);
  v4 = v21;
  v22 = v21 == 1;
  result = 3i64;
  if ( !v22 )
    return v4;
  return result;
}

