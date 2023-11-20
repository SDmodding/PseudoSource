// File Line: 62
// RVA: 0xA7B1D0
__int64 __fastcall CAkParentNode<CAkParameterNodeBase>::Children(CAkParentNode<CAkParameterNodeBase> *this)
{
  return LOWORD(this->m_mapChildId.m_uLength);
}

// File Line: 79
// RVA: 0xA7AFC0
__int64 __fastcall CAkParentNode<CAkParameterNodeBase>::AddChildInternal(CAkParentNode<CAkParameterNodeBase> *this, CAkParameterNodeBase *pAudioNode)
{
  CAkParameterNodeBase *v2; // rbx
  CAkParentNode<CAkParameterNodeBase> *v3; // rdi
  unsigned int v4; // esi
  CAkParameterNodeBase **v5; // rax

  v2 = pAudioNode;
  v3 = this;
  v4 = ((__int64 (*)(void))this->vfptr[20].__vecDelDtor)();
  if ( v4 == 1 )
  {
    v5 = AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::AddNoSetKey<unsigned long>(
           &v3->m_mapChildId,
           v2->key);
    if ( v5 )
    {
      *v5 = v2;
      ((void (__fastcall *)(CAkParameterNodeBase *, CAkParentNode<CAkParameterNodeBase> *))v2->vfptr[1].Release)(v2, v3);
      v3->vfptr->AddRef((CAkIndexable *)&v3->vfptr);
    }
    else
    {
      v4 = 2;
    }
  }
  v2->vfptr->Release((CAkIndexable *)&v2->vfptr);
  return v4;
}

// File Line: 103
// RVA: 0xA7CEA0
void __fastcall CAkParentNode<CAkParameterNodeBase>::RemoveChild(CAkParentNode<CAkParameterNodeBase> *this, CAkParameterNodeBase *in_pChild)
{
  CAkParameterNodeBase *v2; // rbx
  CAkParentNode<CAkParameterNodeBase> *v3; // rdi

  v2 = in_pChild;
  v3 = this;
  if ( (CAkParentNode<CAkParameterNodeBase> *)in_pChild->m_pParentNode == this )
  {
    ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD))in_pChild->vfptr[1].Release)(in_pChild, 0i64);
    AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Unset<unsigned long>(
      &v3->m_mapChildId,
      v2->key);
    v3->vfptr->Release((CAkIndexable *)&v3->vfptr);
  }
}

// File Line: 118
// RVA: 0xA7CEF0
void __fastcall CAkParentNode<CAkParameterNodeBase>::RemoveChild(CAkParentNode<CAkParameterNodeBase> *this, WwiseObjectIDext in_ulID)
{
  CAkParentNode<CAkParameterNodeBase> *v2; // rbx
  CAkParameterNodeBase **v3; // rax

  v2 = this;
  v3 = AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Exists<unsigned long>(
         &this->m_mapChildId,
         in_ulID.id);
  if ( v3 )
    v2->vfptr[3].__vecDelDtor((CAkIndexable *)&v2->vfptr, (unsigned int)*v3);
}

// File Line: 128
// RVA: 0xA88D00
signed __int64 __fastcall CAkParentNode<CAkParameterNode>::SetChildren(CAkParentNode<CAkParameterNode> *this, char **io_rpData, unsigned int *io_rulDataSize)
{
  char **v3; // r15
  CAkParentNode<CAkParameterNode> *v4; // r14
  unsigned int v5; // edi
  unsigned int v6; // esi
  CAkParameterNodeBase **v7; // rax
  unsigned int v8; // ebx
  __int64 v10; // [rsp+48h] [rbp+10h]

  v3 = io_rpData;
  v4 = this;
  v5 = *(_DWORD *)*io_rpData;
  v6 = 1;
  *io_rpData += 4;
  if ( !v5 )
    return v6;
  v7 = (CAkParameterNodeBase **)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8i64 * v5);
  v4->m_mapChildId.m_pItems = v7;
  if ( v7 )
  {
    v8 = 0;
    v4->m_mapChildId.m_ulReserved = v5;
    if ( v5 )
    {
      do
      {
        BYTE4(v10) = 0;
        LODWORD(v10) = *(_DWORD *)*v3;
        *v3 += 4;
        v6 = ((__int64 (__fastcall *)(CAkParentNode<CAkParameterNode> *, __int64))v4->vfptr[2].Release)(v4, v10);
        if ( v6 != 1 )
          break;
        ++v8;
      }
      while ( v8 < v5 );
    }
    return v6;
  }
  return 52i64;
}

// File Line: 153
// RVA: 0xA88610
void __fastcall CAkParentNode<CAkParameterNode>::GetChildren(CAkParentNode<CAkParameterNode> *this, unsigned int *io_ruNumItems, AkObjectInfo *out_aObjectInfos, unsigned int *in_uIndex_Out, unsigned int in_uDepth)
{
  CAkParameterNodeBase **v5; // rbx
  unsigned int *v6; // rdi
  AkObjectInfo *v7; // r14
  unsigned int *v8; // rsi
  CAkParentNode<CAkParameterNode> *v9; // rbp
  __int64 v10; // rax
  _QWORD v11[5]; // [rsp+20h] [rbp-28h]

  v5 = this->m_mapChildId.m_pItems;
  v6 = in_uIndex_Out;
  v7 = out_aObjectInfos;
  v8 = io_ruNumItems;
  v9 = this;
  if ( v5 != &v5[this->m_mapChildId.m_uLength] )
  {
    do
    {
      v10 = *v6;
      if ( (unsigned int)v10 < *v8 )
      {
        v7[v10].objID = (*v5)->key;
        v7[*v6].parentID = (*v5)->m_pParentNode->key;
        v7[*v6].iDepth = in_uDepth;
      }
      if ( ++*v6 == *v8 )
        break;
      LODWORD(v11[0]) = in_uDepth + 1;
      ((void (__fastcall *)(CAkParameterNodeBase *, unsigned int *, AkObjectInfo *, unsigned int *, _QWORD))(*v5)->vfptr[3].AddRef)(
        *v5,
        v8,
        v7,
        v6,
        v11[0]);
      if ( *v6 == *v8 )
        break;
      ++v5;
    }
    while ( v5 != &v9->m_mapChildId.m_pItems[v9->m_mapChildId.m_uLength] );
  }
}

