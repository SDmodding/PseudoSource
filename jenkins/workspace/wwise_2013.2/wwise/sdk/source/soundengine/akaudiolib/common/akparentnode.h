// File Line: 62
// RVA: 0xA7B1D0
__int64 __fastcall CAkParentNode<CAkParameterNodeBase>::Children(CAkParentNode<CAkParameterNodeBase> *this)
{
  return LOWORD(this->m_mapChildId.m_uLength);
}

// File Line: 79
// RVA: 0xA7AFC0
__int64 __fastcall CAkParentNode<CAkParameterNodeBase>::AddChildInternal(
        CAkParentNode<CAkParameterNodeBase> *this,
        CAkParameterNodeBase *pAudioNode)
{
  unsigned int v4; // esi
  CAkParameterNodeBase **v5; // rax

  v4 = ((__int64 (__fastcall *)(CAkParentNode<CAkParameterNodeBase> *))this->vfptr[20].__vecDelDtor)(this);
  if ( v4 == 1 )
  {
    v5 = AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::AddNoSetKey<unsigned long>(
           &this->m_mapChildId,
           pAudioNode->key);
    if ( v5 )
    {
      *v5 = pAudioNode;
      ((void (__fastcall *)(CAkParameterNodeBase *, CAkParentNode<CAkParameterNodeBase> *))pAudioNode->vfptr[1].Release)(
        pAudioNode,
        this);
      this->vfptr->AddRef(this);
    }
    else
    {
      v4 = 2;
    }
  }
  pAudioNode->vfptr->Release(pAudioNode);
  return v4;
}

// File Line: 103
// RVA: 0xA7CEA0
void __fastcall CAkParentNode<CAkParameterNodeBase>::RemoveChild(
        CAkParentNode<CAkParameterNodeBase> *this,
        CAkParameterNodeBase *in_pChild)
{
  if ( in_pChild->m_pParentNode == this )
  {
    ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD))in_pChild->vfptr[1].Release)(in_pChild, 0i64);
    AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Unset<unsigned long>(
      &this->m_mapChildId,
      in_pChild->key);
    this->vfptr->Release(this);
  }
}

// File Line: 118
// RVA: 0xA7CEF0
void __fastcall CAkParentNode<CAkParameterNodeBase>::RemoveChild(
        CAkParentNode<CAkParameterNodeBase> *this,
        WwiseObjectIDext in_ulID)
{
  CAkParameterNodeBase **v3; // rax

  v3 = AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Exists<unsigned long>(
         &this->m_mapChildId,
         in_ulID.id);
  if ( v3 )
    this->vfptr[3].__vecDelDtor(this, (unsigned int)*v3);
}

// File Line: 128
// RVA: 0xA88D00
__int64 __fastcall CAkParentNode<CAkParameterNode>::SetChildren(
        CAkParentNode<CAkParameterNode> *this,
        char **io_rpData,
        unsigned int *io_rulDataSize)
{
  unsigned int v5; // edi
  unsigned int v6; // esi
  CAkParameterNodeBase **v7; // rax
  unsigned int v8; // ebx
  __int64 v10; // [rsp+48h] [rbp+10h]

  v5 = *(_DWORD *)*io_rpData;
  v6 = 1;
  *io_rpData += 4;
  if ( !v5 )
    return v6;
  v7 = (CAkParameterNodeBase **)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8i64 * v5);
  this->m_mapChildId.m_pItems = v7;
  if ( v7 )
  {
    v8 = 0;
    this->m_mapChildId.m_ulReserved = v5;
    do
    {
      BYTE4(v10) = 0;
      LODWORD(v10) = *(_DWORD *)*io_rpData;
      *io_rpData += 4;
      v6 = ((__int64 (__fastcall *)(CAkParentNode<CAkParameterNode> *, __int64))this->vfptr[2].Release)(this, v10);
      if ( v6 != 1 )
        break;
      ++v8;
    }
    while ( v8 < v5 );
    return v6;
  }
  return 52i64;
}

// File Line: 153
// RVA: 0xA88610
void __fastcall CAkParentNode<CAkParameterNode>::GetChildren(
        CAkParentNode<CAkParameterNode> *this,
        unsigned int *io_ruNumItems,
        AkObjectInfo *out_aObjectInfos,
        unsigned int *in_uIndex_Out,
        int in_uDepth)
{
  CAkParameterNodeBase **m_pItems; // rbx
  __int64 v10; // rax

  m_pItems = this->m_mapChildId.m_pItems;
  if ( m_pItems != &m_pItems[this->m_mapChildId.m_uLength] )
  {
    do
    {
      v10 = *in_uIndex_Out;
      if ( (unsigned int)v10 < *io_ruNumItems )
      {
        out_aObjectInfos[v10].objID = (*m_pItems)->key;
        out_aObjectInfos[*in_uIndex_Out].parentID = (*m_pItems)->m_pParentNode->key;
        out_aObjectInfos[*in_uIndex_Out].iDepth = in_uDepth;
      }
      if ( ++*in_uIndex_Out == *io_ruNumItems )
        break;
      ((void (__fastcall *)(CAkParameterNodeBase *, unsigned int *, AkObjectInfo *, unsigned int *, int))(*m_pItems)->vfptr[3].AddRef)(
        *m_pItems,
        io_ruNumItems,
        out_aObjectInfos,
        in_uIndex_Out,
        in_uDepth + 1);
      if ( *in_uIndex_Out == *io_ruNumItems )
        break;
      ++m_pItems;
    }
    while ( m_pItems != &this->m_mapChildId.m_pItems[this->m_mapChildId.m_uLength] );
  }
}

