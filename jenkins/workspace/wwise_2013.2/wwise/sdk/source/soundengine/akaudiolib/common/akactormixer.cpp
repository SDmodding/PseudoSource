// File Line: 33
// RVA: 0xA88330
CAkActorMixer *__fastcall CAkActorMixer::Create(unsigned int in_ulID)
{
  CAkActorMixer *result; // rax
  CAkActorMixer *v3; // rbx
  hkpEntity *v4; // rdx
  unsigned int NumOriginalFrames; // eax
  int v6; // ecx
  bool v7; // al

  result = (CAkActorMixer *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xA8ui64);
  v3 = result;
  if ( result )
  {
    CAkParameterNode::CAkParameterNode(result, in_ulID);
    v3->m_mapChildId.m_pItems = 0i64;
    *(_QWORD *)&v3->m_mapChildId.m_uLength = 0i64;
    v3->vfptr = (CAkIndexableVtbl *)&CAkActorMixer::`vftable;
    NumOriginalFrames = hkaReferencePoseAnimation::getNumOriginalFrames((hkEntitySelectorAll *)v3, v4);
    v7 = 0;
    if ( NumOriginalFrames <= 0xC )
    {
      v6 = 5121;
      if ( _bittest(&v6, NumOriginalFrames) )
        v7 = 1;
    }
    *((_BYTE *)&v3->CAkParameterNodeBase + 83) &= ~2u;
    *((_BYTE *)&v3->CAkParameterNodeBase + 83) |= 2 * v7;
    CAkParameterNodeBase::AddToIndex(v3);
    return v3;
  }
  return result;
}

// File Line: 52
// RVA: 0xA882A0
__int64 __fastcall CAkActorMixer::CanAddChild(CAkActorMixer *this, CAkParameterNodeBase *in_pAudioNode)
{
  unsigned int v3; // ebx
  unsigned int key; // esi

  v3 = 1;
  if ( in_pAudioNode->m_pParentNode )
    return 21i64;
  key = in_pAudioNode->key;
  if ( AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Exists<unsigned long>(
         &this->m_mapChildId,
         key) )
  {
    return 5i64;
  }
  if ( this->key == key )
    return 23;
  return v3;
}

// File Line: 78
// RVA: 0xA88DC0
__int64 __fastcall CAkActorMixer::SetInitialValues(CAkActorMixer *this, char *in_pData, unsigned int in_ulDataSize)
{
  __int64 result; // rax
  char *io_rpData; // [rsp+38h] [rbp+10h] BYREF
  unsigned int io_rulDataSize; // [rsp+40h] [rbp+18h] BYREF

  io_rulDataSize = in_ulDataSize;
  io_rpData = in_pData + 4;
  result = CAkParameterNodeBase::SetNodeBaseParams(this, &io_rpData, &io_rulDataSize, 0);
  if ( (_DWORD)result == 1 )
    return CAkParentNode<CAkParameterNode>::SetChildren(this, &io_rpData, &io_rulDataSize);
  return result;
}

