// File Line: 68
// RVA: 0xA6B230
void __fastcall CAkParameterNode::CAkParameterNode(CAkParameterNode *this, unsigned int in_ulID)
{
  CAkParameterNodeBase::CAkParameterNodeBase(this, in_ulID);
  this->vfptr = (CAkIndexableVtbl *)&CAkParameterNode::`vftable;
  this->m_pMapSIS = 0i64;
  this->m_p3DParameters = 0i64;
  this->m_ranges.m_pProps = 0i64;
  *((_BYTE *)this + 144) &= 0x80u;
  *((_BYTE *)this + 146) &= 0xF8u;
  this->m_pAssociatedLayers = 0i64;
  this->m_pAuxChunk = 0i64;
  *((_BYTE *)this + 145) = 4;
}

// File Line: 72
// RVA: 0xA6B290
void __fastcall CAkParameterNode::~CAkParameterNode(CAkParameterNode *this)
{
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *m_pMapSIS; // rcx
  MapStruct<CAkRegisteredObj *,CAkSIS *> *m_pItems; // rbx
  CAkSIS *item; // rsi
  int v5; // ebp
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *v6; // rbx
  MapStruct<CAkRegisteredObj *,CAkSIS *> *v7; // rdx
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *v8; // rdx
  CAkGen3DParamsEx *m_p3DParameters; // rcx
  CAkGen3DParamsEx *v10; // rbx
  int v11; // esi
  CAkGen3DParamsEx *v12; // rcx
  AkArray<CAkLayer *,CAkLayer *,ArrayPoolDefault,4,AkArrayAllocatorDefault> *m_pAssociatedLayers; // rbx
  CAkLayer **v14; // rdx
  AkArray<CAkLayer *,CAkLayer *,ArrayPoolDefault,4,AkArrayAllocatorDefault> *v15; // rdx
  CAkParameterNode::AuxChunk *m_pAuxChunk; // rdx
  char *m_pProps; // rdx

  this->vfptr = (CAkIndexableVtbl *)&CAkParameterNode::`vftable;
  m_pMapSIS = this->m_pMapSIS;
  if ( m_pMapSIS )
  {
    m_pItems = m_pMapSIS->m_pItems;
    if ( m_pMapSIS->m_pItems != &m_pMapSIS->m_pItems[m_pMapSIS->m_uLength] )
    {
      do
      {
        item = m_pItems->item;
        v5 = g_DefaultPoolId;
        if ( item )
        {
          CAkSIS::~CAkSIS(m_pItems->item);
          AK::MemoryMgr::Free(v5, item);
        }
        ++m_pItems;
      }
      while ( m_pItems != &this->m_pMapSIS->m_pItems[this->m_pMapSIS->m_uLength] );
    }
    v6 = this->m_pMapSIS;
    v7 = v6->m_pItems;
    if ( v6->m_pItems )
    {
      v6->m_uLength = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, v7);
      v6->m_pItems = 0i64;
      v6->m_ulReserved = 0;
    }
    v8 = this->m_pMapSIS;
    if ( v8 )
      AK::MemoryMgr::Free(g_DefaultPoolId, v8);
    this->m_pMapSIS = 0i64;
  }
  m_p3DParameters = this->m_p3DParameters;
  if ( m_p3DParameters )
  {
    CAkGen3DParamsEx::FreePathInfo(m_p3DParameters);
    CAkGen3DParams::Term(this->m_p3DParameters);
    v10 = this->m_p3DParameters;
    v11 = g_DefaultPoolId;
    if ( v10 )
    {
      v10->vfptr->__vecDelDtor(this->m_p3DParameters, 0);
      AK::MemoryMgr::Free(v11, v10);
    }
    this->m_p3DParameters = 0i64;
  }
  v12 = this->m_p3DParameters;
  if ( v12 )
    CAkGen3DParamsEx::FreePathInfo(v12);
  m_pAssociatedLayers = this->m_pAssociatedLayers;
  if ( m_pAssociatedLayers )
  {
    v14 = m_pAssociatedLayers->m_pItems;
    if ( m_pAssociatedLayers->m_pItems )
    {
      m_pAssociatedLayers->m_uLength = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, v14);
      m_pAssociatedLayers->m_pItems = 0i64;
      m_pAssociatedLayers->m_ulReserved = 0;
    }
    v15 = this->m_pAssociatedLayers;
    if ( v15 )
      AK::MemoryMgr::Free(g_DefaultPoolId, v15);
  }
  m_pAuxChunk = this->m_pAuxChunk;
  if ( m_pAuxChunk )
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pAuxChunk);
  m_pProps = this->m_ranges.m_pProps;
  if ( m_pProps )
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pProps);
  this->m_ranges.m_pProps = 0i64;
  CAkParameterNodeBase::~CAkParameterNodeBase(this);
}

// File Line: 102
// RVA: 0xA6E870
void __fastcall CAkParameterNode::SetAkProp(
        CAkParameterNode *this,
        AkPropID in_eProp,
        float in_fValue,
        float in_fMin,
        float in_fMax)
{
  float v5; // xmm9_4
  __int64 v6; // rdi
  int v7; // ebx
  char *v9; // r8
  unsigned int v10; // r9d
  __int64 v11; // rcx
  __int64 v12; // rdx
  __int64 v13; // rdx
  AkPropValue *v14; // rax
  char *m_pProps; // r8
  unsigned int v16; // r9d
  __int64 v17; // rcx
  __int64 v18; // rdx
  __int64 v19; // rdx
  AkPropValue *p_in_Value; // rax
  char *v21; // rdx
  unsigned int v22; // r8d
  __int64 v23; // rcx
  AkPropValue in_Value; // [rsp+A8h] [rbp+10h] BYREF

  v5 = in_fMax;
  v6 = in_eProp;
  v7 = 0;
  if ( (unsigned int)in_eProp <= AkPropID_BusVolume
    || (unsigned int)(in_eProp - 8) <= 1
    || (unsigned int)(in_eProp - 18) <= 6 )
  {
    m_pProps = this->m_props.m_pProps;
    in_Value.fValue = 0.0;
    if ( m_pProps )
    {
      v16 = (unsigned __int8)*m_pProps;
      v17 = 0i64;
      while ( 1 )
      {
        v18 = (unsigned int)(v17 + 1);
        if ( m_pProps[v18] == (_BYTE)v6 )
          break;
        v17 = (unsigned int)v18;
        if ( (unsigned int)v18 >= v16 )
          goto LABEL_20;
      }
      v19 = (__int64)&m_pProps[4 * v17 + ((v16 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_20:
      v19 = 0i64;
    }
    p_in_Value = &in_Value;
    if ( v19 )
      p_in_Value = (AkPropValue *)v19;
    in_Value.fValue = p_in_Value->fValue;
    if ( (float)(in_fValue - in_Value.fValue) != 0.0 )
    {
      ((void (__fastcall *)(CAkParameterNode *, _QWORD, CAkIndexableVtbl *, _QWORD, _QWORD))this->vfptr[5].Release)(
        this,
        (unsigned int)g_AkPropRTPCID[v6],
        this->vfptr,
        0i64,
        0i64);
      goto LABEL_25;
    }
  }
  else
  {
    if ( (unsigned int)(in_eProp - 11) > 2 )
    {
      CAkParameterNodeBase::SetAkProp(this, in_eProp, in_fValue, in_fMin, in_fMax);
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
      v13 = (__int64)&v9[4 * v11 + ((v10 + 4) & 0xFFFFFFFC)];
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
      ((void (__fastcall *)(CAkParameterNode *, CAkIndexableVtbl *, _QWORD, _QWORD, _QWORD))this->vfptr[17].Release)(
        this,
        this->vfptr,
        (unsigned int)g_AkPropRTPCID[v6],
        0i64,
        0i64);
LABEL_25:
      in_Value.fValue = in_fValue;
      AkPropBundle<AkPropValue>::SetAkProp(&this->m_props, v6, LODWORD(in_fValue));
    }
  }
LABEL_26:
  if ( in_fMin != 0.0 || v5 != 0.0 )
    goto LABEL_35;
  v21 = this->m_ranges.m_pProps;
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
LABEL_35:
      AkPropBundle<RANGED_MODIFIERS<AkPropValue>>::SetAkProp(
        &this->m_ranges,
        v6,
        (RANGED_MODIFIERS<AkPropValue>)__PAIR64__(LODWORD(v5), LODWORD(in_fMin)));
  }
}

// File Line: 151
// RVA: 0xA6E7D0
void __fastcall CAkParameterNode::SetAkProp(
        CAkParameterNode *this,
        __int32 in_eProp,
        int in_iValue,
        unsigned int in_iMin,
        int in_iMax)
{
  char v6; // bl
  char *m_pProps; // r8
  unsigned int v9; // r9d
  __int64 v10; // rcx
  __int64 v11; // rdx

  v6 = in_eProp;
  CAkParameterNodeBase::SetAkProp(this, (AkPropID)in_eProp, in_iValue, in_iMin, in_iMax);
  if ( in_iMin || in_iMax )
    goto LABEL_9;
  m_pProps = this->m_ranges.m_pProps;
  if ( m_pProps )
  {
    v9 = (unsigned __int8)*m_pProps;
    v10 = 0i64;
    while ( 1 )
    {
      v11 = (unsigned int)(v10 + 1);
      if ( m_pProps[v11] == v6 )
        break;
      v10 = (unsigned int)v11;
      if ( (unsigned int)v11 >= v9 )
        return;
    }
    if ( &m_pProps[8 * v10 + ((v9 + 4) & 0xFFFFFFFC)] )
LABEL_9:
      AkPropBundle<RANGED_MODIFIERS<AkPropValue>>::SetAkProp(
        &this->m_ranges,
        v6,
        (RANGED_MODIFIERS<AkPropValue>)__PAIR64__(in_iMax, in_iMin));
  }
}

// File Line: 178
// RVA: 0xA6C170
void __fastcall CAkParameterNode::Get3DParams(
        CAkParameterNode *this,
        CAkGen3DParams **out_rp3DParams,
        CAkRegisteredObj *in_GameObj,
        AkPannerType *out_ePannerType,
        AkPositionSourceType *out_ePosType,
        BaseGenParams *io_pBasePosParams)
{
  CAkParameterNodeBase *m_pParentNode; // rax
  CAkParameterNode *i; // rbx

  m_pParentNode = this->m_pParentNode;
  for ( i = this; (*((_BYTE *)&i->CAkParameterNodeBase + 83) & 0x10) == 0; m_pParentNode = m_pParentNode->m_pParentNode )
  {
    if ( !m_pParentNode )
      break;
    i = (CAkParameterNode *)m_pParentNode;
  }
  CAkParameterNode::Get3DCloneForObject(i, out_rp3DParams, out_ePosType);
  *out_ePannerType = *((_BYTE *)i + 145) & 3;
  if ( (i->m_RTPCBitArray.m_iBitArray & 0x400) != 0 )
    *out_ePannerType = (int)CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, i, 0xAu, in_GameObj);
  CAkParameterNodeBase::Get2DParams(i, in_GameObj, io_pBasePosParams);
}

// File Line: 279
// RVA: 0xA6F750
void __fastcall CAkParameterNode::UpdateBaseParams(
        CAkParameterNode *this,
        CAkRegisteredObj *in_GameObj,
        BaseGenParams *io_pBasePosParams,
        CAkGen3DParams *io_p3DParams)
{
  CAkParameterNode *v6; // rbx
  bool v7; // al

  do
  {
    v6 = this;
    this = (CAkParameterNode *)this->m_pParentNode;
  }
  while ( (*((_BYTE *)&v6->CAkParameterNodeBase + 83) & 0x10) == 0 && this );
  CAkParameterNodeBase::Get2DParams(v6, in_GameObj, io_pBasePosParams);
  if ( io_p3DParams )
  {
    v7 = CAkParameterNodeBase::Get3DPanning(v6, in_GameObj, &io_p3DParams->m_Params.m_Position);
    *((_BYTE *)&io_p3DParams->m_Params + 68) &= ~4u;
    *((_BYTE *)&io_p3DParams->m_Params + 68) |= 4 * v7;
  }
}

// File Line: 306
// RVA: 0xA6D600
__int64 __fastcall CAkParameterNode::GetMaxRadius(CAkParameterNode *this, float *out_fRadius)
{
  CAkParameterNode *v3; // rax
  CAkGen3DParamsEx *m_p3DParameters; // rdx
  unsigned __int8 v5; // bl
  CAkIndexable *PtrAndAddRef; // rax
  CAkIndexable *v7; // r8
  unsigned __int8 vfptr; // al
  unsigned int *v9; // rdx

  *out_fRadius = 0.0;
  do
  {
    v3 = this;
    this = (CAkParameterNode *)this->m_pParentNode;
  }
  while ( (*((_BYTE *)&v3->CAkParameterNodeBase + 83) & 0x10) == 0 && this );
  m_p3DParameters = v3->m_p3DParameters;
  v5 = 0;
  if ( m_p3DParameters )
  {
    PtrAndAddRef = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                     (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxAttenuations,
                     m_p3DParameters->m_Params.m_uAttenuationID);
    v7 = PtrAndAddRef;
    if ( PtrAndAddRef )
    {
      vfptr = (unsigned __int8)PtrAndAddRef[5].vfptr;
      if ( vfptr != 0xFF )
      {
        v9 = &v7[1].key + 4 * vfptr;
        if ( *(_QWORD *)v9 )
        {
          if ( v9 )
          {
            v5 = 1;
            *out_fRadius = *(float *)(*(_QWORD *)v9 + 12i64 * (v9[2] - 1));
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
__int64 __fastcall CAkParameterNode::GetAudioParameters(
        CAkParameterNode *this,
        AkSoundParamsEx *io_Parameters,
        unsigned int in_ulParamSelect,
        CAkKeyArray<AkMutedMapItem,float,2> *io_rMutedMap,
        CAkRegisteredObj *in_GameObjPtr,
        float in_bIncludeRange,
        AkPBIModValues *io_Ranges,
        bool in_bDoBusCheck)
{
  unsigned int v9; // ebx
  CAkRegisteredObj *v12; // r13
  __int64 v13; // r12
  float v14; // xmm7_4
  char *m_pProps; // r8
  unsigned int v16; // r9d
  __int64 v17; // rcx
  __int64 v18; // rdx
  __int64 v19; // rdx
  int *v20; // rax
  unsigned __int64 m_iBitArray; // rax
  char v22; // cl
  char v23; // al
  char *v24; // r8
  unsigned int v25; // r9d
  __int64 v26; // rcx
  __int64 v27; // rdx
  __int64 v28; // rdx
  int *v29; // rax
  char *v30; // r8
  unsigned int v31; // r9d
  __int64 v32; // rcx
  __int64 v33; // rdx
  __int64 v34; // rdx
  int *v35; // rax
  char *v36; // r8
  unsigned int v37; // r9d
  __int64 v38; // rcx
  __int64 v39; // rdx
  __int64 v40; // rdx
  int *v41; // rax
  char *v42; // r8
  unsigned int v43; // r9d
  __int64 v44; // rcx
  __int64 v45; // rdx
  __int64 v46; // rdx
  float *p_fValue; // rax
  CAkSIS *m_pGlobalSIS; // r8
  char *v49; // r8
  unsigned int v50; // r9d
  int v51; // ecx
  __int64 v52; // rdx
  float *v53; // rdx
  char *v54; // r8
  unsigned int v55; // r9d
  int v56; // ecx
  __int64 v57; // rdx
  float *v58; // rdx
  char *v59; // r8
  unsigned int v60; // r9d
  int v61; // ecx
  __int64 v62; // rdx
  float *v63; // rdx
  char *v64; // r8
  unsigned int v65; // r9d
  int v66; // ecx
  __int64 v67; // rdx
  float *v68; // rdx
  float v69; // xmm2_4
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *m_pMapSIS; // rcx
  MapStruct<CAkRegisteredObj *,CAkSIS *> *m_pItems; // rax
  __int64 v72; // rcx
  CAkSIS **p_item; // rax
  CAkSIS *v74; // r10
  char *v75; // r8
  unsigned int v76; // r9d
  int v77; // ecx
  __int64 v78; // rdx
  float *v79; // rdx
  char *v80; // r8
  unsigned int v81; // r9d
  int v82; // ecx
  __int64 v83; // rdx
  float *v84; // rdx
  char *v85; // r8
  unsigned int v86; // r9d
  int v87; // ecx
  __int64 v88; // rdx
  float *v89; // rdx
  char *v90; // r8
  unsigned int v91; // r9d
  int v92; // ecx
  __int64 v93; // rdx
  float *v94; // rdx
  float v95; // xmm2_4
  char v96; // r15
  AkPBIModValues *v97; // rdi
  char *v98; // r8
  unsigned int v99; // r9d
  __int64 v100; // rcx
  __int64 v101; // rdx
  float *v102; // rbx
  float v103; // xmm0_4
  float v104; // xmm6_4
  char *v105; // r8
  unsigned int v106; // r9d
  __int64 v107; // rcx
  __int64 v108; // rdx
  float *v109; // rbx
  float v110; // xmm0_4
  float v111; // xmm6_4
  char *v112; // r8
  unsigned int v113; // r9d
  __int64 v114; // rcx
  __int64 v115; // rdx
  float *v116; // rbx
  float v117; // xmm6_4
  char *v118; // r8
  unsigned int v119; // r9d
  __int64 v120; // rcx
  __int64 v121; // rdx
  __int64 v122; // rdx
  int *p_in_bIncludeRange; // rax
  char *v124; // r8
  unsigned int v125; // r9d
  __int64 v126; // rcx
  __int64 v127; // rdx
  __int64 v128; // rdx
  int *v129; // rax
  char *v130; // r8
  unsigned int v131; // r9d
  __int64 v132; // rcx
  __int64 v133; // rdx
  __int64 v134; // rdx
  int *v135; // rax
  char *v136; // r8
  unsigned int v137; // r9d
  __int64 v138; // rcx
  __int64 v139; // rdx
  __int64 v140; // rdx
  int *v141; // rax
  char *v142; // r8
  unsigned int v143; // r9d
  __int64 v144; // rcx
  __int64 v145; // rdx
  __int64 v146; // rdx
  int *v147; // rax
  char *v148; // r8
  unsigned int v149; // r9d
  __int64 v150; // rcx
  __int64 v151; // rdx
  __int64 v152; // rdx
  int *v153; // rax
  char *v154; // r8
  unsigned int v155; // r9d
  __int64 v156; // rcx
  __int64 v157; // rdx
  int *v158; // rax
  CAkParameterNodeBase *m_pParentNode; // rcx
  CAkKeyArray<AkMutedMapItem,float,2> *v160; // r12
  CAkParameterNodeBase *m_pBusOutputNode; // rcx
  AkArray<CAkLayer *,CAkLayer *,ArrayPoolDefault,4,AkArrayAllocatorDefault> *m_pAssociatedLayers; // rax
  CAkLayer **v163; // rbx
  __int64 v164; // rdi
  unsigned int v165; // r15d
  int v167; // [rsp+28h] [rbp-48h]
  int v168; // [rsp+38h] [rbp-38h]
  AkMutedMapItem v169; // [rsp+40h] [rbp-30h] BYREF
  float fValue; // [rsp+B0h] [rbp+40h] BYREF
  unsigned int in_ulParamSelecta; // [rsp+C0h] [rbp+50h]
  CAkKeyArray<AkMutedMapItem,float,2> *v172; // [rsp+C8h] [rbp+58h]

  v172 = io_rMutedMap;
  in_ulParamSelecta = in_ulParamSelect;
  v9 = in_ulParamSelect;
  CAkParameterNodeBase::GetAudioStateParams(this, io_Parameters, in_ulParamSelect);
  v12 = in_GameObjPtr;
  v13 = 0i64;
  v14 = 0.0;
  if ( (v9 & 1) != 0 )
  {
    m_pProps = this->m_props.m_pProps;
    fValue = 0.0;
    if ( m_pProps )
    {
      v16 = (unsigned __int8)*m_pProps;
      v17 = 0i64;
      while ( 1 )
      {
        v18 = (unsigned int)(v17 + 1);
        if ( !m_pProps[v18] )
          break;
        v17 = (unsigned int)v18;
        if ( (unsigned int)v18 >= v16 )
          goto LABEL_6;
      }
      v19 = (__int64)&m_pProps[4 * v17 + ((v16 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_6:
      v19 = 0i64;
    }
    v20 = (int *)&fValue;
    if ( v19 )
      v20 = (int *)v19;
    fValue = *(float *)v20;
    io_Parameters->Volume = fValue + io_Parameters->Volume;
    m_iBitArray = this->m_RTPCBitArray.m_iBitArray;
    if ( _bittest64((const __int64 *)&m_iBitArray, (unsigned int)g_AkPropRTPCID[0]) )
      io_Parameters->Volume = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, g_AkPropRTPCID[0], v12)
                            + io_Parameters->Volume;
    v22 = *((_BYTE *)&io_Parameters->normalization + 4);
    if ( (v22 & 2) == 0 )
    {
      v23 = *((_BYTE *)this + 146);
      if ( (v23 & 1) != 0 || !this->m_pParentNode )
        *((_BYTE *)&io_Parameters->normalization + 4) = v22 & 0xFE | ((unsigned __int8)(v23 & 2 | 4) >> 1);
    }
    v24 = this->m_props.m_pProps;
    fValue = 0.0;
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
      v28 = (__int64)&v24[4 * v26 + ((v25 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_19:
      v28 = 0i64;
    }
    v29 = (int *)&fValue;
    if ( v28 )
      v29 = (int *)v28;
    fValue = *(float *)v29;
    io_Parameters->normalization.fMakeUpGain = fValue + io_Parameters->normalization.fMakeUpGain;
    if ( (this->m_RTPCBitArray.m_iBitArray & 0x1000000000i64) != 0 )
      io_Parameters->normalization.fMakeUpGain = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 0x24u, v12)
                                               + io_Parameters->normalization.fMakeUpGain;
  }
  if ( (v9 & 2) != 0 )
  {
    v30 = this->m_props.m_pProps;
    fValue = 0.0;
    if ( v30 )
    {
      v31 = (unsigned __int8)*v30;
      v32 = 0i64;
      while ( 1 )
      {
        v33 = (unsigned int)(v32 + 1);
        if ( v30[v33] == 2 )
          break;
        v32 = (unsigned int)v33;
        if ( (unsigned int)v33 >= v31 )
          goto LABEL_29;
      }
      v34 = (__int64)&v30[4 * v32 + ((v31 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_29:
      v34 = 0i64;
    }
    v35 = (int *)&fValue;
    if ( v34 )
      v35 = (int *)v34;
    fValue = *(float *)v35;
    io_Parameters->Pitch = fValue + io_Parameters->Pitch;
    if ( (this->m_RTPCBitArray.m_iBitArray & 4) != 0 )
      io_Parameters->Pitch = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 2u, v12) + io_Parameters->Pitch;
  }
  if ( (v9 & 4) != 0 )
  {
    v36 = this->m_props.m_pProps;
    fValue = 0.0;
    if ( v36 )
    {
      v37 = (unsigned __int8)*v36;
      v38 = 0i64;
      while ( 1 )
      {
        v39 = (unsigned int)(v38 + 1);
        if ( v36[v39] == 3 )
          break;
        v38 = (unsigned int)v39;
        if ( (unsigned int)v39 >= v37 )
          goto LABEL_39;
      }
      v40 = (__int64)&v36[4 * v38 + ((v37 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_39:
      v40 = 0i64;
    }
    v41 = (int *)&fValue;
    if ( v40 )
      v41 = (int *)v40;
    fValue = *(float *)v41;
    io_Parameters->LPF = fValue + io_Parameters->LPF;
    if ( (this->m_RTPCBitArray.m_iBitArray & 8) != 0 )
      io_Parameters->LPF = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 3u, v12) + io_Parameters->LPF;
  }
  if ( (v9 & 0x10) != 0
    && (*((_BYTE *)&io_Parameters->hdr + 4) & 1) == 0
    && (*((char *)this + 145) < 0 || !this->m_pParentNode) )
  {
    if ( (this->m_RTPCBitArray.m_iBitArray & 0x800000000i64) != 0 )
    {
      io_Parameters->hdr.fActiveRange = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 0x23u, v12);
    }
    else
    {
      v42 = this->m_props.m_pProps;
      fValue = g_AkPropDefault[32].fValue;
      if ( v42 )
      {
        v43 = (unsigned __int8)*v42;
        v44 = 0i64;
        while ( 1 )
        {
          v45 = (unsigned int)(v44 + 1);
          if ( v42[v45] == 32 )
            break;
          v44 = (unsigned int)v45;
          if ( (unsigned int)v45 >= v43 )
            goto LABEL_58;
        }
        v46 = (__int64)&v42[4 * v44 + ((v43 + 4) & 0xFFFFFFFC)];
      }
      else
      {
LABEL_58:
        v46 = 0i64;
      }
      p_fValue = &fValue;
      if ( v46 )
        p_fValue = (float *)v46;
      io_Parameters->hdr.fActiveRange = *p_fValue;
    }
    *((_BYTE *)&io_Parameters->hdr + 4) = *((_BYTE *)&io_Parameters->hdr + 4) ^ (*((_BYTE *)&io_Parameters->hdr + 4) ^ (*((_BYTE *)this + 146) >> 1)) & 2 | 1;
  }
  m_pGlobalSIS = this->m_pGlobalSIS;
  if ( m_pGlobalSIS )
  {
    v49 = m_pGlobalSIS->m_values.m_pProps;
    if ( v49 )
    {
      v50 = (unsigned __int8)*v49;
      v51 = 0;
      while ( 1 )
      {
        v52 = (unsigned int)(v51 + 1);
        if ( !v49[v52] )
          break;
        ++v51;
        if ( (unsigned int)v52 >= v50 )
          goto LABEL_72;
      }
      v53 = (float *)&v49[16 * v51 + ((v50 + 4) & 0xFFFFFFFC)];
      if ( v53 )
        io_Parameters->Volume = *v53 + io_Parameters->Volume;
    }
LABEL_72:
    v54 = this->m_pGlobalSIS->m_values.m_pProps;
    if ( v54 )
    {
      v55 = (unsigned __int8)*v54;
      v56 = 0;
      while ( 1 )
      {
        v57 = (unsigned int)(v56 + 1);
        if ( v54[v57] == 2 )
          break;
        ++v56;
        if ( (unsigned int)v57 >= v55 )
          goto LABEL_79;
      }
      v58 = (float *)&v54[16 * v56 + ((v55 + 4) & 0xFFFFFFFC)];
      if ( v58 )
        io_Parameters->Pitch = io_Parameters->Pitch + *v58;
    }
LABEL_79:
    v59 = this->m_pGlobalSIS->m_values.m_pProps;
    if ( v59 )
    {
      v60 = (unsigned __int8)*v59;
      v61 = 0;
      while ( 1 )
      {
        v62 = (unsigned int)(v61 + 1);
        if ( v59[v62] == 3 )
          break;
        ++v61;
        if ( (unsigned int)v62 >= v60 )
          goto LABEL_86;
      }
      v63 = (float *)&v59[16 * v61 + ((v60 + 4) & 0xFFFFFFFC)];
      if ( v63 )
        io_Parameters->LPF = io_Parameters->LPF + *v63;
    }
LABEL_86:
    v64 = this->m_pGlobalSIS->m_values.m_pProps;
    if ( v64 )
    {
      v65 = (unsigned __int8)*v64;
      v66 = 0;
      while ( 1 )
      {
        v67 = (unsigned int)(v66 + 1);
        if ( v64[v67] == 10 )
          break;
        ++v66;
        if ( (unsigned int)v67 >= v65 )
          goto LABEL_94;
      }
      v68 = (float *)&v64[16 * v66 + ((v65 + 4) & 0xFFFFFFFC)];
      if ( v68 )
      {
        v69 = *v68;
        if ( *v68 != 1.0 )
        {
          v169.m_Identifier = this;
          *((_DWORD *)&v169 + 2) = *((_DWORD *)&v169 + 2) & 0xFFFFFFFC | 1;
          CAkKeyArray<AkMutedMapItem,float,2>::Set(io_rMutedMap, &v169, v69);
        }
      }
    }
  }
LABEL_94:
  m_pMapSIS = this->m_pMapSIS;
  if ( m_pMapSIS )
  {
    m_pItems = m_pMapSIS->m_pItems;
    v72 = (__int64)&m_pMapSIS->m_pItems[m_pMapSIS->m_uLength];
    if ( m_pItems != (MapStruct<CAkRegisteredObj *,CAkSIS *> *)v72 )
    {
      do
      {
        if ( m_pItems->key == v12 )
          break;
        ++m_pItems;
      }
      while ( m_pItems != (MapStruct<CAkRegisteredObj *,CAkSIS *> *)v72 );
      if ( m_pItems != (MapStruct<CAkRegisteredObj *,CAkSIS *> *)v72 )
      {
        p_item = &m_pItems->item;
        if ( p_item )
        {
          v74 = *p_item;
          v75 = (*p_item)->m_values.m_pProps;
          if ( v75 )
          {
            v76 = (unsigned __int8)*v75;
            v77 = 0;
            while ( 1 )
            {
              v78 = (unsigned int)(v77 + 1);
              if ( !v75[v78] )
                break;
              ++v77;
              if ( (unsigned int)v78 >= v76 )
                goto LABEL_107;
            }
            v79 = (float *)&v75[16 * v77 + ((v76 + 4) & 0xFFFFFFFC)];
            if ( v79 )
              io_Parameters->Volume = *v79 + io_Parameters->Volume;
          }
LABEL_107:
          v80 = v74->m_values.m_pProps;
          if ( v80 )
          {
            v81 = (unsigned __int8)*v80;
            v82 = 0;
            while ( 1 )
            {
              v83 = (unsigned int)(v82 + 1);
              if ( v80[v83] == 2 )
                break;
              ++v82;
              if ( (unsigned int)v83 >= v81 )
                goto LABEL_114;
            }
            v84 = (float *)&v80[16 * v82 + ((v81 + 4) & 0xFFFFFFFC)];
            if ( v84 )
              io_Parameters->Pitch = *v84 + io_Parameters->Pitch;
          }
LABEL_114:
          v85 = v74->m_values.m_pProps;
          if ( v85 )
          {
            v86 = (unsigned __int8)*v85;
            v87 = 0;
            while ( 1 )
            {
              v88 = (unsigned int)(v87 + 1);
              if ( v85[v88] == 3 )
                break;
              ++v87;
              if ( (unsigned int)v88 >= v86 )
                goto LABEL_121;
            }
            v89 = (float *)&v85[16 * v87 + ((v86 + 4) & 0xFFFFFFFC)];
            if ( v89 )
              io_Parameters->LPF = io_Parameters->LPF + *v89;
          }
LABEL_121:
          v90 = v74->m_values.m_pProps;
          if ( v90 )
          {
            v91 = (unsigned __int8)*v90;
            v92 = 0;
            while ( 1 )
            {
              v93 = (unsigned int)(v92 + 1);
              if ( v90[v93] == 10 )
                break;
              ++v92;
              if ( (unsigned int)v93 >= v91 )
                goto LABEL_129;
            }
            v94 = (float *)&v90[16 * v92 + ((v91 + 4) & 0xFFFFFFFC)];
            if ( v94 )
            {
              v95 = *v94;
              if ( *v94 != 1.0 )
              {
                *((_DWORD *)&v169 + 2) &= 0xFFFFFFFC;
                v169.m_Identifier = this;
                CAkKeyArray<AkMutedMapItem,float,2>::Set(io_rMutedMap, &v169, v95);
              }
            }
          }
        }
      }
    }
  }
LABEL_129:
  v96 = LOBYTE(in_bIncludeRange);
  v97 = io_Ranges;
  if ( LOBYTE(in_bIncludeRange) )
  {
    v98 = this->m_ranges.m_pProps;
    if ( v98 )
    {
      v99 = (unsigned __int8)*v98;
      v100 = 0i64;
      while ( 1 )
      {
        v101 = (unsigned int)(v100 + 1);
        if ( !v98[v101] )
          break;
        v100 = (unsigned int)v101;
        if ( (unsigned int)v101 >= v99 )
          goto LABEL_139;
      }
      v102 = (float *)&v98[8 * v100 + ((v99 + 4) & 0xFFFFFFFC)];
      if ( v102 )
      {
        v103 = 0.0;
        v104 = v102[1] - *v102;
        if ( v104 != 0.0 )
          v103 = (double)rand() * 0.00003051850947599719 * v104;
        v97->VolumeOffset = (float)(v103 + *v102) + v97->VolumeOffset;
      }
LABEL_139:
      v105 = this->m_ranges.m_pProps;
      if ( v105 )
      {
        v106 = (unsigned __int8)*v105;
        v107 = 0i64;
        while ( 1 )
        {
          v108 = (unsigned int)(v107 + 1);
          if ( v105[v108] == 2 )
            break;
          v107 = (unsigned int)v108;
          if ( (unsigned int)v108 >= v106 )
            goto LABEL_148;
        }
        v109 = (float *)&v105[8 * v107 + ((v106 + 4) & 0xFFFFFFFC)];
        if ( v109 )
        {
          v110 = 0.0;
          v111 = v109[1] - *v109;
          if ( v111 != 0.0 )
            v110 = (double)rand() * 0.00003051850947599719 * v111;
          v97->PitchOffset = (float)(v110 + *v109) + v97->PitchOffset;
        }
      }
LABEL_148:
      v112 = this->m_ranges.m_pProps;
      if ( v112 )
      {
        v113 = (unsigned __int8)*v112;
        v114 = 0i64;
        while ( 1 )
        {
          v115 = (unsigned int)(v114 + 1);
          if ( v112[v115] == 3 )
            break;
          v114 = (unsigned int)v115;
          if ( (unsigned int)v115 >= v113 )
            goto LABEL_157;
        }
        v116 = (float *)&v112[8 * v114 + ((v113 + 4) & 0xFFFFFFFC)];
        if ( v116 )
        {
          v117 = v116[1] - *v116;
          if ( v117 != 0.0 )
            v14 = (double)rand() * 0.00003051850947599719 * v117;
          v97->LPFOffset = (float)(v14 + *v116) + v97->LPFOffset;
        }
      }
LABEL_157:
      v9 = in_ulParamSelecta;
    }
  }
  if ( !io_Parameters->bUserDefinedServiced && ((*((_BYTE *)this + 145) & 0x40) != 0 || !this->m_pParentNode) )
  {
    io_Parameters->bUserDefinedServiced = 1;
    if ( this->m_pAuxChunk )
    {
      v118 = this->m_props.m_pProps;
      in_bIncludeRange = 0.0;
      if ( v118 )
      {
        v119 = (unsigned __int8)*v118;
        v120 = 0i64;
        while ( 1 )
        {
          v121 = (unsigned int)(v120 + 1);
          if ( v118[v121] == 18 )
            break;
          v120 = (unsigned int)v121;
          if ( (unsigned int)v121 >= v119 )
            goto LABEL_166;
        }
        v122 = (__int64)&v118[4 * v120 + ((v119 + 4) & 0xFFFFFFFC)];
      }
      else
      {
LABEL_166:
        v122 = 0i64;
      }
      p_in_bIncludeRange = (int *)&in_bIncludeRange;
      if ( v122 )
        p_in_bIncludeRange = (int *)v122;
      in_bIncludeRange = *(float *)p_in_bIncludeRange;
      io_Parameters->aUserAuxSendVolume[0] = in_bIncludeRange + io_Parameters->aUserAuxSendVolume[0];
      if ( (this->m_RTPCBitArray.m_iBitArray & 0x8000) != 0 )
        io_Parameters->aUserAuxSendVolume[0] = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 0xFu, v12)
                                             + io_Parameters->aUserAuxSendVolume[0];
      v124 = this->m_props.m_pProps;
      in_bIncludeRange = 0.0;
      if ( v124 )
      {
        v125 = (unsigned __int8)*v124;
        v126 = 0i64;
        while ( 1 )
        {
          v127 = (unsigned int)(v126 + 1);
          if ( v124[v127] == 19 )
            break;
          v126 = (unsigned int)v127;
          if ( (unsigned int)v127 >= v125 )
            goto LABEL_175;
        }
        v128 = (__int64)&v124[4 * v126 + ((v125 + 4) & 0xFFFFFFFC)];
      }
      else
      {
LABEL_175:
        v128 = 0i64;
      }
      v129 = (int *)&in_bIncludeRange;
      if ( v128 )
        v129 = (int *)v128;
      in_bIncludeRange = *(float *)v129;
      io_Parameters->aUserAuxSendVolume[1] = in_bIncludeRange + io_Parameters->aUserAuxSendVolume[1];
      if ( (this->m_RTPCBitArray.m_iBitArray & 0x10000) != 0 )
        io_Parameters->aUserAuxSendVolume[1] = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 0x10u, v12)
                                             + io_Parameters->aUserAuxSendVolume[1];
      v130 = this->m_props.m_pProps;
      in_bIncludeRange = 0.0;
      if ( v130 )
      {
        v131 = (unsigned __int8)*v130;
        v132 = 0i64;
        while ( 1 )
        {
          v133 = (unsigned int)(v132 + 1);
          if ( v130[v133] == 20 )
            break;
          v132 = (unsigned int)v133;
          if ( (unsigned int)v133 >= v131 )
            goto LABEL_184;
        }
        v134 = (__int64)&v130[4 * v132 + ((v131 + 4) & 0xFFFFFFFC)];
      }
      else
      {
LABEL_184:
        v134 = 0i64;
      }
      v135 = (int *)&in_bIncludeRange;
      if ( v134 )
        v135 = (int *)v134;
      in_bIncludeRange = *(float *)v135;
      io_Parameters->aUserAuxSendVolume[2] = in_bIncludeRange + io_Parameters->aUserAuxSendVolume[2];
      if ( (this->m_RTPCBitArray.m_iBitArray & 0x20000) != 0 )
        io_Parameters->aUserAuxSendVolume[2] = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 0x11u, v12)
                                             + io_Parameters->aUserAuxSendVolume[2];
      v136 = this->m_props.m_pProps;
      in_bIncludeRange = 0.0;
      if ( v136 )
      {
        v137 = (unsigned __int8)*v136;
        v138 = 0i64;
        while ( 1 )
        {
          v139 = (unsigned int)(v138 + 1);
          if ( v136[v139] == 21 )
            break;
          v138 = (unsigned int)v139;
          if ( (unsigned int)v139 >= v137 )
            goto LABEL_193;
        }
        v140 = (__int64)&v136[4 * v138 + ((v137 + 4) & 0xFFFFFFFC)];
      }
      else
      {
LABEL_193:
        v140 = 0i64;
      }
      v141 = (int *)&in_bIncludeRange;
      if ( v140 )
        v141 = (int *)v140;
      in_bIncludeRange = *(float *)v141;
      io_Parameters->aUserAuxSendVolume[3] = in_bIncludeRange + io_Parameters->aUserAuxSendVolume[3];
      if ( (this->m_RTPCBitArray.m_iBitArray & 0x40000) != 0 )
        io_Parameters->aUserAuxSendVolume[3] = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 0x12u, v12)
                                             + io_Parameters->aUserAuxSendVolume[3];
      io_Parameters->aAuxSend[0] = this->m_pAuxChunk->aAux[0];
      io_Parameters->aAuxSend[1] = this->m_pAuxChunk->aAux[1];
      io_Parameters->aAuxSend[2] = this->m_pAuxChunk->aAux[2];
      io_Parameters->aAuxSend[3] = this->m_pAuxChunk->aAux[3];
    }
  }
  if ( !io_Parameters->bGameDefinedServiced && ((*((_BYTE *)this + 145) & 0x10) != 0 || !this->m_pParentNode) )
  {
    io_Parameters->bGameDefinedServiced = 1;
    v142 = this->m_props.m_pProps;
    in_bIncludeRange = 0.0;
    if ( v142 )
    {
      v143 = (unsigned __int8)*v142;
      v144 = 0i64;
      while ( 1 )
      {
        v145 = (unsigned int)(v144 + 1);
        if ( v142[v145] == 22 )
          break;
        v144 = (unsigned int)v145;
        if ( (unsigned int)v145 >= v143 )
          goto LABEL_206;
      }
      v146 = (__int64)&v142[4 * v144 + ((v143 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_206:
      v146 = 0i64;
    }
    v147 = (int *)&in_bIncludeRange;
    if ( v146 )
      v147 = (int *)v146;
    in_bIncludeRange = *(float *)v147;
    io_Parameters->fGameAuxSendVolume = in_bIncludeRange + io_Parameters->fGameAuxSendVolume;
    if ( (this->m_RTPCBitArray.m_iBitArray & 0x80000) != 0 )
      io_Parameters->fGameAuxSendVolume = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 0x13u, v12)
                                        + io_Parameters->fGameAuxSendVolume;
    io_Parameters->bGameDefinedAuxEnabled = (*((_BYTE *)this + 145) & 0x20) != 0;
  }
  if ( in_bDoBusCheck && this->m_pBusOutputNode )
  {
    v148 = this->m_props.m_pProps;
    in_bIncludeRange = 0.0;
    if ( v148 )
    {
      v149 = (unsigned __int8)*v148;
      v150 = 0i64;
      while ( 1 )
      {
        v151 = (unsigned int)(v150 + 1);
        if ( v148[v151] == 23 )
          break;
        v150 = (unsigned int)v151;
        if ( (unsigned int)v151 >= v149 )
          goto LABEL_218;
      }
      v152 = (__int64)&v148[4 * v150 + ((v149 + 4) & 0xFFFFFFFC)];
    }
    else
    {
LABEL_218:
      v152 = 0i64;
    }
    v153 = (int *)&in_bIncludeRange;
    if ( v152 )
      v153 = (int *)v152;
    in_bIncludeRange = *(float *)v153;
    io_Parameters->fOutputBusVolume = in_bIncludeRange + io_Parameters->fOutputBusVolume;
    if ( (this->m_RTPCBitArray.m_iBitArray & 0x400000) != 0 )
      io_Parameters->fOutputBusVolume = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 0x16u, v12)
                                      + io_Parameters->fOutputBusVolume;
    v154 = this->m_props.m_pProps;
    in_bIncludeRange = 0.0;
    if ( v154 )
    {
      v155 = (unsigned __int8)*v154;
      v156 = 0i64;
      while ( 1 )
      {
        v157 = (unsigned int)(v156 + 1);
        if ( v154[v157] == 24 )
          break;
        v156 = (unsigned int)v157;
        if ( (unsigned int)v157 >= v155 )
          goto LABEL_235;
      }
      v13 = (__int64)&v154[4 * v156 + ((v155 + 4) & 0xFFFFFFFC)];
    }
LABEL_235:
    v158 = (int *)&in_bIncludeRange;
    if ( v13 )
      v158 = (int *)v13;
    in_bIncludeRange = *(float *)v158;
    io_Parameters->fOutputBusLPF = in_bIncludeRange + io_Parameters->fOutputBusLPF;
    if ( (this->m_RTPCBitArray.m_iBitArray & 0x800000) != 0 )
      io_Parameters->fOutputBusLPF = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 0x17u, v12)
                                   + io_Parameters->fOutputBusLPF;
    m_pParentNode = this->m_pParentNode;
    v160 = v172;
    if ( m_pParentNode )
      ((void (__fastcall *)(CAkParameterNodeBase *, AkSoundParamsEx *, _QWORD, CAkKeyArray<AkMutedMapItem,float,2> *, CAkRegisteredObj *, char, AkPBIModValues *, _BYTE))m_pParentNode->vfptr[10].Release)(
        m_pParentNode,
        io_Parameters,
        v9,
        v172,
        v12,
        v96,
        v97,
        0);
    m_pBusOutputNode = this->m_pBusOutputNode;
    LOBYTE(v168) = 0;
    goto LABEL_244;
  }
  m_pBusOutputNode = this->m_pParentNode;
  v160 = v172;
  if ( m_pBusOutputNode )
  {
    LOBYTE(v168) = in_bDoBusCheck;
LABEL_244:
    LOBYTE(v167) = v96;
    ((void (__fastcall *)(CAkParameterNodeBase *, AkSoundParamsEx *, _QWORD, CAkKeyArray<AkMutedMapItem,float,2> *, CAkRegisteredObj *, int, AkPBIModValues *, int))m_pBusOutputNode->vfptr[10].Release)(
      m_pBusOutputNode,
      io_Parameters,
      v9,
      v160,
      v12,
      v167,
      v97,
      v168);
  }
  m_pAssociatedLayers = this->m_pAssociatedLayers;
  if ( m_pAssociatedLayers )
  {
    v163 = m_pAssociatedLayers->m_pItems;
    v164 = (__int64)&m_pAssociatedLayers->m_pItems[m_pAssociatedLayers->m_uLength];
    if ( m_pAssociatedLayers->m_pItems != (CAkLayer **)v164 )
    {
      v165 = in_ulParamSelecta;
      do
        CAkLayer::GetAudioParameters(*v163++, this, io_Parameters, v165, v160, v12);
      while ( v163 != (CAkLayer **)v164 );
    }
  }
  return 1i64;
}

// File Line: 499
// RVA: 0xA6EAE0
void __fastcall CAkParameterNode::SetAkProp(
        CAkParameterNode *this,
        AkPropID in_eProp,
        CAkRegisteredObj *in_GameObjPtr,
        AkValueMeaning in_eValueMeaning,
        float in_fTargetValue,
        AkCurveInterpolation in_eFadeCurve,
        int in_lTransitionTime)
{
  CAkSIS *v10; // rax

  v10 = (CAkSIS *)this->vfptr[19].__vecDelDtor(this, in_GameObjPtr);
  if ( v10 )
    CAkParameterNodeBase::StartSISTransition(
      this,
      v10,
      in_eProp,
      in_fTargetValue,
      in_eValueMeaning,
      in_eFadeCurve,
      in_lTransitionTime);
}

// File Line: 551
// RVA: 0xA6DD60
void __fastcall CAkParameterNode::Mute(
        CAkParameterNode *this,
        CAkRegisteredObj *in_GameObjPtr,
        AkCurveInterpolation in_eFadeCurve,
        int in_lTransitionTime)
{
  CAkSIS *v7; // rax

  v7 = (CAkSIS *)this->vfptr[19].__vecDelDtor(this, in_GameObjPtr);
  if ( v7 )
    CAkParameterNodeBase::StartSisMuteTransitions(this, v7, 0.0, in_eFadeCurve, in_lTransitionTime);
}

// File Line: 562
// RVA: 0xA6F3A0
void __fastcall CAkParameterNode::Unmute(
        CAkParameterNode *this,
        CAkRegisteredObj *in_GameObjPtr,
        AkCurveInterpolation in_eFadeCurve,
        int in_lTransitionTime)
{
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *m_pMapSIS; // r10
  MapStruct<CAkRegisteredObj *,CAkSIS *> *m_pItems; // rax
  __int64 v9; // rcx
  CAkSIS *item; // rdx
  CAkSIS *m_pGlobalSIS; // r8
  char *m_pProps; // r8
  unsigned int v13; // r9d
  int i; // ecx
  __int64 v15; // rdx
  float *v16; // rdx

  if ( in_GameObjPtr )
  {
    m_pMapSIS = this->m_pMapSIS;
    if ( m_pMapSIS )
    {
      m_pItems = m_pMapSIS->m_pItems;
      v9 = (__int64)&m_pMapSIS->m_pItems[m_pMapSIS->m_uLength];
      if ( m_pMapSIS->m_pItems != (MapStruct<CAkRegisteredObj *,CAkSIS *> *)v9 )
      {
        do
        {
          if ( m_pItems->key == in_GameObjPtr )
            break;
          ++m_pItems;
        }
        while ( m_pItems != (MapStruct<CAkRegisteredObj *,CAkSIS *> *)v9 );
        if ( m_pItems != (MapStruct<CAkRegisteredObj *,CAkSIS *> *)v9
          && m_pItems != (MapStruct<CAkRegisteredObj *,CAkSIS *> *)-8i64 )
        {
          item = m_pItems->item;
          goto LABEL_18;
        }
      }
    }
  }
  else
  {
    m_pGlobalSIS = this->m_pGlobalSIS;
    if ( m_pGlobalSIS )
    {
      m_pProps = m_pGlobalSIS->m_values.m_pProps;
      if ( m_pProps )
      {
        v13 = (unsigned __int8)*m_pProps;
        for ( i = 0; ; ++i )
        {
          v15 = (unsigned int)(i + 1);
          if ( m_pProps[v15] == 10 )
            break;
          if ( (unsigned int)v15 >= v13 )
            return;
        }
        v16 = (float *)&m_pProps[16 * i + ((v13 + 4) & 0xFFFFFFFC)];
        if ( v16 )
        {
          if ( 1.0 != *v16 )
          {
            CAkRegistryMgr::SetNodeIDAsModified(g_pRegistryMgr, this);
            item = this->m_pGlobalSIS;
LABEL_18:
            if ( item )
              CAkParameterNodeBase::StartSisMuteTransitions(this, item, 1.0, in_eFadeCurve, in_lTransitionTime);
          }
        }
      }
    }
  }
}

// File Line: 598
// RVA: 0xA6F500
void __fastcall CAkParameterNode::UnmuteAllObj(
        CAkParameterNode *this,
        unsigned int in_eFadeCurve,
        unsigned int in_lTransitionTime)
{
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *m_pMapSIS; // r9
  MapStruct<CAkRegisteredObj *,CAkSIS *> *m_pItems; // rbx
  CAkSIS *item; // r10
  char *m_pProps; // r8
  unsigned int v10; // r9d
  int v11; // ecx
  __int64 v12; // rdx
  float *v13; // r9

  m_pMapSIS = this->m_pMapSIS;
  if ( m_pMapSIS )
  {
    m_pItems = m_pMapSIS->m_pItems;
    if ( m_pMapSIS->m_pItems != &m_pMapSIS->m_pItems[m_pMapSIS->m_uLength] )
    {
      do
      {
        item = m_pItems->item;
        m_pProps = item->m_values.m_pProps;
        if ( m_pProps )
        {
          v10 = (unsigned __int8)*m_pProps;
          v11 = 0;
          while ( 1 )
          {
            v12 = (unsigned int)(v11 + 1);
            if ( m_pProps[v12] == 10 )
              break;
            ++v11;
            if ( (unsigned int)v12 >= v10 )
              goto LABEL_11;
          }
          v13 = (float *)&m_pProps[16 * v11 + ((v10 + 4) & 0xFFFFFFFC)];
          if ( v13 )
          {
            if ( 1.0 != *v13 )
              ((void (__fastcall *)(CAkParameterNode *, CAkRegisteredObj *, _QWORD, _QWORD))this->vfptr[12].AddRef)(
                this,
                item->m_pGameObj,
                in_eFadeCurve,
                in_lTransitionTime);
          }
        }
LABEL_11:
        ++m_pItems;
      }
      while ( m_pItems != &this->m_pMapSIS->m_pItems[this->m_pMapSIS->m_uLength] );
    }
  }
}

// File Line: 613
// RVA: 0xA6F4B0
void __fastcall CAkParameterNode::UnmuteAll(
        CAkParameterNode *this,
        unsigned int in_eFadeCurve,
        unsigned int in_lTransitionTime)
{
  ((void (__fastcall *)(CAkParameterNode *, _QWORD, _QWORD, _QWORD))this->vfptr[12].AddRef)(
    this,
    0i64,
    in_eFadeCurve,
    in_lTransitionTime);
  ((void (__fastcall *)(CAkParameterNode *, _QWORD, _QWORD))this->vfptr[20].__vecDelDtor)(
    this,
    in_eFadeCurve,
    in_lTransitionTime);
}

// File Line: 619
// RVA: 0xA6F5F0
void __fastcall CAkParameterNode::Unregister(CAkParameterNode *this, CAkRegisteredObj *in_GameObjPtr)
{
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *m_pMapSIS; // rcx
  MapStruct<CAkRegisteredObj *,CAkSIS *> *m_pItems; // rbx
  CAkSIS *item; // rsi
  int v7; // edi
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *v8; // rdx
  unsigned __int64 v9; // rcx

  m_pMapSIS = this->m_pMapSIS;
  if ( m_pMapSIS )
  {
    m_pItems = m_pMapSIS->m_pItems;
    if ( m_pMapSIS->m_pItems != &m_pMapSIS->m_pItems[m_pMapSIS->m_uLength] )
    {
      do
      {
        if ( m_pItems->key == in_GameObjPtr )
        {
          item = m_pItems->item;
          if ( item )
          {
            v7 = g_DefaultPoolId;
            CAkSIS::~CAkSIS(m_pItems->item);
            AK::MemoryMgr::Free(v7, item);
          }
          v8 = this->m_pMapSIS;
          v9 = (unsigned __int64)&v8->m_pItems[v8->m_uLength - 1];
          if ( (unsigned __int64)m_pItems < v9 )
            qmemcpy(
              m_pItems,
              &m_pItems[1],
              8
            * (((((v9 - (unsigned __int64)m_pItems - 1) >> 3) & 0xFFFFFFFFFFFFFFFEui64) + 2) & 0x1FFFFFFFFFFFFFFEi64));
          --v8->m_uLength;
        }
        else
        {
          ++m_pItems;
        }
      }
      while ( m_pItems != &this->m_pMapSIS->m_pItems[this->m_pMapSIS->m_uLength] );
    }
  }
}

// File Line: 646
// RVA: 0xA6E200
void __fastcall CAkParameterNode::ResetAkProp(
        CAkParameterNode *this,
        unsigned int in_eProp,
        AkCurveInterpolation in_eFadeCurve,
        int in_lTransitionTime)
{
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *m_pMapSIS; // rdx
  int v6; // edi
  MapStruct<CAkRegisteredObj *,CAkSIS *> *m_pItems; // rbx
  CAkSIS *item; // r10
  char *m_pProps; // r8
  unsigned int v13; // r9d
  int v14; // ecx
  __int64 v15; // rdx
  float *v16; // rdx
  CAkSIS *m_pGlobalSIS; // rdx
  char *v18; // rdx
  unsigned int v19; // r8d
  __int64 v20; // rcx
  float *v21; // rcx

  m_pMapSIS = this->m_pMapSIS;
  v6 = 0;
  if ( m_pMapSIS )
  {
    m_pItems = m_pMapSIS->m_pItems;
    if ( m_pMapSIS->m_pItems != &m_pMapSIS->m_pItems[m_pMapSIS->m_uLength] )
    {
      do
      {
        item = m_pItems->item;
        m_pProps = item->m_values.m_pProps;
        if ( m_pProps )
        {
          v13 = (unsigned __int8)*m_pProps;
          v14 = 0;
          while ( 1 )
          {
            v15 = (unsigned int)(v14 + 1);
            if ( m_pProps[v15] == (_BYTE)in_eProp )
              break;
            ++v14;
            if ( (unsigned int)v15 >= v13 )
              goto LABEL_11;
          }
          v16 = (float *)&m_pProps[16 * v14 + ((v13 + 4) & 0xFFFFFFFC)];
          if ( v16 && *v16 != 0.0 )
            ((void (__fastcall *)(CAkParameterNode *, _QWORD, CAkRegisteredObj *, _QWORD, _DWORD, int, _DWORD))this->vfptr[11].Release)(
              this,
              in_eProp,
              item->m_pGameObj,
              0i64,
              0,
              4,
              0);
        }
LABEL_11:
        ++m_pItems;
      }
      while ( m_pItems != &this->m_pMapSIS->m_pItems[this->m_pMapSIS->m_uLength] );
    }
  }
  m_pGlobalSIS = this->m_pGlobalSIS;
  if ( m_pGlobalSIS )
  {
    v18 = m_pGlobalSIS->m_values.m_pProps;
    if ( v18 )
    {
      v19 = (unsigned __int8)*v18;
      while ( 1 )
      {
        v20 = (unsigned int)(v6 + 1);
        if ( v18[v20] == (_BYTE)in_eProp )
          break;
        ++v6;
        if ( (unsigned int)v20 >= v19 )
          return;
      }
      v21 = (float *)&v18[16 * v6 + ((v19 + 4) & 0xFFFFFFFC)];
      if ( v21 )
      {
        if ( *v21 != 0.0 )
          ((void (__fastcall *)(CAkParameterNode *, _QWORD, _QWORD, _QWORD, _DWORD, AkCurveInterpolation, int))this->vfptr[11].Release)(
            this,
            in_eProp,
            0i64,
            0i64,
            0,
            in_eFadeCurve,
            in_lTransitionTime);
      }
    }
  }
}

// File Line: 670
// RVA: 0xA6B910
CAkActionPlayAndContinue *__fastcall CreateDelayedAction(
        ContParams *in_pContinuousParams,
        AkPBIParams *in_rPBIParams,
        unsigned int in_uTargetElementID)
{
  CAkActionPlayAndContinue *result; // rax
  CAkActionPlayAndContinue *v7; // rbx
  __int64 v8; // [rsp+30h] [rbp+8h]

  result = CAkActionPlayAndContinue::Create(AkActionType_PlayAndContinue, 0, &in_pContinuousParams->spContList);
  v7 = result;
  if ( result )
  {
    result->m_ulPauseCount = in_pContinuousParams->ulPauseCount;
    CAkActionPlayAndContinue::SetHistory(result, &in_rPBIParams->playHistory);
    LODWORD(v8) = in_uTargetElementID;
    BYTE4(v8) = 0;
    ((void (__fastcall *)(CAkActionPlayAndContinue *, __int64))v7->vfptr[1].AddRef)(v7, v8);
    CAkActionPlayAndContinue::SetInstigator(v7, in_rPBIParams->pInstigator);
    CAkActionPlayAndContinue::SetSAInfo(v7, in_rPBIParams->sequenceID);
    CAkActionPlayAndContinue::SetIsFirstPlay(v7, in_rPBIParams->bIsFirst);
    CAkActionPlayAndContinue::SetInitialPlaybackState(v7, in_rPBIParams->ePlaybackState);
    return v7;
  }
  return result;
}

// File Line: 687
// RVA: 0xA6B9D0
__int64 __fastcall CreateDelayedPendingAction(
        ContParams *in_pContinuousParams,
        AkPBIParams *in_rPBIParams,
        unsigned int iDelaySamples,
        CAkActionPlayAndContinue *in_pAction)
{
  AkPendingAction *v8; // rax
  AkPendingAction *v9; // rax
  AkPendingAction *v10; // rdi
  unsigned int v11; // esi
  int v13; // ebx
  int v14; // ebx

  v8 = (AkPendingAction *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
  if ( !v8 )
    return 52i64;
  AkPendingAction::AkPendingAction(v8, in_rPBIParams->pGameObj);
  v10 = v9;
  if ( !v9 )
    return 52i64;
  if ( CAkActionPlayAndContinue::SetPlayStopTransition(
         in_pAction,
         in_pContinuousParams->pPlayStopTransition,
         in_pContinuousParams->bIsPlayStopTransitionFading,
         v9) != AK_Success
    || CAkActionPlayAndContinue::SetPauseResumeTransition(
         in_pAction,
         in_pContinuousParams->pPauseResumeTransition,
         in_pContinuousParams->bIsPauseResumeTransitionFading,
         v10) != AK_Success )
  {
    v14 = g_DefaultPoolId;
    ((void (__fastcall *)(AkPendingAction *, _QWORD))v10->vfptr[1].TransUpdateValue)(v10, 0i64);
    AK::MemoryMgr::Free(v14, v10);
    return 52i64;
  }
  CAkActionPlayAndContinue::SetPathInfo(in_pAction, in_pContinuousParams->pPathInfo);
  v11 = ((__int64 (__fastcall *)(CAkActionPlayAndContinue *, __int64, _QWORD))in_pAction->vfptr[1].Release)(
          in_pAction,
          14i64,
          iDelaySamples);
  if ( v11 == 1 )
  {
    v10->pAction = in_pAction;
    UserParams::operator=(&v10->UserParam, &in_rPBIParams->userParams);
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
__int64 __fastcall CAkParameterNode::DelayPlayback(CAkParameterNode *this, float in_fDelay, AkPBIParams *in_rPBIParams)
{
  unsigned int DelayedPendingAction; // esi
  CAkContinuationList *v6; // rax
  CAkContinuationList *v7; // rcx
  ContParams *pContinuousParams; // rbx
  CAkContinuationList *v9; // rax
  CAkContinuationList *v10; // rcx
  CAkActionPlayAndContinue *DelayedAction; // rax
  CAkActionPlayAndContinue *v12; // rdi
  double v13; // xmm2_8
  double v14; // xmm0_8
  __int64 v16; // [rsp+20h] [rbp-58h] BYREF
  int v17; // [rsp+28h] [rbp-50h]
  _QWORD v18[3]; // [rsp+30h] [rbp-48h] BYREF
  __int16 v19; // [rsp+48h] [rbp-30h]
  CAkContinuationList *v20; // [rsp+50h] [rbp-28h]
  int v21; // [rsp+58h] [rbp-20h]

  v18[0] = 0i64;
  v18[1] = 0i64;
  v16 = 0i64;
  v17 = 0;
  DelayedPendingAction = 52;
  v19 = 0;
  v20 = 0i64;
  v18[2] = &v16;
  v21 = 0;
  v6 = CAkContinuationList::Create();
  v7 = v20;
  v20 = v6;
  if ( v7 )
  {
    CAkContinuationList::Release(v7);
    v6 = v20;
  }
  if ( !v6 )
    return 2i64;
  pContinuousParams = in_rPBIParams->pContinuousParams;
  if ( !pContinuousParams )
  {
    v9 = CAkContinuationList::Create();
    v10 = v20;
    v20 = v9;
    if ( v10 )
    {
      CAkContinuationList::Release(v10);
      v9 = v20;
    }
    if ( v9 )
    {
      pContinuousParams = (ContParams *)v18;
      goto LABEL_9;
    }
    return 2i64;
  }
LABEL_9:
  DelayedAction = CreateDelayedAction(pContinuousParams, in_rPBIParams, this->key);
  v12 = DelayedAction;
  if ( DelayedAction )
  {
    DelayedAction->m_bSkipDelay = 1;
    DelayedAction->m_ePBIType = in_rPBIParams->eType;
    v13 = (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency * in_fDelay;
    if ( v13 <= 0.0 )
      v14 = DOUBLE_N0_5;
    else
      v14 = DOUBLE_0_5;
    DelayedPendingAction = CreateDelayedPendingAction(pContinuousParams, in_rPBIParams, (int)(v14 + v13), DelayedAction);
    v12->vfptr->Release(v12);
  }
  if ( v20 )
    CAkContinuationList::Release(v20);
  return DelayedPendingAction;
}

// File Line: 766
// RVA: 0xA6DE40
__int64 __fastcall CAkParameterNode::PlayAndContinueAlternate(CAkParameterNode *this, AkPBIParams *in_rPBIParams)
{
  ContParams *pContinuousParams; // rax
  unsigned int DelayedPendingAction; // ebp
  unsigned int v5; // edx
  __int64 m_iBitArray; // rcx
  CAkSmartPtr<CAkContinuationList> *p_spContList; // rdx
  CAkSmartPtr<CAkContinuationList> v8; // rcx
  __int64 m_uLength; // rax
  CAkContinueListItem *m_pItems; // rsi
  __int64 v11; // rbx
  CAkMultiPlayNode *m_pT; // rcx
  CAkParameterNodeBase *NextToPlayContinuous; // rdx
  unsigned int v15; // edx
  __int64 v16; // rcx
  CAkContinuationList *v17; // rbx
  CAkContinuationList *v18; // rbx
  ContParams *v19; // rdx
  unsigned int key; // r15d
  AkTransitionMode v21; // r14d
  float v22; // xmm0_4
  CAkActionPlayAndContinue *DelayedAction; // rbx
  double v24; // xmm1_8
  double v25; // xmm0_8
  signed int v26; // r8d
  ContParams *v27; // rdx
  CAkContinuationList *v28; // rcx
  unsigned __int16 out_rwPositionSelected; // [rsp+78h] [rbp+10h] BYREF
  unsigned int out_uSelectedNodeID; // [rsp+80h] [rbp+18h] BYREF

  pContinuousParams = in_rPBIParams->pContinuousParams;
  DelayedPendingAction = 2;
  if ( !pContinuousParams || !pContinuousParams->spContList.m_pT )
    return 2i64;
  if ( in_rPBIParams->playHistory.HistArray.uiArraySize )
  {
    do
    {
      v5 = in_rPBIParams->playHistory.HistArray.uiArraySize - 1;
      if ( v5 < 0x20 )
      {
        m_iBitArray = in_rPBIParams->playHistory.arrayIsContinuous.m_iBitArray;
        if ( _bittest64(&m_iBitArray, v5) )
          break;
      }
      in_rPBIParams->playHistory.HistArray.uiArraySize = v5;
    }
    while ( v5 );
  }
  p_spContList = &in_rPBIParams->pContinuousParams->spContList;
  out_rwPositionSelected = 0;
  for ( v8.m_pT = p_spContList->m_pT; v8.m_pT->m_listItems.m_uLength; p_spContList = &v19->spContList )
  {
    m_uLength = v8.m_pT->m_listItems.m_uLength;
    m_pItems = v8.m_pT->m_listItems.m_pItems;
    v11 = m_uLength;
    m_pT = v8.m_pT->m_listItems.m_pItems[m_uLength - 1].m_pMultiPlayNode.m_pT;
    if ( m_pT )
    {
      CAkMultiPlayNode::ContGetList(m_pT, m_pItems[m_uLength - 1].m_pAlternateContList, p_spContList);
      v18 = in_rPBIParams->pContinuousParams->spContList.m_pT;
      CAkContinueListItem::~CAkContinueListItem(&v18->m_listItems.m_pItems[v18->m_listItems.m_uLength - 1]);
      --v18->m_listItems.m_uLength;
      if ( !in_rPBIParams->pContinuousParams->spContList.m_pT )
      {
        DelayedPendingAction = 3;
        break;
      }
    }
    else
    {
      NextToPlayContinuous = CAkRanSeqCntr::GetNextToPlayContinuous(
                               m_pItems[m_uLength - 1].m_pContainer.m_pT,
                               in_rPBIParams->pGameObj,
                               &out_rwPositionSelected,
                               &out_uSelectedNodeID,
                               &m_pItems[m_uLength - 1].m_pContainerInfo,
                               &m_pItems[m_uLength - 1].m_LoopingInfo);
      if ( NextToPlayContinuous )
      {
        in_rPBIParams->playHistory.HistArray.aCntrHist[in_rPBIParams->playHistory.HistArray.uiArraySize - 1] = out_rwPositionSelected;
        key = NextToPlayContinuous->key;
        NextToPlayContinuous->vfptr->Release(NextToPlayContinuous);
        v21 = CAkRanSeqCntr::TransitionMode(m_pItems[v11 - 1].m_pContainer.m_pT);
        v22 = CAkRanSeqCntr::TransitionTime(m_pItems[v11 - 1].m_pContainer.m_pT, in_rPBIParams->pGameObj);
        if ( key )
        {
          DelayedAction = CreateDelayedAction(in_rPBIParams->pContinuousParams, in_rPBIParams, key);
          if ( DelayedAction )
          {
            if ( v21 != Transition_Delay
              || ((v24 = (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency * v22 * 0.001, v24 <= 0.0)
                ? (v25 = DOUBLE_N0_5)
                : (v25 = DOUBLE_0_5),
                  v26 = (int)(v25 + v24),
                  v26 < 10240) )
            {
              v26 = 10240;
            }
            DelayedPendingAction = CreateDelayedPendingAction(
                                     in_rPBIParams->pContinuousParams,
                                     in_rPBIParams,
                                     v26,
                                     DelayedAction);
            DelayedAction->vfptr->Release(DelayedAction);
          }
        }
        break;
      }
      if ( in_rPBIParams->playHistory.HistArray.uiArraySize-- != 1 )
      {
        do
        {
          v15 = in_rPBIParams->playHistory.HistArray.uiArraySize - 1;
          if ( v15 < 0x20 )
          {
            v16 = in_rPBIParams->playHistory.arrayIsContinuous.m_iBitArray;
            if ( _bittest64(&v16, v15) )
              break;
          }
          in_rPBIParams->playHistory.HistArray.uiArraySize = v15;
        }
        while ( v15 );
      }
      v17 = in_rPBIParams->pContinuousParams->spContList.m_pT;
      CAkContinueListItem::~CAkContinueListItem(&v17->m_listItems.m_pItems[v17->m_listItems.m_uLength - 1]);
      --v17->m_listItems.m_uLength;
    }
    v19 = in_rPBIParams->pContinuousParams;
    v8.m_pT = v19->spContList.m_pT;
  }
  v27 = in_rPBIParams->pContinuousParams;
  if ( v27->spContList.m_pT && ((DelayedPendingAction - 1) & 0xFFFFFFFD) != 0 )
  {
    v28 = v27->spContList.m_pT;
    v27->spContList.m_pT = 0i64;
    if ( v28 )
      CAkContinuationList::Release(v28);
  }
  return DelayedPendingAction;
}

// File Line: 882
// RVA: 0xA6C010
__int64 __fastcall CAkParameterNode::ExecuteActionExceptParentCheck(
        CAkParameterNode *this,
        ActionParamsExcept *in_rAction)
{
  CAkParameterNodeBase *m_pParentNode; // rbx

  m_pParentNode = this->m_pParentNode;
  if ( !m_pParentNode )
    return ((__int64 (__fastcall *)(CAkParameterNode *, ActionParamsExcept *))this->vfptr[4].AddRef)(this, in_rAction);
  while ( !CAkParameterNodeBase::IsException(m_pParentNode, in_rAction->pExeceptionList) )
  {
    m_pParentNode = m_pParentNode->m_pParentNode;
    if ( !m_pParentNode )
      return ((__int64 (__fastcall *)(CAkParameterNode *, ActionParamsExcept *))this->vfptr[4].AddRef)(this, in_rAction);
  }
  return 1i64;
}

// File Line: 901
// RVA: 0xA6EF90
__int64 __fastcall CAkParameterNode::SetInitialParams(
        CAkParameterNode *this,
        char **io_rpData,
        unsigned int *io_rulDataSize)
{
  __int64 result; // rax

  if ( (unsigned int)AkPropBundle<AkPropValue>::SetInitialParams(&this->m_props, io_rpData, io_rulDataSize) != 1 )
    return 2i64;
  result = AkPropBundle<RANGED_MODIFIERS<AkPropValue>>::SetInitialParams(&this->m_ranges, io_rpData, io_rulDataSize);
  if ( (_DWORD)result != 1 )
    return 2i64;
  *((_BYTE *)&this->CAkParameterNodeBase + 82) |= 0x80u;
  return result;
}

// File Line: 917
// RVA: 0xA6ECE0
__int64 __fastcall CAkParameterNode::SetInitialFxParams(
        CAkParameterNode *this,
        char **io_rpData,
        unsigned int *io_rulDataSize,
        bool in_bPartialLoadOnly)
{
  char v6; // cl
  AKRESULT v8; // r14d
  char *v9; // rax
  unsigned int v10; // ecx
  unsigned int v11; // r12d
  int v12; // edi
  char *v13; // rax
  unsigned int v14; // ecx
  unsigned int v15; // r15d
  char v16; // dl
  char v17; // bl
  unsigned int in_bitsFXBypass; // [rsp+20h] [rbp-48h]
  unsigned int in_uFXIndex; // [rsp+78h] [rbp+10h]
  char v21; // [rsp+88h] [rbp+20h]

  v6 = **io_rpData;
  v8 = AK_Success;
  ++*io_rpData;
  if ( !in_bPartialLoadOnly )
  {
    *((_BYTE *)&this->CAkParameterNodeBase + 83) &= ~0x40u;
    *((_BYTE *)&this->CAkParameterNodeBase + 83) |= (v6 != 0) << 6;
  }
  v9 = *io_rpData + 1;
  v10 = (unsigned __int8)**io_rpData;
  *io_rpData = v9;
  v11 = v10;
  if ( !(_BYTE)v10 )
    return 1i64;
  v12 = 0;
  in_bitsFXBypass = (unsigned __int8)*v9;
  *io_rpData = v9 + 1;
  while ( 1 )
  {
    v13 = *io_rpData + 1;
    v14 = (unsigned __int8)**io_rpData;
    *io_rpData = v13;
    v13 += 4;
    v15 = *((_DWORD *)v13 - 1);
    *io_rpData = v13;
    v16 = *v13++;
    v21 = v16;
    in_uFXIndex = v14;
    *io_rpData = v13;
    v17 = *v13;
    *io_rpData = v13 + 1;
    CAkParameterNodeBase::RenderedFX(this, v14, v17 != 0);
    if ( !v17 )
    {
      if ( v15 )
      {
        if ( !in_bPartialLoadOnly )
        {
          v8 = CAkParameterNodeBase::SetFX(this, in_uFXIndex, v15, v21 != 0);
          if ( v8 != AK_Success )
            break;
        }
      }
    }
    if ( ++v12 >= v11 )
    {
      if ( in_bPartialLoadOnly )
        return (unsigned int)v8;
      break;
    }
  }
  CAkParameterNodeBase::MainBypassFX(this, in_bitsFXBypass, 0xFFFFFFFF);
  return (unsigned int)v8;
}

// File Line: 980
// RVA: 0xA6BF80
__int64 __fastcall CAkParameterNode::Enable3DPosParams(CAkParameterNode *this)
{
  CAkGen3DParams *v2; // rax
  CAkGen3DParamsEx *v3; // rdi
  __int64 result; // rax

  if ( this->m_p3DParameters )
    return 1i64;
  *((_BYTE *)&this->CAkParameterNodeBase + 83) |= 0x10u;
  v2 = (CAkGen3DParams *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x68ui64);
  v3 = (CAkGen3DParamsEx *)v2;
  if ( !v2 )
    return 52i64;
  CAkGen3DParams::CAkGen3DParams(v2);
  result = 1i64;
  v3->vfptr = (CAkGen3DParamsVtbl *)&CAkGen3DParamsEx::`vftable;
  v3->m_PathState.ulCurrentListIndex = 0;
  v3->m_PathState.pbPlayed = 0i64;
  v3->m_Params.m_ID = this->key;
  this->m_p3DParameters = v3;
  return result;
}

// File Line: 1006
// RVA: 0xA6BE70
void __fastcall CAkParameterNode::DisablePosParams(CAkParameterNode *this)
{
  CAkGen3DParamsEx *m_p3DParameters; // rcx
  CAkGen3DParamsEx *v3; // rdi
  int v4; // esi

  m_p3DParameters = this->m_p3DParameters;
  if ( m_p3DParameters )
  {
    CAkGen3DParamsEx::FreePathInfo(m_p3DParameters);
    CAkGen3DParams::Term(this->m_p3DParameters);
    v3 = this->m_p3DParameters;
    v4 = g_DefaultPoolId;
    if ( v3 )
    {
      v3->vfptr->__vecDelDtor(v3, 0);
      AK::MemoryMgr::Free(v4, v3);
    }
    this->m_p3DParameters = 0i64;
  }
}

// File Line: 1022
// RVA: 0xA6E130
void __fastcall CAkParameterNode::PosSetPositioningType(
        CAkParameterNode *this,
        bool in_bOverride,
        bool in_bRTPC,
        AkPannerType in_ePanner,
        AkPositionSourceType in_ePosSource)
{
  char v5; // di

  *((_BYTE *)&this->CAkParameterNodeBase + 83) &= ~0x10u;
  v5 = in_ePanner;
  *((_BYTE *)&this->CAkParameterNodeBase + 83) |= 16 * in_bOverride;
  if ( in_bOverride )
  {
    CAkParameterNode::Enable3DPosParams(this);
    *((_BYTE *)this + 145) &= 0xF0u;
    *((_BYTE *)this + 145) |= v5 & 3 | (unsigned __int8)(4 * (in_ePosSource & 3));
  }
  else
  {
    CAkParameterNode::DisablePosParams(this);
    *((_BYTE *)this + 145) &= 0xFCu;
  }
  if ( !in_bRTPC )
    ((void (__fastcall *)(CAkParameterNode *, CAkIndexableVtbl *, __int64))this->vfptr[17].Release)(
      this,
      this->vfptr,
      10i64);
}

// File Line: 1206
// RVA: 0xA6C0B0
void __fastcall CAkParameterNode::Get3DCloneForObject(
        CAkParameterNode *this,
        CAkGen3DParams **in_rp3DParams,
        AkPositionSourceType *out_ePosType)
{
  CAkGen3DParams *v5; // rax
  CAkGen3DParamsEx *m_p3DParameters; // rcx
  _QWORD *v7; // rdx

  *out_ePosType = (*((unsigned __int8 *)this + 145) >> 2) & 3;
  if ( this->m_p3DParameters )
  {
    if ( *in_rp3DParams )
      goto LABEL_6;
    v5 = (CAkGen3DParams *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x58ui64);
    if ( v5 )
      CAkGen3DParams::CAkGen3DParams(v5);
    *in_rp3DParams = v5;
    if ( v5 )
    {
LABEL_6:
      m_p3DParameters = this->m_p3DParameters;
      v7 = *in_rp3DParams;
      v7[1] = *(_QWORD *)&m_p3DParameters->m_Params.m_ID;
      v7[2] = *(_QWORD *)&m_p3DParameters->m_Params.m_fConeOutsideVolume;
      v7[3] = *(_QWORD *)&m_p3DParameters->m_Params.m_Position.X;
      v7[4] = *(_QWORD *)&m_p3DParameters->m_Params.m_Position.Z;
      v7[5] = *(_QWORD *)&m_p3DParameters->m_Params.m_TransitionTime;
      v7[6] = m_p3DParameters->m_Params.m_pArrayVertex;
      v7[7] = *(_QWORD *)&m_p3DParameters->m_Params.m_ulNumVertices;
      v7[8] = m_p3DParameters->m_Params.m_pArrayPlaylist;
      v7[9] = *(_QWORD *)&m_p3DParameters->m_Params.m_ulNumPlaylistItem;
      v7[10] = m_p3DParameters->m_Params.m_pAttenuation;
    }
  }
}

// File Line: 1224
// RVA: 0xA6D6D0
CAkSIS *__fastcall CAkParameterNode::GetSIS(CAkParameterNode *this, CAkRegisteredObj *in_GameObjPtr)
{
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *m_pMapSIS; // rcx
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *v5; // rax
  MapStruct<CAkRegisteredObj *,CAkSIS *> *m_pItems; // rax
  __int64 v8; // rcx
  CAkSIS *v9; // rdi
  CAkParameterNodeBase::FXChunk *v10; // rax
  char v11; // r14
  CAkSIS *v12; // rax
  int v13; // ebx
  CAkParameterNodeBase::FXChunk *m_pFXChunk; // rax
  char bitsMainFXBypass; // di
  CAkSIS *v16; // rax

  if ( !in_GameObjPtr )
  {
    CAkRegistryMgr::SetNodeIDAsModified(g_pRegistryMgr, this);
    if ( !this->m_pGlobalSIS )
    {
      m_pFXChunk = this->m_pFXChunk;
      if ( m_pFXChunk )
        bitsMainFXBypass = m_pFXChunk->bitsMainFXBypass;
      else
        bitsMainFXBypass = 0;
      v16 = (CAkSIS *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x28ui64);
      if ( v16 )
      {
        v16->m_pParamNode = this;
        v16->m_pGameObj = 0i64;
        v16->vfptr = (ITransitionableVtbl *)&CAkSIS::`vftable;
        v16->m_values.m_pProps = 0i64;
        v16->m_bitsFXBypass = bitsMainFXBypass;
      }
      else
      {
        v16 = 0i64;
      }
      this->m_pGlobalSIS = v16;
    }
    return this->m_pGlobalSIS;
  }
  m_pMapSIS = this->m_pMapSIS;
  if ( !m_pMapSIS )
  {
    v5 = (CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x10ui64);
    this->m_pMapSIS = v5;
    if ( v5 )
    {
      v5->m_pItems = 0i64;
      *(_QWORD *)&v5->m_uLength = 0i64;
    }
    m_pMapSIS = this->m_pMapSIS;
    if ( !m_pMapSIS )
      return 0i64;
  }
  m_pItems = m_pMapSIS->m_pItems;
  v8 = (__int64)&m_pMapSIS->m_pItems[m_pMapSIS->m_uLength];
  if ( m_pItems == (MapStruct<CAkRegisteredObj *,CAkSIS *> *)v8 )
    goto LABEL_13;
  do
  {
    if ( m_pItems->key == in_GameObjPtr )
      break;
    ++m_pItems;
  }
  while ( m_pItems != (MapStruct<CAkRegisteredObj *,CAkSIS *> *)v8 );
  if ( m_pItems == (MapStruct<CAkRegisteredObj *,CAkSIS *> *)v8
    || m_pItems == (MapStruct<CAkRegisteredObj *,CAkSIS *> *)-8i64 )
  {
LABEL_13:
    v10 = this->m_pFXChunk;
    if ( v10 )
      v11 = v10->bitsMainFXBypass;
    else
      v11 = 0;
    v12 = (CAkSIS *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x28ui64);
    v9 = v12;
    if ( v12 )
    {
      v12->m_pParamNode = this;
      v12->m_pGameObj = in_GameObjPtr;
      v12->vfptr = (ITransitionableVtbl *)&CAkSIS::`vftable;
      v12->m_values.m_pProps = 0i64;
      v12->m_bitsFXBypass = v11;
      if ( CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4>::Set(
             (CAkKeyArray<CAkRSSub *,CAkContainerBaseInfo *,4> *)this->m_pMapSIS,
             (CAkRSSub *)in_GameObjPtr,
             (CAkContainerBaseInfo *)v12) )
      {
        if ( (unsigned int)CAkRegisteredObj::SetNodeAsModified(in_GameObjPtr, this) == 1 )
          return v9;
        CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4>::Unset(this->m_pMapSIS, in_GameObjPtr);
      }
      v13 = g_DefaultPoolId;
      CAkSIS::~CAkSIS(v9);
      AK::MemoryMgr::Free(v13, v9);
    }
    return 0i64;
  }
  return m_pItems->item;
}

// File Line: 1280
// RVA: 0xA6D890
__int64 __fastcall CAkParameterNode::GetVirtualBehavior(CAkParameterNode *this, AkVirtualQueueBehavior *out_Behavior)
{
  CAkParameterNodeBase *m_pParentNode; // rax

  if ( (*((_BYTE *)&this->CAkParameterNodeBase + 82) & 4) == 0 )
  {
    do
    {
      m_pParentNode = this->m_pParentNode;
      if ( !m_pParentNode )
        break;
      this = (CAkParameterNode *)this->m_pParentNode;
    }
    while ( (*((_BYTE *)m_pParentNode + 82) & 4) == 0 );
  }
  *out_Behavior = *((_BYTE *)this + 144) & 7;
  return (*((unsigned __int8 *)this + 144) >> 3) & 0xF;
}

// File Line: 1293
// RVA: 0xA6DA90
bool __fastcall CAkParameterNode::Has3DParams(CAkParameterNode *this)
{
  return this->m_p3DParameters != 0i64;
}

// File Line: 1298
// RVA: 0xA6F000
__int64 __fastcall CAkParameterNode::SetPositioningParams(
        CAkParameterNode *this,
        char **io_rpData,
        unsigned int *io_rulDataSize)
{
  char v5; // r8
  char *v6; // rax
  char v7; // cl
  char *v8; // rax
  char v9; // dl
  char v10; // cl
  __int64 result; // rax
  AKRESULT v12; // r8d
  CAkGen3DParamsEx *m_p3DParameters; // rdx
  int v14; // ecx
  unsigned int v15; // ecx
  unsigned int *v16; // rax
  char v17; // cl
  AkPathMode v18; // ecx
  int v19; // ecx
  unsigned int v20; // esi
  AkPathVertex *v21; // rdx
  unsigned int v22; // r10d
  char *v23; // rcx
  unsigned int v24; // ebp
  __int64 in_ulNumPlaylistItem; // r14
  char *v26; // r9
  CAkGen3DParamsEx *v27; // rcx
  __int64 v28; // r10
  __int64 v29; // rdx
  char *v30; // rax
  float v31; // xmm0_4
  float v32; // xmm1_4
  CAkGen3DParamsEx *v33; // rax
  char *v34; // rax
  CAkGen3DParamsEx *v35; // rcx
  float v36; // xmm1_4
  char *v37; // rax
  float v38; // xmm0_4
  float v39; // xmm1_4
  CAkGen3DParamsEx *v40; // rax
  char *v41; // rax
  CAkGen3DParamsEx *v42; // rcx
  float v43; // xmm1_4
  __int64 v44; // rdx
  char *v45; // rax
  float v46; // xmm0_4
  float v47; // xmm1_4
  CAkGen3DParamsEx *v48; // rax

  v5 = *(*io_rpData)++;
  *((_BYTE *)&this->CAkParameterNodeBase + 83) &= ~0x10u;
  *((_BYTE *)&this->CAkParameterNodeBase + 83) |= 16 * (v5 != 0);
  if ( (*((_BYTE *)&this->CAkParameterNodeBase + 83) & 0x10) == 0 )
    return 1i64;
  v6 = *io_rpData + 1;
  v7 = **io_rpData;
  *io_rpData = v6;
  v8 = v6 + 1;
  v9 = *(v8 - 1);
  *io_rpData = v8;
  if ( v7 )
  {
    v10 = *v8;
    *io_rpData = v8 + 1;
    *((_BYTE *)&this->CAkParameterNodeBase + 83) &= ~0x20u;
    *((_BYTE *)&this->CAkParameterNodeBase + 83) |= 32 * (v10 != 0);
    *((_BYTE *)this + 145) &= 0xFCu;
  }
  if ( !v9 )
    return 1i64;
  result = CAkParameterNode::Enable3DPosParams(this);
  *((_BYTE *)this + 145) &= ~2u;
  *((_BYTE *)this + 145) |= 1u;
  v12 = (int)result;
  if ( (_DWORD)result == 1 )
  {
    m_p3DParameters = this->m_p3DParameters;
    v14 = *(_DWORD *)*io_rpData;
    *io_rpData += 4;
    *((_BYTE *)this + 145) &= 0xF3u;
    *((_BYTE *)this + 145) |= 4 * (v14 & 3);
    v15 = *(_DWORD *)*io_rpData;
    *io_rpData += 4;
    m_p3DParameters->m_Params.m_uAttenuationID = v15;
    LOBYTE(v15) = *(*io_rpData)++;
    *((_BYTE *)&m_p3DParameters->m_Params + 68) &= ~1u;
    *((_BYTE *)&m_p3DParameters->m_Params + 68) |= (_BYTE)v15 != 0;
    v16 = (unsigned int *)*io_rpData;
    if ( (*((_BYTE *)this + 145) & 0xC) == 4 )
    {
      v17 = *(_BYTE *)v16;
      *io_rpData = (char *)v16 + 1;
      *((_BYTE *)&m_p3DParameters->m_Params + 68) &= ~8u;
      *((_BYTE *)&m_p3DParameters->m_Params + 68) |= 8 * (v17 != 0);
      return 1i64;
    }
    else
    {
      v18 = *v16;
      *io_rpData = (char *)(v16 + 1);
      m_p3DParameters->m_Params.m_ePathMode = v18;
      LOBYTE(v18) = *(*io_rpData)++;
      *((_BYTE *)&m_p3DParameters->m_Params + 68) &= ~0x20u;
      *((_BYTE *)&m_p3DParameters->m_Params + 68) |= 32 * ((_BYTE)v18 != AkStepSequence);
      v19 = *(_DWORD *)*io_rpData;
      *io_rpData += 4;
      m_p3DParameters->m_Params.m_TransitionTime = v19;
      LOBYTE(v19) = *(*io_rpData)++;
      *((_BYTE *)&m_p3DParameters->m_Params + 68) &= ~0x10u;
      v20 = 0;
      *((_BYTE *)&m_p3DParameters->m_Params + 68) |= 16 * ((_BYTE)v19 != 0);
      v21 = 0i64;
      v22 = *(_DWORD *)*io_rpData;
      v23 = *io_rpData + 4;
      *io_rpData = v23;
      if ( v22 )
      {
        v21 = (AkPathVertex *)v23;
        *io_rpData = &v23[16 * v22];
      }
      v24 = 2;
      in_ulNumPlaylistItem = *(unsigned int *)*io_rpData;
      v26 = *io_rpData + 4;
      *io_rpData = v26;
      if ( (_DWORD)in_ulNumPlaylistItem )
      {
        *io_rpData = &v26[8 * in_ulNumPlaylistItem];
        if ( v22 )
        {
          v27 = this->m_p3DParameters;
          if ( v27 )
            v12 = CAkGen3DParams::SetPath(v27, v21, v22, (AkPathListItemOffset *)v26, in_ulNumPlaylistItem);
          else
            v12 = AK_Fail;
        }
      }
      v28 = 0i64;
      if ( (int)in_ulNumPlaylistItem >= 4 )
      {
        v29 = 0i64;
        v28 = 4i64 * (((unsigned int)(in_ulNumPlaylistItem - 4) >> 2) + 1);
        do
        {
          v30 = *io_rpData + 8;
          *io_rpData = v30;
          v31 = *((float *)v30 - 2);
          v32 = *((float *)v30 - 1);
          v33 = this->m_p3DParameters;
          if ( v33 && v20 < v33->m_Params.m_ulNumPlaylistItem )
          {
            v33->m_Params.m_pArrayPlaylist[v29].fRangeX = v31;
            this->m_p3DParameters->m_Params.m_pArrayPlaylist[v29].fRangeY = v32;
          }
          v34 = *io_rpData + 8;
          *io_rpData = v34;
          v35 = this->m_p3DParameters;
          v36 = *((float *)v34 - 1);
          if ( v35 && v24 - 1 < v35->m_Params.m_ulNumPlaylistItem )
          {
            v35->m_Params.m_pArrayPlaylist[v29 + 1].fRangeX = *((float *)v34 - 2);
            this->m_p3DParameters->m_Params.m_pArrayPlaylist[v29 + 1].fRangeY = v36;
          }
          v37 = *io_rpData + 8;
          *io_rpData = v37;
          v38 = *((float *)v37 - 2);
          v39 = *((float *)v37 - 1);
          v40 = this->m_p3DParameters;
          if ( v40 && v24 < v40->m_Params.m_ulNumPlaylistItem )
          {
            v40->m_Params.m_pArrayPlaylist[v29 + 2].fRangeX = v38;
            this->m_p3DParameters->m_Params.m_pArrayPlaylist[v29 + 2].fRangeY = v39;
          }
          v41 = *io_rpData + 8;
          *io_rpData = v41;
          v42 = this->m_p3DParameters;
          v43 = *((float *)v41 - 1);
          if ( v42 && v24 + 1 < v42->m_Params.m_ulNumPlaylistItem )
          {
            v42->m_Params.m_pArrayPlaylist[v29 + 3].fRangeX = *((float *)v41 - 2);
            this->m_p3DParameters->m_Params.m_pArrayPlaylist[v29 + 3].fRangeY = v43;
          }
          v20 += 4;
          v29 += 4i64;
          v24 += 4;
        }
        while ( v20 < (int)in_ulNumPlaylistItem - 3 );
      }
      if ( v20 < (unsigned int)in_ulNumPlaylistItem )
      {
        v44 = v28;
        do
        {
          v45 = *io_rpData + 8;
          *io_rpData = v45;
          v46 = *((float *)v45 - 2);
          v47 = *((float *)v45 - 1);
          v48 = this->m_p3DParameters;
          if ( v48 )
          {
            if ( v20 < v48->m_Params.m_ulNumPlaylistItem )
            {
              v48->m_Params.m_pArrayPlaylist[v44].fRangeX = v46;
              this->m_p3DParameters->m_Params.m_pArrayPlaylist[v44].fRangeY = v47;
            }
          }
          ++v20;
          ++v44;
        }
        while ( v20 < (unsigned int)in_ulNumPlaylistItem );
      }
      return (unsigned int)v12;
    }
  }
  return result;
}

// File Line: 1379
// RVA: 0xA6EC00
__int64 __fastcall CAkParameterNode::SetAuxParams(
        CAkParameterNode *this,
        char **io_rpData,
        unsigned int *io_rulDataSize)
{
  char v5; // r8
  char v6; // cl
  char v7; // cl
  char v8; // cl
  bool v9; // bp
  signed int i; // ebx
  unsigned int v11; // edx
  __int64 result; // rax

  v5 = *(*io_rpData)++;
  *((_BYTE *)this + 145) &= ~0x10u;
  *((_BYTE *)this + 145) |= 16 * (v5 != 0);
  v6 = *(*io_rpData)++;
  *((_BYTE *)this + 145) &= ~0x20u;
  *((_BYTE *)this + 145) |= 32 * (v6 != 0);
  v7 = *(*io_rpData)++;
  *((_BYTE *)this + 145) &= ~0x40u;
  *((_BYTE *)this + 145) |= (v7 != 0) << 6;
  v8 = *(*io_rpData)++;
  v9 = v8 != 0;
  for ( i = 0; i < 4; ++i )
  {
    v11 = 0;
    if ( v9 )
    {
      v11 = *(_DWORD *)*io_rpData;
      *io_rpData += 4;
    }
    result = CAkParameterNode::SetAuxBusSend(this, v11, i);
    if ( (_DWORD)result != 1 )
      break;
  }
  return result;
}

// File Line: 1403
// RVA: 0xA6E520
__int64 __fastcall CAkParameterNode::SetAdvSettingsParams(
        CAkParameterNode *this,
        char **io_rpData,
        unsigned int *io_rulDataSize)
{
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
  *((_BYTE *)&this->CAkParameterNodeBase + 82) &= ~0x10u;
  *((_BYTE *)&this->CAkParameterNodeBase + 82) |= 16 * (v9 != 0);
  v10 = **io_rpData;
  v11 = *io_rpData + 1;
  *io_rpData = v11;
  v12 = *v11++;
  *io_rpData = v11;
  v13 = *v11++;
  *io_rpData = v11;
  v14 = *v11;
  *io_rpData = v11 + 1;
  *((_BYTE *)this + 145) &= ~0x80u;
  *((_BYTE *)this + 145) |= v14 << 7;
  v15 = *(*io_rpData)++;
  *((_BYTE *)this + 146) &= ~1u;
  *((_BYTE *)this + 146) |= v15 & 1;
  v16 = *(*io_rpData)++;
  *((_BYTE *)this + 146) &= ~2u;
  *((_BYTE *)this + 146) |= 2 * (v16 & 1);
  v17 = *(*io_rpData)++;
  *((_BYTE *)this + 146) &= ~4u;
  *((_BYTE *)this + 144) &= 0xF8u;
  *((_BYTE *)this + 144) |= v4 & 7;
  *((_BYTE *)this + 146) |= 4 * (v17 & 1);
  CAkParameterNodeBase::SetMaxReachedBehavior(this, v6 != 0);
  CAkParameterNodeBase::SetOverLimitBehavior(this, v7 != 0);
  *((_BYTE *)this + 144) ^= (*((_BYTE *)this + 144) ^ (8 * v10)) & 0x78;
  CAkParameterNodeBase::SetMaxNumInstOverrideParent(this, v12 != 0);
  CAkParameterNodeBase::SetVVoicesOptOverrideParent(this, v13 != 0);
  return 1i64;
}

// File Line: 1436
// RVA: 0xA6D320
void __fastcall CAkParameterNode::GetFX(
        CAkParameterNode *this,
        unsigned int in_uFXIndex,
        AkFXDesc *out_rFXInfo,
        CAkRegisteredObj *in_GameObj)
{
  __int64 v6; // rsi
  CAkParameterNodeBase *m_pParentNode; // rcx
  CAkParameterNodeBase::FXChunk *m_pFXChunk; // rcx
  unsigned int id; // edx
  CAkFxBase *PtrAndAddRef; // rax
  CAkFxBase *m_pT; // rcx
  CAkFxBase *v13; // rcx

  v6 = in_uFXIndex;
  if ( (*((_BYTE *)&this->CAkParameterNodeBase + 83) & 0x40) != 0 || (m_pParentNode = this->m_pParentNode) == 0i64 )
  {
    m_pFXChunk = this->m_pFXChunk;
    if ( m_pFXChunk )
    {
      id = m_pFXChunk->aFX[in_uFXIndex].id;
      if ( id )
      {
        if ( m_pFXChunk->aFX[v6].bShareSet )
          PtrAndAddRef = (CAkFxBase *)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(&g_pIndex->m_idxFxShareSets, id);
        else
          PtrAndAddRef = (CAkFxBase *)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                                        (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxFxCustom,
                                        id);
        m_pT = out_rFXInfo->pFx.m_pT;
        out_rFXInfo->pFx.m_pT = PtrAndAddRef;
      }
      else
      {
        m_pT = out_rFXInfo->pFx.m_pT;
        out_rFXInfo->pFx.m_pT = 0i64;
      }
      if ( m_pT )
        m_pT->vfptr->Release(m_pT);
      out_rFXInfo->bIsBypassed = CAkParameterNode::GetBypassFX(this, v6, in_GameObj);
    }
    else
    {
      v13 = out_rFXInfo->pFx.m_pT;
      out_rFXInfo->pFx.m_pT = 0i64;
      if ( v13 )
        v13->vfptr->Release(v13);
      out_rFXInfo->bIsBypassed = 0;
    }
  }
  else
  {
    m_pParentNode->vfptr[14].__vecDelDtor(m_pParentNode, in_uFXIndex);
  }
}

// File Line: 1475
// RVA: 0xA6D400
void __fastcall CAkParameterNode::GetFXDataID(
        CAkParameterNode *this,
        unsigned int in_uFXIndex,
        unsigned int in_uDataIndex,
        unsigned int *out_rDataID)
{
  __int64 v6; // r11
  CAkParameterNodeBase *m_pParentNode; // r10
  CAkParameterNodeBase::FXChunk *m_pFXChunk; // rdx
  bool v9; // zf
  unsigned int id; // edx
  CAkIndexable *v11; // rax
  unsigned int *v12; // rdx
  _DWORD *v13; // rax
  _DWORD *v14; // rcx
  unsigned int *v15; // rax
  unsigned int v16; // ecx

  v6 = in_uFXIndex;
  if ( (*((_BYTE *)&this->CAkParameterNodeBase + 83) & 0x40) != 0 || (m_pParentNode = this->m_pParentNode) == 0i64 )
  {
    *out_rDataID = -1;
    m_pFXChunk = this->m_pFXChunk;
    if ( m_pFXChunk )
    {
      v9 = !m_pFXChunk->aFX[v6].bShareSet;
      id = m_pFXChunk->aFX[v6].id;
      v11 = v9
          ? CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
              (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxFxCustom,
              id)
          : CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(&g_pIndex->m_idxFxShareSets, id);
      v12 = (unsigned int *)v11;
      if ( v11 )
      {
        v13 = *(_DWORD **)&v11[1].key;
        v14 = &v13[2 * v12[12]];
        if ( v13 == v14 )
          goto LABEL_15;
        do
        {
          if ( *v13 == in_uDataIndex )
            break;
          v13 += 2;
        }
        while ( v13 != v14 );
        if ( v13 == v14 || (v15 = v13 + 1) == 0i64 )
LABEL_15:
          v16 = 0;
        else
          v16 = *v15;
        *out_rDataID = v16;
        (*(void (__fastcall **)(unsigned int *))(*(_QWORD *)v12 + 16i64))(v12);
      }
    }
  }
  else
  {
    ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD))m_pParentNode->vfptr[14].AddRef)(
      this->m_pParentNode,
      in_uFXIndex);
  }
}

// File Line: 1508
// RVA: 0xA6D0E0
bool __fastcall CAkParameterNode::GetBypassFX(
        CAkParameterNode *this,
        unsigned int in_uFXIndex,
        CAkRegisteredObj *in_GameObjPtr)
{
  CAkParameterNodeBase::FXChunk *m_pFXChunk; // r9
  unsigned __int64 m_iBitArray; // rax
  CAkSIS *m_pGlobalSIS; // rax
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *m_pMapSIS; // rcx
  CAkRegisteredObj **p_key; // rax
  __int64 v9; // rcx
  CAkSIS **v10; // rax

  m_pFXChunk = this->m_pFXChunk;
  if ( !m_pFXChunk )
    goto LABEL_6;
  if ( m_pFXChunk->aFX[in_uFXIndex].id )
  {
    m_iBitArray = this->m_RTPCBitArray.m_iBitArray;
    if ( _bittest64((const __int64 *)&m_iBitArray, (unsigned __int8)(in_uFXIndex + 24)) )
    {
      if ( CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, in_uFXIndex + 24, in_GameObjPtr) != 0.0 )
      {
        LOBYTE(m_pGlobalSIS) = 1;
        return (char)m_pGlobalSIS;
      }
LABEL_6:
      LOBYTE(m_pGlobalSIS) = 0;
      return (char)m_pGlobalSIS;
    }
  }
  m_pMapSIS = this->m_pMapSIS;
  if ( !m_pMapSIS )
    goto LABEL_15;
  p_key = &m_pMapSIS->m_pItems->key;
  v9 = (__int64)&m_pMapSIS->m_pItems[m_pMapSIS->m_uLength];
  if ( p_key == (CAkRegisteredObj **)v9 )
    goto LABEL_15;
  do
  {
    if ( *p_key == in_GameObjPtr )
      break;
    p_key += 2;
  }
  while ( p_key != (CAkRegisteredObj **)v9 );
  if ( p_key == (CAkRegisteredObj **)v9 || (v10 = (CAkSIS **)(p_key + 1)) == 0i64 )
  {
LABEL_15:
    m_pGlobalSIS = this->m_pGlobalSIS;
    if ( !m_pGlobalSIS )
      return ((unsigned __int8)m_pFXChunk->bitsMainFXBypass >> in_uFXIndex) & 1;
  }
  else
  {
    m_pGlobalSIS = *v10;
  }
  LOBYTE(m_pGlobalSIS) = ((unsigned __int8)m_pGlobalSIS->m_bitsFXBypass >> in_uFXIndex) & 1;
  return (char)m_pGlobalSIS;
}

// File Line: 1547
// RVA: 0xA6CFF0
CAkParameterNodeBase::FXChunk *__fastcall CAkParameterNode::GetBypassAllFX(
        CAkParameterNode *this,
        CAkRegisteredObj *in_GameObjPtr)
{
  CAkParameterNodeBase *m_pParentNode; // rcx
  CAkParameterNodeBase::FXChunk *result; // rax
  bool v6; // dl
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *m_pMapSIS; // rcx
  CAkRegisteredObj **p_key; // rax
  __int64 v9; // rcx
  CAkRegisteredObj **v10; // rax
  CAkSIS *m_pGlobalSIS; // rax

  if ( (*((_BYTE *)&this->CAkParameterNodeBase + 83) & 0x40) == 0 )
  {
    m_pParentNode = this->m_pParentNode;
    if ( m_pParentNode )
      return (CAkParameterNodeBase::FXChunk *)((__int64 (__fastcall *)(CAkParameterNodeBase *, CAkRegisteredObj *, CAkRegisteredObj *))m_pParentNode->vfptr[14].Release)(
                                                m_pParentNode,
                                                in_GameObjPtr,
                                                in_GameObjPtr);
  }
  result = this->m_pFXChunk;
  if ( result )
  {
    v6 = (result->bitsMainFXBypass & 0x10) != 0;
    if ( (this->m_RTPCBitArray.m_iBitArray & 0x10000000) != 0 )
    {
      return (CAkParameterNodeBase::FXChunk *)(CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 0x1Cu, in_GameObjPtr) != 0.0);
    }
    else
    {
      m_pMapSIS = this->m_pMapSIS;
      if ( !m_pMapSIS )
        goto LABEL_14;
      p_key = &m_pMapSIS->m_pItems->key;
      v9 = (__int64)&m_pMapSIS->m_pItems[m_pMapSIS->m_uLength];
      if ( p_key == (CAkRegisteredObj **)v9 )
        goto LABEL_14;
      do
      {
        if ( *p_key == in_GameObjPtr )
          break;
        p_key += 2;
      }
      while ( p_key != (CAkRegisteredObj **)v9 );
      if ( p_key == (CAkRegisteredObj **)v9 || (v10 = p_key + 1) == 0i64 )
      {
LABEL_14:
        m_pGlobalSIS = this->m_pGlobalSIS;
        if ( m_pGlobalSIS )
          return (CAkParameterNodeBase::FXChunk *)((m_pGlobalSIS->m_bitsFXBypass & 0x10) != 0);
        return (CAkParameterNodeBase::FXChunk *)v6;
      }
      else
      {
        return (CAkParameterNodeBase::FXChunk *)(((*v10)->m_EnvironmentValues[1].auxBusID & 0x10) != 0);
      }
    }
  }
  return result;
}

// File Line: 1589
// RVA: 0xA6E370
void __fastcall CAkParameterNode::ResetFXBypass(CAkParameterNode *this, char in_bitsFXBypass, char in_uTargetMask)
{
  CAkSIS *m_pGlobalSIS; // rcx
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *m_pMapSIS; // rdx
  MapStruct<CAkRegisteredObj *,CAkSIS *> *m_pItems; // rax
  char v9; // r8
  char v10; // r10
  CAkSIS *item; // rdx

  m_pGlobalSIS = this->m_pGlobalSIS;
  if ( m_pGlobalSIS )
    m_pGlobalSIS->m_bitsFXBypass = in_uTargetMask & in_bitsFXBypass | m_pGlobalSIS->m_bitsFXBypass & ~in_uTargetMask;
  m_pMapSIS = this->m_pMapSIS;
  if ( m_pMapSIS )
  {
    m_pItems = m_pMapSIS->m_pItems;
    if ( m_pMapSIS->m_pItems != &m_pMapSIS->m_pItems[m_pMapSIS->m_uLength] )
    {
      v9 = ~in_uTargetMask;
      v10 = in_uTargetMask & in_bitsFXBypass;
      do
      {
        item = m_pItems->item;
        ++m_pItems;
        item->m_bitsFXBypass = v10 | v9 & item->m_bitsFXBypass;
      }
      while ( m_pItems != &this->m_pMapSIS->m_pItems[this->m_pMapSIS->m_uLength] );
    }
  }
}

// File Line: 1605
// RVA: 0xA6B850
__int64 __fastcall CAkParameterNode::AssociateLayer(CAkParameterNode *this, ITransitionable *in_pLayer)
{
  AkArray<CAkLayer *,CAkLayer *,ArrayPoolDefault,4,AkArrayAllocatorDefault> *v4; // rax
  AkArray<ITransitionable *,ITransitionable *,ArrayPoolDefault,4,AkArrayAllocatorDefault> *m_pAssociatedLayers; // rcx
  AkArray<CAkLayer *,CAkLayer *,ArrayPoolDefault,4,AkArrayAllocatorDefault> *v7; // rdx

  if ( !this->m_pAssociatedLayers )
  {
    v4 = (AkArray<CAkLayer *,CAkLayer *,ArrayPoolDefault,4,AkArrayAllocatorDefault> *)AK::MemoryMgr::Malloc(
                                                                                        g_DefaultPoolId,
                                                                                        0x10ui64);
    this->m_pAssociatedLayers = v4;
    if ( v4 )
    {
      v4->m_pItems = 0i64;
      *(_QWORD *)&v4->m_uLength = 0i64;
    }
  }
  m_pAssociatedLayers = (AkArray<ITransitionable *,ITransitionable *,ArrayPoolDefault,4,AkArrayAllocatorDefault> *)this->m_pAssociatedLayers;
  if ( m_pAssociatedLayers
    && AkArray<CAkPBI *,CAkPBI *,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast(m_pAssociatedLayers, in_pLayer) )
  {
    this->vfptr[12].Category(this);
    return 1i64;
  }
  else
  {
    v7 = this->m_pAssociatedLayers;
    if ( v7 )
    {
      if ( !v7->m_uLength )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, v7);
        this->m_pAssociatedLayers = 0i64;
      }
    }
    return 52i64;
  }
}

// File Line: 1627
// RVA: 0xA6BEE0
__int64 __fastcall CAkParameterNode::DissociateLayer(CAkParameterNode *this, CAkLayer *in_pLayer)
{
  AkArray<CAkLayer *,CAkLayer *,ArrayPoolDefault,4,AkArrayAllocatorDefault> *m_pAssociatedLayers; // r8
  CAkLayer **m_pItems; // rdi
  __int64 v4; // rax

  m_pAssociatedLayers = this->m_pAssociatedLayers;
  if ( !m_pAssociatedLayers )
    return 2i64;
  m_pItems = m_pAssociatedLayers->m_pItems;
  v4 = (__int64)&m_pAssociatedLayers->m_pItems[m_pAssociatedLayers->m_uLength];
  if ( m_pAssociatedLayers->m_pItems == (CAkLayer **)v4 )
    return 2i64;
  do
  {
    if ( *m_pItems == in_pLayer )
      break;
    ++m_pItems;
  }
  while ( m_pItems != (CAkLayer **)v4 );
  if ( m_pItems == (CAkLayer **)v4 )
    return 2i64;
  if ( (unsigned __int64)m_pItems < v4 - 8 )
    qmemcpy(m_pItems, m_pItems + 1, 8 * (((unsigned __int64)(v4 - 8 - (_QWORD)m_pItems - 1) >> 3) + 1));
  --m_pAssociatedLayers->m_uLength;
  this->vfptr[12].Category(this);
  return 1i64;
}

// File Line: 1659
// RVA: 0xA6DAA0
__int64 __fastcall CAkParameterNode::IncrementPlayCount(CAkParameterNode *this, CounterParameters *io_params)
{
  AKRESULT v4; // eax
  unsigned int v5; // ebx
  AkActivityChunk *m_pActivityChunk; // rax
  AKRESULT v7; // eax
  unsigned __int16 uiFlagForwardToBus; // ax
  bool bMaxConsidered; // bp
  unsigned int v10; // eax
  unsigned __int16 v11; // cx
  CAkParameterNodeBase::AkFeedbackInfo *m_pFeedbackInfo; // rax
  unsigned int v13; // eax
  unsigned int v14; // eax

  v4 = CAkParameterNodeBase::IncrementPlayCountValue(this, io_params->uiFlagForwardToBus);
  v5 = v4;
  if ( (*((_BYTE *)&this->CAkParameterNodeBase + 82) & 8) != 0 || !this->m_pParentNode )
  {
    if ( !io_params->bMaxConsidered && v4 == AK_Success )
    {
      m_pActivityChunk = this->m_pActivityChunk;
      if ( !m_pActivityChunk || (*((_BYTE *)m_pActivityChunk + 80) & 1) != 0 )
        v7 = CAkParameterNodeBase::IncrementPlayCountGlobal(
               this,
               io_params->fPriority,
               &io_params->ui16NumKicked,
               &io_params->pAMLimiter);
      else
        v7 = CAkParameterNodeBase::IncrementPlayCountGameObject(
               this,
               io_params->fPriority,
               &io_params->ui16NumKicked,
               io_params->pGameObj,
               &io_params->pAMLimiter);
      v5 = v7;
    }
    io_params->bMaxConsidered = 1;
  }
  uiFlagForwardToBus = io_params->uiFlagForwardToBus;
  bMaxConsidered = io_params->bMaxConsidered;
  if ( (uiFlagForwardToBus & 1) != 0 )
  {
    if ( this->m_pBusOutputNode )
    {
      io_params->bMaxConsidered = 0;
      io_params->uiFlagForwardToBus = uiFlagForwardToBus & 0xFFFE;
      v10 = ((__int64 (__fastcall *)(CAkParameterNodeBase *, CounterParameters *))this->m_pBusOutputNode->CAkParameterNodeBase::vfptr[8].Release)(
              this->m_pBusOutputNode,
              io_params);
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
  v11 = io_params->uiFlagForwardToBus;
  if ( (v11 & 2) != 0 )
  {
    m_pFeedbackInfo = this->m_pFeedbackInfo;
    if ( m_pFeedbackInfo )
    {
      if ( m_pFeedbackInfo->m_pFeedbackBus )
      {
        io_params->bMaxConsidered = 0;
        io_params->uiFlagForwardToBus = v11 & 0xFFFD;
        v13 = ((__int64 (__fastcall *)(CAkFeedbackBus *, CounterParameters *))this->m_pFeedbackInfo->m_pFeedbackBus->CAkParameterNodeBase::vfptr[8].Release)(
                this->m_pFeedbackInfo->m_pFeedbackBus,
                io_params);
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
  if ( this->m_pParentNode )
  {
    io_params->bMaxConsidered = bMaxConsidered;
    v14 = ((__int64 (__fastcall *)(CAkParameterNodeBase *, CounterParameters *))this->m_pParentNode->CAkParameterNodeBase::vfptr[8].Release)(
            this->m_pParentNode,
            io_params);
    if ( v14 != 1 )
    {
      if ( v14 == 80 )
      {
        if ( v5 == 1 )
          return 80;
      }
      else
      {
        return v14;
      }
    }
  }
  return v5;
}

// File Line: 1724
// RVA: 0xA6BB20
void __fastcall CAkParameterNode::DecrementPlayCount(CAkParameterNode *this, CounterParameters *io_params)
{
  AkActivityChunk *m_pActivityChunk; // rax
  unsigned __int16 uiFlagForwardToBus; // ax
  bool bMaxConsidered; // si
  unsigned __int16 v7; // ax
  CAkParameterNodeBase::AkFeedbackInfo *m_pFeedbackInfo; // rcx

  CAkParameterNodeBase::DecrementPlayCountValue(this);
  if ( (*((_BYTE *)&this->CAkParameterNodeBase + 82) & 8) != 0 || !this->m_pParentNode )
  {
    if ( !io_params->bMaxConsidered )
    {
      m_pActivityChunk = this->m_pActivityChunk;
      if ( m_pActivityChunk )
      {
        if ( (*((_BYTE *)m_pActivityChunk + 80) & 1) != 0 )
          CAkParameterNodeBase::DecrementPlayCountGlobal(this);
        else
          CAkParameterNodeBase::DecrementPlayCountGameObject(this, io_params->pGameObj);
      }
    }
    io_params->bMaxConsidered = 1;
  }
  uiFlagForwardToBus = io_params->uiFlagForwardToBus;
  bMaxConsidered = io_params->bMaxConsidered;
  if ( (uiFlagForwardToBus & 1) != 0 && this->m_pBusOutputNode )
  {
    io_params->bMaxConsidered = 0;
    io_params->uiFlagForwardToBus = uiFlagForwardToBus & 0xFFFE;
    ((void (__fastcall *)(CAkParameterNodeBase *, CounterParameters *))this->m_pBusOutputNode->CAkParameterNodeBase::vfptr[8].Category)(
      this->m_pBusOutputNode,
      io_params);
  }
  v7 = io_params->uiFlagForwardToBus;
  if ( (v7 & 2) != 0 )
  {
    m_pFeedbackInfo = this->m_pFeedbackInfo;
    if ( m_pFeedbackInfo )
    {
      if ( m_pFeedbackInfo->m_pFeedbackBus )
      {
        io_params->bMaxConsidered = 0;
        io_params->uiFlagForwardToBus = v7 & 0xFFFD;
        ((void (__fastcall *)(CAkFeedbackBus *, CounterParameters *))this->m_pFeedbackInfo->m_pFeedbackBus->CAkParameterNodeBase::vfptr[8].Category)(
          this->m_pFeedbackInfo->m_pFeedbackBus,
          io_params);
      }
    }
  }
  if ( this->m_pParentNode )
  {
    io_params->bMaxConsidered = bMaxConsidered;
    ((void (__fastcall *)(CAkParameterNodeBase *, CounterParameters *))this->m_pParentNode->CAkParameterNodeBase::vfptr[8].Category)(
      this->m_pParentNode,
      io_params);
  }
}

// File Line: 1779
// RVA: 0xA6DC20
void __fastcall CAkParameterNode::IncrementVirtualCount(CAkParameterNode *this, CounterParameters *io_params)
{
  AkActivityChunk *m_pActivityChunk; // rcx
  unsigned __int16 uiFlagForwardToBus; // ax
  bool bMaxConsidered; // si
  unsigned __int16 v7; // ax
  CAkParameterNodeBase::AkFeedbackInfo *m_pFeedbackInfo; // rcx

  if ( ((*((_BYTE *)&this->CAkParameterNodeBase + 82) & 8) != 0 || !this->m_pParentNode) && !io_params->bMaxConsidered )
  {
    m_pActivityChunk = this->m_pActivityChunk;
    if ( m_pActivityChunk )
    {
      if ( (*((_BYTE *)m_pActivityChunk + 80) & 1) != 0 )
        ++m_pActivityChunk->m_iVirtualCountValid;
      else
        CAkParameterNodeBase::IncrementVirtualCountGameObject(this, io_params->pGameObj);
    }
    io_params->bMaxConsidered = 1;
  }
  uiFlagForwardToBus = io_params->uiFlagForwardToBus;
  bMaxConsidered = io_params->bMaxConsidered;
  if ( (uiFlagForwardToBus & 1) != 0 && this->m_pBusOutputNode )
  {
    io_params->bMaxConsidered = 0;
    io_params->uiFlagForwardToBus = uiFlagForwardToBus & 0xFFFE;
    this->m_pBusOutputNode->CAkParameterNodeBase::vfptr[9].__vecDelDtor(this->m_pBusOutputNode, (unsigned int)io_params);
  }
  v7 = io_params->uiFlagForwardToBus;
  if ( (v7 & 2) != 0 )
  {
    m_pFeedbackInfo = this->m_pFeedbackInfo;
    if ( m_pFeedbackInfo )
    {
      if ( m_pFeedbackInfo->m_pFeedbackBus )
      {
        io_params->bMaxConsidered = 0;
        io_params->uiFlagForwardToBus = v7 & 0xFFFD;
        this->m_pFeedbackInfo->m_pFeedbackBus->CAkParameterNodeBase::vfptr[9].__vecDelDtor(
          this->m_pFeedbackInfo->m_pFeedbackBus,
          (unsigned int)io_params);
      }
    }
  }
  if ( this->m_pParentNode )
  {
    io_params->bMaxConsidered = bMaxConsidered;
    this->m_pParentNode->CAkParameterNodeBase::vfptr[9].__vecDelDtor(this->m_pParentNode, (unsigned int)io_params);
  }
}

// File Line: 1834
// RVA: 0xA6BC10
void __fastcall CAkParameterNode::DecrementVirtualCount(CAkParameterNode *this, CounterParameters *io_params)
{
  AkActivityChunk *m_pActivityChunk; // rax
  bool bAllowKick; // r8
  unsigned __int16 *p_ui16NumKicked; // rdx
  unsigned __int16 uiFlagForwardToBus; // ax
  bool bMaxConsidered; // si
  unsigned __int16 v9; // ax
  CAkParameterNodeBase::AkFeedbackInfo *m_pFeedbackInfo; // rcx

  if ( (*((_BYTE *)&this->CAkParameterNodeBase + 82) & 8) != 0 || !this->m_pParentNode )
  {
    if ( !io_params->bMaxConsidered )
    {
      m_pActivityChunk = this->m_pActivityChunk;
      if ( m_pActivityChunk )
      {
        bAllowKick = io_params->bAllowKick;
        p_ui16NumKicked = &io_params->ui16NumKicked;
        if ( (*((_BYTE *)m_pActivityChunk + 80) & 1) != 0 )
          CAkParameterNodeBase::DecrementVirtualCountGlobal(this, p_ui16NumKicked, bAllowKick);
        else
          CAkParameterNodeBase::DecrementVirtualCountGameObject(this, p_ui16NumKicked, bAllowKick, io_params->pGameObj);
      }
    }
    io_params->bMaxConsidered = 1;
  }
  uiFlagForwardToBus = io_params->uiFlagForwardToBus;
  bMaxConsidered = io_params->bMaxConsidered;
  if ( (uiFlagForwardToBus & 1) != 0 && this->m_pBusOutputNode )
  {
    io_params->bMaxConsidered = 0;
    io_params->uiFlagForwardToBus = uiFlagForwardToBus & 0xFFFE;
    ((void (__fastcall *)(CAkParameterNodeBase *, CounterParameters *))this->m_pBusOutputNode->CAkParameterNodeBase::vfptr[9].AddRef)(
      this->m_pBusOutputNode,
      io_params);
  }
  v9 = io_params->uiFlagForwardToBus;
  if ( (v9 & 2) != 0 )
  {
    m_pFeedbackInfo = this->m_pFeedbackInfo;
    if ( m_pFeedbackInfo )
    {
      if ( m_pFeedbackInfo->m_pFeedbackBus )
      {
        io_params->bMaxConsidered = 0;
        io_params->uiFlagForwardToBus = v9 & 0xFFFD;
        ((void (__fastcall *)(CAkFeedbackBus *, CounterParameters *))this->m_pFeedbackInfo->m_pFeedbackBus->CAkParameterNodeBase::vfptr[9].AddRef)(
          this->m_pFeedbackInfo->m_pFeedbackBus,
          io_params);
      }
    }
  }
  if ( this->m_pParentNode )
  {
    io_params->bMaxConsidered = bMaxConsidered;
    ((void (__fastcall *)(CAkParameterNodeBase *, CounterParameters *))this->m_pParentNode->CAkParameterNodeBase::vfptr[9].AddRef)(
      this->m_pParentNode,
      io_params);
  }
}

// File Line: 1885
// RVA: 0xA6B6A0
void __fastcall CAkParameterNode::ApplyMaxNumInstances(
        CAkParameterNode *this,
        unsigned __int16 in_u16MaxNumInstance,
        CAkRegisteredObj *in_pGameObj,
        unsigned int *in_pExceptArray,
        bool in_bFromRTPC)
{
  AkActivityChunk *m_pActivityChunk; // r10
  char v8; // al
  StructMaxInst *v9; // rax
  CAkLimiter *m_pLimiter; // rax
  MapStruct<CAkRegisteredObj *,StructMaxInst> *v11; // rax
  CAkLimiter *v12; // rcx
  MapStruct<CAkRegisteredObj *,StructMaxInst> *m_pItems; // rcx
  CAkRegisteredObj **v14; // rax
  __int64 v15; // r8
  CAkLimiter *v16; // rax
  AkActivityChunk *v17; // r8
  MapStruct<CAkRegisteredObj *,StructMaxInst> *v18; // rax
  CAkLimiter *v19; // rcx

  if ( in_bFromRTPC )
  {
    m_pActivityChunk = this->m_pActivityChunk;
    if ( m_pActivityChunk )
    {
      v8 = *((_BYTE *)m_pActivityChunk + 80);
      if ( in_pGameObj )
      {
        if ( (v8 & 1) == 0 && ((*((_BYTE *)&this->CAkParameterNodeBase + 82) & 8) != 0 || !this->m_pParentNode) )
        {
          v9 = CAkKeyArray<CAkRegisteredObj *,StructMaxInst,2>::Exists(
                 &this->m_pActivityChunk->m_ListPlayCountPerObj,
                 in_pGameObj);
          if ( v9 )
          {
            m_pLimiter = v9->m_pLimiter;
            if ( m_pLimiter )
              m_pLimiter->m_u16LimiterMax = in_u16MaxNumInstance;
          }
        }
      }
      else if ( (v8 & 1) != 0 )
      {
        m_pActivityChunk->m_Limiter.m_u16LimiterMax = in_u16MaxNumInstance;
      }
      else if ( in_pExceptArray )
      {
        m_pItems = m_pActivityChunk->m_ListPlayCountPerObj.m_pItems;
        if ( m_pActivityChunk->m_ListPlayCountPerObj.m_pItems != &m_pActivityChunk->m_ListPlayCountPerObj.m_pItems[m_pActivityChunk->m_ListPlayCountPerObj.m_uLength] )
        {
          do
          {
            v14 = *(CAkRegisteredObj ***)in_pExceptArray;
            v15 = *(_QWORD *)in_pExceptArray + 8i64 * in_pExceptArray[2];
            if ( *(_QWORD *)in_pExceptArray == v15 )
            {
LABEL_22:
              v16 = m_pItems->item.m_pLimiter;
              if ( v16 )
                v16->m_u16LimiterMax = in_u16MaxNumInstance;
            }
            else
            {
              while ( *v14 != m_pItems->key )
              {
                if ( ++v14 == (CAkRegisteredObj **)v15 )
                  goto LABEL_22;
              }
            }
            ++m_pItems;
          }
          while ( m_pItems != &this->m_pActivityChunk->m_ListPlayCountPerObj.m_pItems[this->m_pActivityChunk->m_ListPlayCountPerObj.m_uLength] );
        }
      }
      else
      {
        v11 = m_pActivityChunk->m_ListPlayCountPerObj.m_pItems;
        if ( m_pActivityChunk->m_ListPlayCountPerObj.m_pItems != &m_pActivityChunk->m_ListPlayCountPerObj.m_pItems[m_pActivityChunk->m_ListPlayCountPerObj.m_uLength] )
        {
          do
          {
            v12 = v11->item.m_pLimiter;
            if ( v12 )
              v12->m_u16LimiterMax = in_u16MaxNumInstance;
            ++v11;
          }
          while ( v11 != &this->m_pActivityChunk->m_ListPlayCountPerObj.m_pItems[this->m_pActivityChunk->m_ListPlayCountPerObj.m_uLength] );
        }
      }
    }
  }
  else
  {
    v17 = this->m_pActivityChunk;
    if ( v17 )
    {
      if ( (*((_BYTE *)v17 + 80) & 1) != 0 )
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
        while ( v18 != &this->m_pActivityChunk->m_ListPlayCountPerObj.m_pItems[this->m_pActivityChunk->m_ListPlayCountPerObj.m_uLength] );
      }
    }
    this->m_u16MaxNumInstance = in_u16MaxNumInstance;
  }
}nk->m_ListPlayCountPerObj.m_uLength] );
      }
    }
    this->m_u1

// File Line: 1972
// RVA: 0xA6DD10
bool __fastcall CAkParameterNode::IsOrIsChildOf(
        CAkParameterNode *this,
        CAkParameterNode *in_pNodeToTest,
        bool __formal)
{
  bool result; // al
  char v6; // dl
  CAkBus *m_pBusOutputNode; // rcx

  result = 0;
  v6 = 0;
  do
  {
    if ( !this )
      break;
    result = in_pNodeToTest == this;
    if ( in_pNodeToTest != this && !v6 )
    {
      m_pBusOutputNode = (CAkBus *)this->m_pBusOutputNode;
      if ( m_pBusOutputNode )
      {
        result = CAkBus::IsOrIsChildOf(m_pBusOutputNode, in_pNodeToTest);
        v6 = 1;
      }
    }
    this = (CAkParameterNode *)this->m_pParentNode;
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
__int64 __fastcall CAkParameterNode::SetAuxBusSend(
        CAkParameterNode *this,
        unsigned int in_AuxBusID,
        unsigned int in_ulIndex)
{
  CAkParameterNode::AuxChunk *m_pAuxChunk; // r9
  __int64 v4; // rsi
  CAkParameterNode::AuxChunk *v7; // rax
  __int64 i; // rcx

  m_pAuxChunk = this->m_pAuxChunk;
  v4 = in_ulIndex;
  if ( !m_pAuxChunk )
  {
    if ( !in_AuxBusID )
      return 1i64;
    v7 = (CAkParameterNode::AuxChunk *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x10ui64);
    this->m_pAuxChunk = v7;
    if ( v7 )
    {
      for ( i = 0i64; i < 4; ++i )
        v7->aAux[i] = 0;
    }
    m_pAuxChunk = this->m_pAuxChunk;
    if ( !m_pAuxChunk )
      return 52i64;
  }
  m_pAuxChunk->aAux[v4] = in_AuxBusID;
  this->vfptr[12].Category(this);
  return 1i64;
}

// File Line: 2076
// RVA: 0xA6D4D0
__int64 __fastcall CAkParameterNode::GetFeedbackParameters(
        CAkParameterNode *this,
        AkFeedbackParams *io_Params,
        CAkSource *in_pSource,
        CAkRegisteredObj *in_GameObjPtr,
        bool in_bDoBusCheck)
{
  AKRESULT FeedbackParameters; // eax
  CAkSIS *m_pGlobalSIS; // r9
  unsigned int v10; // r8d
  AKRESULT v11; // r10d
  char *m_pProps; // r9
  unsigned int v13; // r11d
  int v14; // ecx
  __int64 v15; // rdx
  float *v16; // rdx
  CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *m_pMapSIS; // rcx
  CAkRegisteredObj **p_key; // rax
  __int64 v19; // rcx
  CAkRegisteredObj **v20; // rax
  unsigned __int8 *v21; // rdx
  unsigned int v22; // r9d
  __int64 v23; // rcx
  __int64 result; // rax
  __int64 v25; // rcx
  unsigned __int8 *v26; // rax
  bool v27; // zf
  float *v28; // rcx

  FeedbackParameters = CAkParameterNodeBase::GetFeedbackParameters(
                         this,
                         io_Params,
                         in_pSource,
                         in_GameObjPtr,
                         in_bDoBusCheck);
  m_pGlobalSIS = this->m_pGlobalSIS;
  v10 = 0;
  v11 = FeedbackParameters;
  if ( m_pGlobalSIS )
  {
    m_pProps = m_pGlobalSIS->m_values.m_pProps;
    if ( m_pProps )
    {
      v13 = (unsigned __int8)*m_pProps;
      v14 = 0;
      while ( 1 )
      {
        v15 = (unsigned int)(v14 + 1);
        if ( m_pProps[v15] == 8 )
          break;
        ++v14;
        if ( (unsigned int)v15 >= v13 )
          goto LABEL_9;
      }
      v16 = (float *)&m_pProps[16 * v14 + ((v13 + 4) & 0xFFFFFFFC)];
      if ( v16 )
        io_Params->m_NewVolume = *v16 + io_Params->m_NewVolume;
    }
  }
LABEL_9:
  m_pMapSIS = this->m_pMapSIS;
  if ( !m_pMapSIS )
    return (unsigned int)v11;
  p_key = &m_pMapSIS->m_pItems->key;
  v19 = (__int64)&m_pMapSIS->m_pItems[m_pMapSIS->m_uLength];
  if ( p_key == (CAkRegisteredObj **)v19 )
    return (unsigned int)v11;
  do
  {
    if ( *p_key == in_GameObjPtr )
      break;
    p_key += 2;
  }
  while ( p_key != (CAkRegisteredObj **)v19 );
  if ( p_key == (CAkRegisteredObj **)v19 )
    return (unsigned int)v11;
  v20 = p_key + 1;
  if ( !v20 )
    return (unsigned int)v11;
  v21 = (unsigned __int8 *)(*v20)->m_EnvironmentValues[0];
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
    io_Params->m_NewVolume = *v28 + io_Params->m_NewVolume;
  return result;
}

// File Line: 2096
// RVA: 0xA6D260
float __fastcall CAkParameterNode::GetEffectiveFeedbackVolume(CAkParameterNode *this, CAkRegisteredObj *in_GameObjPtr)
{
  float result; // xmm0_4
  char *m_pProps; // r8
  float v5; // xmm6_4
  unsigned int v6; // r9d
  __int64 v7; // rcx
  __int64 v8; // rdx
  float *v9; // rbx
  float v10; // xmm0_4
  float v11; // xmm7_4

  result = CAkParameterNodeBase::GetEffectiveFeedbackVolume(this, in_GameObjPtr);
  m_pProps = this->m_ranges.m_pProps;
  v5 = result;
  if ( m_pProps )
  {
    v6 = (unsigned __int8)*m_pProps;
    v7 = 0i64;
    while ( 1 )
    {
      v8 = (unsigned int)(v7 + 1);
      if ( m_pProps[v8] == 8 )
        break;
      v7 = (unsigned int)v8;
      if ( (unsigned int)v8 >= v6 )
        return result;
    }
    v9 = (float *)&m_pProps[8 * v7 + ((v6 + 4) & 0xFFFFFFFC)];
    if ( v9 )
    {
      v10 = 0.0;
      v11 = v9[1] - *v9;
      if ( v11 != 0.0 )
        v10 = (double)rand() * 0.00003051850947599719 * v11;
      return v5 + (float)(v10 + *v9);
    }
  }
  return v5;
}

// File Line: 2104
// RVA: 0xA6D1A0
float __fastcall CAkParameterNode::GetEffectiveFeedbackLPF(CAkParameterNode *this, CAkRegisteredObj *in_GameObjPtr)
{
  float result; // xmm0_4
  char *m_pProps; // r8
  float v5; // xmm6_4
  unsigned int v6; // r9d
  __int64 v7; // rcx
  __int64 v8; // rdx
  float *v9; // rbx
  float v10; // xmm0_4
  float v11; // xmm7_4

  result = CAkParameterNodeBase::GetEffectiveFeedbackLPF(this, in_GameObjPtr);
  m_pProps = this->m_ranges.m_pProps;
  v5 = result;
  if ( m_pProps )
  {
    v6 = (unsigned __int8)*m_pProps;
    v7 = 0i64;
    while ( 1 )
    {
      v8 = (unsigned int)(v7 + 1);
      if ( m_pProps[v8] == 9 )
        break;
      v7 = (unsigned int)v8;
      if ( (unsigned int)v8 >= v6 )
        return result;
    }
    v9 = (float *)&m_pProps[8 * v7 + ((v6 + 4) & 0xFFFFFFFC)];
    if ( v9 )
    {
      v10 = 0.0;
      v11 = v9[1] - *v9;
      if ( v11 != 0.0 )
        v10 = (double)rand() * 0.00003051850947599719 * v11;
      return v5 + (float)(v10 + *v9);
    }
  }
  return v5;
}

// File Line: 2121
// RVA: 0xA6D8D0
__int64 __fastcall CAkParameterNode::HandleInitialDelay(CAkParameterNode *this, AkPBIParams *in_rPBIParams)
{
  unsigned int v4; // ebp
  __int64 result; // rax
  char *m_pProps; // r8
  int v7; // ebx
  unsigned int v8; // r9d
  __int64 v9; // rcx
  __int64 v10; // rdx
  __int64 v11; // rdx
  float *p_in_fDelay; // rax
  float v13; // xmm6_4
  char *v14; // rdx
  unsigned int v15; // r8d
  __int64 v16; // rcx
  float *v17; // rbx
  float v18; // xmm0_4
  float v19; // xmm7_4
  float in_fDelay; // [rsp+78h] [rbp+10h] BYREF

  v4 = 1;
  if ( in_rPBIParams->bSkipDelay )
  {
    in_rPBIParams->bSkipDelay = 0;
    return 1i64;
  }
  m_pProps = this->m_props.m_pProps;
  v7 = 0;
  in_fDelay = 0.0;
  if ( m_pProps )
  {
    v8 = (unsigned __int8)*m_pProps;
    v9 = 0i64;
    while ( 1 )
    {
      v10 = (unsigned int)(v9 + 1);
      if ( m_pProps[v10] == 25 )
        break;
      v9 = (unsigned int)v10;
      if ( (unsigned int)v10 >= v8 )
        goto LABEL_7;
    }
    v11 = (__int64)&m_pProps[4 * v9 + ((v8 + 4) & 0xFFFFFFFC)];
  }
  else
  {
LABEL_7:
    v11 = 0i64;
  }
  p_in_fDelay = &in_fDelay;
  if ( v11 )
    p_in_fDelay = (float *)v11;
  in_fDelay = *p_in_fDelay;
  v13 = in_fDelay;
  if ( (this->m_RTPCBitArray.m_iBitArray & 0x40) != 0 )
    v13 = v13 + CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 6u, in_rPBIParams->pGameObj);
  v14 = this->m_ranges.m_pProps;
  if ( v14 )
  {
    v15 = (unsigned __int8)*v14;
    while ( 1 )
    {
      v16 = (unsigned int)(v7 + 1);
      if ( v14[v16] == 25 )
        break;
      ++v7;
      if ( (unsigned int)v16 >= v15 )
        goto LABEL_22;
    }
    v17 = (float *)&v14[8 * v7 + ((v15 + 4) & 0xFFFFFFFC)];
    if ( v17 )
    {
      v18 = 0.0;
      v19 = v17[1] - *v17;
      if ( v19 != 0.0 )
        v18 = (double)rand() * 0.00003051850947599719 * v19;
      v13 = v13 + (float)(v18 + *v17);
    }
  }
LABEL_22:
  if ( v13 <= 0.0 )
    return v4;
  if ( in_rPBIParams->sequenceID )
  {
    in_rPBIParams->uFrameOffset += AkTimeConv::SecondsToSamples(v13);
    return 1i64;
  }
  v4 = CAkParameterNode::DelayPlayback(this, v13, in_rPBIParams);
  result = 3i64;
  if ( v4 != 1 )
    return v4;
  return result;
}

