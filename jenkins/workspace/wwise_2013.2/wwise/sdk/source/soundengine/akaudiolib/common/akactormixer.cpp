// File Line: 33
// RVA: 0xA88330
CAkActorMixer *__fastcall CAkActorMixer::Create(unsigned int in_ulID)
{
  unsigned int v1; // edi
  CAkActorMixer *result; // rax
  CAkActorMixer *v3; // rbx
  hkpEntity *v4; // rdx
  unsigned int v5; // eax
  signed int v6; // ecx
  bool v7; // al

  v1 = in_ulID;
  result = (CAkActorMixer *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xA8ui64);
  v3 = result;
  if ( result )
  {
    CAkParameterNode::CAkParameterNode((CAkParameterNode *)&result->vfptr, v1);
    v3->m_mapChildId.m_pItems = 0i64;
    *(_QWORD *)&v3->m_mapChildId.m_uLength = 0i64;
    v3->vfptr = (CAkIndexableVtbl *)&CAkActorMixer::`vftable';
    v5 = hkaReferencePoseAnimation::getNumOriginalFrames((hkEntitySelectorAll *)v3, v4);
    v7 = 0;
    if ( v5 <= 0xC )
    {
      v6 = 5121;
      if ( _bittest(&v6, v5) )
        v7 = 1;
    }
    *((_BYTE *)&v3->0 + 83) &= 0xFDu;
    *((_BYTE *)&v3->0 + 83) |= 2 * v7;
    CAkParameterNodeBase::AddToIndex((CAkParameterNodeBase *)&v3->vfptr);
    result = v3;
  }
  return result;
}

// File Line: 52
// RVA: 0xA882A0
signed __int64 __fastcall CAkActorMixer::CanAddChild(CAkActorMixer *this, CAkParameterNodeBase *in_pAudioNode)
{
  CAkActorMixer *v2; // rdi
  unsigned int v3; // ebx
  unsigned int v5; // esi

  v2 = this;
  v3 = 1;
  if ( in_pAudioNode->m_pParentNode )
    return 21i64;
  v5 = in_pAudioNode->key;
  if ( AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Exists<unsigned long>(
         &this->m_mapChildId,
         in_pAudioNode->key) )
  {
    return 5i64;
  }
  if ( v2->key == v5 )
    v3 = 23;
  return v3;
}

// File Line: 78
// RVA: 0xA88DC0
__int64 __fastcall CAkActorMixer::SetInitialValues(CAkActorMixer *this, char *in_pData, unsigned int in_ulDataSize)
{
  CAkActorMixer *v3; // rbx
  __int64 result; // rax
  char *io_rpData; // [rsp+38h] [rbp+10h]
  unsigned int io_rulDataSize; // [rsp+40h] [rbp+18h]

  io_rulDataSize = in_ulDataSize;
  io_rpData = in_pData + 4;
  v3 = this;
  result = CAkParameterNodeBase::SetNodeBaseParams((CAkParameterNodeBase *)&this->vfptr, &io_rpData, &io_rulDataSize, 0);
  if ( (_DWORD)result == 1 )
    result = CAkParentNode<CAkParameterNode>::SetChildren(
               (CAkParentNode<CAkParameterNode> *)&v3->vfptr,
               &io_rpData,
               &io_rulDataSize);
  return result;
}

