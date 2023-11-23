// File Line: 34
// RVA: 0x8CB750
__int64 __fastcall Scaleform::GFx::DisplayList::FindDisplayIndex(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *ch)
{
  unsigned __int64 Size; // r8
  __int64 result; // rax
  Scaleform::GFx::DisplayList::DisplayEntry *i; // rcx

  Size = this->DisplayObjectArray.Data.Size;
  result = 0i64;
  if ( !Size )
    return -1i64;
  for ( i = this->DisplayObjectArray.Data.Data; i->pCharacter != ch; ++i )
  {
    if ( ++result >= Size )
      return -1i64;
  }
  return result;
}

// File Line: 45
// RVA: 0x8D6CE0
unsigned __int64 __fastcall Scaleform::GFx::DisplayList::GetDisplayIndex(Scaleform::GFx::DisplayList *this, int depth)
{
  unsigned __int64 result; // rax

  result = Scaleform::GFx::DisplayList::FindDisplayIndex(this, depth);
  if ( result >= this->DisplayObjectArray.Data.Size
    || this->DisplayObjectArray.Data.Data[result].pCharacter->Depth != depth )
  {
    return -1i64;
  }
  return result;
}

// File Line: 58
// RVA: 0x8D6D20
Scaleform::GFx::DisplayObjectBase *__fastcall Scaleform::GFx::DisplayList::GetDisplayObjectAtDepth(
        Scaleform::GFx::DisplayList *this,
        int depth,
        bool *pisMarkedForRemove)
{
  unsigned __int64 DisplayIndex; // rax
  unsigned __int64 v7; // r10
  Scaleform::GFx::DisplayObjectBase *result; // rax

  DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex(this, depth);
  v7 = DisplayIndex;
  if ( DisplayIndex >= this->DisplayObjectArray.Data.Size )
    return 0i64;
  result = this->DisplayObjectArray.Data.Data[DisplayIndex].pCharacter;
  if ( result->Depth != depth || v7 == -1i64 || result->Depth != depth )
    return 0i64;
  if ( pisMarkedForRemove )
    *pisMarkedForRemove = (result->Flags & 0x40) != 0;
  return result;
}

// File Line: 77
// RVA: 0x8D5F20
Scaleform::GFx::DisplayObjectBase *__fastcall Scaleform::GFx::DisplayList::GetCharacterAtDepth(
        Scaleform::GFx::DisplayList *this,
        int depth,
        _DWORD *id,
        unsigned __int64 *pindex)
{
  unsigned __int64 DisplayIndex; // rax
  unsigned __int64 v9; // rdi
  unsigned __int64 Size; // rbp
  unsigned __int64 v11; // rsi
  bool i; // cf
  Scaleform::GFx::DisplayObjectBase *pCharacter; // rbx

  DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex(this, depth);
  v9 = DisplayIndex;
  Size = this->DisplayObjectArray.Data.Size;
  if ( DisplayIndex < Size )
  {
    v11 = DisplayIndex;
    if ( this->DisplayObjectArray.Data.Data[DisplayIndex].pCharacter->Depth == depth && DisplayIndex != -1i64 )
    {
      for ( i = DisplayIndex < Size; i; i = v9 < Size )
      {
        pCharacter = this->DisplayObjectArray.Data.Data[v11].pCharacter;
        if ( pCharacter )
          ++pCharacter->RefCount;
        if ( pCharacter->Depth == depth && pCharacter->Id.Id == *id )
        {
          if ( pindex )
            *pindex = v9;
          Scaleform::RefCountNTSImpl::Release(pCharacter);
          return pCharacter;
        }
        Scaleform::RefCountNTSImpl::Release(pCharacter);
        ++v9;
        ++v11;
      }
    }
  }
  return 0i64;
}

// File Line: 123
// RVA: 0x912110
char __fastcall Scaleform::GFx::DisplayList::SwapDepths(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        int depth1,
        int depth2,
        unsigned int frame)
{
  int v5; // r13d
  Scaleform::GFx::DisplayObjectBase *v7; // r15
  unsigned __int64 DisplayIndex; // rax
  unsigned __int64 v10; // rbp
  unsigned __int64 v11; // r14
  unsigned __int64 v12; // rax
  unsigned __int64 v13; // rdi
  unsigned __int64 Size; // r8
  Scaleform::GFx::DisplayObjectBase *Data; // rcx
  Scaleform::RefCountNTSImplCore *v16; // r15
  Scaleform::RefCountNTSImpl *v17; // rsi
  Scaleform::RefCountNTSImpl *vfptr; // r13
  Scaleform::GFx::DisplayObjectBase *pCharacter; // rcx
  unsigned int v20; // edx
  Scaleform::GFx::DisplayList::DisplayEntry *v21; // rcx
  Scaleform::GFx::DisplayObjectBase *v22; // rsi
  Scaleform::GFx::DisplayObjectBase *v23; // rcx
  char Flags; // al
  int v26; // [rsp+20h] [rbp-68h]
  Scaleform::GFx::DisplayList::DisplayEntry val; // [rsp+28h] [rbp-60h] BYREF
  __int64 v28; // [rsp+38h] [rbp-50h]
  Scaleform::RefCountNTSImpl *v29; // [rsp+40h] [rbp-48h]
  int v30; // [rsp+48h] [rbp-40h]
  int v31; // [rsp+4Ch] [rbp-3Ch]
  int v33; // [rsp+A0h] [rbp+18h]

  v28 = -2i64;
  v5 = depth2;
  v7 = owner;
  if ( depth1 == depth2 )
    return 1;
  DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex(this, depth1);
  v10 = DisplayIndex;
  if ( DisplayIndex < this->DisplayObjectArray.Data.Size )
  {
    v11 = DisplayIndex;
    if ( this->DisplayObjectArray.Data.Data[DisplayIndex].pCharacter->Depth == depth1 && DisplayIndex != -1i64 )
    {
      v12 = Scaleform::GFx::DisplayList::FindDisplayIndex(this, v5);
      v13 = v12;
      Size = this->DisplayObjectArray.Data.Size;
      if ( (v10 >= Size || (this->DisplayObjectArray.Data.Data[v11].pCharacter->Flags & 0x8000u) == 0)
        && (v12 >= Size || (this->DisplayObjectArray.Data.Data[v12].pCharacter->Flags & 0x8000u) == 0) )
      {
        this->pCachedChar = 0i64;
        if ( v12 < Size )
        {
          Data = (Scaleform::GFx::DisplayObjectBase *)this->DisplayObjectArray.Data.Data;
          val.pCharacter = Data;
          v16 = (Scaleform::GFx::DisplayObjectBase *)((char *)Data + 16 * v12);
          if ( HIDWORD(v16->vfptr[5].__vecDelDtor) == v5 )
          {
            v29 = 0i64;
            v17 = (Scaleform::RefCountNTSImpl *)(&Data->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr)[v11 * 2];
            v29 = v17;
            if ( v17 )
              ++v17->RefCount;
            v33 = *(&Data->RefCount + 1 * v11);
            v30 = v33;
            v26 = *(&Data->RefCount + 1 * v11 + 1);
            v31 = v26;
            vfptr = (Scaleform::RefCountNTSImpl *)v16->vfptr;
            if ( (&Data->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr)[v11 * 2] )
            {
              Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)(&Data->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr)[v11 * 2]);
              Data = val.pCharacter;
            }
            (&Data->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr)[v11 * 2] = (Scaleform::RefCountNTSImplCoreVtbl *)vfptr;
            if ( vfptr )
              ++vfptr->RefCount;
            *(&Data->RefCount + 1 * v11) = v16->RefCount;
            *(&Data->RefCount + 1 * v11 + 1) = *(&v16->RefCount + 1);
            if ( v16->vfptr )
              Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v16->vfptr);
            v16->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)v17;
            if ( v17 )
              ++v17->RefCount;
            v16->RefCount = v33;
            *(&v16->RefCount + 1) = v26;
            if ( v17 )
              Scaleform::RefCountNTSImpl::Release(v17);
            Scaleform::GFx::DisplayList::SwapRenderTreeNodes(this, owner, v10, v13);
            pCharacter = this->DisplayObjectArray.Data.Data[v11].pCharacter;
            v20 = frame;
            v5 = depth2;
            if ( pCharacter )
            {
              pCharacter->Depth = depth1;
              pCharacter->CreateFrame = frame + 1;
            }
LABEL_33:
            v23 = this->DisplayObjectArray.Data.Data[v13].pCharacter;
            if ( v23 )
            {
              v23->Depth = v5;
              v23->CreateFrame = v20 + 1;
            }
            ++this->ModId;
            Flags = this->Flags;
            if ( (Flags & 2) != 0 )
              this->Flags = Flags | 1;
            return 1;
          }
          v7 = owner;
        }
        v21 = this->DisplayObjectArray.Data.Data;
        val.pCharacter = 0i64;
        v22 = v21[v11].pCharacter;
        val.pCharacter = v22;
        if ( v22 )
          ++v22->RefCount;
        val.TreeIndex = v21[v11].TreeIndex;
        val.MaskTreeIndex = v21[v11].MaskTreeIndex;
        Scaleform::GFx::DisplayList::RemoveFromRenderTree(this, v7, v10);
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          &this->DisplayObjectArray,
          v10);
        if ( v10 < v13 )
          --v13;
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
          &this->DisplayObjectArray,
          v13,
          &val);
        Scaleform::GFx::DisplayList::InsertIntoRenderTree(this, v7, v13);
        if ( v22 )
          Scaleform::RefCountNTSImpl::Release(v22);
        v20 = frame;
        goto LABEL_33;
      }
    }
  }
  return 0;
}

// File Line: 181
// RVA: 0x9123C0
char __fastcall Scaleform::GFx::DisplayList::SwapEntriesAtIndexes(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        unsigned __int64 origIndex1,
        unsigned __int64 origIndex2)
{
  Scaleform::GFx::DisplayList::DisplayEntry *Data; // rax
  Scaleform::GFx::DisplayObjectBase *pCharacter; // rbx
  unsigned __int64 v10; // r12
  Scaleform::GFx::DisplayList::DisplayEntry *v11; // r13
  Scaleform::GFx::DisplayList::DisplayEntry *v12; // r15
  Scaleform::GFx::DisplayObjectBase *v13; // rbp
  Scaleform::GFx::DisplayList::DisplayEntry *v14; // r15
  bool v15; // di
  unsigned int TreeIndex; // [rsp+90h] [rbp+18h]
  unsigned int MaskTreeIndex; // [rsp+98h] [rbp+20h]

  if ( origIndex1 == origIndex2 )
    return 1;
  Data = this->DisplayObjectArray.Data.Data;
  pCharacter = this->DisplayObjectArray.Data.Data[origIndex1].pCharacter;
  if ( pCharacter )
    ++pCharacter->RefCount;
  TreeIndex = Data[origIndex1].TreeIndex;
  MaskTreeIndex = Data[origIndex1].MaskTreeIndex;
  if ( (pCharacter->Flags & 0x8000u) != 0
    || origIndex2 < this->DisplayObjectArray.Data.Size
    && (this->DisplayObjectArray.Data.Data[origIndex2].pCharacter->Flags & 0x8000u) != 0 )
  {
    v15 = 0;
  }
  else
  {
    ++this->ModId;
    v10 = origIndex2;
    v11 = &this->DisplayObjectArray.Data.Data[origIndex2];
    v12 = &this->DisplayObjectArray.Data.Data[origIndex1];
    v13 = v11->pCharacter;
    if ( v12->pCharacter )
      Scaleform::RefCountNTSImpl::Release(v12->pCharacter);
    v12->pCharacter = v13;
    if ( v13 )
      ++v13->RefCount;
    v12->TreeIndex = v11->TreeIndex;
    v12->MaskTreeIndex = v11->MaskTreeIndex;
    v14 = &this->DisplayObjectArray.Data.Data[v10];
    if ( v14->pCharacter )
      Scaleform::RefCountNTSImpl::Release(v14->pCharacter);
    v14->pCharacter = pCharacter;
    ++pCharacter->RefCount;
    v14->TreeIndex = TreeIndex;
    v14->MaskTreeIndex = MaskTreeIndex;
    v15 = Scaleform::GFx::DisplayList::SwapRenderTreeNodes(this, owner, origIndex1, origIndex2);
  }
  Scaleform::RefCountNTSImpl::Release(pCharacter);
  return v15;
}

// File Line: 200
// RVA: 0x8DAAA0
__int64 __fastcall Scaleform::GFx::DisplayList::GetLargestDepthInUse(Scaleform::GFx::DisplayList *this)
{
  unsigned __int64 Size; // rcx

  Size = this->DisplayObjectArray.Data.Size;
  if ( Size )
    return (unsigned int)this->DisplayObjectArray.Data.Data[Size - 1].pCharacter->Depth;
  else
    return 0xFFFFFFFFi64;
}

// File Line: 208
// RVA: 0x8D6DA0
Scaleform::GFx::DisplayObject *__fastcall Scaleform::GFx::DisplayList::GetDisplayObjectByName(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::ASString *name,
        bool caseSensitive)
{
  int v5; // ebx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::DisplayObject *pCachedChar; // rcx
  bool v9; // di
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  unsigned __int64 Size; // r12
  unsigned __int64 v13; // rbp
  __int64 v14; // r14
  Scaleform::GFx::DisplayObjectBase *pCharacter; // rdi
  bool v16; // si
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::DisplayObject *v18; // rcx
  Scaleform::GFx::ASString *v19; // rdi
  char v20; // di
  Scaleform::GFx::ASStringNode *v21; // rcx
  unsigned __int64 v22; // r12
  unsigned __int64 v23; // rbp
  __int64 v24; // r14
  Scaleform::GFx::ASString *v25; // rsi
  char v26; // si
  Scaleform::GFx::ASStringNode *v27; // rcx
  Scaleform::GFx::ASString result; // [rsp+68h] [rbp+10h] BYREF

  v5 = 0;
  pNode = name->pNode;
  if ( !name->pNode->Size )
    return 0i64;
  if ( caseSensitive )
  {
    pCachedChar = this->pCachedChar;
    v9 = 0;
    if ( pCachedChar )
    {
      v5 = 1;
      if ( Scaleform::GFx::DisplayObject::GetName(pCachedChar, &result)->pNode == name->pNode )
        v9 = 1;
    }
    if ( (v5 & 1) != 0 )
    {
      v5 &= ~1u;
      v10 = result.pNode;
      v11 = result.pNode->RefCount-- == 1;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    }
    if ( v9 )
      return this->pCachedChar;
    Size = this->DisplayObjectArray.Data.Size;
    v13 = 0i64;
    if ( !Size )
      goto LABEL_54;
    v14 = 0i64;
    while ( 1 )
    {
      pCharacter = this->DisplayObjectArray.Data.Data[v14].pCharacter;
      v16 = 0;
      if ( pCharacter )
      {
        if ( (pCharacter->Flags & 0x100) != 0 )
        {
          v5 |= 2u;
          if ( Scaleform::GFx::DisplayObject::GetName(
                 (Scaleform::GFx::DisplayObject *)this->DisplayObjectArray.Data.Data[v14].pCharacter,
                 &result)->pNode == name->pNode )
            v16 = 1;
        }
      }
      if ( (v5 & 2) != 0 )
      {
        v5 &= ~2u;
        v17 = result.pNode;
        v11 = result.pNode->RefCount-- == 1;
        if ( v11 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      }
      if ( v16 )
        break;
      ++v13;
      ++v14;
      if ( v13 >= Size )
        goto LABEL_54;
    }
  }
  else
  {
    if ( !pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(pNode);
    v18 = this->pCachedChar;
    if ( !v18 )
      goto LABEL_32;
    v19 = Scaleform::GFx::DisplayObject::GetName(v18, &result);
    v5 = 4;
    if ( !v19->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v19->pNode);
    if ( name->pNode->pLower == v19->pNode->pLower )
      v20 = 1;
    else
LABEL_32:
      v20 = 0;
    if ( (v5 & 4) != 0 )
    {
      v5 &= ~4u;
      v21 = result.pNode;
      v11 = result.pNode->RefCount-- == 1;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v21);
    }
    if ( v20 )
      return this->pCachedChar;
    v22 = this->DisplayObjectArray.Data.Size;
    v23 = 0i64;
    if ( !v22 )
      goto LABEL_54;
    v24 = 0i64;
    while ( 1 )
    {
      pCharacter = this->DisplayObjectArray.Data.Data[v24].pCharacter;
      if ( !pCharacter || (pCharacter->Flags & 0x100) == 0 )
        goto LABEL_45;
      v25 = Scaleform::GFx::DisplayObject::GetName(
              (Scaleform::GFx::DisplayObject *)this->DisplayObjectArray.Data.Data[v24].pCharacter,
              &result);
      v5 |= 8u;
      if ( !v25->pNode->pLower )
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v25->pNode);
      if ( name->pNode->pLower == v25->pNode->pLower )
        v26 = 1;
      else
LABEL_45:
        v26 = 0;
      if ( (v5 & 8) != 0 )
      {
        v5 &= ~8u;
        v27 = result.pNode;
        v11 = result.pNode->RefCount-- == 1;
        if ( v11 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v27);
      }
      if ( v26 )
        break;
      ++v23;
      ++v24;
      if ( v23 >= v22 )
        goto LABEL_54;
    }
  }
  if ( !pCharacter )
  {
LABEL_54:
    this->pCachedChar = 0i64;
    return this->pCachedChar;
  }
  this->pCachedChar = (Scaleform::GFx::DisplayObject *)pCharacter;
  return this->pCachedChar;
}

// File Line: 264
// RVA: 0x8B05B0
void __fastcall Scaleform::GFx::DisplayList::AddDisplayObject(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        Scaleform::GFx::CharPosInfo *pos,
        Scaleform::GFx::DisplayObjectBase *ch,
        char addFlags)
{
  int Depth; // r14d
  unsigned __int64 Size; // r12
  unsigned __int64 DisplayIndex; // rax
  unsigned __int64 v12; // rsi
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  __int64 v15; // rdx

  Depth = pos->Depth;
  Size = this->DisplayObjectArray.Data.Size;
  DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex(this, Depth);
  v12 = DisplayIndex;
  this->pCachedChar = 0i64;
  if ( (addFlags & 1) != 0
    && DisplayIndex < Size
    && this->DisplayObjectArray.Data.Data[DisplayIndex].pCharacter->Depth == Depth )
  {
    Scaleform::GFx::DisplayList::UnloadDisplayObjectAtIndex(this, owner, DisplayIndex);
    v12 = Scaleform::GFx::DisplayList::FindDisplayIndex(this, Depth);
  }
  ch->Depth = Depth;
  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(ch);
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(RenderNode, 2u);
  WritableData[5] = *(Scaleform::Render::ContextImpl::EntryData *)&pos->ColorTransform.M[0][0];
  WritableData[6] = *(Scaleform::Render::ContextImpl::EntryData *)&pos->ColorTransform.M[1][0];
  ch->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[3].__vecDelDtor(
    ch,
    (unsigned int)&pos->Matrix_1);
  ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))ch->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[18].__vecDelDtor)(ch);
  ch->ClipDepth = pos->ClipDepth;
  ch->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[16].__vecDelDtor(
    ch,
    (unsigned __int8)pos->BlendMode);
  ch->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[56].__vecDelDtor(
    ch,
    (unsigned int)pos->pFilters.pObject);
  if ( (pos->Flags.Flags & 0x200) != 0 )
  {
    LOBYTE(v15) = pos->Visible != 0;
    ch->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[58].__vecDelDtor(
      ch,
      v15);
  }
  ++this->ModId;
  Scaleform::GFx::DisplayList::AddEntryAtIndex(this, owner, v12, ch);
  ch->Flags &= 0xEFEFu;
  ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))ch->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[73].__vecDelDtor)(ch);
}

// File Line: 352
// RVA: 0x8B0D50
void __fastcall Scaleform::GFx::DisplayList::AddEntryAtIndex(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        unsigned __int64 index,
        Scaleform::GFx::DisplayObjectBase *ch)
{
  unsigned __int64 Size; // r8
  Scaleform::GFx::DisplayList::DisplayEntry *v9; // rax
  char Flags; // al

  if ( ch )
    ++ch->RefCount;
  ++this->ModId;
  Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->DisplayObjectArray.Data,
    this->DisplayObjectArray.Data.Size + 1);
  Size = this->DisplayObjectArray.Data.Size;
  if ( index < Size - 1 )
    memmove(
      &this->DisplayObjectArray.Data.Data[index + 1],
      &this->DisplayObjectArray.Data.Data[index],
      16 * (Size - index - 1));
  v9 = &this->DisplayObjectArray.Data.Data[index];
  if ( v9 )
  {
    v9->pCharacter = ch;
    if ( ch )
      ++ch->RefCount;
    *(_QWORD *)&v9->TreeIndex = -1i64;
  }
  Scaleform::GFx::DisplayList::InsertIntoRenderTree(this, owner, index);
  Flags = this->Flags;
  if ( (Flags & 2) != 0 )
    this->Flags = Flags | 1;
  if ( ch )
    Scaleform::RefCountNTSImpl::Release(ch);
}

// File Line: 368
// RVA: 0x8EB920
void __fastcall Scaleform::GFx::DisplayList::MoveDisplayObject(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        Scaleform::GFx::CharPosInfo *pos)
{
  int Depth; // ebp
  unsigned __int64 Size; // rbx
  unsigned __int64 DisplayIndex; // rax
  Scaleform::GFx::DisplayList::DisplayEntry *v9; // r8
  Scaleform::GFx::DisplayObjectBase *pCharacter; // rbx
  __int64 v11; // rdx
  __int64 v12; // rdx
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax

  Depth = pos->Depth;
  Size = this->DisplayObjectArray.Data.Size;
  DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex(this, Depth);
  if ( DisplayIndex < Size )
  {
    v9 = &this->DisplayObjectArray.Data.Data[DisplayIndex];
    pCharacter = v9->pCharacter;
    if ( v9->pCharacter->Depth == Depth )
    {
      ++this->ModId;
      v9->pCharacter->Flags &= ~0x40u;
      if ( v9->TreeIndex == -1 )
        Scaleform::GFx::DisplayList::InsertIntoRenderTree(this, owner, DisplayIndex);
      if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[51].__vecDelDtor)(pCharacter) )
      {
        if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[52].__vecDelDtor)(pCharacter) )
          return;
        LOBYTE(v12) = 1;
        pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
          pCharacter,
          v12);
      }
      if ( (pos->Flags.Flags & 8) != 0 )
      {
        RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(pCharacter);
        WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(RenderNode, 2u);
        WritableData[5] = *(Scaleform::Render::ContextImpl::EntryData *)&pos->ColorTransform.M[0][0];
        WritableData[6] = *(Scaleform::Render::ContextImpl::EntryData *)&pos->ColorTransform.M[1][0];
      }
      if ( (pos->Flags.Flags & 4) != 0 )
        pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[3].__vecDelDtor(
          pCharacter,
          (unsigned int)&pos->Matrix_1);
      if ( SLOBYTE(pos->Flags.Flags) < 0 )
        pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[16].__vecDelDtor(
          pCharacter,
          (unsigned __int8)pos->BlendMode);
      if ( (pos->Flags.Flags & 0x200) != 0 )
      {
        LOBYTE(v11) = pos->Visible != 0;
        pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[58].__vecDelDtor(
          pCharacter,
          v11);
      }
      pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[56].__vecDelDtor(
        pCharacter,
        (unsigned int)pos->pFilters.pObject);
      ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[18].__vecDelDtor)(pCharacter);
    }
  }
}

// File Line: 433
// RVA: 0x8FFE60
void __fastcall Scaleform::GFx::DisplayList::ReplaceDisplayObject(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        Scaleform::GFx::CharPosInfo *pos,
        Scaleform::GFx::DisplayObjectBase *ch)
{
  unsigned __int64 Size; // rbx
  int Depth; // r12d
  unsigned __int64 DisplayIndex; // rax
  unsigned __int64 v11; // r13
  Scaleform::GFx::DisplayList::DisplayEntry *v12; // rbx
  Scaleform::GFx::DisplayObjectBase *pCharacter; // rsi
  Scaleform::GFx::CharPosInfo *Cxform; // rbx
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::Matrix2x4<float> *p_Matrix_1; // rax
  unsigned int BlendMode; // eax
  __int64 v19; // rdx
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rbx
  unsigned __int8 v21; // al
  char Flags; // al

  Size = this->DisplayObjectArray.Data.Size;
  Depth = pos->Depth;
  DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex(this, Depth);
  v11 = DisplayIndex;
  if ( DisplayIndex < Size && (v12 = &this->DisplayObjectArray.Data.Data[DisplayIndex], v12->pCharacter->Depth == Depth) )
  {
    ++this->ModId;
    pCharacter = v12->pCharacter;
    if ( v12->pCharacter )
      ++pCharacter->RefCount;
    ch->Depth = Depth;
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))ch->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[70].__vecDelDtor)(ch);
    v12->pCharacter->Flags &= ~0x40u;
    if ( v12->TreeIndex == -1 )
      Scaleform::GFx::DisplayList::InsertIntoRenderTree(this, owner, v11);
    if ( v12->pCharacter )
      Scaleform::RefCountNTSImpl::Release(v12->pCharacter);
    v12->pCharacter = ch;
    ++ch->RefCount;
    if ( (pos->Flags.Flags & 8) != 0 )
      Cxform = pos;
    else
      Cxform = (Scaleform::GFx::CharPosInfo *)Scaleform::GFx::DisplayObjectBase::GetCxform(pCharacter);
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(ch);
    WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(RenderNode, 2u);
    WritableData[5] = *(Scaleform::Render::ContextImpl::EntryData *)&Cxform->ColorTransform.M[0][0];
    WritableData[6] = *(Scaleform::Render::ContextImpl::EntryData *)&Cxform->ColorTransform.M[1][0];
    if ( (pos->Flags.Flags & 4) != 0 )
      p_Matrix_1 = &pos->Matrix_1;
    else
      p_Matrix_1 = (Scaleform::Render::Matrix2x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(pCharacter);
    ch->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[3].__vecDelDtor(
      ch,
      (unsigned int)p_Matrix_1);
    if ( SLOBYTE(pos->Flags.Flags) >= 0 )
      BlendMode = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[15].__vecDelDtor)(pCharacter);
    else
      BlendMode = (unsigned __int8)pos->BlendMode;
    ch->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[16].__vecDelDtor(
      ch,
      BlendMode);
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))ch->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[18].__vecDelDtor)(ch);
    ch->ClipDepth = pos->ClipDepth;
    ch->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[56].__vecDelDtor(
      ch,
      (unsigned int)pos->pFilters.pObject);
    if ( (pos->Flags.Flags & 0x200) != 0 )
    {
      LOBYTE(v19) = pos->Visible != 0;
      ch->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[58].__vecDelDtor(
        ch,
        v19);
    }
    else
    {
      vfptr = ch->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
      v21 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(pCharacter);
      vfptr[58].__vecDelDtor(ch, v21);
    }
    Scaleform::GFx::DisplayList::ReplaceRenderTreeNode(this, owner, v11);
    Flags = this->Flags;
    if ( (Flags & 2) != 0 )
      this->Flags = Flags | 1;
    this->pCachedChar = 0i64;
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[75].__vecDelDtor)(pCharacter);
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))ch->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[73].__vecDelDtor)(ch);
    Scaleform::RefCountNTSImpl::Release(pCharacter);
  }
  else
  {
    Scaleform::GFx::DisplayList::AddDisplayObject(this, owner, pos, ch, 1);
  }
}

// File Line: 499
// RVA: 0x900120
void __fastcall Scaleform::GFx::DisplayList::ReplaceDisplayObjectAtIndex(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        unsigned __int64 index,
        Scaleform::GFx::DisplayObjectBase *ch)
{
  Scaleform::GFx::DisplayList::DisplayEntry *v8; // rdi
  char Flags; // al

  if ( index < this->DisplayObjectArray.Data.Size )
  {
    ++this->ModId;
    this->pCachedChar = 0i64;
    v8 = &this->DisplayObjectArray.Data.Data[index];
    if ( v8->pCharacter )
      Scaleform::RefCountNTSImpl::Release(v8->pCharacter);
    v8->pCharacter = ch;
    if ( ch )
      ++ch->RefCount;
    if ( v8->TreeIndex == -1 )
      Scaleform::GFx::DisplayList::InsertIntoRenderTree(this, owner, index);
    else
      Scaleform::GFx::DisplayList::ReplaceRenderTreeNode(this, owner, index);
    Flags = this->Flags;
    if ( (Flags & 2) != 0 )
      this->Flags = Flags | 1;
  }
}

// File Line: 523
// RVA: 0x8FF1A0
void __fastcall Scaleform::GFx::DisplayList::RemoveDisplayObject(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        int depth,
        int *id)
{
  unsigned __int64 Size; // rbp
  unsigned __int64 DisplayIndex; // rax
  unsigned __int64 v10; // r10
  unsigned __int64 v11; // rax
  Scaleform::GFx::DisplayObjectBase *pCharacter; // rbx
  int v13; // edx
  Scaleform::GFx::DisplayList::DisplayEntry *v14; // rcx

  Size = this->DisplayObjectArray.Data.Size;
  DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex(this, depth);
  v10 = DisplayIndex;
  if ( DisplayIndex < Size )
  {
    v11 = DisplayIndex;
    pCharacter = this->DisplayObjectArray.Data.Data[v11].pCharacter;
    if ( pCharacter )
      ++pCharacter->RefCount;
    if ( pCharacter->Depth == depth )
    {
      this->pCachedChar = 0i64;
      ++this->ModId;
      v13 = *id;
      if ( *id == 0x40000 || (v14 = &this->DisplayObjectArray.Data.Data[v11], v14->pCharacter->Id.Id == v13) )
      {
LABEL_10:
        Scaleform::GFx::DisplayList::UnloadDisplayObjectAtIndex(this, owner, v10);
      }
      else
      {
        while ( ++v10 < Size && v14[1].pCharacter->Depth == depth )
        {
          v14 = &this->DisplayObjectArray.Data.Data[v10];
          if ( v14->pCharacter->Id.Id == v13 )
            goto LABEL_10;
        }
      }
    }
    Scaleform::RefCountNTSImpl::Release(pCharacter);
  }
}

// File Line: 617
// RVA: 0x8FF350
void __fastcall Scaleform::GFx::DisplayList::RemoveEntryAtIndex(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        unsigned __int64 index)
{
  char Flags; // al

  Scaleform::GFx::DisplayList::RemoveFromRenderTree(this, owner, index);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
    &this->DisplayObjectArray,
    index);
  Flags = this->Flags;
  ++this->ModId;
  this->pCachedChar = 0i64;
  if ( (Flags & 2) != 0 )
    this->Flags = Flags | 1;
}

// File Line: 670
// RVA: 0x8BBF70
void __fastcall Scaleform::GFx::DisplayList::Clear(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // rdi
  Scaleform::GFx::MovieDefImpl *v5; // rax
  Scaleform::GFx::DisplayList::DisplayEntry *Data; // rdi
  Scaleform::GFx::DisplayObjectBase *pCharacter; // rcx

  pMovieImpl = owner->pASRoot->pMovieImpl;
  v5 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))owner->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(owner);
  Scaleform::GFx::MovieImpl::AddMovieDefToKillList(pMovieImpl, v5);
  while ( this->DisplayObjectArray.Data.Size )
  {
    ++this->ModId;
    Data = this->DisplayObjectArray.Data.Data;
    this->pCachedChar = 0i64;
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))Data->pCharacter->vfptr[75].__vecDelDtor)(Data->pCharacter);
    Scaleform::GFx::DisplayList::RemoveFromRenderTree(this, owner, 0i64);
    Data->pCharacter->pParent = 0i64;
    if ( this->DisplayObjectArray.Data.Size == 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &this->DisplayObjectArray.Data,
        this,
        0i64);
    }
    else
    {
      pCharacter = this->DisplayObjectArray.Data.Data->pCharacter;
      if ( pCharacter )
        Scaleform::RefCountNTSImpl::Release(pCharacter);
      memmove(
        this->DisplayObjectArray.Data.Data,
        &this->DisplayObjectArray.Data.Data[1],
        16 * (this->DisplayObjectArray.Data.Size - 1));
      --this->DisplayObjectArray.Data.Size;
    }
  }
  this->pCachedChar = 0i64;
  Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->DisplayObjectArray.Data,
    0i64);
}

// File Line: 690
// RVA: 0x9150B0
__int64 __fastcall Scaleform::GFx::DisplayList::UnloadAll(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner)
{
  unsigned __int8 v3; // r13
  unsigned __int64 v4; // rbp
  __int64 v5; // rsi
  Scaleform::GFx::DisplayList::DisplayEntry *v6; // r15
  Scaleform::GFx::DisplayObjectBase *pCharacter; // rdi
  char v8; // r12
  Scaleform::GFx::DisplayObjectBase *v9; // rcx
  Scaleform::GFx::DisplayObjectBase *v10; // rdi
  int v11; // r14d
  __int64 DisplayIndex; // rax
  char v13; // al
  Scaleform::GFx::DisplayObjectBase *v14; // rcx
  Scaleform::GFx::DisplayObjectBase *v15; // rcx
  char Flags; // al
  Scaleform::GFx::DisplayList::DisplayEntry val; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::GFx::DisplayObjectBase *v19; // [rsp+78h] [rbp+10h]

  v19 = owner;
  this->pCachedChar = 0i64;
  v3 = 1;
  v4 = 0i64;
  if ( this->DisplayObjectArray.Data.Size )
  {
    v5 = 0i64;
    do
    {
      ++this->ModId;
      v6 = &this->DisplayObjectArray.Data.Data[v5];
      Scaleform::GFx::DisplayList::RemoveFromRenderTree(this, owner, v4);
      pCharacter = v6->pCharacter;
      if ( (v6->pCharacter->Flags & 0x40) != 0 )
        goto LABEL_28;
      if ( !pCharacter )
      {
        v14 = this->DisplayObjectArray.Data.Data[v5].pCharacter;
        if ( v14 )
          v14->pParent = 0i64;
        if ( this->DisplayObjectArray.Data.Size == 1 )
        {
          Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
            &this->DisplayObjectArray.Data,
            0i64);
        }
        else
        {
          v15 = this->DisplayObjectArray.Data.Data[v5].pCharacter;
          if ( v15 )
            Scaleform::RefCountNTSImpl::Release(v15);
          memmove(
            &this->DisplayObjectArray.Data.Data[v5],
            &this->DisplayObjectArray.Data.Data[v5 + 1],
            16 * (this->DisplayObjectArray.Data.Size - v4 - 1));
          --this->DisplayObjectArray.Data.Size;
        }
        this->pCachedChar = 0i64;
        Flags = this->Flags;
        if ( (Flags & 2) != 0 )
          this->Flags = Flags | 1;
        goto LABEL_29;
      }
      if ( (pCharacter->Flags & 0x1000) != 0 || pCharacter->Depth < -1 )
        goto LABEL_28;
      v8 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[74].__vecDelDtor)(v6->pCharacter);
      pCharacter->Flags |= 0x1000u;
      if ( v8 )
      {
        ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[75].__vecDelDtor)(pCharacter);
        v9 = this->DisplayObjectArray.Data.Data[v5].pCharacter;
        if ( v9 )
          v9->pParent = 0i64;
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          &this->DisplayObjectArray,
          v4);
      }
      else
      {
        v10 = v6->pCharacter;
        if ( v6->pCharacter->Depth >= 0 )
        {
          v11 = -1 - v10->Depth;
          val.pCharacter = v6->pCharacter;
          if ( v10 )
            ++v10->RefCount;
          val.TreeIndex = v6->TreeIndex;
          val.MaskTreeIndex = v6->MaskTreeIndex;
          Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
            &this->DisplayObjectArray,
            v4);
          v10->Depth = v11;
          DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex(this, v11);
          Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
            &this->DisplayObjectArray,
            DisplayIndex,
            &val);
          Scaleform::RefCountNTSImpl::Release(v10);
        }
      }
      this->pCachedChar = 0i64;
      v13 = this->Flags;
      if ( (v13 & 2) != 0 )
        this->Flags = v13 | 1;
      if ( !v8 )
      {
LABEL_28:
        ++v4;
        ++v5;
        v3 = 0;
      }
LABEL_29:
      owner = v19;
    }
    while ( v4 < this->DisplayObjectArray.Data.Size );
  }
  return v3;
}

// File Line: 717
// RVA: 0x8EB780
void __fastcall Scaleform::GFx::DisplayList::MarkAllEntriesForRemoval(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        unsigned int targetFrame)
{
  unsigned __int64 Size; // rbp
  unsigned __int64 v7; // rdi
  __int64 v8; // rsi
  Scaleform::GFx::DisplayList::DisplayEntry *Data; // rax
  Scaleform::GFx::DisplayObjectBase *pCharacter; // rbx

  Size = this->DisplayObjectArray.Data.Size;
  v7 = 0i64;
  if ( Size )
  {
    v8 = 0i64;
    do
    {
      Data = this->DisplayObjectArray.Data.Data;
      pCharacter = this->DisplayObjectArray.Data.Data[v8].pCharacter;
      if ( pCharacter )
        ++pCharacter->RefCount;
      if ( pCharacter->Depth <= 0x3FFFu && pCharacter->CreateFrame > targetFrame )
      {
        Data[v8].pCharacter->Flags |= 0x40u;
        Scaleform::GFx::DisplayList::RemoveFromRenderTree(this, owner, v7);
      }
      Scaleform::RefCountNTSImpl::Release(pCharacter);
      ++v7;
      ++v8;
    }
    while ( v7 < Size );
  }
}

// File Line: 749
// RVA: 0x9155B0
void __fastcall Scaleform::GFx::DisplayList::UnloadMarkedObjects(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner)
{
  unsigned __int64 v2; // rbx
  __int64 v5; // rdi
  Scaleform::GFx::DisplayObjectBase *pCharacter; // rcx

  v2 = 0i64;
  this->pCachedChar = 0i64;
  if ( this->DisplayObjectArray.Data.Size )
  {
    v5 = 0i64;
    do
    {
      pCharacter = this->DisplayObjectArray.Data.Data[v5].pCharacter;
      if ( (pCharacter->Flags & 0x40) != 0 )
      {
        pCharacter->Flags &= ~0x40u;
        if ( Scaleform::GFx::DisplayList::UnloadDisplayObjectAtIndex(this, owner, v2) )
        {
          --v2;
          --v5;
        }
      }
      ++v2;
      ++v5;
    }
    while ( v2 < this->DisplayObjectArray.Data.Size );
  }
  ++this->ModId;
  this->pCachedChar = 0i64;
}

// File Line: 777
// RVA: 0x9001C0
void __fastcall Scaleform::GFx::DisplayList::ReplaceRenderTreeNode(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        unsigned __int64 index)
{
  Scaleform::GFx::DisplayList::DisplayEntry *v4; // rsi
  __int64 v5; // rax
  Scaleform::GFx::DisplayObjectBase *pCharacter; // rdi
  __int64 v7; // rbp
  __int64 v8; // rbx
  Scaleform::GFx::MovieImpl *pMovieImpl; // rbx
  Scaleform::GFx::MovieDefImpl *v10; // rax
  _QWORD *v11; // rdx
  Scaleform::Render::TreeContainer *v12; // rbx
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::Render::TreeNode *v14; // rax
  unsigned __int64 TreeIndex; // rdx
  Scaleform::Render::TreeContainer *v16; // rcx

  v4 = &this->DisplayObjectArray.Data.Data[index];
  if ( (v4->pCharacter->Flags & 0x8000u) != 0 )
  {
    Scaleform::GFx::MovieImpl::UpdateTransformParent(owner->pASRoot->pMovieImpl, v4->pCharacter, owner);
    return;
  }
  v5 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))owner->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[69].__vecDelDtor)(owner);
  pCharacter = v4->pCharacter;
  v7 = v5;
  v8 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))owner->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(owner);
  if ( ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(pCharacter) != v8 )
  {
    pMovieImpl = v4->pCharacter->pASRoot->pMovieImpl;
    v10 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v4->pCharacter->vfptr[66].__vecDelDtor)(v4->pCharacter);
    Scaleform::GFx::MovieImpl::AddMovieDefToKillList(pMovieImpl, v10);
  }
  v11 = (_QWORD *)(*(_QWORD *)(*(_QWORD *)((v7 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64 * (unsigned int)((int)(v7 - (v7 & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 144i64);
  if ( (*(_BYTE *)v11 & 1) != 0 )
    v11 = (_QWORD *)((*v11 & 0xFFFFFFFFFFFFFFFEui64) + 16);
  v12 = (Scaleform::Render::TreeContainer *)v11[v4->TreeIndex];
  if ( v4->MaskTreeIndex == -1 )
  {
    if ( (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v12 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                               + 8i64 * (unsigned int)((int)((_DWORD)v12 - ((unsigned int)v12 & 0xFFFFF000) - 56) / 56)
                               + 40)
                   + 10i64) & 0x10) != 0 )
    {
      RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v4->pCharacter);
      Scaleform::Render::TreeNode::SetMaskNode(v12, RenderNode);
      return;
    }
    Scaleform::Render::TreeContainer::Remove((Scaleform::Render::TreeContainer *)v7, v4->TreeIndex, 1ui64);
    v14 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v4->pCharacter);
    TreeIndex = v4->TreeIndex;
    v16 = (Scaleform::Render::TreeContainer *)v7;
  }
  else
  {
    Scaleform::Render::TreeContainer::Remove(v12, v4->MaskTreeIndex, 1ui64);
    v14 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v4->pCharacter);
    TreeIndex = v4->MaskTreeIndex;
    v16 = v12;
  }
  Scaleform::Render::TreeContainer::Insert(v16, TreeIndex, v14);
}

// File Line: 826
// RVA: 0x8FF540
void __fastcall Scaleform::GFx::DisplayList::RemoveFromRenderTree(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        unsigned __int64 index)
{
  unsigned __int64 v3; // r13
  Scaleform::GFx::DisplayList::DisplayEntry *v6; // rsi
  __int16 *pCharacter; // rcx
  Scaleform::GFx::MovieImpl *pMovieImpl; // r8
  __int64 v9; // rbx
  unsigned __int64 Size; // rdx
  Scaleform::GFx::MovieImpl::IndirectTransPair *Data; // r9
  __int16 **i; // rax
  Scaleform::GFx::MovieImpl::IndirectTransPair *v13; // rbx
  Scaleform::Render::ContextImpl::Entry *pObject; // rcx
  bool v15; // zf
  __int64 v16; // rbx
  Scaleform::GFx::MovieImpl *v17; // rbx
  Scaleform::GFx::MovieDefImpl *v18; // rax
  Scaleform::Render::TreeContainer *v19; // rax
  unsigned __int64 TreeIndex; // rdx
  Scaleform::Render::TreeContainer *v21; // r9
  int v22; // r12d
  unsigned __int64 v23; // r14
  unsigned __int64 v24; // r15
  Scaleform::GFx::DisplayList::DisplayEntry *v25; // rbp
  unsigned int v26; // eax
  Scaleform::Render::TreeNode *v27; // rax
  Scaleform::Render::TreeNode *v28; // rbx
  unsigned int v29; // eax
  unsigned __int64 v30; // rdx
  unsigned __int64 v31; // rcx
  unsigned int v32; // eax
  unsigned __int64 MaskTreeIndex; // rbx
  Scaleform::Render::TreeContainer *v34; // rax
  unsigned __int64 v35; // rdx
  unsigned __int64 v36; // rcx
  unsigned int v37; // r8d
  Scaleform::Render::TreeContainer *v38; // [rsp+70h] [rbp+8h]
  Scaleform::Render::TreeContainer *v39; // [rsp+80h] [rbp+18h]

  v3 = index;
  v6 = &this->DisplayObjectArray.Data.Data[index];
  pCharacter = (__int16 *)v6->pCharacter;
  if ( v6->TreeIndex == -1 )
  {
    if ( pCharacter[53] < 0 )
    {
      pMovieImpl = owner->pASRoot->pMovieImpl;
      v9 = 0i64;
      Size = pMovieImpl->IndirectTransformPairs.Data.Size;
      if ( Size )
      {
        Data = pMovieImpl->IndirectTransformPairs.Data.Data;
        for ( i = (__int16 **)&Data->Obj; *i != pCharacter; i += 4 )
        {
          if ( ++v9 >= Size )
            return;
        }
        v13 = &Data[v9];
        pObject = v13->TransformParent.pObject;
        if ( v13->TransformParent.pObject )
        {
          v15 = pObject->RefCount-- == 1;
          if ( v15 )
            Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
        }
        v13->TransformParent.pObject = 0i64;
        v13->OrigParentDepth = -1;
      }
    }
  }
  else
  {
    v16 = (*(__int64 (__fastcall **)(__int16 *))(*(_QWORD *)pCharacter + 528i64))(pCharacter);
    if ( v16 != ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))owner->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(owner) )
    {
      v17 = v6->pCharacter->pASRoot->pMovieImpl;
      v18 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v6->pCharacter->vfptr[66].__vecDelDtor)(v6->pCharacter);
      Scaleform::GFx::MovieImpl::AddMovieDefToKillList(v17, v18);
    }
    v19 = (Scaleform::Render::TreeContainer *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))owner->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[69].__vecDelDtor)(owner);
    v39 = v19;
    TreeIndex = v6->TreeIndex;
    if ( v6->MaskTreeIndex == -1 )
    {
      v21 = (Scaleform::Render::TreeContainer *)Scaleform::Render::TreeContainer::GetAt(v19, TreeIndex);
      v38 = v21;
      v22 = -1;
      if ( (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v21 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                 + 8i64
                                 * (unsigned int)((int)((_DWORD)v21 - ((unsigned int)v21 & 0xFFFFF000) - 56) / 56)
                                 + 40)
                     + 10i64) & 0x10) != 0 )
      {
        v23 = v3 + 1;
        if ( v3 + 1 < this->DisplayObjectArray.Data.Size )
        {
          v24 = v23;
          do
          {
            v25 = &this->DisplayObjectArray.Data.Data[v24];
            v26 = v25->TreeIndex;
            if ( (v26 != v6->TreeIndex || v25->MaskTreeIndex == -1) && v26 != -1 )
              break;
            ++v3;
            if ( v26 != -1 )
            {
              v27 = Scaleform::Render::TreeContainer::GetAt(v21, 0i64);
              v28 = v27;
              if ( v27 )
                ++v27->RefCount;
              Scaleform::Render::TreeContainer::Remove(v38, 0i64, 1ui64);
              v29 = v6->TreeIndex + v25->MaskTreeIndex;
              v25->TreeIndex = v29;
              v25->MaskTreeIndex = -1;
              Scaleform::Render::TreeContainer::Insert(v39, v29, v28);
              ++v22;
              if ( v28 )
              {
                v15 = v28->RefCount-- == 1;
                if ( v15 )
                  Scaleform::Render::ContextImpl::Entry::destroyHelper(v28);
              }
              v21 = v38;
            }
            ++v23;
            ++v24;
          }
          while ( v23 < this->DisplayObjectArray.Data.Size );
        }
      }
      Scaleform::Render::TreeContainer::Remove(v39, v22 + v6->TreeIndex + 1, 1ui64);
      v30 = v3 + 1;
      if ( v3 + 1 < this->DisplayObjectArray.Data.Size )
      {
        v31 = v30;
        do
        {
          v32 = this->DisplayObjectArray.Data.Data[v31].TreeIndex;
          if ( v32 != -1 )
            this->DisplayObjectArray.Data.Data[v31].TreeIndex = v22 + v32;
          ++v30;
          ++v31;
        }
        while ( v30 < this->DisplayObjectArray.Data.Size );
      }
    }
    else
    {
      MaskTreeIndex = v6->MaskTreeIndex;
      v34 = (Scaleform::Render::TreeContainer *)Scaleform::Render::TreeContainer::GetAt(v19, TreeIndex);
      Scaleform::Render::TreeContainer::Remove(v34, MaskTreeIndex, 1ui64);
      v35 = v3 + 1;
      if ( v3 + 1 < this->DisplayObjectArray.Data.Size )
      {
        v36 = v35;
        do
        {
          v37 = this->DisplayObjectArray.Data.Data[v36].TreeIndex;
          if ( v37 != -1 )
          {
            if ( v37 != v6->TreeIndex )
              break;
            --this->DisplayObjectArray.Data.Data[v36].MaskTreeIndex;
          }
          ++v35;
          ++v36;
        }
        while ( v35 < this->DisplayObjectArray.Data.Size );
      }
    }
    *(_QWORD *)&v6->TreeIndex = -1i64;
  }
}

// File Line: 922
// RVA: 0x8E6300
void __fastcall Scaleform::GFx::DisplayList::InsertIntoRenderTree(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        unsigned __int64 index)
{
  unsigned __int64 v3; // rbp
  unsigned __int64 v6; // r14
  Scaleform::GFx::DisplayList::DisplayEntry *v7; // r12
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::Render::TreeNode *v9; // r13
  char v10; // r9
  signed __int64 v11; // rbx
  Scaleform::GFx::DisplayList::DisplayEntry *Data; // rdx
  unsigned int *p_TreeIndex; // rcx
  Scaleform::GFx::DisplayList::DisplayEntry *v14; // r8
  unsigned int v15; // edi
  unsigned int *v16; // rax
  Scaleform::GFx::DisplayList::DisplayEntry *v17; // rbx
  int Depth; // ecx
  Scaleform::Render::TreeContainer *v19; // r14
  Scaleform::Render::TreeContainer *v20; // rdi
  bool v21; // zf
  unsigned __int64 v22; // rdx
  unsigned __int64 v23; // r8
  Scaleform::GFx::DisplayList::DisplayEntry *v24; // rcx
  int v25; // r12d
  unsigned __int64 v26; // rbx
  Scaleform::Render::TreeContainer *v27; // rdi
  unsigned __int64 Size; // r8
  unsigned int *v29; // rdx
  unsigned int v30; // r13d
  unsigned __int64 v31; // rax
  unsigned __int64 v32; // rbp
  unsigned __int64 v33; // r15
  Scaleform::GFx::DisplayObjectBase *v34; // rdx
  Scaleform::GFx::DisplayList::DisplayEntry *v35; // r14
  Scaleform::GFx::DisplayObjectBase *v36; // rcx
  Scaleform::Render::TreeNode *v37; // rax
  Scaleform::Render::TreeNode *v38; // rdi
  unsigned __int64 v39; // rcx
  unsigned int TreeIndex; // eax
  Scaleform::Render::TreeContainer *v41; // [rsp+20h] [rbp-78h]
  Scaleform::Render::TreeContainer *v42; // [rsp+28h] [rbp-70h]
  Scaleform::Render::TreeContainer *v43; // [rsp+28h] [rbp-70h]
  Scaleform::Render::TreeNode *v44; // [rsp+30h] [rbp-68h]
  Scaleform::GFx::DisplayList::DisplayEntry *v45; // [rsp+38h] [rbp-60h]
  int v46; // [rsp+A0h] [rbp+8h]
  Scaleform::GFx::DisplayObjectBase *pCharacter; // [rsp+B0h] [rbp+18h]
  unsigned __int64 indexa; // [rsp+B8h] [rbp+20h]

  v3 = index;
  v6 = 16 * index;
  v42 = (Scaleform::Render::TreeContainer *)(16 * index);
  v7 = &this->DisplayObjectArray.Data.Data[index];
  v45 = v7;
  if ( (v7->pCharacter->Flags & 0x8000u) == 0 )
  {
    v41 = (Scaleform::Render::TreeContainer *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))owner->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[69].__vecDelDtor)(owner);
    pCharacter = v7->pCharacter;
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v7->pCharacter);
    v9 = RenderNode;
    v44 = RenderNode;
    if ( RenderNode )
      ++RenderNode->RefCount;
    v10 = 0;
    if ( v3 )
    {
      v11 = this->DisplayObjectArray.Data.Size - 1;
      if ( v3 - 1 < v11 )
        v11 = v3 - 1;
      if ( v11 < 0 )
      {
LABEL_41:
        indexa = 0i64;
        v7->TreeIndex = 0;
      }
      else
      {
        Data = this->DisplayObjectArray.Data.Data;
        p_TreeIndex = &this->DisplayObjectArray.Data.Data[v11].TreeIndex;
        while ( *p_TreeIndex == -1 )
        {
          p_TreeIndex -= 4;
          if ( --v11 < 0 )
            goto LABEL_41;
        }
        v14 = &Data[v11];
        indexa = 0i64;
        if ( !v14->pCharacter->ClipDepth && v14->MaskTreeIndex == -1 )
          goto LABEL_40;
        v15 = 0;
        if ( v11 )
        {
          v16 = &v14->TreeIndex;
          do
          {
            if ( v16[1] == -1 )
            {
              if ( *v16 != -1 )
                break;
            }
            else if ( *v16 != -1 )
            {
              ++v15;
            }
            v16 -= 4;
            --v11;
          }
          while ( v11 );
        }
        v17 = &Data[v11];
        Depth = pCharacter->Depth;
        if ( Depth <= v17->pCharacter->ClipDepth && (Depth > v17->pCharacter->Depth || Depth == -1) )
        {
          v7->TreeIndex = v17->TreeIndex;
          v7->MaskTreeIndex = v15;
          v19 = (Scaleform::Render::TreeContainer *)Scaleform::Render::TreeContainer::GetAt(v41, v17->TreeIndex);
          if ( pCharacter->ClipDepth )
          {
            v20 = Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeContainer>(&owner->pASRoot->pMovieImpl->RenderContext);
            Scaleform::Render::TreeNode::SetMaskNode(v20, v9);
            Scaleform::Render::TreeContainer::Insert(v19, v7->MaskTreeIndex, v20);
            if ( v20 )
            {
              v21 = v20->RefCount-- == 1;
              if ( v21 )
                Scaleform::Render::ContextImpl::Entry::destroyHelper(v20);
            }
          }
          else
          {
            Scaleform::Render::TreeContainer::Insert(v19, v15, v9);
          }
          v22 = v3 + 1;
          if ( v3 + 1 < this->DisplayObjectArray.Data.Size )
          {
            v23 = v22;
            do
            {
              v24 = &this->DisplayObjectArray.Data.Data[v23];
              if ( v24->pCharacter->Depth > v17->pCharacter->ClipDepth
                || v24->pCharacter->Depth <= v17->pCharacter->Depth )
              {
                break;
              }
              if ( v24->TreeIndex != -1 )
                ++v24->MaskTreeIndex;
              ++v22;
              ++v23;
            }
            while ( v22 < this->DisplayObjectArray.Data.Size );
          }
          v10 = 1;
          v6 = (unsigned __int64)v42;
        }
        else
        {
LABEL_40:
          v7->TreeIndex = v14->TreeIndex + 1;
        }
      }
    }
    else
    {
      indexa = 0i64;
      v7->TreeIndex = 0;
    }
    v25 = 1;
    v46 = 1;
    if ( !v10 )
    {
      v26 = v3 + 1;
      if ( pCharacter->ClipDepth )
      {
        v27 = Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeContainer>(&owner->pASRoot->pMovieImpl->RenderContext);
        v43 = v27;
        Scaleform::Render::TreeNode::SetMaskNode(v27, v9);
        Size = this->DisplayObjectArray.Data.Size;
        if ( v26 < Size )
        {
          v29 = (unsigned int *)((char *)&this->DisplayObjectArray.Data.Data[1].TreeIndex + v6);
          v30 = *v29;
          if ( *v29 != -1 )
            goto LABEL_80;
          v31 = v3 + 1;
          do
          {
            ++v26;
            ++v3;
            ++v31;
            v29 += 4;
            if ( v31 >= Size )
              break;
            v30 = *v29;
          }
          while ( *v29 == -1 );
          if ( v30 != -1 )
          {
LABEL_80:
            v32 = v3 + 1;
            if ( v32 < Size )
            {
              v33 = v32;
              v34 = pCharacter;
              do
              {
                v35 = &this->DisplayObjectArray.Data.Data[v33];
                v36 = v35->pCharacter;
                if ( v35->pCharacter->Depth > v34->ClipDepth || v36->Depth <= v34->Depth )
                  break;
                ++v26;
                if ( v35->TreeIndex != -1 )
                {
                  if ( v36->ClipDepth )
                    break;
                  v37 = Scaleform::Render::TreeContainer::GetAt(v41, v30);
                  v38 = v37;
                  if ( v37 )
                    ++v37->RefCount;
                  Scaleform::Render::TreeContainer::Remove(v41, v30, 1ui64);
                  v35->TreeIndex = v45->TreeIndex;
                  v35->MaskTreeIndex = indexa;
                  Scaleform::Render::TreeContainer::Insert(v43, (unsigned int)indexa, v38);
                  v25 = --v46;
                  ++indexa;
                  if ( v38 )
                  {
                    v21 = v38->RefCount-- == 1;
                    if ( v21 )
                      Scaleform::Render::ContextImpl::Entry::destroyHelper(v38);
                  }
                  v34 = pCharacter;
                }
                ++v32;
                ++v33;
              }
              while ( v32 < this->DisplayObjectArray.Data.Size );
              v27 = v43;
            }
          }
          v9 = v44;
        }
        Scaleform::Render::TreeContainer::Insert(v41, v45->TreeIndex, v27);
        if ( v27 )
        {
          v21 = v27->RefCount-- == 1;
          if ( v21 )
            Scaleform::Render::ContextImpl::Entry::destroyHelper(v27);
        }
      }
      else
      {
        Scaleform::Render::TreeContainer::Insert(v41, v45->TreeIndex, v9);
      }
      if ( v26 < this->DisplayObjectArray.Data.Size )
      {
        v39 = v26;
        do
        {
          TreeIndex = this->DisplayObjectArray.Data.Data[v39].TreeIndex;
          if ( TreeIndex != -1 )
            this->DisplayObjectArray.Data.Data[v39].TreeIndex = v25 + TreeIndex;
          ++v26;
          ++v39;
        }
        while ( v26 < this->DisplayObjectArray.Data.Size );
      }
    }
    if ( v9 )
    {
      v21 = v9->RefCount-- == 1;
      if ( v21 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v9);
    }
  }
  else
  {
    Scaleform::GFx::MovieImpl::UpdateTransformParent(owner->pASRoot->pMovieImpl, v7->pCharacter, owner);
  }
}

// File Line: 1091
// RVA: 0x9125D0
char __fastcall Scaleform::GFx::DisplayList::SwapRenderTreeNodes(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        unsigned __int64 index1,
        unsigned __int64 index2)
{
  Scaleform::GFx::DisplayList::DisplayEntry *v4; // rdi
  Scaleform::GFx::DisplayList::DisplayEntry *v5; // rbx
  Scaleform::Render::TreeNode *RenderNode; // rax
  unsigned int MaskTreeIndex; // ecx
  Scaleform::Render::TreeNode *v8; // r12
  Scaleform::Render::TreeContainer *pParent; // r15
  unsigned __int64 v10; // r14
  Scaleform::Render::TreeNode *v11; // rax
  unsigned int TreeIndex; // ecx
  Scaleform::Render::TreeNode *v13; // r13
  Scaleform::Render::TreeContainer *v14; // rbp
  unsigned __int64 v15; // rsi
  unsigned __int64 v16; // rdx
  Scaleform::Render::TreeNode *v17; // r8
  unsigned __int64 v18; // rdx
  Scaleform::Render::TreeContainer *v19; // rcx
  unsigned int v20; // ecx
  unsigned int v21; // ecx
  unsigned int v22; // ecx
  unsigned int v23; // ecx

  v4 = &this->DisplayObjectArray.Data.Data[index1];
  v5 = &this->DisplayObjectArray.Data.Data[index2];
  if ( (v4->pCharacter->Flags & 0x8000u) == 0 && (v5->pCharacter->Flags & 0x8000u) == 0 )
  {
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v4->pCharacter);
    MaskTreeIndex = v4->MaskTreeIndex;
    v8 = RenderNode;
    if ( MaskTreeIndex == -1 )
      MaskTreeIndex = v4->TreeIndex;
    pParent = (Scaleform::Render::TreeContainer *)RenderNode->pParent;
    v10 = MaskTreeIndex;
    v11 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v5->pCharacter);
    TreeIndex = v5->MaskTreeIndex;
    v13 = v11;
    if ( TreeIndex == -1 )
      TreeIndex = v5->TreeIndex;
    v14 = (Scaleform::Render::TreeContainer *)v11->pParent;
    v15 = TreeIndex;
    if ( v4->pCharacter->ClipDepth || v5->pCharacter->ClipDepth )
    {
      v22 = v4->TreeIndex;
      v4->TreeIndex = v5->TreeIndex;
      v5->TreeIndex = v22;
      v23 = v4->MaskTreeIndex;
      v4->MaskTreeIndex = v5->MaskTreeIndex;
      v5->MaskTreeIndex = v23;
      Scaleform::GFx::DisplayList::RemoveFromRenderTree(this, owner, index1);
      Scaleform::GFx::DisplayList::RemoveFromRenderTree(this, owner, index2);
      Scaleform::GFx::DisplayList::InsertIntoRenderTree(this, owner, index1);
      Scaleform::GFx::DisplayList::InsertIntoRenderTree(this, owner, index2);
      return 1;
    }
    if ( pParent == v14 )
    {
      if ( v10 >= TreeIndex )
      {
        Scaleform::Render::TreeContainer::Remove(v14, TreeIndex, 1ui64);
        Scaleform::Render::TreeContainer::Remove(pParent, v10 - 1, 1ui64);
        Scaleform::Render::TreeContainer::Insert(v14, v15, v8);
        v17 = v13;
        v18 = v10;
        v19 = pParent;
LABEL_15:
        Scaleform::Render::TreeContainer::Insert(v19, v18, v17);
        v20 = v4->TreeIndex;
        v4->TreeIndex = v5->TreeIndex;
        v5->TreeIndex = v20;
        v21 = v4->MaskTreeIndex;
        v4->MaskTreeIndex = v5->MaskTreeIndex;
        v5->MaskTreeIndex = v21;
        return 1;
      }
      Scaleform::Render::TreeContainer::Remove(pParent, v10, 1ui64);
      v16 = v15 - 1;
    }
    else
    {
      Scaleform::Render::TreeContainer::Remove(pParent, v10, 1ui64);
      v16 = v15;
    }
    Scaleform::Render::TreeContainer::Remove(v14, v16, 1ui64);
    Scaleform::Render::TreeContainer::Insert(pParent, v10, v13);
    v17 = v8;
    v18 = v15;
    v19 = v14;
    goto LABEL_15;
  }
  return 0;
}

// File Line: 1156
// RVA: 0x915430
char __fastcall Scaleform::GFx::DisplayList::UnloadDisplayObjectAtIndex(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        unsigned __int64 index)
{
  unsigned __int64 v5; // r14
  Scaleform::GFx::DisplayList::DisplayEntry *v6; // r12
  Scaleform::GFx::DisplayObjectBase *pCharacter; // rdi
  char v9; // r15
  Scaleform::GFx::DisplayObjectBase *v10; // rdx
  Scaleform::GFx::DisplayObjectBase *v11; // rdi
  int v12; // r14d
  __int64 DisplayIndex; // rax
  char Flags; // al
  Scaleform::GFx::DisplayObjectBase *v15; // rcx
  char v16; // al
  Scaleform::GFx::DisplayList::DisplayEntry val; // [rsp+28h] [rbp-30h] BYREF

  v5 = index;
  v6 = &this->DisplayObjectArray.Data.Data[index];
  Scaleform::GFx::DisplayList::RemoveFromRenderTree(this, owner, index);
  pCharacter = v6->pCharacter;
  if ( (v6->pCharacter->Flags & 0x40) != 0 )
    return 0;
  if ( pCharacter )
  {
    if ( (pCharacter->Flags & 0x1000) != 0 || pCharacter->Depth < -1 )
      return 0;
    v9 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[74].__vecDelDtor)(v6->pCharacter);
    pCharacter->Flags |= 0x1000u;
    if ( v9 )
    {
      ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[75].__vecDelDtor)(pCharacter);
      v10 = this->DisplayObjectArray.Data.Data[v5].pCharacter;
      if ( v10 )
        v10->pParent = 0i64;
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
        &this->DisplayObjectArray,
        index);
    }
    else
    {
      v11 = v6->pCharacter;
      if ( v6->pCharacter->Depth >= 0 )
      {
        v12 = -1 - v11->Depth;
        val.pCharacter = v6->pCharacter;
        if ( v11 )
          ++v11->RefCount;
        val.TreeIndex = v6->TreeIndex;
        val.MaskTreeIndex = v6->MaskTreeIndex;
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          &this->DisplayObjectArray,
          index);
        v11->Depth = v12;
        DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex(this, v12);
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
          &this->DisplayObjectArray,
          DisplayIndex,
          &val);
        Scaleform::RefCountNTSImpl::Release(v11);
      }
    }
    this->pCachedChar = 0i64;
    Flags = this->Flags;
    if ( (Flags & 2) != 0 )
      this->Flags = Flags | 1;
    return v9;
  }
  else
  {
    v15 = this->DisplayObjectArray.Data.Data[v5].pCharacter;
    if ( v15 )
      v15->pParent = 0i64;
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
      &this->DisplayObjectArray,
      index);
    this->pCachedChar = 0i64;
    v16 = this->Flags;
    if ( (v16 & 2) != 0 )
      this->Flags = v16 | 1;
    return 1;
  }
}

// File Line: 1230
// RVA: 0x8F3E10
void __fastcall Scaleform::GFx::DisplayList::PropagateMouseEvent(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::EventId *id)
{
  signed __int64 i; // rbx
  char *pCharacter; // rdi

  for ( i = this->DisplayObjectArray.Data.Size - 1; i >= 0; --i )
  {
    pCharacter = (char *)this->DisplayObjectArray.Data.Data[i].pCharacter;
    if ( (*(unsigned __int8 (__fastcall **)(char *))(*(_QWORD *)pCharacter + 472i64))(pCharacter) )
    {
      if ( pCharacter[106] < 0 )
        (*(void (__fastcall **)(char *, Scaleform::GFx::EventId *))(*(_QWORD *)pCharacter + 792i64))(pCharacter, id);
      if ( i >= (signed __int64)this->DisplayObjectArray.Data.Size )
        i = this->DisplayObjectArray.Data.Size;
    }
  }
}

// File Line: 1256
// RVA: 0x8F3CA0
void __fastcall Scaleform::GFx::DisplayList::PropagateKeyEvent(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::EventId *id,
        int *pkeyMask)
{
  unsigned __int64 v6; // rdi
  __int64 v7; // rsi
  Scaleform::GFx::DisplayObjectBase *pCharacter; // rbx

  v6 = 0i64;
  if ( this->DisplayObjectArray.Data.Size )
  {
    v7 = 0i64;
    do
    {
      pCharacter = this->DisplayObjectArray.Data.Data[v7].pCharacter;
      if ( pCharacter )
        ++pCharacter->RefCount;
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(pCharacter) )
      {
        if ( SLOBYTE(pCharacter->Flags) < 0 )
          ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::GFx::EventId *, int *))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[101].__vecDelDtor)(
            pCharacter,
            id,
            pkeyMask);
      }
      Scaleform::RefCountNTSImpl::Release(pCharacter);
      ++v6;
      ++v7;
    }
    while ( v6 < this->DisplayObjectArray.Data.Size );
  }
}

// File Line: 1283
// RVA: 0x919B10
void __fastcall Scaleform::GFx::DisplayList::VisitMembers(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayList::MemberVisitor *pvisitor)
{
  unsigned __int64 Size; // rsi
  __int64 v5; // rbx
  Scaleform::GFx::DisplayObjectBase *pCharacter; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp+8h] BYREF

  Size = this->DisplayObjectArray.Data.Size;
  if ( Size )
  {
    v5 = 0i64;
    do
    {
      pCharacter = this->DisplayObjectArray.Data.Data[v5].pCharacter;
      if ( SLOBYTE(pCharacter->Flags) < 0 )
      {
        Scaleform::GFx::DisplayObject::GetName(
          (Scaleform::GFx::DisplayObject *)this->DisplayObjectArray.Data.Data[v5].pCharacter,
          &result);
        if ( result.pNode->Size )
          pvisitor->vfptr->Visit(pvisitor, &result, (Scaleform::GFx::InteractiveObject *)pCharacter);
        pNode = result.pNode;
        if ( result.pNode->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      }
      ++v5;
      --Size;
    }
    while ( Size );
  }
}

// File Line: 1305
// RVA: 0x8D4F80
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::DisplayList::GetBounds(
        Scaleform::GFx::DisplayList *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *transform)
{
  unsigned __int64 Size; // r14
  __int64 v4; // rdi
  Scaleform::GFx::DisplayObjectBase *pCharacter; // rsi
  float v9; // xmm1_4
  Scaleform::GFx::DisplayObjectBase *v10; // rcx
  float v11; // xmm0_4
  float *v12; // rax
  float v13; // xmm4_4
  float v14; // xmm3_4
  float v15; // xmm5_4
  float v16; // xmm6_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float *v19; // rax
  float x1; // xmm7_4
  float v21; // xmm9_4
  float y1; // xmm6_4
  float v23; // xmm8_4
  float x2; // xmm1_4
  float y2; // xmm0_4
  char v27[16]; // [rsp+8h] [rbp-29h] BYREF
  __int128 v28; // [rsp+18h] [rbp-19h] BYREF
  __m128 i; // [rsp+28h] [rbp-9h]

  Size = this->DisplayObjectArray.Data.Size;
  v4 = 0i64;
  *(_QWORD *)&result->x1 = 0i64;
  *(_QWORD *)&result->x2 = 0i64;
  v28 = _xmm;
  for ( i = _xmm; Size; --Size )
  {
    pCharacter = this->DisplayObjectArray.Data.Data[v4].pCharacter;
    if ( pCharacter )
    {
      v9 = transform->M[0][1];
      v10 = this->DisplayObjectArray.Data.Data[v4].pCharacter;
      *(float *)&v28 = transform->M[0][0];
      *(_QWORD *)((char *)&v28 + 4) = __PAIR64__(LODWORD(transform->M[0][2]), LODWORD(v9));
      v11 = transform->M[1][0];
      HIDWORD(v28) = LODWORD(transform->M[0][3]);
      i.m128_u64[0] = __PAIR64__(LODWORD(transform->M[1][1]), LODWORD(v11));
      i.m128_u64[1] = *(_QWORD *)&transform->M[1][2];
      v12 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(v10);
      v13 = *(float *)&v28;
      v14 = *((float *)&v28 + 1);
      v15 = i.m128_f32[0];
      v16 = i.m128_f32[1];
      *(float *)&v28 = (float)(*(float *)&v28 * *v12) + (float)(*((float *)&v28 + 1) * v12[4]);
      i.m128_f32[0] = (float)(i.m128_f32[0] * *v12) + (float)(i.m128_f32[1] * v12[4]);
      *((float *)&v28 + 1) = (float)(v13 * v12[1]) + (float)(*((float *)&v28 + 1) * v12[5]);
      v17 = v15 * v12[1];
      v18 = i.m128_f32[1] * v12[5];
      DWORD2(v28) = 0;
      *(unsigned __int64 *)((char *)i.m128_u64 + 4) = COERCE_UNSIGNED_INT(v18 + v17);
      *((float *)&v28 + 3) = *((float *)&v28 + 3) + (float)((float)(v13 * v12[3]) + (float)(v14 * v12[7]));
      i.m128_f32[3] = i.m128_f32[3] + (float)((float)(v16 * v12[7]) + (float)(v15 * v12[3]));
      v19 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, char *, __int128 *))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[61].__vecDelDtor)(
                       pCharacter,
                       v27,
                       &v28);
      x1 = *v19;
      v21 = v19[2];
      y1 = v19[1];
      v23 = v19[3];
      if ( *v19 < v21 && y1 < v23 )
      {
        if ( Scaleform::Render::Rect<float>::IsEmpty(result) )
        {
          result->x2 = v21;
          result->y2 = v23;
        }
        else
        {
          if ( result->x1 <= x1 )
            x1 = result->x1;
          x2 = result->x2;
          if ( x2 <= v21 )
            x2 = v21;
          if ( result->y1 <= y1 )
            y1 = result->y1;
          y2 = result->y2;
          if ( y2 <= v23 )
            y2 = v23;
          result->x2 = x2;
          result->y2 = y2;
        }
        result->y1 = y1;
        result->x1 = x1;
      }
    }
    ++v4;
  }
  return result;
}

// File Line: 1341
// RVA: 0x8DD1F0
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::DisplayList::GetRectBounds(
        Scaleform::GFx::DisplayList *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *transform)
{
  unsigned __int64 Size; // r14
  __int64 v4; // rdi
  Scaleform::GFx::DisplayObjectBase *pCharacter; // rsi
  float v9; // xmm1_4
  Scaleform::GFx::DisplayObjectBase *v10; // rcx
  float v11; // xmm0_4
  float *v12; // rax
  float v13; // xmm4_4
  float v14; // xmm3_4
  float v15; // xmm5_4
  float v16; // xmm6_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float *v19; // rax
  float x1; // xmm7_4
  float v21; // xmm9_4
  float y1; // xmm6_4
  float v23; // xmm8_4
  float x2; // xmm1_4
  float y2; // xmm0_4
  char v27[16]; // [rsp+8h] [rbp-29h] BYREF
  __int128 v28; // [rsp+18h] [rbp-19h] BYREF
  __m128 i; // [rsp+28h] [rbp-9h]

  Size = this->DisplayObjectArray.Data.Size;
  v4 = 0i64;
  *(_QWORD *)&result->x1 = 0i64;
  *(_QWORD *)&result->x2 = 0i64;
  v28 = _xmm;
  for ( i = _xmm; Size; --Size )
  {
    pCharacter = this->DisplayObjectArray.Data.Data[v4].pCharacter;
    if ( pCharacter )
    {
      v9 = transform->M[0][1];
      v10 = this->DisplayObjectArray.Data.Data[v4].pCharacter;
      *(float *)&v28 = transform->M[0][0];
      *(_QWORD *)((char *)&v28 + 4) = __PAIR64__(LODWORD(transform->M[0][2]), LODWORD(v9));
      v11 = transform->M[1][0];
      HIDWORD(v28) = LODWORD(transform->M[0][3]);
      i.m128_u64[0] = __PAIR64__(LODWORD(transform->M[1][1]), LODWORD(v11));
      i.m128_u64[1] = *(_QWORD *)&transform->M[1][2];
      v12 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(v10);
      v13 = *(float *)&v28;
      v14 = *((float *)&v28 + 1);
      v15 = i.m128_f32[0];
      v16 = i.m128_f32[1];
      *(float *)&v28 = (float)(*(float *)&v28 * *v12) + (float)(*((float *)&v28 + 1) * v12[4]);
      i.m128_f32[0] = (float)(i.m128_f32[0] * *v12) + (float)(i.m128_f32[1] * v12[4]);
      *((float *)&v28 + 1) = (float)(v13 * v12[1]) + (float)(*((float *)&v28 + 1) * v12[5]);
      v17 = v15 * v12[1];
      v18 = i.m128_f32[1] * v12[5];
      DWORD2(v28) = 0;
      *(unsigned __int64 *)((char *)i.m128_u64 + 4) = COERCE_UNSIGNED_INT(v18 + v17);
      *((float *)&v28 + 3) = *((float *)&v28 + 3) + (float)((float)(v13 * v12[3]) + (float)(v14 * v12[7]));
      i.m128_f32[3] = i.m128_f32[3] + (float)((float)(v16 * v12[7]) + (float)(v15 * v12[3]));
      v19 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, char *, __int128 *))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[62].__vecDelDtor)(
                       pCharacter,
                       v27,
                       &v28);
      x1 = *v19;
      v21 = v19[2];
      y1 = v19[1];
      v23 = v19[3];
      if ( *v19 < v21 && y1 < v23 )
      {
        if ( Scaleform::Render::Rect<float>::IsEmpty(result) )
        {
          result->x2 = v21;
          result->y2 = v23;
        }
        else
        {
          if ( result->x1 <= x1 )
            x1 = result->x1;
          x2 = result->x2;
          if ( x2 <= v21 )
            x2 = v21;
          if ( result->y1 <= y1 )
            y1 = result->y1;
          y2 = result->y2;
          if ( y2 <= v23 )
            y2 = v23;
          result->x2 = x2;
          result->y2 = y2;
        }
        result->y1 = y1;
        result->x1 = x1;
      }
    }
    ++v4;
  }
  return result;
}

// File Line: 1372
// RVA: 0x8CB780
__int64 __fastcall Scaleform::GFx::DisplayList::FindDisplayIndex(Scaleform::GFx::DisplayList *this, int depth)
{
  __int64 v4; // rbx
  __int64 v5; // rbp
  unsigned __int64 v6; // r12
  Scaleform::GFx::DisplayList::DepthToIndexContainer *v7; // rax
  unsigned __int64 v8; // rsi
  unsigned __int64 Size; // r13
  __int64 v10; // r15
  Scaleform::GFx::DisplayList::DisplayEntry *Data; // rcx
  int v12; // r8d
  unsigned __int64 v13; // rdx
  Scaleform::GFx::DisplayList::DepthToIndexContainer *DepthToIndexMap; // rcx
  __int64 v16; // rcx
  Scaleform::GFx::DisplayList::DepthToIndexContainer *v17; // r8
  __int64 v18; // rdx
  __int64 v19; // rax
  unsigned __int64 v20; // rdx
  Scaleform::GFx::DisplayList::DisplayEntry *i; // rcx
  int v22; // [rsp+90h] [rbp+18h] BYREF
  Scaleform::GFx::DisplayList::DepthToIndexContainer *v23; // [rsp+98h] [rbp+20h]

  v4 = 0i64;
  if ( (this->Flags & 1) == 0 )
    goto LABEL_22;
  v5 = -1i64;
  if ( this->DisplayObjectArray.Data.Size <= 0xA )
  {
    DepthToIndexMap = this->DepthToIndexMap;
    if ( !DepthToIndexMap )
      goto LABEL_20;
    v13 = 0i64;
  }
  else
  {
    v6 = 0i64;
    if ( !this->DepthToIndexMap )
    {
      v22 = 322;
      v7 = (Scaleform::GFx::DisplayList::DepthToIndexContainer *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::DisplayList *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                                   Scaleform::Memory::pGlobalHeap,
                                                                   this,
                                                                   24i64,
                                                                   &v22,
                                                                   -2i64);
      v23 = v7;
      if ( v7 )
      {
        v7->Array.Data.Data = 0i64;
        v7->Array.Data.Size = 0i64;
        v7->Array.Data.Policy.Capacity = 0i64;
      }
      else
      {
        v7 = 0i64;
      }
      this->DepthToIndexMap = v7;
    }
    v8 = 0i64;
    Size = this->DisplayObjectArray.Data.Size;
    if ( Size )
    {
      v10 = 0i64;
      do
      {
        Data = this->DisplayObjectArray.Data.Data;
        if ( v5 == -1 && Data[v10].pCharacter->Depth >= depth )
          v5 = v8;
        v12 = Data[v10].pCharacter->Depth;
        if ( v12 != -1 )
          Scaleform::GFx::DisplayList::DepthToIndexContainer::SetElement(this->DepthToIndexMap, v6++, v12, v8);
        ++v8;
        ++v10;
      }
      while ( v8 < Size );
    }
    v13 = v6;
    DepthToIndexMap = this->DepthToIndexMap;
  }
  Scaleform::ArrayData<Scaleform::GFx::DisplayList::DepthToIndexMapElem,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DepthToIndexMapElem,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &DepthToIndexMap->Array.Data,
    v13);
LABEL_20:
  this->Flags &= ~1u;
  if ( v5 != -1 )
    return v5;
LABEL_22:
  if ( (this->Flags & 2) == 0 )
  {
    v16 = this->DisplayObjectArray.Data.Size;
    while ( v16 > 0 )
    {
      if ( this->DisplayObjectArray.Data.Data[(v16 >> 1) + v4].pCharacter->Depth >= depth )
      {
        v16 >>= 1;
      }
      else
      {
        v4 += (v16 >> 1) + 1;
        v16 += -1 - (v16 >> 1);
      }
    }
    return v4;
  }
  v17 = this->DepthToIndexMap;
  if ( v17 && this->DisplayObjectArray.Data.Size > 0xA )
  {
    v18 = v17->Array.Data.Size;
    while ( v18 > 0 )
    {
      v19 = (v18 >> 1) + v4;
      if ( v17->Array.Data.Data[v19].Depth >= depth )
      {
        v18 >>= 1;
      }
      else
      {
        v4 = v19 + 1;
        v18 += -1 - (v18 >> 1);
      }
    }
    if ( v4 == v17->Array.Data.Size )
      return this->DisplayObjectArray.Data.Size;
    return v17->Array.Data.Data[v4].Index;
  }
  else
  {
    v20 = this->DisplayObjectArray.Data.Size;
    if ( v20 )
    {
      for ( i = this->DisplayObjectArray.Data.Data; i->pCharacter->Depth < depth; ++i )
      {
        if ( ++v4 >= v20 )
          return v20;
      }
      return v4;
    }
  }
  return v20;
}->Depth < depth; ++i )
      {
        if ( +

