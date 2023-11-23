// File Line: 64
// RVA: 0x1596A00
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc5_Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher_0_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::ASString_const_____ptr64_Scaleform::GFx::AS3::Value_const_____ptr64_bool_long_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243CB20 = v1;
  Scaleform::GFx::AS3::ThunkFunc5<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher,0,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Value const &,bool,long,bool>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Value *, bool, int, bool))Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::addEventListener;
  return result;
}

// File Line: 65
// RVA: 0x15905E0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher_1_bool_Scaleform::GFx::AS3::Instances::fl_events::Event_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243CB30 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher,1,bool,Scaleform::GFx::AS3::Instances::fl_events::Event *>::Method = Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::dispatchEvent;
  return result;
}

// File Line: 66
// RVA: 0x1590610
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher_2_bool_Scaleform::GFx::ASString_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243CB40 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher,2,bool,Scaleform::GFx::ASString const &>::Method = Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::hasEventListener;
  return result;
}

// File Line: 67
// RVA: 0x1596370
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc3_Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher_3_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::ASString_const_____ptr64_Scaleform::GFx::AS3::Value_const_____ptr64_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243CB50 = v1;
  Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher,3,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Value const &,bool>::Method = Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::removeEventListener;
  return result;
}

// File Line: 68
// RVA: 0x1590640
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher_4_bool_Scaleform::GFx::ASString_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243CB60 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher,4,bool,Scaleform::GFx::ASString const &>::Method = Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::willTrigger;
  return result;
}

// File Line: 78
// RVA: 0x77CE50
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcher(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instance::Instance(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::`vftable;
  this->VMRef = t->pVM;
  this->pImpl.pObject = 0i64;
  this->pImpl.Owner = 1;
}

// File Line: 84
// RVA: 0x82B150
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::addEventListener(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::WeakProxy *type,
        Scaleform::GFx::AS3::Value *listener,
        bool useCapture,
        int priority,
        bool useWeakReference)
{
  Scaleform::AutoPtr<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl> *p_pImpl; // r14
  __int64 v10; // rax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *v11; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *pObject; // rdi
  Scaleform::GFx::ASStringNode *v13; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v14; // rsi
  __int64 v15; // rax
  unsigned __int64 *v16; // r12
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> **v17; // r12
  unsigned __int64 v18; // rsi
  bool v19; // zf
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> *v20; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> *v22; // r12
  unsigned __int64 Size; // r15
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *Data; // rdi
  Scaleform::GFx::AS3::Value *p_mFunction; // rbx
  unsigned __int64 v26; // rdi
  Scaleform::GFx::AS3::Value *v27; // rbx
  Scaleform::GFx::AS3::VM *pVM; // r8
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // rcx
  Scaleform::GFx::ASStringNode *v30; // rbx
  int v31; // edx
  Scaleform::GFx::AS3::Traits *v32; // rcx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *v33; // rax
  unsigned int Flags; // edi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // r12
  unsigned int v36; // r14d
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx
  unsigned __int64 v38; // r13
  __int64 v39; // rdx
  __int64 v40; // r15
  Scaleform::GFx::AS3::WeakProxy *pV; // r15
  Scaleform::GFx::AS3::GASRefCountBase *v42; // r8
  unsigned __int64 v43; // rsi
  unsigned __int64 v44; // rcx
  Scaleform::GFx::AS3::Value::V1U v45; // rdx
  Scaleform::MemoryHeap *v46; // r8
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *v47; // rdi
  unsigned int v48; // ecx
  int v49; // ecx
  Scaleform::GFx::AS3::GASRefCountBase *v50; // rcx
  Scaleform::GFx::ASString key; // [rsp+20h] [rbp-60h] BYREF
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> *v52; // [rsp+28h] [rbp-58h] BYREF
  Scaleform::MemoryHeap *MHeap; // [rsp+30h] [rbp-50h]
  Scaleform::GFx::AS3::Value::V1U v54; // [rsp+38h] [rbp-48h]
  Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeRef v55; // [rsp+40h] [rbp-40h] BYREF
  int v56; // [rsp+50h] [rbp-30h]
  Scaleform::GFx::AS3::Value v57; // [rsp+58h] [rbp-28h] BYREF
  __int64 v58; // [rsp+78h] [rbp-8h]
  Scaleform::Pickable<Scaleform::GFx::AS3::WeakProxy> resulta; // [rsp+D0h] [rbp+50h] BYREF

  resulta.pV = type;
  v58 = -2i64;
  p_pImpl = &this->pImpl;
  if ( !this->pImpl.pObject )
  {
    MHeap = this->pTraits.pObject->pVM->MHeap;
    v10 = (__int64)MHeap->vfptr->Alloc((Scaleform::MemoryHeap *)this, 24ui64, 0i64);
    v11 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *)v10;
    v54.VStr = (Scaleform::GFx::ASStringNode *)v10;
    if ( v10 )
    {
      *(_QWORD *)v10 = 0i64;
      v55.pFirst = (Scaleform::GFx::ASString *)(v10 + 8);
      key.pNode = (Scaleform::GFx::ASStringNode *)(v10 + 8);
      *(_QWORD *)(v10 + 8) = 0i64;
      *(_DWORD *)(v10 + 16) = 0;
    }
    else
    {
      v11 = 0i64;
    }
    Scaleform::AutoPtr<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl>::operator=(
      p_pImpl,
      v11);
    type = resulta.pV;
  }
  pObject = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)p_pImpl->pObject;
  if ( !useCapture )
    ++pObject;
  v13 = *(Scaleform::GFx::ASStringNode **)&type->RefCount;
  key.pNode = v13;
  ++v13->RefCount;
  v14.pTable = pObject->pTable;
  if ( pObject->pTable
    && (v15 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                pObject,
                &key,
                v13->HashFlags & v14.pTable->SizeMask),
        v15 >= 0)
    && (v16 = &v14.pTable[1].SizeMask + 3 * v15) != 0i64 )
  {
    v17 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> **)(v16 + 1);
    v18 = 0i64;
  }
  else
  {
    v18 = 0i64;
    v17 = 0i64;
  }
  v19 = v13->RefCount-- == 1;
  if ( v19 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  if ( v17 )
  {
    v22 = *v17;
    v52 = v22;
  }
  else
  {
    v55.pFirst = (Scaleform::GFx::ASString *)this->pTraits.pObject->pVM->MHeap;
    v20 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *, __int64, _QWORD))v55.pFirst->pNode[2].pData)(this, 24i64, 0i64);
    MHeap = (Scaleform::MemoryHeap *)v20;
    if ( v20 )
    {
      v54.VStr = (Scaleform::GFx::ASStringNode *)v20;
      v20->Data = 0i64;
      v20->Size = 0i64;
      v20->Policy.Capacity = 0i64;
    }
    else
    {
      v20 = 0i64;
    }
    v52 = v20;
    key.pNode = *(Scaleform::GFx::ASStringNode **)&resulta.pV->RefCount;
    ++key.pNode->RefCount;
    v55.pFirst = &key;
    v55.pSecond = (Scaleform::GFx::MovieImpl::StickyVarNode *const *)&v52;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      pObject,
      pObject,
      &v55,
      key.pNode->HashFlags);
    pNode = key.pNode;
    v19 = key.pNode->RefCount-- == 1;
    if ( v19 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v22 = v52;
  }
  Size = v22->Size;
  if ( !Size )
  {
LABEL_30:
    v26 = v18;
    if ( v18 < Size )
    {
      v27 = (Scaleform::GFx::AS3::Value *)((char *)&v22->Data->mFunction + 32 * v18 + 8 * v18);
      while ( (v27->Flags & 0x200) != 0 && !v27->Bonus.pWeakProxy->pObject
           || !Scaleform::GFx::AS3::StrictEqual(v27, listener) )
      {
        ++v26;
        v27 = (Scaleform::GFx::AS3::Value *)((char *)v27 + 40);
        if ( v26 >= Size )
          goto LABEL_36;
      }
      return;
    }
LABEL_36:
    pVM = this->pTraits.pObject->pVM;
    StringManagerRef = pVM->StringManagerRef;
    v30 = *(Scaleform::GFx::ASStringNode **)&resulta.pV->RefCount;
    key.pNode = v30;
    ++v30->RefCount;
    if ( v30 == StringManagerRef->Builtins[34].pNode )
    {
      v31 = 2;
      *((_DWORD *)pVM[1].vfptr[2].__vecDelDtor + 5300) |= 0x80000u;
      p_pImpl->pObject->Flags |= 1u;
    }
    else if ( v30 == StringManagerRef->Builtins[35].pNode )
    {
      v31 = 16777237;
      p_pImpl->pObject->Flags |= 0x20u;
    }
    else if ( v30 == StringManagerRef->Builtins[36].pNode )
    {
      v31 = 16777238;
      p_pImpl->pObject->Flags |= 0x40u;
    }
    else if ( v30 == StringManagerRef->Builtins[28].pNode )
    {
      v31 = 16777233;
      p_pImpl->pObject->Flags |= 2u;
    }
    else if ( v30 == StringManagerRef->Builtins[33].pNode )
    {
      v31 = 16777234;
      p_pImpl->pObject->Flags |= 4u;
    }
    else if ( v30 == StringManagerRef->Builtins[44].pNode )
    {
      v31 = 16777235;
      p_pImpl->pObject->Flags |= 8u;
    }
    else
    {
      if ( v30 != StringManagerRef->Builtins[45].pNode )
      {
        if ( StringManagerRef->Builtins[49].pNode == v30
          || StringManagerRef->Builtins[53].pNode == v30
          || StringManagerRef->Builtins[47].pNode == v30
          || StringManagerRef->Builtins[48].pNode == v30
          || StringManagerRef->Builtins[52].pNode == v30
          || StringManagerRef->Builtins[51].pNode == v30
          || StringManagerRef->Builtins[56].pNode == v30
          || StringManagerRef->Builtins[55].pNode == v30 )
        {
          v33 = p_pImpl->pObject;
          if ( useCapture )
          {
            if ( v33->CaptureButtonHandlersCnt != -1 )
              ++v33->CaptureButtonHandlersCnt;
          }
          else if ( v33->ButtonHandlersCnt != -1 )
          {
            ++v33->ButtonHandlersCnt;
          }
        }
LABEL_67:
        v56 = priority;
        Flags = listener->Flags;
        v57.Flags = Flags;
        pWeakProxy = listener->Bonus.pWeakProxy;
        v57.Bonus.pWeakProxy = pWeakProxy;
        v54 = listener->value.VS._1;
        v57.value.VS._1 = v54;
        MHeap = (Scaleform::MemoryHeap *)listener->value.VS._2.VObj;
        v57.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)MHeap;
        v36 = Flags & 0x1F;
        if ( v36 <= 9 )
          goto LABEL_79;
        if ( (Flags & 0x200) != 0 )
        {
          ++pWeakProxy->RefCount;
          goto LABEL_79;
        }
        if ( v36 == 10 )
        {
          ++listener->value.VS._1.VStr->RefCount;
        }
        else
        {
          if ( (Flags & 0x1F) <= 0xA )
            goto LABEL_79;
          if ( (Flags & 0x1F) <= 0xF )
          {
            VObj = listener->value.VS._1;
          }
          else
          {
            if ( (Flags & 0x1F) > 0x11 )
              goto LABEL_79;
            VObj = (Scaleform::GFx::AS3::Value::V1U)listener->value.VS._2.VObj;
          }
          if ( VObj.VStr )
            VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
        }
LABEL_79:
        resulta.pV = (Scaleform::GFx::AS3::WeakProxy *)v52;
        v38 = v52->Size;
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          v52,
          v52,
          v38 + 1);
        if ( v38 + 1 > v38 )
        {
          v39 = *(_QWORD *)&resulta.pV->RefCount + 40 * v38;
          v40 = 1i64;
          do
          {
            v55.pFirst = (Scaleform::GFx::ASString *)v39;
            if ( v39 )
            {
              *(_DWORD *)v39 = 0;
              *(_DWORD *)(v39 + 8) = 0;
              *(_QWORD *)(v39 + 16) = 0i64;
            }
            v39 += 40i64;
            --v40;
          }
          while ( v40 );
          v30 = key.pNode;
        }
        pV = resulta.pV;
        v42 = resulta.pV->pObject;
        if ( v18 < (unsigned __int64)&v42[-1].RefCount + 7 )
          memmove(
            (void *)(*(_QWORD *)&resulta.pV->RefCount + 40 * v18 + 40),
            (const void *)(*(_QWORD *)&resulta.pV->RefCount + 40 * v18),
            40i64 * (_QWORD)((char *)v42 - v18 - 1));
        v43 = 40 * v18;
        v19 = v43 + *(_QWORD *)&pV->RefCount == 0;
        v44 = v43 + *(_QWORD *)&pV->RefCount;
        resulta.pV = (Scaleform::GFx::AS3::WeakProxy *)v44;
        if ( !v19 )
        {
          *(_DWORD *)v44 = priority;
          *(_DWORD *)(v44 + 8) = Flags;
          *(_QWORD *)(v44 + 16) = pWeakProxy;
          v45 = v54;
          *(Scaleform::GFx::AS3::Value::V1U *)(v44 + 24) = v54;
          v46 = MHeap;
          *(_QWORD *)(v44 + 32) = MHeap;
          if ( (Flags & 0x1F) > 9 )
          {
            if ( (Flags & 0x200) != 0 )
            {
              ++pWeakProxy->RefCount;
            }
            else if ( v36 == 10 )
            {
              ++v45.VStr->RefCount;
            }
            else if ( (Flags & 0x1F) <= 0xF )
            {
              if ( v45.VStr )
                v45.VStr->Size = (v45.VStr->Size + 1) & 0x8FBFFFFF;
            }
            else if ( (Flags & 0x1F) <= 0x11 && v46 )
            {
              v46->RefCount = (v46->RefCount + 1) & 0x8FBFFFFF;
            }
          }
        }
        if ( (Flags & 0x1F) > 9 )
        {
          if ( (Flags & 0x200) != 0 )
          {
            v19 = pWeakProxy->RefCount-- == 1;
            if ( v19 )
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
            memset(&v57.Bonus, 0, 24);
            v57.Flags = Flags & 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v57);
          }
        }
        if ( !useWeakReference )
          goto LABEL_114;
        v47 = &v52->Data[v43 / 0x28];
        v48 = v47->mFunction.Flags;
        if ( (v48 & 0x200) != 0 )
          goto LABEL_114;
        v49 = v48 & 0x1F;
        if ( v49 <= 10 )
          goto LABEL_114;
        if ( v49 < 16 )
        {
          v50 = v47->mFunction.value.VS._1.VObj;
        }
        else
        {
          if ( v49 > 17 )
          {
LABEL_114:
            v19 = v30->RefCount-- == 1;
            if ( v19 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v30);
            return;
          }
          v50 = v47->mFunction.value.VS._2.VObj;
        }
        if ( v50 )
        {
          v47->mFunction.Bonus.pWeakProxy = Scaleform::GFx::AS3::GASRefCountBase::CreateWeakProxy(v50, &resulta)->pV;
          v47->mFunction.Flags |= 0x200u;
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v47->mFunction);
        }
        goto LABEL_114;
      }
      v31 = 16777236;
      p_pImpl->pObject->Flags |= 0x10u;
    }
    if ( !v52->Size )
    {
      v32 = this->pTraits.pObject;
      if ( (unsigned int)(v32->TraitsType - 22) <= 0xC && (v32->Flags & 0x20) == 0 )
        Scaleform::GFx::AS3::EventChains::AddToChain(
          (Scaleform::GFx::AS3::EventChains *)&pVM[1].vfptr[43],
          v31,
          (Scaleform::GFx::DisplayObject *)this[1]._pRCC);
    }
    goto LABEL_67;
  }
  Data = v22->Data;
  p_mFunction = &v22->Data->mFunction;
  while ( (p_mFunction->Flags & 0x200) != 0 && !p_mFunction->Bonus.pWeakProxy->pObject
       || !Scaleform::GFx::AS3::StrictEqual(p_mFunction, listener) )
  {
    if ( priority <= (signed int)Data->Priority )
    {
      ++v18;
      ++Data;
      p_mFunction = (Scaleform::GFx::AS3::Value *)((char *)p_mFunction + 40);
      if ( v18 < Size )
        continue;
    }
    goto LABEL_30;
  }
}

// File Line: 233
// RVA: 0x834A80
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::dispatchEvent(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        bool *result,
        Scaleform::GFx::AS3::Instances::fl_events::Event *event)
{
  bool *v4; // rdi
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v8; // zf
  Scaleform::GFx::AS3::Instances::fl_events::Event *VStr; // rbx
  char v10; // si
  Scaleform::GFx::AS3::Value::V1U *ConstString; // rax
  char v12; // r15
  Scaleform::GFx::AS3::Value::V1U v13; // rdi
  Scaleform::GFx::ASStringNode *VObj; // rdx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v15; // r8
  int v16; // r12d
  const char *pData; // rax
  Scaleform::GFx::ASString *v18; // rax
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::AS3::Traits *v22; // rcx
  Scaleform::GFx::AS3::Value::V1U v23; // rax
  __int64 *v24; // rax
  Scaleform::GFx::ASStringNode *v25; // rcx
  unsigned int Size; // eax
  Scaleform::GFx::AS3::Value::V1U *v27; // rax
  Scaleform::GFx::AS3::Value::V1U v28; // rcx
  Scaleform::GFx::ASStringNode *v29; // rcx
  Scaleform::GFx::AS3::VM::Error *v30; // rax
  Scaleform::GFx::ASStringNode *v31; // rcx
  Scaleform::GFx::AS3::Traits *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Value v34; // [rsp+40h] [rbp-C0h] BYREF
  Scaleform::GFx::AS3::Value v; // [rsp+60h] [rbp-A0h] BYREF
  Scaleform::GFx::AS3::Value func; // [rsp+80h] [rbp-80h] BYREF
  Scaleform::GFx::AS3::Value _this; // [rsp+A0h] [rbp-60h] BYREF
  Scaleform::GFx::AS3::VM::Error v38; // [rsp+C0h] [rbp-40h] BYREF
  Scaleform::GFx::AS3::Multiname v39; // [rsp+D0h] [rbp-30h] BYREF
  Scaleform::GFx::ASString v40; // [rsp+100h] [rbp+0h] BYREF
  __int64 v41; // [rsp+108h] [rbp+8h]
  Scaleform::GFx::ASString resulta; // [rsp+160h] [rbp+60h] BYREF
  Scaleform::GFx::AS3::Instances::fl_events::Event *v44; // [rsp+168h] [rbp+68h] BYREF

  v41 = -2i64;
  v4 = result;
  if ( !event )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v38, 1009, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this->pTraits.pObject->pVM, v6, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v38.Message.pNode;
    v8 = v38.Message.pNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return;
  }
  VStr = 0i64;
  v44 = 0i64;
  v10 = 10;
  if ( !Scaleform::GFx::AS3::Instances::fl_events::Event::NeedsCloning(event) )
  {
    event->RefCount = (event->RefCount + 1) & 0x8FBFFFFF;
    VStr = event;
    v44 = event;
LABEL_89:
    if ( VStr )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&VStr->Target,
        (Scaleform::GFx::AS3::Instances::fl::XMLList *)this);
      pObject = this->pTraits.pObject;
      if ( (unsigned int)(pObject->TraitsType - 22) > 0xC || (pObject->Flags & 0x20) != 0 )
      {
        *((_BYTE *)VStr + 84) |= 0x20u;
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(this, VStr, 0);
      }
      else
      {
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(
          this,
          VStr,
          (Scaleform::GFx::DisplayObject *)this[1]._pRCC);
      }
      *v4 = (*((_BYTE *)VStr + 84) & 4) == 0;
    }
    else
    {
      v27 = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                                                 this->pTraits.pObject->pVM->StringManagerRef,
                                                 &resulta,
                                                 "event");
      v34.Flags = 10;
      v34.Bonus.pWeakProxy = 0i64;
      v28 = *v27;
      v34.value.VS._1 = v28;
      if ( v28.VStr == &v28.VStr->pManager->NullStringNode )
      {
        v34.value.VS._1.VStr = 0i64;
        v34.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v38.Message.pNode;
        v10 = 12;
        v34.Flags = 12;
      }
      else
      {
        ++v28.VStr->RefCount;
      }
      v29 = resulta.pNode;
      v8 = resulta.pNode->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v29);
      Scaleform::GFx::AS3::VM::Error::Error(&v38, 2007, this->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this->pTraits.pObject->pVM,
        v30,
        &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v31 = v38.Message.pNode;
      v8 = v38.Message.pNode->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v31);
      if ( (v10 & 0x1Fu) > 9 )
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v34);
    }
    goto LABEL_104;
  }
  if ( (event->pTraits.pObject->Flags & 0x10) == 0 )
  {
    v24 = (__int64 *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl_events::Event *, Scaleform::GFx::ASString *))event->vfptr[7].~RefCountBaseGC<328>)(
                       event,
                       &resulta);
    if ( v24 != (__int64 *)&v44 )
    {
      if ( *v24 )
        *(_DWORD *)(*v24 + 32) = (*(_DWORD *)(*v24 + 32) + 1) & 0x8FBFFFFF;
      VStr = (Scaleform::GFx::AS3::Instances::fl_events::Event *)*v24;
      v44 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)*v24;
    }
    v25 = resulta.pNode;
    if ( resulta.pNode )
    {
      if ( ((__int64)resulta.pNode & 1) != 0 )
      {
        --resulta.pNode;
      }
      else
      {
        Size = resulta.pNode->Size;
        if ( (Size & 0x3FFFFF) != 0 )
        {
          resulta.pNode->Size = Size - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v25);
        }
      }
    }
    goto LABEL_89;
  }
  _this.Flags = 12;
  _this.Bonus.pWeakProxy = 0i64;
  _this.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)event;
  event->RefCount = (event->RefCount + 1) & 0x8FBFFFFF;
  v.Flags = 0;
  v.Bonus.pWeakProxy = 0i64;
  func.Flags = 0;
  func.Bonus.pWeakProxy = 0i64;
  ConstString = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                                                     this->pTraits.pObject->pVM->StringManagerRef,
                                                     (Scaleform::GFx::ASString *)&v38,
                                                     "clone");
  v12 = 10;
  v34.Flags = 10;
  v34.Bonus.pWeakProxy = 0i64;
  v13 = *ConstString;
  v34.value.VS._1 = v13;
  if ( v13.VStr == &v13.VStr->pManager->NullStringNode )
  {
    v13.VStr = 0i64;
    v34.value.VS._1.VStr = 0i64;
    VObj = v38.Message.pNode;
    v34.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v38.Message.pNode;
    v12 = 12;
    v34.Flags = 12;
  }
  else
  {
    ++v13.VStr->RefCount;
    VObj = (Scaleform::GFx::ASStringNode *)v34.value.VS._2.VObj;
  }
  v15 = this->pTraits.pObject->pVM->PublicNamespace.pObject;
  v39.Kind = MN_QName;
  v39.Obj.pObject = v15;
  if ( v15 )
    v15->RefCount = (v15->RefCount + 1) & 0x8FBFFFFF;
  v39.Name.Flags = 0;
  v39.Name.Bonus.pWeakProxy = 0i64;
  v16 = v12 & 0x1F;
  if ( (unsigned int)(v16 - 12) <= 3
    && v13.VStr
    && (pData = v13.VStr[1].pData, *((_DWORD *)pData + 30) == 17)
    && (pData[112] & 0x20) == 0 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v39.Name, (Scaleform::GFx::ASString *)&v13.VStr[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v39.Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v13.VStr[1].RefCount);
    v39.Kind &= 0xFFFFFFF9;
  }
  else
  {
    _mm_prefetch((const char *)&v34, 2);
    *(_QWORD *)&v39.Name.Flags = *(_QWORD *)&v34.Flags;
    v39.Name.Bonus.pWeakProxy = 0i64;
    v39.Name.value.VS._1 = v13;
    v39.Name.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)VObj;
    if ( (v12 & 0x1Fu) > 9 )
    {
      if ( v16 == 10 )
      {
        ++v13.VStr->RefCount;
      }
      else if ( (v12 & 0x1Fu) <= 0xF )
      {
        if ( v13.VStr )
          v13.VStr->Size = (v13.VStr->Size + 1) & 0x8FBFFFFF;
      }
      else if ( (v12 & 0x1Fu) <= 0x11 && VObj )
      {
        VObj->Size = (VObj->Size + 1) & 0x8FBFFFFF;
      }
    }
    if ( (v39.Name.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v39.Name, &resulta);
      if ( resulta.pNode->Size )
      {
        if ( *resulta.pNode->pData == 64 )
        {
          v39.Kind |= 8u;
          v18 = Scaleform::GFx::ASString::Substring(&resulta, &v40, 1, resulta.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign(&v39.Name, v18);
          v19 = v40.pNode;
          v8 = v40.pNode->RefCount-- == 1;
          if ( v8 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v19);
        }
      }
      v20 = resulta.pNode;
      v8 = resulta.pNode->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v20);
    }
  }
  if ( (v12 & 0x1Fu) > 9 )
    Scaleform::GFx::AS3::Value::ReleaseInternal(&v34);
  v21 = *(Scaleform::GFx::ASStringNode **)&v38.ID;
  v8 = (*(_DWORD *)(*(_QWORD *)&v38.ID + 24i64))-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v21);
  if ( !*(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl_events::Event *, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))event->vfptr[1].~RefCountBaseGC<328>)(
                    event,
                    &resulta,
                    &v39,
                    &func) )
  {
LABEL_60:
    Scaleform::GFx::AS3::Multiname::~Multiname(&v39);
    if ( (func.Flags & 0x1F) > 9 )
    {
      if ( (func.Flags & 0x200) != 0 )
      {
        v8 = func.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v8 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&func.Bonus, 0, 24);
        func.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
      }
    }
    if ( (v.Flags & 0x1F) > 9 )
    {
      if ( (v.Flags & 0x200) != 0 )
      {
        v8 = v.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v8 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v.Bonus, 0, 24);
        v.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
      }
    }
    if ( (_this.Flags & 0x1F) > 9 )
    {
      if ( (_this.Flags & 0x200) != 0 )
      {
        v8 = _this.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v8 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&_this.Bonus, 0, 24);
        _this.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
      }
    }
    v4 = result;
    goto LABEL_89;
  }
  Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this->pTraits.pObject->pVM, &func, &_this, &v, 0, 0i64, 0);
  v22 = this->pTraits.pObject;
  if ( !v22->pVM->HandleException )
  {
    if ( (v.Flags & 0x1F) - 12 <= 3 )
    {
      if ( Scaleform::GFx::AS3::VM::IsOfType(
             v22->pVM,
             &v,
             *(Scaleform::GFx::AS3::ClassTraits::fl::Object **)&v22->pVM[1].XMLSupport_.pObject->Enabled) )
      {
        v23 = v.value.VS._1;
        if ( v.value.VS._1.VStr )
        {
          ++v.value.VS._1.VStr->Size;
          v23.VStr->Size &= 0x8FBFFFFF;
          VStr = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v23.VStr;
          v44 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v23.VStr;
        }
      }
    }
    goto LABEL_60;
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&v39);
  if ( (func.Flags & 0x1F) > 9 )
  {
    if ( (func.Flags & 0x200) != 0 )
    {
      v8 = func.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&func.Bonus, 0, 24);
      func.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
    }
  }
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
    {
      v8 = v.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v.Bonus, 0, 24);
      v.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    }
  }
  if ( (_this.Flags & 0x1F) > 9 )
  {
    if ( (_this.Flags & 0x200) != 0 )
    {
      v8 = _this.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&_this.Bonus, 0, 24);
      _this.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
    }
  }
LABEL_104:
  if ( VStr )
  {
    if ( ((unsigned __int8)VStr & 1) != 0 )
    {
      v44 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)((char *)VStr - 1);
    }
    else
    {
      RefCount = VStr->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        VStr->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(VStr);
      }
    }
  }
}

// File Line: 302
// RVA: 0x84DD20
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::hasEventListener(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        bool *result,
        Scaleform::GFx::ASString *type)
{
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *pObject; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // rdi
  __int64 v9; // rax
  unsigned __int64 *v10; // rax
  char *v11; // rax
  bool v12; // al
  bool v13; // zf
  Scaleform::GFx::ASStringNode *v14; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v15; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v16; // rdi
  __int64 v17; // rax
  unsigned __int64 *v18; // rax
  char *v19; // rax
  bool v20; // al
  Scaleform::GFx::ASString key; // [rsp+50h] [rbp+8h] BYREF

  pNode = type->pNode;
  key.pNode = pNode;
  ++pNode->RefCount;
  pObject = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)this->pImpl.pObject;
  v12 = 0;
  if ( pObject )
  {
    pTable = pObject[1].pTable;
    if ( pTable )
    {
      v9 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
             pObject + 1,
             &key,
             pNode->HashFlags & pTable->SizeMask);
      if ( v9 >= 0 )
      {
        v10 = &pTable[1].SizeMask + 3 * v9;
        if ( v10 )
        {
          v11 = (char *)(v10 + 1);
          if ( v11 )
          {
            if ( *(_QWORD *)v11 && *(_QWORD *)(*(_QWORD *)v11 + 8i64) )
              v12 = 1;
          }
        }
      }
    }
  }
  *result = v12;
  v13 = pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( !*result )
  {
    v14 = type->pNode;
    key.pNode = v14;
    ++v14->RefCount;
    v15 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)this->pImpl.pObject;
    v20 = 0;
    if ( v15 )
    {
      v16.pTable = v15->pTable;
      if ( v15->pTable )
      {
        v17 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                v15,
                &key,
                v14->HashFlags & v16.pTable->SizeMask);
        if ( v17 >= 0 )
        {
          v18 = &v16.pTable[1].SizeMask + 3 * v17;
          if ( v18 )
          {
            v19 = (char *)(v18 + 1);
            if ( v19 )
            {
              if ( *(_QWORD *)v19 && *(_QWORD *)(*(_QWORD *)v19 + 8i64) )
                v20 = 1;
            }
          }
        }
      }
    }
    *result = v20;
    v13 = v14->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  }
}

// File Line: 310
// RVA: 0x859A00
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::removeEventListener(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASString *type,
        Scaleform::GFx::AS3::Value *listener,
        bool useCapture)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *pObject; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v9; // rbx
  __int64 v10; // rax
  unsigned __int64 *v11; // rax
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> > **v12; // rax
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> > *v13; // r14
  unsigned __int64 v14; // rdi
  unsigned __int64 Size; // rsi
  Scaleform::GFx::AS3::Value *i; // rbx

  pObject = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)this->pImpl.pObject;
  if ( pObject )
  {
    if ( !useCapture )
      ++pObject;
    v9.pTable = pObject->pTable;
    if ( pObject->pTable )
    {
      v10 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
              pObject,
              type,
              v9.pTable->SizeMask & type->pNode->HashFlags);
      if ( v10 >= 0 )
      {
        v11 = &v9.pTable[1].SizeMask + 3 * v10;
        if ( v11 )
        {
          v12 = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> > **)(v11 + 1);
          if ( v12 )
          {
            v13 = *v12;
            v14 = 0i64;
            Size = (*v12)->Data.Size;
            if ( Size )
            {
              for ( i = &v13->Data.Data->mFunction;
                    (i->Flags & 0x200) != 0 && !i->Bonus.pWeakProxy->pObject
                 || !Scaleform::GFx::AS3::StrictEqual(i, listener);
                    i = (Scaleform::GFx::AS3::Value *)((char *)i + 40) )
              {
                if ( ++v14 >= Size )
                  return;
              }
              Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
                v13,
                v14);
              Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::OnRemoveEventListener(
                this,
                type,
                useCapture,
                v13->Data.Size);
            }
          }
        }
      }
    }
  }
}

// File Line: 340
// RVA: 0x86C0B0
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::willTrigger(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        bool *result,
        Scaleform::GFx::ASString *type)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *pObject; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v7; // rdi
  __int64 v8; // rax
  unsigned __int64 *v9; // rax
  char *v10; // rax
  bool v11; // al
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v12; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // rdi
  __int64 v14; // rax
  unsigned __int64 *v15; // rax
  char *v16; // rax
  bool v17; // al
  Scaleform::GFx::AS3::Traits *v18; // rcx
  __int64 v19; // rdi
  unsigned __int64 Size; // rbp
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *Data; // r12
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v22; // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v23; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v24; // rbx
  __int64 v25; // rax
  unsigned __int64 *v26; // rax
  char *v27; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v28; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v29; // rbx
  __int64 v30; // rax
  unsigned __int64 *v31; // rax
  char *v32; // rax
  bool v33; // al
  Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> evtFlowArray; // [rsp+40h] [rbp-148h] BYREF

  pObject = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)this->pImpl.pObject;
  v11 = 0;
  if ( pObject )
  {
    v7.pTable = pObject->pTable;
    if ( pObject->pTable )
    {
      v8 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
             pObject,
             type,
             type->pNode->HashFlags & v7.pTable->SizeMask);
      if ( v8 >= 0 )
      {
        v9 = &v7.pTable[1].SizeMask + 3 * v8;
        if ( v9 )
        {
          v10 = (char *)(v9 + 1);
          if ( v10 )
          {
            if ( *(_QWORD *)v10 && *(_QWORD *)(*(_QWORD *)v10 + 8i64) )
              v11 = 1;
          }
        }
      }
    }
  }
  *result = v11;
  if ( !v11 )
  {
    v12 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)this->pImpl.pObject;
    v17 = 0;
    if ( v12 )
    {
      pTable = v12[1].pTable;
      if ( pTable )
      {
        v14 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                v12 + 1,
                type,
                type->pNode->HashFlags & pTable->SizeMask);
        if ( v14 >= 0 )
        {
          v15 = &pTable[1].SizeMask + 3 * v14;
          if ( v15 )
          {
            v16 = (char *)(v15 + 1);
            if ( v16 )
            {
              if ( *(_QWORD *)v16 && *(_QWORD *)(*(_QWORD *)v16 + 8i64) )
                v17 = 1;
            }
          }
        }
      }
    }
    *result = v17;
    if ( !v17 )
    {
      v18 = this->pTraits.pObject;
      if ( (unsigned int)(v18->TraitsType - 22) <= 0xC && (v18->Flags & 0x20) == 0 )
      {
        evtFlowArray.pHeap = v18->pVM->MHeap;
        v19 = 0i64;
        evtFlowArray.Size = 0i64;
        evtFlowArray.Reserved = 32i64;
        `eh vector constructor iterator(
          evtFlowArray.Static,
          8ui64,
          32,
          (void (__fastcall *)(void *))Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>::`default constructor closure);
        evtFlowArray.Data = evtFlowArray.Static;
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CaptureEventFlow(
          this,
          (Scaleform::GFx::DisplayObject *)this[1]._pRCC,
          &evtFlowArray);
        Size = evtFlowArray.Size;
        if ( evtFlowArray.Size )
        {
          Data = evtFlowArray.Data;
          while ( 1 )
          {
            v22 = Data[v19].pObject;
            v23 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v22->pImpl.pObject;
            if ( v23 )
            {
              v24.pTable = v23->pTable;
              if ( v23->pTable )
              {
                v25 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                        v23,
                        type,
                        type->pNode->HashFlags & v24.pTable->SizeMask);
                if ( v25 >= 0 )
                {
                  v26 = &v24.pTable[1].SizeMask + 3 * v25;
                  if ( v26 )
                  {
                    v27 = (char *)(v26 + 1);
                    if ( v27 )
                    {
                      if ( *(_QWORD *)v27 && *(_QWORD *)(*(_QWORD *)v27 + 8i64) )
                        break;
                    }
                  }
                }
              }
            }
            v28 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v22->pImpl.pObject;
            v33 = 0;
            if ( v28 )
            {
              v29 = v28[1].pTable;
              if ( v29 )
              {
                v30 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                        v28 + 1,
                        type,
                        type->pNode->HashFlags & v29->SizeMask);
                if ( v30 >= 0 )
                {
                  v31 = &v29[1].SizeMask + 3 * v30;
                  if ( v31 )
                  {
                    v32 = (char *)(v31 + 1);
                    if ( v32 )
                    {
                      if ( *(_QWORD *)v32 && *(_QWORD *)(*(_QWORD *)v32 + 8i64) )
                        v33 = 1;
                    }
                  }
                }
              }
            }
            *result = v33;
            if ( !v33 && ++v19 < Size )
              continue;
            goto LABEL_45;
          }
          *result = 1;
        }
LABEL_45:
        Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>::Clear(&evtFlowArray);
        `eh vector destructor iterator(
          evtFlowArray.Static,
          8ui64,
          32,
          (void (__fastcall *)(void *))Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent>::~SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent>);
      }
    }
  }
}

// File Line: 374
// RVA: 0x78A840
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::~EventDispatcher(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this)
{
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::`vftable;
  Scaleform::AutoPtr<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl>::~AutoPtr<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl>(&this->pImpl);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instance::`vftable;
  Scaleform::GFx::AS3::Traits::DestructTail(
    (Scaleform::GFx::AS3::Traits *)((unsigned __int64)this->pTraits.pObject & 0xFFFFFFFFFFFFFFFEui64),
    this);
  Scaleform::GFx::AS3::Object::~Object(this);
}

// File Line: 391
// RVA: 0x7D5AB0
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *),
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *ed,
        bool useCapture)
{
  Scaleform::GFx::AS3::VM *v6; // rbx
  Scaleform::GFx::AS3::RefCountCollector<328> *v7; // r9
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // r10
  unsigned __int64 v10; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v11; // rcx
  unsigned __int64 v12; // r14
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash *v13; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v14; // rcx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> *v15; // rsi
  unsigned __int64 Size; // rdi
  __int64 v17; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *v18; // r8
  unsigned int Flags; // eax
  int v20; // eax
  unsigned __int64 v21; // rdi
  unsigned __int64 v22; // rbp
  __int64 v23; // r15
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *v24; // rdx
  unsigned int v25; // ecx
  __int64 v26; // r8
  Scaleform::GFx::AS3::Value *p_mFunction; // rbx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  int v30; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> **p_VObj; // rdx
  Scaleform::GFx::AS3::RefCountBaseGC<328> **p_value; // r8
  unsigned __int64 SizeMask; // rdx
  unsigned __int64 *v34; // rcx
  __int64 v35; // [rsp+20h] [rbp-68h]
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *v36; // [rsp+28h] [rbp-60h]
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash *v37; // [rsp+30h] [rbp-58h]
  unsigned __int64 v38; // [rsp+38h] [rbp-50h]
  unsigned __int64 v39; // [rsp+90h] [rbp+8h]

  v35 = -2i64;
  v6 = vm;
  v7 = prcc;
  pTable = this->mHash.pTable;
  if ( this->mHash.pTable )
  {
    v10 = 0i64;
    v11 = pTable + 1;
    do
    {
      if ( v11->EntryCount != -2i64 )
        break;
      ++v10;
      v11 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)((char *)v11 + 24);
    }
    while ( v10 <= pTable->SizeMask );
    v37 = this;
    v38 = v10;
  }
  else
  {
    v37 = 0i64;
    v38 = 0i64;
  }
  v12 = v38;
  v39 = v38;
LABEL_8:
  v13 = v37;
  while ( v13 )
  {
    v14 = v13->mHash.pTable;
    if ( !v13->mHash.pTable || (signed __int64)v12 > (signed __int64)v14->SizeMask )
      break;
    v15 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> *)*(&v14[2].EntryCount + 3 * v12);
    if ( !v15 )
      goto LABEL_55;
    if ( v6->InDestructor )
    {
      Size = v15->Size;
      if ( !Size )
        goto LABEL_55;
      v17 = 0i64;
      while ( 2 )
      {
        v18 = &v15->Data[v17];
        Flags = v18->mFunction.Flags;
        if ( (Flags & 0x200) == 0 || v18->mFunction.Bonus.pWeakProxy->pObject )
        {
          v20 = Flags & 0x1F;
          if ( v20 > 10 && (v18->mFunction.Flags & 0x200) == 0 )
          {
            if ( v20 <= 15 )
            {
              if ( v18->mFunction.value.VS._1.VStr )
                goto LABEL_25;
            }
            else if ( v20 <= 17 && v18->mFunction.value.VS._2.VObj )
            {
LABEL_25:
              op(v7);
              v7 = prcc;
            }
          }
        }
        ++v17;
        if ( !--Size )
          goto LABEL_54;
        continue;
      }
    }
    v21 = 0i64;
    v22 = v15->Size;
    if ( !v22 )
      goto LABEL_55;
    v23 = 0i64;
    do
    {
      v24 = &v15->Data[v23];
      v25 = v24->mFunction.Flags;
      v26 = v25 >> 9;
      if ( (v25 & 0x200) == 0 || v24->mFunction.Bonus.pWeakProxy->pObject )
      {
        v30 = v25 & 0x1F;
        if ( v30 > 10 && (v24->mFunction.Flags & 0x200) == 0 )
        {
          if ( v30 <= 15 )
          {
            p_value = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v24->mFunction.value;
            if ( v24->mFunction.value.VS._1.VStr )
            {
              p_VObj = 0i64;
              if ( (unsigned int)(v30 - 11) <= 4 )
                p_VObj = p_value;
LABEL_51:
              ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))op)(
                v7,
                p_VObj);
            }
          }
          else if ( v30 <= 17 )
          {
            p_VObj = &v24->mFunction.value.VS._2.VObj;
            if ( *p_VObj )
              goto LABEL_51;
          }
        }
        ++v21;
        ++v23;
        goto LABEL_53;
      }
      if ( v15->Size == 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          v15,
          v15,
          0i64);
      }
      else
      {
        v36 = &v15->Data[v23];
        p_mFunction = &v24->mFunction;
        if ( (v24->mFunction.Flags & 0x1F) > 9 )
        {
          if ( (v24->mFunction.Flags & 0x200) != 0 )
          {
            pWeakProxy = v24->mFunction.Bonus.pWeakProxy;
            if ( pWeakProxy->RefCount-- == 1 )
            {
              LOBYTE(v26) = (v25 & 0x200) != 0;
              ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *, __int64, Scaleform::GFx::AS3::RefCountCollector<328> *, __int64, Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
                Scaleform::Memory::pGlobalHeap,
                pWeakProxy,
                v26,
                v7,
                v35,
                v36);
            }
            p_mFunction->Bonus.pWeakProxy = 0i64;
            p_mFunction->value.VS._1.VStr = 0i64;
            p_mFunction->value.VS._2.VObj = 0i64;
            p_mFunction->Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v24->mFunction);
          }
        }
        memmove(&v15->Data[v23], &v15->Data[v23 + 1], 40 * (v15->Size - v21 - 1));
        --v15->Size;
      }
      Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::OnRemoveEventListener(
        ed,
        (Scaleform::GFx::ASString *)&v37->mHash.pTable[1].SizeMask + 3 * v12,
        useCapture,
        --v22);
LABEL_53:
      v7 = prcc;
    }
    while ( v21 < v22 );
LABEL_54:
    v6 = vm;
    v12 = v39;
LABEL_55:
    v13 = v37;
    SizeMask = v37->mHash.pTable->SizeMask;
    v7 = prcc;
    if ( (__int64)v12 <= (__int64)SizeMask )
    {
      v39 = ++v12;
      if ( v12 <= SizeMask )
      {
        v34 = &v37->mHash.pTable[1].EntryCount + 3 * v12;
        while ( 1 )
        {
          v7 = prcc;
          v13 = v37;
          if ( *v34 != -2i64 )
            break;
          v39 = ++v12;
          v34 += 3;
          if ( v12 > SizeMask )
            goto LABEL_8;
        }
      }
    }
  }
}     v39 = ++v12;
          v34 += 3;
          if ( v12 > SizeMask )
            goto LABEL_8;
        }
      }
    }
  }
}

// File Line: 435
// RVA: 0x7D5760
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *pObject; // rcx

  Scaleform::GFx::AS3::Object::ForEachChild_GC(this, prcc, op);
  pObject = this->pImpl.pObject;
  if ( pObject )
  {
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash::ForEachChild_GC(
      &pObject->CaptureListeners,
      prcc,
      op,
      this->VMRef,
      this,
      1);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash::ForEachChild_GC(
      &this->pImpl.pObject->Listeners,
      prcc,
      op,
      this->VMRef,
      this,
      0);
  }
}

// File Line: 447
// RVA: 0x7BC990
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateEventObject(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        Scaleform::GFx::ASString *type,
        bool bubbles,
        bool cancelable)
{
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher **pObject; // rbx

  pObject = (Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher **)this->pTraits.pObject;
  if ( !pObject[17] )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Traits *))(*pObject)->MouseEventTraits.pObject)(this->pTraits.pObject);
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateEventObject(
    pObject[17],
    result,
    type,
    bubbles,
    cancelable);
  return result;
}

// File Line: 453
// RVA: 0x7BE740
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateProgressEventObject(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        Scaleform::GFx::ASString *type)
{
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher **pObject; // rbx

  pObject = (Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher **)this->pTraits.pObject;
  if ( !pObject[17] )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Traits *))(*pObject)->MouseEventTraits.pObject)(this->pTraits.pObject);
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateProgressEventObject(pObject[17], result, type);
  return result;
}

// File Line: 469
// RVA: 0x7BCCE0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateFocusEventObject(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        Scaleform::GFx::ASString *type,
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *relatedObj,
        char controllerIdx,
        bool shiftKey)
{
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher **pObject; // rbx
  int v11; // [rsp+28h] [rbp-30h]

  pObject = (Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher **)this->pTraits.pObject;
  if ( !pObject[17] )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Traits *))(*pObject)->MouseEventTraits.pObject)(this->pTraits.pObject);
  LOBYTE(v11) = shiftKey;
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateFocusEventObject(
    pObject[17],
    result,
    type,
    relatedObj,
    controllerIdx,
    v11);
  return result;
}

// File Line: 475
// RVA: 0x7BD780
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateIOErrorEventObject(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        const char *errText)
{
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher **pObject; // rbx

  pObject = (Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher **)this->pTraits.pObject;
  if ( !pObject[17] )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Traits *))(*pObject)->MouseEventTraits.pObject)(this->pTraits.pObject);
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateIOErrorEventObject(pObject[17], result, errText);
  return result;
}

// File Line: 514
// RVA: 0x7C4BD0
_BOOL8 __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        Scaleform::GFx::EventId *evtId,
        Scaleform::GFx::DisplayObject *dispObject)
{
  Scaleform::GFx::AS3::Traits *pObject; // rbx
  Scaleform::GFx::AS3::VM *pVM; // rdi
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *v8; // r10
  Scaleform::GFx::AS3::Instances::fl_events::Event *v9; // rbx
  unsigned int Id; // eax
  Scaleform::GFx::AS3::Object *v11; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v12; // rcx
  Scaleform::GFx::AS3::Object *v13; // rcx
  Scaleform::GFx::AS3::Object *v14; // rcx
  bool v15; // di
  Scaleform::GFx::AS3::Instances::fl_events::Event *v16; // rcx
  Scaleform::GFx::AS3::Object *v17; // rcx
  Scaleform::GFx::AS3::Object *v18; // rcx
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v19; // rcx
  Scaleform::GFx::AS3::Object *v20; // rcx
  unsigned int v21; // eax
  Scaleform::GFx::AS3::Object *v22; // rcx
  Scaleform::GFx::AS3::Instances::fl_events::Event *v23; // rsi
  __int64 v24; // rax
  __int64 v25; // rax
  __int64 v26; // rcx
  __int64 v27; // r15
  Scaleform::GFx::AS3::Instances::fl::XMLList *v28; // rdx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v29; // rcx
  unsigned int v30; // eax
  Scaleform::GFx::ASString *vfptr; // r8
  Scaleform::GFx::ASString *v32; // r8
  unsigned int v33; // eax
  Scaleform::GFx::AS3::Instances::fl_events::Event *v34; // rsi
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v35; // rcx
  unsigned int RefCount; // eax
  __int64 ControllerIndex; // rax
  __int64 v38; // rax
  __int64 v39; // rcx
  __int64 v40; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v41; // rdx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Traits> *v42; // rdi
  Scaleform::GFx::AS3::Traits *pRCC; // rcx
  unsigned int v44; // eax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v45; // rcx
  unsigned int v46; // eax
  unsigned int v47; // eax
  Scaleform::GFx::AS3::Object *v48; // rcx
  Scaleform::GFx::AS3::Object *v49; // rcx
  Scaleform::GFx::AS3::Object *v50; // rcx
  Scaleform::GFx::AS3::Object *v51; // rcx
  Scaleform::GFx::AS3::Object *v52; // rcx
  Scaleform::GFx::AS3::Object *v53; // rcx
  unsigned int v54; // eax
  unsigned int v55; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> v57; // [rsp+30h] [rbp-49h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> v58; // [rsp+38h] [rbp-41h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> v59; // [rsp+40h] [rbp-39h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> v60; // [rsp+48h] [rbp-31h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> v61; // [rsp+50h] [rbp-29h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> v62; // [rsp+58h] [rbp-21h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent> v63; // [rsp+60h] [rbp-19h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::AccelerometerEvent> v64; // [rsp+68h] [rbp-11h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent> v65; // [rsp+70h] [rbp-9h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::GeolocationEvent> v66; // [rsp+78h] [rbp-1h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> v67; // [rsp+80h] [rbp+7h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::StatusEvent> v68; // [rsp+88h] [rbp+Fh] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> v69; // [rsp+90h] [rbp+17h] BYREF
  __int64 v70; // [rsp+98h] [rbp+1Fh]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> v71; // [rsp+E8h] [rbp+6Fh] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> result; // [rsp+F8h] [rbp+7Fh] BYREF

  v70 = -2i64;
  pObject = this->pTraits.pObject;
  pVM = pObject->pVM;
  if ( !pObject->pConstructor.pObject )
    pObject->vfptr[3].~RefCountBaseGC<328>(this->pTraits.pObject);
  v8 = (Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *)pObject->pConstructor.pObject;
  v9 = 0i64;
  Id = evtId->Id;
  if ( evtId->Id > 0x100000A )
  {
    switch ( Id )
    {
      case 0x100000Bu:
        v34 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
                                                                    v8,
                                                                    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v57,
                                                                    evtId,
                                                                    (Scaleform::GFx::ASString *)&pVM[1].vfptr[96],
                                                                    (Scaleform::GFx::AS3::Instances::fl::XMLList *)this)->pObject;
        v71.pObject = v34;
        if ( v34 )
          v34->RefCount = (v34->RefCount + 1) & 0x8FBFFFFF;
        v35 = v57.pObject;
        if ( v57.pObject )
        {
          if ( ((__int64)v57.pObject & 1) != 0 )
          {
            --v57.pObject;
          }
          else
          {
            RefCount = v57.pObject->RefCount;
            if ( (RefCount & 0x3FFFFF) != 0 )
            {
              v57.pObject->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v35);
            }
          }
        }
        if ( v34 )
        {
          v34->RefCount = (v34->RefCount + 1) & 0x8FBFFFFF;
          v9 = v34;
        }
        ControllerIndex = (unsigned int)evtId->ControllerIndex;
        if ( (unsigned int)ControllerIndex < 6
          && (v38 = (__int64)&pVM[1].vfptr[28 * ControllerIndex + 112]) != 0
          && (v39 = *(_QWORD *)(v38 + 24)) != 0 )
        {
          v40 = v39 + 4i64 * *(unsigned __int8 *)(v39 + 109);
          v41 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v40 + 16);
          if ( !v41 )
            v41 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v40 + 8);
          if ( ((unsigned __int8)v41 & 1) != 0 )
            v41 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v41 - 1);
          v42 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Traits> *)&v34[1].8;
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v34[1].8,
            v41);
        }
        else
        {
          v42 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Traits> *)&v34[1].8;
          pRCC = (Scaleform::GFx::AS3::Traits *)v34[1]._pRCC;
          if ( pRCC )
          {
            if ( ((unsigned __int8)pRCC & 1) != 0 )
            {
              v42->pObject = (Scaleform::GFx::AS3::Traits *)((char *)pRCC - 1);
            }
            else
            {
              v44 = pRCC->RefCount;
              if ( (v44 & 0x3FFFFF) != 0 )
              {
                pRCC->RefCount = v44 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pRCC);
              }
            }
            v42->pObject = 0i64;
          }
        }
        if ( (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)v42->pObject == this )
        {
          v45 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)v42->pObject;
          if ( v42->pObject )
          {
            if ( ((unsigned __int8)v45 & 1) != 0 )
            {
              v42->pObject = (Scaleform::GFx::AS3::Traits *)(&v45[-1].pImpl.Owner + 7);
            }
            else
            {
              v46 = v45->RefCount;
              if ( (v46 & 0x3FFFFF) != 0 )
              {
                v45->RefCount = v46 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v45);
              }
            }
            v42->pObject = 0i64;
          }
        }
        if ( ((unsigned __int8)v34 & 1) != 0 )
        {
          v71.pObject = (Scaleform::GFx::AS3::Instances::fl_events::Event *)((char *)v34 - 1);
          goto LABEL_163;
        }
        v47 = v34->RefCount;
        if ( (v47 & 0x3FFFFF) == 0 )
          goto LABEL_163;
        v34->RefCount = v47 - 1;
        v12 = v34;
        break;
      case 0x100000Cu:
        v48 = Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
                v8,
                (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v58,
                evtId,
                (Scaleform::GFx::ASString *)&pVM[1].vfptr[92],
                (Scaleform::GFx::AS3::Instances::fl::XMLList *)this)->pObject;
        if ( v48 )
        {
          v48->RefCount = (v48->RefCount + 1) & 0x8FBFFFFF;
          v9 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v48;
        }
        v12 = v58.pObject;
        if ( !v58.pObject )
          goto LABEL_163;
        if ( ((__int64)v58.pObject & 1) == 0 )
          goto LABEL_160;
        --v58.pObject;
        goto LABEL_163;
      case 0x100000Du:
        v49 = Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
                v8,
                (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v60,
                evtId,
                (Scaleform::GFx::ASString *)&pVM[1].vfptr[93],
                (Scaleform::GFx::AS3::Instances::fl::XMLList *)this)->pObject;
        if ( v49 )
        {
          v49->RefCount = (v49->RefCount + 1) & 0x8FBFFFFF;
          v9 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v49;
        }
        v12 = v60.pObject;
        if ( !v60.pObject )
          goto LABEL_163;
        if ( ((__int64)v60.pObject & 1) == 0 )
          goto LABEL_160;
        --v60.pObject;
        goto LABEL_163;
      case 0x100000Eu:
        v50 = Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
                v8,
                (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v62,
                evtId,
                (Scaleform::GFx::ASString *)&pVM[1].vfptr[99],
                (Scaleform::GFx::AS3::Instances::fl::XMLList *)this)->pObject;
        if ( v50 )
        {
          v50->RefCount = (v50->RefCount + 1) & 0x8FBFFFFF;
          v9 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v50;
        }
        v12 = v62.pObject;
        if ( !v62.pObject )
          goto LABEL_163;
        if ( ((__int64)v62.pObject & 1) == 0 )
          goto LABEL_160;
        --v62.pObject;
        goto LABEL_163;
      case 0x1000011u:
      case 0x1000012u:
        vfptr = (Scaleform::GFx::ASString *)pVM[1].vfptr;
        if ( evtId->Id == 16777233 )
          v32 = vfptr + 73;
        else
          v32 = vfptr + 78;
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateEventObject(
          v8,
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v71,
          v32,
          0,
          0);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v71.pObject->Target,
          (Scaleform::GFx::AS3::Instances::fl::XMLList *)this);
        if ( !Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(this, v71.pObject, 0)
          && dispObject )
        {
          dispObject->Flags |= 0x20u;
        }
        v15 = (*((_BYTE *)v71.pObject + 84) & 4) == 0;
        goto LABEL_30;
      case 0x1000013u:
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateEventObject(
          v8,
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v71,
          (Scaleform::GFx::ASString *)&pVM[1].vfptr[89],
          0,
          0);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v71.pObject->Target,
          (Scaleform::GFx::AS3::Instances::fl::XMLList *)this);
        if ( !Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(this, v71.pObject, 0)
          && dispObject )
        {
          dispObject->Flags |= 0x20u;
        }
        v15 = (*((_BYTE *)v71.pObject + 84) & 4) == 0;
        goto LABEL_30;
      case 0x1000014u:
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateEventObject(
          v8,
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v71,
          (Scaleform::GFx::ASString *)&pVM[1].vfptr[90],
          0,
          0);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v71.pObject->Target,
          (Scaleform::GFx::AS3::Instances::fl::XMLList *)this);
        if ( !Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(this, v71.pObject, 0)
          && dispObject )
        {
          dispObject->Flags |= 0x20u;
        }
        v15 = (*((_BYTE *)v71.pObject + 84) & 4) == 0;
        goto LABEL_30;
      case 0x1000024u:
        v51 = Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateAccelerometerEventObject(
                v8,
                (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v64,
                evtId,
                (Scaleform::GFx::ASString *)&pVM[1].vfptr[104],
                (Scaleform::GFx::AS3::Instances::fl::XMLList *)this)->pObject;
        if ( v51 )
        {
          v51->RefCount = (v51->RefCount + 1) & 0x8FBFFFFF;
          v9 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v51;
        }
        v12 = v64.pObject;
        if ( !v64.pObject )
          goto LABEL_163;
        if ( ((__int64)v64.pObject & 1) == 0 )
          goto LABEL_160;
        --v64.pObject;
        goto LABEL_163;
      case 0x1000025u:
        v52 = Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateGeolocationEventObject(
                v8,
                (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v66,
                evtId,
                (Scaleform::GFx::ASString *)&pVM[1].vfptr[104],
                (Scaleform::GFx::AS3::Instances::fl::XMLList *)this)->pObject;
        if ( v52 )
        {
          v52->RefCount = (v52->RefCount + 1) & 0x8FBFFFFF;
          v9 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v52;
        }
        v12 = v66.pObject;
        if ( !v66.pObject )
          goto LABEL_163;
        if ( ((__int64)v66.pObject & 1) == 0 )
          goto LABEL_160;
        --v66.pObject;
        goto LABEL_163;
      case 0x1000026u:
        v53 = Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateStatusEventObject(
                v8,
                (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v68,
                evtId,
                (Scaleform::GFx::ASString *)&pVM[1].vfptr[105],
                (Scaleform::GFx::AS3::Instances::fl::XMLList *)this)->pObject;
        if ( v53 )
        {
          v53->RefCount = (v53->RefCount + 1) & 0x8FBFFFFF;
          v9 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v53;
        }
        v12 = v68.pObject;
        if ( !v68.pObject )
          goto LABEL_163;
        if ( ((__int64)v68.pObject & 1) == 0 )
          goto LABEL_160;
        --v68.pObject;
        goto LABEL_163;
      default:
        goto LABEL_164;
    }
    goto LABEL_162;
  }
  if ( Id == 16777226 )
  {
    Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
      v8,
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v71,
      evtId,
      (Scaleform::GFx::ASString *)&pVM[1].vfptr[97],
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)this);
    v23 = v71.pObject;
    if ( v71.pObject )
    {
      ++v71.pObject->RefCount;
      v23->RefCount &= 0x8FBFFFFF;
      v9 = v23;
      v23 = v71.pObject;
    }
    v24 = (unsigned int)evtId->ControllerIndex;
    if ( (unsigned int)v24 < 6
      && (v25 = (__int64)&pVM[1].vfptr[28 * v24 + 112]) != 0
      && (v26 = *(_QWORD *)(v25 + 24)) != 0 )
    {
      v27 = v26 + 4i64 * *(unsigned __int8 *)(v26 + 109);
      v28 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v27 + 16);
      if ( !v28 )
        v28 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v27 + 8);
      if ( ((unsigned __int8)v28 & 1) != 0 )
        v28 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v28 - 1);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v23[1].8,
        v28);
    }
    else
    {
      v29 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v23[1]._pRCC;
      if ( v29 )
      {
        if ( ((unsigned __int8)v29 & 1) != 0 )
        {
          v23[1].pRCCRaw = (unsigned __int64)&v29[-1].RefCount + 7;
        }
        else
        {
          v30 = v29->RefCount;
          if ( (v30 & 0x3FFFFF) != 0 )
          {
            v29->RefCount = v30 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v29);
          }
        }
        v23[1].pRCCRaw = 0i64;
      }
    }
    v12 = v71.pObject;
    if ( !v71.pObject )
      goto LABEL_163;
    if ( ((__int64)v71.pObject & 1) != 0 )
    {
      --v71.pObject;
      goto LABEL_163;
    }
    goto LABEL_160;
  }
  if ( Id > 0x40 )
  {
    switch ( Id )
    {
      case 0x80u:
        v22 = Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateKeyboardEventObject(
                v8,
                (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v63,
                evtId,
                (Scaleform::GFx::ASString *)&pVM[1].vfptr[103],
                (Scaleform::GFx::AS3::Instances::fl::XMLList *)this)->pObject;
        if ( v22 )
        {
          v22->RefCount = (v22->RefCount + 1) & 0x8FBFFFFF;
          v9 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v22;
        }
        v12 = v63.pObject;
        if ( !v63.pObject )
          goto LABEL_163;
        if ( ((__int64)v63.pObject & 1) != 0 )
        {
          --v63.pObject;
          goto LABEL_163;
        }
        goto LABEL_160;
      case 0x2000u:
        v20 = Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
                v8,
                (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v69,
                evtId,
                (Scaleform::GFx::ASString *)&pVM[1].vfptr[101],
                (Scaleform::GFx::AS3::Instances::fl::XMLList *)this)->pObject;
        if ( v20 )
        {
          v20->RefCount = (v20->RefCount + 1) & 0x8FBFFFFF;
          v9 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v20;
        }
        v19 = v69.pObject;
        if ( !v69.pObject )
          goto LABEL_53;
        if ( ((__int64)v69.pObject & 1) != 0 )
        {
          --v69.pObject;
          goto LABEL_53;
        }
        break;
      case 0x4000u:
        v18 = Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
                v8,
                (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v61,
                evtId,
                (Scaleform::GFx::ASString *)&pVM[1].vfptr[100],
                (Scaleform::GFx::AS3::Instances::fl::XMLList *)this)->pObject;
        if ( v18 )
        {
          v18->RefCount = (v18->RefCount + 1) & 0x8FBFFFFF;
          v9 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v18;
        }
        v19 = v61.pObject;
        if ( !v61.pObject )
        {
LABEL_53:
          *((_BYTE *)v9 + 84) &= ~1u;
          goto LABEL_163;
        }
        if ( ((__int64)v61.pObject & 1) != 0 )
        {
          --v61.pObject;
          goto LABEL_53;
        }
        break;
      default:
        goto LABEL_164;
    }
    v21 = v19->RefCount;
    if ( (v21 & 0x3FFFFF) != 0 )
    {
      v19->RefCount = v21 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v19);
    }
    goto LABEL_53;
  }
  if ( Id == 64 )
  {
    v17 = Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateKeyboardEventObject(
            v8,
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v65,
            evtId,
            (Scaleform::GFx::ASString *)&pVM[1].vfptr[102],
            (Scaleform::GFx::AS3::Instances::fl::XMLList *)this)->pObject;
    if ( v17 )
    {
      v17->RefCount = (v17->RefCount + 1) & 0x8FBFFFFF;
      v9 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v17;
    }
    v12 = v65.pObject;
    if ( !v65.pObject )
      goto LABEL_163;
    if ( ((__int64)v65.pObject & 1) != 0 )
    {
      --v65.pObject;
      goto LABEL_163;
    }
    goto LABEL_160;
  }
  if ( Id != 2 )
  {
    if ( Id != 8 )
    {
      if ( Id == 16 )
      {
        v13 = Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
                v8,
                (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v67,
                evtId,
                (Scaleform::GFx::ASString *)&pVM[1].vfptr[94],
                (Scaleform::GFx::AS3::Instances::fl::XMLList *)this)->pObject;
        if ( v13 )
        {
          v13->RefCount = (v13->RefCount + 1) & 0x8FBFFFFF;
          v9 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v13;
        }
        v12 = v67.pObject;
        if ( !v67.pObject )
          goto LABEL_163;
        if ( ((__int64)v67.pObject & 1) != 0 )
        {
          --v67.pObject;
          goto LABEL_163;
        }
        goto LABEL_160;
      }
      if ( Id == 32 )
      {
        v11 = Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
                v8,
                (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&result,
                evtId,
                (Scaleform::GFx::ASString *)&pVM[1].vfptr[98],
                (Scaleform::GFx::AS3::Instances::fl::XMLList *)this)->pObject;
        if ( v11 )
        {
          v11->RefCount = (v11->RefCount + 1) & 0x8FBFFFFF;
          v9 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v11;
        }
        v12 = result.pObject;
        if ( !result.pObject )
          goto LABEL_163;
        if ( ((__int64)result.pObject & 1) != 0 )
        {
          --result.pObject;
LABEL_163:
          Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(this, v9, dispObject);
          v15 = (*((_BYTE *)v9 + 84) & 4) == 0;
          goto LABEL_165;
        }
        goto LABEL_160;
      }
LABEL_164:
      v15 = 1;
      goto LABEL_165;
    }
    v14 = Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
            v8,
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v59,
            evtId,
            (Scaleform::GFx::ASString *)&pVM[1].vfptr[95],
            (Scaleform::GFx::AS3::Instances::fl::XMLList *)this)->pObject;
    if ( v14 )
    {
      v14->RefCount = (v14->RefCount + 1) & 0x8FBFFFFF;
      v9 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v14;
    }
    v12 = v59.pObject;
    if ( !v59.pObject )
      goto LABEL_163;
    if ( ((__int64)v59.pObject & 1) != 0 )
    {
      --v59.pObject;
      goto LABEL_163;
    }
LABEL_160:
    v54 = v12->RefCount;
    if ( (v54 & 0x3FFFFF) == 0 )
      goto LABEL_163;
    v12->RefCount = v54 - 1;
LABEL_162:
    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v12);
    goto LABEL_163;
  }
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateEventObject(
    v8,
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v71,
    (Scaleform::GFx::ASString *)&pVM[1].vfptr[79],
    0,
    0);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v71.pObject->Target,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)this);
  if ( !Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(this, v71.pObject, 0)
    && dispObject )
  {
    dispObject->Flags |= 0x20u;
  }
  v15 = (*((_BYTE *)v71.pObject + 84) & 4) == 0;
LABEL_30:
  v16 = v71.pObject;
  if ( v71.pObject )
  {
    if ( ((__int64)v71.pObject & 1) != 0 )
    {
      --v71.pObject;
    }
    else
    {
      v33 = v71.pObject->RefCount;
      if ( (v33 & 0x3FFFFF) != 0 )
      {
        v71.pObject->RefCount = v33 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v16);
      }
    }
  }
LABEL_165:
  if ( v9 )
  {
    if ( ((unsigned __int8)v9 & 1) == 0 )
    {
      v55 = v9->RefCount;
      if ( (v55 & 0x3FFFFF) != 0 )
      {
        v9->RefCount = v55 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v9);
      }
    }
  }
  return v15;
}

// File Line: 719
// RVA: 0x7C56B0
_BOOL8 __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::Instances::fl_events::Event *evtObj,
        Scaleform::GFx::DisplayObject *dispObject)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&evtObj->Target,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)this);
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(this, evtObj, dispObject);
  return (*((_BYTE *)evtObj + 84) & 4) == 0;
}

// File Line: 729
// RVA: 0x7C6420
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::Instances::fl_events::Event *evt,
        Scaleform::GFx::DisplayObject *dispObject)
{
  __int64 v6; // rdi
  unsigned __int64 v7; // rbp
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pObject; // rax
  char v9; // al
  unsigned __int64 Size; // rbp
  unsigned int RefCount; // eax
  Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> evtFlowArray; // [rsp+40h] [rbp-148h] BYREF

  *((_BYTE *)evt + 84) |= 0x20u;
  if ( !dispObject )
  {
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(this, evt, 0);
    return;
  }
  if ( this )
    this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  ++dispObject->RefCount;
  evtFlowArray.pHeap = this->pTraits.pObject->pVM->MHeap;
  v6 = 0i64;
  evtFlowArray.Size = 0i64;
  evtFlowArray.Reserved = 32i64;
  `eh vector constructor iterator(
    evtFlowArray.Static,
    8ui64,
    32,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>::`default constructor closure);
  evtFlowArray.Data = evtFlowArray.Static;
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CaptureEventFlow(this, dispObject, &evtFlowArray);
  evt->Phase = 1;
  v7 = evtFlowArray.Size - 1;
  if ( (signed __int64)(evtFlowArray.Size - 1) >= 0 )
  {
    while ( Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(
              evtFlowArray.Data[v7].pObject,
              evt,
              1) )
    {
      if ( Scaleform::GFx::AS3::Instances::fl_events::Event::IsPropagationStopped(evt) )
        goto LABEL_23;
      if ( (--v7 & 0x8000000000000000ui64) != 0i64 )
        goto LABEL_10;
    }
    pObject = evtFlowArray.Data[v7].pObject;
    goto LABEL_21;
  }
LABEL_10:
  evt->Phase = 2;
  if ( Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(this, evt, 0) )
  {
    v9 = *((_BYTE *)evt + 84);
    if ( (v9 & 8) == 0 && (v9 & 0x10) == 0 && (v9 & 1) != 0 )
    {
      evt->Phase = 3;
      Size = evtFlowArray.Size;
      if ( evtFlowArray.Size )
      {
        while ( Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(
                  evtFlowArray.Data[v6].pObject,
                  evt,
                  0) )
        {
          if ( !Scaleform::GFx::AS3::Instances::fl_events::Event::IsPropagationStopped(evt) && ++v6 < Size )
            continue;
          goto LABEL_23;
        }
        pObject = evtFlowArray.Data[v6].pObject;
LABEL_21:
        if ( pObject->pDispObj.pObject )
          pObject->pDispObj.pObject->Flags |= 0x20u;
      }
    }
  }
  else
  {
    dispObject->Flags |= 0x20u;
  }
LABEL_23:
  Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>::Clear(&evtFlowArray);
  `eh vector destructor iterator(
    evtFlowArray.Static,
    8ui64,
    32,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent>::~SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent>);
  Scaleform::RefCountNTSImpl::Release(dispObject);
  if ( ((unsigned __int8)this & 1) == 0 )
  {
    RefCount = this->RefCount;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      this->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(this);
    }
  }
}

// File Line: 811
// RVA: 0x7B3320
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CaptureEventFlow(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        Scaleform::GFx::DisplayObject *dispObject,
        Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> *evtFlowArray)
{
  Scaleform::GFx::InteractiveObject *i; // rdi
  char *v5; // rcx
  __int64 v6; // rax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v7; // rbx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> val; // [rsp+48h] [rbp+10h] BYREF

  for ( i = dispObject->pParent; i; i = i->pParent )
  {
    v5 = (char *)i + 4 * (unsigned __int8)i->AvmObjOffset;
    v6 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v5 + 8i64))(v5);
    if ( v6 )
      v6 -= 56i64;
    v7 = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)(v6 + 16);
    if ( !v7 )
      v7 = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)(v6 + 8);
    if ( ((unsigned __int8)v7 & 1) != 0 )
      v7 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v7 - 1);
    if ( v7 )
    {
      val.pObject = v7;
      v7->RefCount = (v7->RefCount + 1) & 0x8FBFFFFF;
      Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>::PushBack(
        evtFlowArray,
        &val);
      if ( ((unsigned __int8)v7 & 1) != 0 )
      {
        val.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v7 - 1);
      }
      else
      {
        RefCount = v7->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v7->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
        }
      }
    }
  }
}

// File Line: 826
// RVA: 0x7C5700
char __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::Instances::fl_events::Event *evtObj,
        bool useCapture)
{
  int v5; // esi
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *pObject; // rcx
  Scaleform::GFx::ASString *p_Type; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v9; // rbx
  __int64 v10; // rax
  unsigned __int64 *v11; // rdi
  _QWORD **v12; // rdi
  char v13; // bl
  _QWORD *v14; // rdi
  unsigned __int64 v15; // rdx
  __int64 v16; // rcx
  int v17; // edx
  _QWORD *v18; // r9
  Scaleform::GFx::AS3::Value::V1U v19; // r8
  Scaleform::GFx::AS3::Value::V2U v20; // r10
  unsigned int Flags; // ebx
  bool v22; // zf
  Scaleform::GFx::AS3::Value *p_func; // rdx
  char v24; // bl
  Scaleform::GFx::AS3::Value::V2U v25; // rax
  int v26; // edx
  __int64 v27; // rdx
  unsigned int v28; // edi
  unsigned int v29; // ebx
  Scaleform::GFx::AS3::Traits *v30; // rcx
  char *v31; // rax
  unsigned __int64 v32; // r15
  unsigned __int64 v33; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *v34; // rcx
  unsigned __int64 v35; // r12
  Scaleform::GFx::AS3::Value::V2U *v36; // rdi
  int VObj; // ecx
  Scaleform::GFx::AS3::Object *v38; // r8
  Scaleform::GFx::AS3::Value::V1U v39; // rdx
  Scaleform::GFx::AS3::Value::V2U v40; // r9
  unsigned int v41; // ebx
  Scaleform::GFx::AS3::Value *p_this; // rdx
  Scaleform::GFx::AS3::Value::V2U v43; // rax
  int v44; // ecx
  Scaleform::GFx::AS3::Value::V2U v45; // rcx
  unsigned int v46; // ebx
  unsigned int v47; // ebx
  Scaleform::GFx::AS3::Traits *v48; // rcx
  char v49; // bl
  unsigned __int64 v50; // r12
  Scaleform::GFx::AS3::Value *v51; // rbx
  unsigned __int64 v52; // r15
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  unsigned int RefCount; // ecx
  Scaleform::GFx::AS3::Value v55; // [rsp+48h] [rbp-B8h] BYREF
  Scaleform::GFx::AS3::Value func; // [rsp+68h] [rbp-98h] BYREF
  Scaleform::GFx::AS3::Value argv; // [rsp+88h] [rbp-78h] BYREF
  Scaleform::GFx::AS3::Value _this; // [rsp+A8h] [rbp-58h] BYREF
  Scaleform::GFx::AS3::Value result; // [rsp+C8h] [rbp-38h] BYREF
  unsigned __int64 i; // [rsp+E8h] [rbp-18h]
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v61; // [rsp+F0h] [rbp-10h]
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *v62; // [rsp+F8h] [rbp-8h]
  char *v63; // [rsp+100h] [rbp+0h]
  __int64 v64; // [rsp+108h] [rbp+8h]
  char v65[48]; // [rsp+110h] [rbp+10h] BYREF
  char v66; // [rsp+2E0h] [rbp+1E0h]
  char *v67; // [rsp+2F8h] [rbp+1F8h]

  v64 = -2i64;
  v5 = 0;
  if ( !this->pImpl.pObject )
    return 1;
  v61 = this;
  this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  if ( useCapture )
    pObject = this->pImpl.pObject;
  else
    pObject = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *)&this->pImpl.pObject->Listeners;
  p_Type = &evtObj->Type;
  v9.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)pObject->CaptureListeners.mHash.pTable;
  if ( pObject->CaptureListeners.mHash.pTable
    && (v10 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)pObject,
                p_Type,
                p_Type->pNode->HashFlags & v9.pTable->SizeMask),
        v10 >= 0)
    && (v11 = &v9.pTable[1].SizeMask + 3 * v10) != 0i64 )
  {
    v12 = (_QWORD **)(v11 + 1);
  }
  else
  {
    v12 = 0i64;
  }
  v13 = 1;
  v66 = 1;
  if ( v12 )
  {
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&evtObj->CurrentTarget,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)this);
    v14 = *v12;
    v15 = v14[1];
    if ( v15 == 1 )
    {
      v16 = *v14;
      if ( (*(_DWORD *)(*v14 + 8i64) & 0x200) == 0 || *(_QWORD *)(*(_QWORD *)(v16 + 16) + 8i64) )
      {
        _this.Flags = 0;
        _this.Bonus.pWeakProxy = 0i64;
        argv.Flags = 12;
        argv.Bonus.pWeakProxy = 0i64;
        argv.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)evtObj;
        if ( evtObj )
          evtObj->RefCount = (evtObj->RefCount + 1) & 0x8FBFFFFF;
        result.Flags = 0;
        result.Bonus.pWeakProxy = 0i64;
        v17 = *(_DWORD *)(v16 + 8);
        if ( (v17 & 0x200) != 0 )
        {
          v55.Bonus.pWeakProxy = 0i64;
          _mm_prefetch((const char *)(v16 + 8), 2);
          *(_QWORD *)&v55.Flags = *(_QWORD *)(v16 + 8);
          v18 = *(_QWORD **)(v16 + 16);
          v55.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v18;
          v19 = *(Scaleform::GFx::AS3::Value::V1U *)(v16 + 24);
          v55.value.VS._1 = v19;
          v20.VObj = *(Scaleform::GFx::AS3::Object **)(v16 + 32);
          v55.value.VS._2 = v20;
          if ( (v17 & 0x1Fu) > 9 )
            ++*(_DWORD *)v18;
          Flags = v55.Flags;
          if ( (v55.Flags & 0x200) != 0 )
          {
            if ( v18[1] )
            {
              if ( (v55.Flags & 0x1F) == 10 )
              {
                ++v19.VStr->RefCount;
              }
              else if ( (v55.Flags & 0x1F) > 0xA )
              {
                if ( (v55.Flags & 0x1F) <= 0xF )
                {
                  if ( v19.VStr )
                    v19.VStr->Size = (v19.VStr->Size + 1) & 0x8FBFFFFF;
                }
                else if ( (v55.Flags & 0x1F) <= 0x11 && v20.VObj )
                {
                  v20.VObj->RefCount = (v20.VObj->RefCount + 1) & 0x8FBFFFFF;
                }
              }
              v22 = (*(_DWORD *)v18)-- == 1;
              if ( v22 )
                Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v18);
            }
            else
            {
              v55.value = 0ui64;
              Flags = v55.Flags & 0xFFFFFFE0;
              v55.Flags &= 0xFFFFFFE0;
            }
            v55.Bonus.pWeakProxy = 0i64;
            v55.Flags = Flags & 0xFFFFFDFF;
          }
          p_func = &v55;
          v24 = 1;
        }
        else
        {
          func.Flags = *(_DWORD *)(v16 + 8);
          func.Bonus.pWeakProxy = *(Scaleform::GFx::AS3::WeakProxy **)(v16 + 16);
          func.value.VS._1.VStr = *(Scaleform::GFx::ASStringNode **)(v16 + 24);
          v25.VObj = *(Scaleform::GFx::AS3::Object **)(v16 + 32);
          func.value.VS._2 = v25;
          v26 = v17 & 0x1F;
          if ( v26 > 9 )
          {
            if ( v26 == 10 )
            {
              ++*(_DWORD *)(*(_QWORD *)(v16 + 24) + 24i64);
            }
            else if ( v26 <= 15 )
            {
              v27 = *(_QWORD *)(v16 + 24);
              if ( v27 )
                *(_DWORD *)(v27 + 32) = (*(_DWORD *)(v27 + 32) + 1) & 0x8FBFFFFF;
            }
            else if ( v26 <= 17 && v25.VObj )
            {
              v25.VObj->RefCount = (v25.VObj->RefCount + 1) & 0x8FBFFFFF;
            }
          }
          p_func = &func;
          v24 = 2;
        }
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
          this->pTraits.pObject->pVM,
          p_func,
          &_this,
          &result,
          1u,
          &argv,
          0);
        if ( (v24 & 2) != 0 )
        {
          v24 &= ~2u;
          v28 = func.Flags;
          if ( (func.Flags & 0x1F) > 9 )
          {
            if ( (func.Flags & 0x200) != 0 )
            {
              v22 = func.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v22 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              memset(&func.Bonus, 0, 24);
              func.Flags = v28 & 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
            }
          }
        }
        if ( (v24 & 1) != 0 )
        {
          v29 = v55.Flags;
          if ( (v55.Flags & 0x1F) > 9 )
          {
            if ( (v55.Flags & 0x200) != 0 )
            {
              v22 = v55.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v22 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              memset(&v55.Bonus, 0, 24);
              v55.Flags = v29 & 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v55);
            }
          }
        }
        v30 = this->pTraits.pObject;
        if ( v30->pVM->HandleException )
        {
          Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v30->pVM);
          v13 = 0;
        }
        else
        {
          v13 = 1;
        }
        if ( (result.Flags & 0x1F) > 9 )
        {
          if ( (result.Flags & 0x200) != 0 )
          {
            v22 = result.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v22 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&result.Bonus, 0, 24);
            result.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
          }
        }
        if ( (argv.Flags & 0x1F) > 9 )
        {
          if ( (argv.Flags & 0x200) != 0 )
          {
            v22 = argv.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v22 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&argv.Bonus, 0, 24);
            argv.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&argv);
          }
        }
        if ( (_this.Flags & 0x1F) > 9 )
        {
          if ( (_this.Flags & 0x200) != 0 )
          {
            v22 = _this.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v22 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&_this.Bonus, 0, 24);
            _this.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
          }
        }
      }
    }
    else if ( v15 > 1 )
    {
      if ( v15 > 0xA )
        v31 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                        Scaleform::Memory::pGlobalHeap,
                        this,
                        40 * v15,
                        0i64);
      else
        v31 = v65;
      v67 = v31;
      v32 = v14[1];
      v63 = v31;
      v33 = 0i64;
      for ( i = 0i64; v33 < v32; i = v33 )
      {
        v34 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *)&v31[40 * v33];
        v62 = v34;
        if ( v34 )
        {
          Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener::Listener(
            v34,
            (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *)(*v14 + 40 * v33));
          v31 = v67;
        }
        ++v33;
      }
      v35 = 0i64;
      if ( v32 )
      {
        v36 = (Scaleform::GFx::AS3::Value::V2U *)(v31 + 32);
        do
        {
          if ( ((__int64)v36[-3].VObj & 0x200) == 0 || v36[-2].VObj->pRCCRaw )
          {
            func.Flags = 0;
            func.Bonus.pWeakProxy = 0i64;
            argv.Flags = 0;
            argv.Bonus.pWeakProxy = 0i64;
            v55.Flags = 12;
            v55.Bonus.pWeakProxy = 0i64;
            v55.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)evtObj;
            if ( evtObj )
              evtObj->RefCount = (evtObj->RefCount + 1) & 0x8FBFFFFF;
            VObj = (int)v36[-3].VObj;
            if ( (VObj & 0x200) != 0 )
            {
              _this.Bonus.pWeakProxy = 0i64;
              _mm_prefetch((const char *)&v36[-3], 2);
              *(Scaleform::GFx::AS3::Value::V2U *)&_this.Flags = v36[-3];
              v38 = v36[-2].VObj;
              _this.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v38;
              v39 = (Scaleform::GFx::AS3::Value::V1U)v36[-1].VObj;
              _this.value.VS._1 = v39;
              v40.VObj = v36->VObj;
              _this.value.VS._2 = (Scaleform::GFx::AS3::Value::V2U)v36->VObj;
              if ( (VObj & 0x1Fu) > 9 )
                ++LODWORD(v38->vfptr);
              v41 = _this.Flags;
              if ( (_this.Flags & 0x200) != 0 )
              {
                if ( v38->pRCCRaw )
                {
                  if ( (_this.Flags & 0x1F) == 10 )
                  {
                    ++v39.VStr->RefCount;
                  }
                  else if ( (_this.Flags & 0x1F) > 0xA )
                  {
                    if ( (_this.Flags & 0x1F) <= 0xF )
                    {
                      if ( v39.VStr )
                        v39.VStr->Size = (v39.VStr->Size + 1) & 0x8FBFFFFF;
                    }
                    else if ( (_this.Flags & 0x1F) <= 0x11 && v40.VObj )
                    {
                      v40.VObj->RefCount = (v40.VObj->RefCount + 1) & 0x8FBFFFFF;
                    }
                  }
                  v22 = LODWORD(v38->vfptr)-- == 1;
                  if ( v22 )
                    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v38);
                }
                else
                {
                  _this.value = 0ui64;
                  v41 = _this.Flags & 0xFFFFFFE0;
                  _this.Flags &= 0xFFFFFFE0;
                }
                _this.Bonus.pWeakProxy = 0i64;
                _this.Flags = v41 & 0xFFFFFDFF;
              }
              p_this = &_this;
              v5 |= 4u;
            }
            else
            {
              result.Flags = (unsigned int)v36[-3].VObj;
              result.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v36[-2].VObj;
              result.value.VS._1.VObj = v36[-1].VObj;
              v43.VObj = v36->VObj;
              result.value.VS._2 = (Scaleform::GFx::AS3::Value::V2U)v36->VObj;
              v44 = VObj & 0x1F;
              if ( v44 > 9 )
              {
                if ( v44 == 10 )
                {
                  ++LODWORD(v36[-1].VObj->pPrev);
                }
                else if ( v44 <= 15 )
                {
                  v45.VObj = v36[-1].VObj;
                  if ( v45.VObj )
                    v45.VObj->RefCount = (v45.VObj->RefCount + 1) & 0x8FBFFFFF;
                }
                else if ( v44 <= 17 && v43.VObj )
                {
                  v43.VObj->RefCount = (v43.VObj->RefCount + 1) & 0x8FBFFFFF;
                }
              }
              p_this = &result;
              v5 |= 8u;
            }
            Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
              this->pTraits.pObject->pVM,
              p_this,
              &func,
              &argv,
              1u,
              &v55,
              0);
            if ( (v5 & 8) != 0 )
            {
              v5 &= ~8u;
              v46 = result.Flags;
              if ( (result.Flags & 0x1F) > 9 )
              {
                if ( (result.Flags & 0x200) != 0 )
                {
                  v22 = result.Bonus.pWeakProxy->RefCount-- == 1;
                  if ( v22 )
                    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                  memset(&result.Bonus, 0, 24);
                  result.Flags = v46 & 0xFFFFFDE0;
                }
                else
                {
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
                }
              }
            }
            if ( (v5 & 4) != 0 )
            {
              v5 &= ~4u;
              v47 = _this.Flags;
              if ( (_this.Flags & 0x1F) > 9 )
              {
                if ( (_this.Flags & 0x200) != 0 )
                {
                  v22 = _this.Bonus.pWeakProxy->RefCount-- == 1;
                  if ( v22 )
                    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                  memset(&_this.Bonus, 0, 24);
                  _this.Flags = v47 & 0xFFFFFDE0;
                }
                else
                {
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
                }
              }
            }
            v48 = this->pTraits.pObject;
            if ( v48->pVM->HandleException )
            {
              Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v48->pVM);
              v49 = 0;
              v66 = 0;
            }
            else
            {
              v49 = v66;
            }
            Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::~HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>((Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *)&v36[-4]);
            if ( (*((_BYTE *)evtObj + 84) & 0x10) != 0 || !v49 )
            {
              if ( (v55.Flags & 0x1F) > 9 )
              {
                if ( (v55.Flags & 0x200) != 0 )
                {
                  v22 = v55.Bonus.pWeakProxy->RefCount-- == 1;
                  if ( v22 )
                    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                  memset(&v55.Bonus, 0, 24);
                  v55.Flags &= 0xFFFFFDE0;
                }
                else
                {
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&v55);
                }
              }
              if ( (argv.Flags & 0x1F) > 9 )
              {
                if ( (argv.Flags & 0x200) != 0 )
                {
                  v22 = argv.Bonus.pWeakProxy->RefCount-- == 1;
                  if ( v22 )
                    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                  memset(&argv.Bonus, 0, 24);
                  argv.Flags &= 0xFFFFFDE0;
                }
                else
                {
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&argv);
                }
              }
              if ( (func.Flags & 0x1F) > 9 )
              {
                if ( (func.Flags & 0x200) != 0 )
                {
                  v22 = func.Bonus.pWeakProxy->RefCount-- == 1;
                  if ( v22 )
                    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                  memset(&func.Bonus, 0, 24);
                  func.Flags &= 0xFFFFFDE0;
                }
                else
                {
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
                }
              }
              break;
            }
            if ( (v55.Flags & 0x1F) > 9 )
            {
              if ( (v55.Flags & 0x200) != 0 )
              {
                v22 = v55.Bonus.pWeakProxy->RefCount-- == 1;
                if ( v22 )
                  ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                memset(&v55.Bonus, 0, 24);
                v55.Flags &= 0xFFFFFDE0;
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(&v55);
              }
            }
            if ( (argv.Flags & 0x1F) > 9 )
            {
              if ( (argv.Flags & 0x200) != 0 )
              {
                v22 = argv.Bonus.pWeakProxy->RefCount-- == 1;
                if ( v22 )
                  ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                memset(&argv.Bonus, 0, 24);
                argv.Flags &= 0xFFFFFDE0;
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(&argv);
              }
            }
            if ( (func.Flags & 0x1F) > 9 )
            {
              if ( (func.Flags & 0x200) != 0 )
              {
                v22 = func.Bonus.pWeakProxy->RefCount-- == 1;
                if ( v22 )
                  ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                memset(&func.Bonus, 0, 24);
                func.Flags &= 0xFFFFFDE0;
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
              }
            }
          }
          else
          {
            Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::~HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>((Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *)&v36[-4]);
          }
          ++v35;
          v36 += 5;
        }
        while ( v35 < v32 );
      }
      v50 = v35 + 1;
      if ( v50 < v32 )
      {
        v51 = (Scaleform::GFx::AS3::Value *)&v67[32 * v50 + 8 + 8 * v50];
        v52 = v32 - v50;
        do
        {
          if ( (v51->Flags & 0x1F) > 9 )
          {
            if ( (v51->Flags & 0x200) != 0 )
            {
              pWeakProxy = v51->Bonus.pWeakProxy;
              v22 = pWeakProxy->RefCount-- == 1;
              if ( v22 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              v51->Bonus.pWeakProxy = 0i64;
              v51->value.VS._1.VStr = 0i64;
              v51->value.VS._2.VObj = 0i64;
              v51->Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(v51);
            }
          }
          v51 = (Scaleform::GFx::AS3::Value *)((char *)v51 + 40);
          --v52;
        }
        while ( v52 );
      }
      if ( v67 != v65 )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v67);
      v13 = v66;
    }
  }
  if ( ((unsigned __int8)this & 1) != 0 )
  {
    v61 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)this - 1);
  }
  else
  {
    RefCount = this->RefCount;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      this->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(this);
    }
  }
  return v13;
}

// File Line: 929
// RVA: 0x7C6240
char __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchToTarget(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        Scaleform::GFx::ASString *type,
        Scaleform::GFx::AS3::Instances::fl::XMLList *target,
        bool useCapture,
        Scaleform::GFx::DisplayObject *dispObject)
{
  Scaleform::GFx::AS3::Traits *pObject; // rbx
  Scaleform::GFx::AS3::VM *pVM; // rax
  Scaleform::GFx::AS3::ASVM *v11; // rdi
  Scaleform::GFx::LogState *v12; // rbx
  const char *pData; // rbx
  Scaleform::GFx::LogState *LogState; // rax
  bool v16; // bl
  Scaleform::GFx::AS3::Instances::fl_events::Event *v17; // rcx
  unsigned int RefCount; // edx
  Scaleform::Ptr<Scaleform::GFx::LogState> result; // [rsp+30h] [rbp-28h] BYREF
  __int64 v20; // [rsp+38h] [rbp-20h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> v21; // [rsp+60h] [rbp+8h] BYREF

  v20 = -2i64;
  if ( !this->pImpl.pObject )
    return 1;
  pObject = this->pTraits.pObject;
  pVM = pObject->pVM;
  if ( pVM->HandleException )
  {
    v11 = (Scaleform::GFx::AS3::ASVM *)pObject->pVM;
    v12 = Scaleform::GFx::StateBag::GetLogState((Scaleform::GFx::StateBag *)pVM[1].vfptr[2].__vecDelDtor + 2, &result)->pObject;
    if ( result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
    if ( v12 )
    {
      pData = type->pNode->pData;
      LogState = Scaleform::GFx::AS3::ASVM::GetLogState(v11);
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptError(
        &LogState->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
        "Cant dispatch %s - exception is not cleared",
        pData);
    }
    return 1;
  }
  if ( !pObject->pConstructor.pObject )
    pObject->vfptr[3].~RefCountBaseGC<328>(this->pTraits.pObject);
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateEventObject(
    (Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *)pObject->pConstructor.pObject,
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v21,
    type,
    0,
    0);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v21.pObject->Target,
    target);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v21.pObject->CurrentTarget,
    target);
  if ( !Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(this, v21.pObject, useCapture)
    && dispObject )
  {
    dispObject->Flags |= 0x20u;
  }
  v16 = (*((_BYTE *)v21.pObject + 84) & 4) == 0;
  v17 = v21.pObject;
  if ( v21.pObject )
  {
    if ( ((__int64)v21.pObject & 1) != 0 )
    {
      --v21.pObject;
    }
    else
    {
      RefCount = v21.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v21.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v17);
      }
    }
  }
  return v16;
}

// File Line: 981
// RVA: 0x7F1FD0
char __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::HasEventHandler(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        Scaleform::GFx::ASString *type,
        bool useCapture)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *pObject; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v4; // rbx
  __int64 v5; // rax
  unsigned __int64 *v6; // rax
  __int64 *v7; // rax
  __int64 v8; // rax

  pObject = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)this->pImpl.pObject;
  if ( !pObject )
    return 0;
  if ( !useCapture )
    ++pObject;
  v4.pTable = pObject->pTable;
  if ( pObject->pTable
    && (v5 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               pObject,
               type,
               v4.pTable->SizeMask & type->pNode->HashFlags),
        v5 >= 0)
    && (v6 = &v4.pTable[1].SizeMask + 3 * v5) != 0i64
    && (v7 = (__int64 *)(v6 + 1)) != 0i64
    && (v8 = *v7) != 0
    && *(_QWORD *)(v8 + 8) )
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

// File Line: 994
// RVA: 0x82A110
char __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::WillTrigger(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        Scaleform::GFx::ASString *type,
        bool useCapture)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *pObject; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v7; // rbx
  __int64 v8; // rax
  unsigned __int64 *v9; // rax
  __int64 *v10; // rax
  __int64 v11; // rax
  Scaleform::GFx::AS3::Traits *v13; // rcx
  Scaleform::GFx::AS3::RefCountCollector<328> *pRCC; // rbx
  __int64 v15; // rbx
  __int64 v16; // rcx
  __int64 v17; // rax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v18; // rcx

  pObject = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)this->pImpl.pObject;
  if ( pObject )
  {
    if ( !useCapture )
      ++pObject;
    v7.pTable = pObject->pTable;
    if ( pObject->pTable )
    {
      v8 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
             pObject,
             type,
             v7.pTable->SizeMask & type->pNode->HashFlags);
      if ( v8 >= 0 )
      {
        v9 = &v7.pTable[1].SizeMask + 3 * v8;
        if ( v9 )
        {
          v10 = (__int64 *)(v9 + 1);
          if ( v10 )
          {
            v11 = *v10;
            if ( v11 )
            {
              if ( *(_QWORD *)(v11 + 8) )
                return 1;
            }
          }
        }
      }
    }
  }
  v13 = this->pTraits.pObject;
  if ( (unsigned int)(v13->TraitsType - 22) <= 0xC && (v13->Flags & 0x20) == 0 )
  {
    pRCC = this[1]._pRCC;
    if ( pRCC )
    {
      v15 = *(_QWORD *)&pRCC->Roots[2].nRoots;
      if ( v15 )
      {
        while ( 1 )
        {
          v16 = v15 + 4i64 * *(unsigned __int8 *)(v15 + 109);
          v17 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v16 + 8i64))(v16);
          if ( v17 )
            v17 -= 56i64;
          v18 = *(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher **)(v17 + 16);
          if ( !v18 )
            v18 = *(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher **)(v17 + 8);
          if ( ((unsigned __int8)v18 & 1) != 0 )
            v18 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)v18 - 1);
          if ( v18 && Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::HasEventHandler(v18, type, useCapture) )
            break;
          v15 = *(_QWORD *)(v15 + 56);
          if ( !v15 )
            return 0;
        }
        return 1;
      }
    }
  }
  return 0;
}

// File Line: 1021
// RVA: 0x805260
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::OnRemoveEventListener(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        Scaleform::GFx::ASString *evtType,
        bool useCapture,
        unsigned __int64 listenersArrSize)
{
  __int64 v5; // r11
  _QWORD *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rdx
  Scaleform::GFx::EventId::IdCode v8; // edx
  Scaleform::GFx::AS3::Traits *pObject; // rcx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *v10; // rcx
  char CaptureButtonHandlersCnt; // al
  char ButtonHandlersCnt; // al

  v5 = *(_QWORD *)(((unsigned __int64)this->pTraits.pObject & 0xFFFFFFFFFFFFFFFEui64) + 128);
  v6 = *(_QWORD **)(v5 + 744);
  if ( !v6 )
    return;
  pNode = evtType->pNode;
  if ( pNode == (Scaleform::GFx::ASStringNode *)v6[79] )
  {
    v8 = Event_EnterFrame;
    *(_DWORD *)(v6[2] + 21200i64) |= 0x80000u;
LABEL_14:
    if ( !listenersArrSize )
    {
      pObject = this->pTraits.pObject;
      if ( (unsigned int)(pObject->TraitsType - 22) <= 0xC && (pObject->Flags & 0x20) == 0 )
        Scaleform::GFx::AS3::EventChains::RemoveFromChain(
          (Scaleform::GFx::AS3::EventChains *)(*(_QWORD *)(v5 + 744) + 344i64),
          v8,
          (Scaleform::GFx::DisplayObject *)this[1]._pRCC);
    }
    return;
  }
  if ( pNode == (Scaleform::GFx::ASStringNode *)v6[80] )
  {
    v8 = Event_FrameConstructed;
    goto LABEL_14;
  }
  if ( pNode == (Scaleform::GFx::ASStringNode *)v6[81] )
  {
    v8 = Event_ExitFrame;
    goto LABEL_14;
  }
  if ( pNode == (Scaleform::GFx::ASStringNode *)v6[73] )
  {
    v8 = Event_Activate;
    goto LABEL_14;
  }
  if ( pNode == (Scaleform::GFx::ASStringNode *)v6[78] )
  {
    v8 = Event_Deactivate;
    goto LABEL_14;
  }
  if ( pNode == (Scaleform::GFx::ASStringNode *)v6[89] )
  {
    v8 = Event_Render;
    goto LABEL_14;
  }
  if ( (Scaleform::GFx::ASStringNode *)v6[94] == pNode
    || (Scaleform::GFx::ASStringNode *)v6[98] == pNode
    || (Scaleform::GFx::ASStringNode *)v6[92] == pNode
    || (Scaleform::GFx::ASStringNode *)v6[93] == pNode
    || (Scaleform::GFx::ASStringNode *)v6[97] == pNode
    || (Scaleform::GFx::ASStringNode *)v6[96] == pNode
    || (Scaleform::GFx::ASStringNode *)v6[101] == pNode
    || (Scaleform::GFx::ASStringNode *)v6[100] == pNode )
  {
    v10 = this->pImpl.pObject;
    if ( useCapture )
    {
      CaptureButtonHandlersCnt = v10->CaptureButtonHandlersCnt;
      if ( CaptureButtonHandlersCnt != -1 )
        v10->CaptureButtonHandlersCnt = CaptureButtonHandlersCnt - 1;
    }
    else
    {
      ButtonHandlersCnt = v10->ButtonHandlersCnt;
      if ( ButtonHandlersCnt != -1 )
        v10->ButtonHandlersCnt = ButtonHandlersCnt - 1;
    }
  }
}

// File Line: 1094
// RVA: 0x811BE0
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::RemoveListenersForMovieDef(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        Scaleform::GFx::MovieDefImpl *defimpl,
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash *hash)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash *v3; // r12
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // r9
  unsigned __int64 v6; // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v7; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v8; // rdi
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> *v9; // rdi
  unsigned __int64 v10; // rbp
  __int64 v11; // r14
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *Data; // r8
  Scaleform::GFx::AS3::Value *p_mFunction; // rdx
  int v14; // ecx
  Scaleform::GFx::AS3::Traits *ValueTraits; // rax
  __int64 v16; // rax
  Scaleform::GFx::AS3::Traits *pTraits; // rcx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *v18; // rbx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  unsigned __int64 SizeMask; // rdx
  unsigned __int64 *v22; // rcx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash *v24; // [rsp+80h] [rbp+18h]

  v3 = hash;
  v24 = hash;
  pTable = hash->mHash.pTable;
  v6 = 0i64;
  if ( hash->mHash.pTable )
  {
    v7 = pTable + 1;
    do
    {
      if ( v7->EntryCount != -2i64 )
        break;
      ++v6;
      v7 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)((char *)v7 + 24);
    }
    while ( v6 <= pTable->SizeMask );
  }
  else
  {
    v3 = 0i64;
    v24 = 0i64;
  }
  while ( v3 )
  {
    v8 = v3->mHash.pTable;
    if ( !v3->mHash.pTable || (signed __int64)v6 > (signed __int64)v8->SizeMask )
      break;
    v9 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> *)*(&v8[2].EntryCount + 3 * v6);
    v10 = 0i64;
    if ( !v9->Size )
      goto LABEL_33;
    v11 = 0i64;
    do
    {
      Data = v9->Data;
      p_mFunction = &v9->Data[v11].mFunction;
      if ( (p_mFunction->Flags & 0x200) != 0 && !p_mFunction->Bonus.pWeakProxy->pObject )
      {
LABEL_30:
        ++v10;
        ++v11;
        continue;
      }
      v14 = p_mFunction->Flags & 0x1F;
      if ( v14 == 7 )
      {
        pTraits = Data[v11].mFunction.value.VS._2.pTraits;
        goto LABEL_18;
      }
      if ( v14 == 17 )
      {
        pTraits = Data[v11].mFunction.value.VS._2.VObj->pTraits.pObject;
LABEL_18:
        v16 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *))pTraits->vfptr[2].~RefCountBaseGC<328>)(pTraits);
        goto LABEL_19;
      }
      ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(this->pTraits.pObject->pVM, p_mFunction);
      v16 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *))ValueTraits->vfptr[2].~RefCountBaseGC<328>)(ValueTraits);
LABEL_19:
      if ( !v16 || *(Scaleform::GFx::MovieDefImpl **)(*(_QWORD *)(v16 + 152) + 368i64) != defimpl )
        goto LABEL_30;
      if ( v9->Size == 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          v9,
          v9,
          0i64);
      }
      else
      {
        v18 = &v9->Data[v11];
        if ( (v18->mFunction.Flags & 0x1F) > 9 )
        {
          if ( (v18->mFunction.Flags & 0x200) != 0 )
          {
            pWeakProxy = v18->mFunction.Bonus.pWeakProxy;
            if ( pWeakProxy->RefCount-- == 1 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            v18->mFunction.Bonus.pWeakProxy = 0i64;
            v18->mFunction.value.VS._1.VStr = 0i64;
            v18->mFunction.value.VS._2.VObj = 0i64;
            v18->mFunction.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v18->mFunction);
          }
        }
        memmove(&v9->Data[v11], &v9->Data[v11 + 1], 40 * (v9->Size - v10 - 1));
        --v9->Size;
      }
    }
    while ( v10 < v9->Size );
    v3 = v24;
LABEL_33:
    SizeMask = v3->mHash.pTable->SizeMask;
    if ( (__int64)v6 <= (__int64)SizeMask && ++v6 <= SizeMask )
    {
      v22 = &v3->mHash.pTable[1].EntryCount + 3 * v6;
      do
      {
        if ( *v22 != -2i64 )
          break;
        ++v6;
        v22 += 3;
      }
      while ( v6 <= SizeMask );
    }
  }
}

// File Line: 1169
// RVA: 0x77CE10
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher::EventDispatcher(
        Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::ClassInfo *ci)
{
  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(this, vm, ci);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher::`vftable;
}

// File Line: 1176
// RVA: 0x7FF520
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 1195
// RVA: 0x7D56F0
void __fastcall Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::ForEachChild_GC(
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  Scaleform::GFx::AS3::Object::ForEachChild_GC(this, prcc, op);
  if ( this->ParentClass.pObject )
    op(prcc, &this->ParentClass.pObject);
  if ( this->pPrototype.pObject )
    op(prcc, &this->pPrototype.pObject);
  if ( this->EventTraits.pObject )
    op(prcc, &this->EventTraits.pObject);
  if ( this->MouseEventTraits.pObject )
    op(prcc, &this->MouseEventTraits.pObject);
}

// File Line: 1211
// RVA: 0x7BC890
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateEventObject(
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        Scaleform::GFx::ASString *type,
        bool bubbles,
        bool cancelable)
{
  Scaleform::GFx::AS3::Value ptr; // [rsp+40h] [rbp-88h] BYREF
  int v8; // [rsp+60h] [rbp-68h]
  __int64 v9; // [rsp+68h] [rbp-60h]
  bool v10; // [rsp+70h] [rbp-58h]
  int v11; // [rsp+80h] [rbp-48h]
  __int64 v12; // [rsp+88h] [rbp-40h]
  bool v13; // [rsp+90h] [rbp-38h]
  __int64 v14; // [rsp+A0h] [rbp-28h]
  Scaleform::GFx::AS3::Value::VU v15; // [rsp+A8h] [rbp-20h]

  v14 = -2i64;
  result->pObject = 0i64;
  ptr.Flags = 10;
  ptr.Bonus.pWeakProxy = 0i64;
  *(Scaleform::GFx::ASString *)&ptr.value.VNumber = (Scaleform::GFx::ASString)type->pNode;
  if ( ptr.value.VS._1.VStr == &ptr.value.VS._1.VStr->pManager->NullStringNode )
  {
    v15.VS._1.VStr = 0i64;
    ptr.value = v15;
    ptr.Flags = 12;
  }
  else
  {
    ++ptr.value.VS._1.VStr->RefCount;
  }
  v8 = 1;
  v9 = 0i64;
  v10 = bubbles;
  v11 = 1;
  v12 = 0i64;
  v13 = cancelable;
  Scaleform::GFx::AS3::ASVM::_constructInstance(
    (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM,
    result,
    (Scaleform::GFx::AS3::Object *)this->pTraits.pObject->pVM[1].XMLSupport_.pObject,
    3u,
    &ptr);
  `eh vector destructor iterator(&ptr, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  return result;
}

// File Line: 1246
// RVA: 0x7BDDC0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        Scaleform::GFx::EventId *evtId,
        Scaleform::GFx::ASString *type,
        Scaleform::GFx::AS3::Instances::fl::XMLList *target)
{
  Scaleform::GFx::ASStringNode *pNode; // rdx
  Scaleform::GFx::AS3::ASVM *pVM; // rsi
  Scaleform::GFx::AS3::Object **p_pObject; // r8
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *pObject; // rax
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v12; // rcx
  __int64 ControllerIndex; // rax
  char *v14; // rsi
  float v15; // xmm1_4
  unsigned int Id; // eax
  unsigned int v17; // ecx
  Scaleform::GFx::AS3::Value argv; // [rsp+40h] [rbp-20h] BYREF
  Scaleform::Render::Point<float> p; // [rsp+90h] [rbp+30h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *v22; // [rsp+98h] [rbp+38h]

  v22 = result;
  result->pObject = 0i64;
  argv.Flags = 10;
  argv.Bonus.pWeakProxy = 0i64;
  pNode = type->pNode;
  argv.value.VS._1.VStr = pNode;
  if ( pNode == &pNode->pManager->NullStringNode )
  {
    argv.value.VS._1.VStr = 0i64;
    argv.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)argv.Bonus.pWeakProxy;
    argv.Flags = 12;
  }
  else
  {
    ++pNode->RefCount;
  }
  pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  p_pObject = &pVM->MouseEventExClass.pObject;
  if ( !pVM->ExtensionsEnabled )
    p_pObject = &pVM->MouseEventClass.pObject;
  Scaleform::GFx::AS3::ASVM::_constructInstance(pVM, result, *p_pObject, 1u, &argv);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&result->pObject[1].16,
    target);
  pObject = (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)result->pObject;
  if ( ((evtId->Id - 0x2000) & 0xFFFFDFFF) != 0 )
    *((_BYTE *)&pObject->Scaleform::GFx::AS3::Instances::fl_events::Event + 84) |= 1u;
  else
    *((_BYTE *)&pObject->Scaleform::GFx::AS3::Instances::fl_events::Event + 84) &= ~1u;
  BYTE4(result->pObject[1].pPrevRoot) &= ~2u;
  BYTE4(result->pObject[2].pRCCRaw) = (evtId->KeysState.States & 4) != 0;
  BYTE5(result->pObject[2].pRCCRaw) = (evtId->KeysState.States & 2) != 0;
  BYTE6(result->pObject[2].pRCCRaw) = evtId->KeysState.States & 1;
  result->pObject[1].RefCount = evtId->MouseWheelDelta;
  if ( pVM->ExtensionsEnabled )
  {
    v12 = (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)result->pObject;
    LODWORD(v12[1].vfptr) = evtId->ControllerIndex;
    LODWORD(v12[1]._pRCC) = (unsigned __int8)evtId->RollOverCnt;
    HIDWORD(v12[1].vfptr) = (unsigned __int8)evtId->AsciiCode;
  }
  ControllerIndex = (unsigned int)evtId->ControllerIndex;
  if ( (unsigned int)ControllerIndex < 6 )
    v14 = (char *)this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor + 80 * ControllerIndex + 8696;
  else
    v14 = 0i64;
  v15 = *((float *)v14 + 15);
  p.x = *((float *)v14 + 14);
  p.y = v15;
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent::SetStageCoords(
    (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)result->pObject,
    &p);
  Id = evtId->Id;
  if ( evtId->Id == 0x2000 || Id == 0x4000 || Id - 16777226 <= 1 )
    v17 = *((_DWORD *)v14 + 13);
  else
    v17 = *((_DWORD *)v14 + 12);
  LODWORD(result->pObject[2]._pRCC) = v17;
  if ( (argv.Flags & 0x1F) > 9 )
  {
    if ( (argv.Flags & 0x200) != 0 )
    {
      if ( argv.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&argv.Bonus, 0, 24);
      argv.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&argv);
    }
  }
  return result;
}

// File Line: 1300
// RVA: 0x7BD800
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateKeyboardEventObject(
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        Scaleform::GFx::EventId *evtId,
        Scaleform::GFx::ASString *type,
        Scaleform::GFx::AS3::Instances::fl::XMLList *target)
{
  Scaleform::GFx::AS3::ASVM *pVM; // rdi
  Scaleform::GFx::AS3::Object **p_pObject; // r8
  Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *pObject; // rbp
  Scaleform::GFx::EventId *p_RefCount; // rcx
  Scaleform::GFx::AS3::Value argv; // [rsp+40h] [rbp-38h] BYREF

  result->pObject = 0i64;
  argv.Flags = 10;
  argv.Bonus.pWeakProxy = 0i64;
  *(Scaleform::GFx::ASString *)&argv.value.VNumber = (Scaleform::GFx::ASString)type->pNode;
  if ( argv.value.VS._1.VStr == &argv.value.VS._1.VStr->pManager->NullStringNode )
  {
    argv.value = 0ui64;
    argv.Flags = 12;
  }
  else
  {
    ++argv.value.VS._1.VStr->RefCount;
  }
  pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  p_pObject = &pVM->KeyboardEventExClass.pObject;
  if ( !pVM->ExtensionsEnabled )
    p_pObject = &pVM->KeyboardEventClass.pObject;
  Scaleform::GFx::AS3::ASVM::_constructInstance(pVM, result, *p_pObject, 1u, &argv);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&result->pObject[1].16,
    target);
  pObject = (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *)result->pObject;
  p_RefCount = (Scaleform::GFx::EventId *)&result->pObject[1].RefCount;
  p_RefCount->Id = evtId->Id;
  p_RefCount->WcharCode = evtId->WcharCode;
  p_RefCount->KeyCode = evtId->KeyCode;
  p_RefCount->AsciiCode = evtId->AsciiCode;
  p_RefCount->RollOverCnt = evtId->RollOverCnt;
  p_RefCount->ControllerIndex = evtId->ControllerIndex;
  p_RefCount->KeysState.States = evtId->KeysState.States;
  p_RefCount->MouseWheelDelta = evtId->MouseWheelDelta;
  if ( !pObject->EvtId.AsciiCode )
    pObject->EvtId.AsciiCode = Scaleform::GFx::EventId::ConvertKeyCodeToAscii(p_RefCount);
  BYTE4(result->pObject[1].pPrevRoot) |= 1u;
  BYTE4(result->pObject[1].pPrevRoot) &= ~2u;
  if ( pVM->ExtensionsEnabled )
    LODWORD(result->pObject[2].vfptr) = evtId->ControllerIndex;
  if ( (argv.Flags & 0x1F) > 9 )
  {
    if ( (argv.Flags & 0x200) != 0 )
    {
      if ( argv.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&argv.Bonus, 0, 24);
      argv.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&argv);
    }
  }
  return result;
}

// File Line: 1342
// RVA: 0x7BF460
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateStatusEventObject(
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        Scaleform::GFx::EventId *evtId,
        Scaleform::GFx::ASString *type,
        Scaleform::GFx::AS3::Instances::fl::XMLList *target)
{
  Scaleform::GFx::AS3::Value argv; // [rsp+40h] [rbp-28h] BYREF

  result->pObject = 0i64;
  argv.Flags = 10;
  argv.Bonus.pWeakProxy = 0i64;
  *(Scaleform::GFx::ASString *)&argv.value.VNumber = (Scaleform::GFx::ASString)type->pNode;
  if ( argv.value.VS._1.VStr == &argv.value.VS._1.VStr->pManager->NullStringNode )
  {
    argv.value.VS._1.VStr = 0i64;
    argv.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)argv.Bonus.pWeakProxy;
    argv.Flags = 12;
  }
  else
  {
    ++argv.value.VS._1.VStr->RefCount;
  }
  Scaleform::GFx::AS3::ASVM::_constructInstance(
    (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM,
    result,
    (Scaleform::GFx::AS3::Object *)this->pTraits.pObject->pVM[1].ScopeStack.Data.pHeap,
    1u,
    &argv);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&result->pObject[1].16,
    target);
  BYTE4(result->pObject[1].pPrevRoot) |= 1u;
  BYTE4(result->pObject[1].pPrevRoot) &= ~2u;
  Scaleform::GFx::ASString::operator=(
    (Scaleform::GFx::ASString *)&result->pObject[1].RefCount,
    (const char *)((**(_QWORD **)&evtId[1].WcharCode & 0xFFFFFFFFFFFFFFFCui64) + 12));
  Scaleform::GFx::ASString::operator=(
    (Scaleform::GFx::ASString *)&result->pObject[1].pTraits,
    (const char *)((**(_QWORD **)&evtId[1].AsciiCode & 0xFFFFFFFFFFFFFFFCui64) + 12));
  if ( (argv.Flags & 0x1F) > 9 )
  {
    if ( (argv.Flags & 0x200) != 0 )
    {
      if ( argv.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&argv.Bonus, 0, 24);
      argv.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&argv);
    }
  }
  return result;
}

// File Line: 1360
// RVA: 0x7BB7B0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateAccelerometerEventObject(
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        Scaleform::GFx::EventId *evtId,
        Scaleform::GFx::ASString *type,
        Scaleform::GFx::AS3::Instances::fl::XMLList *target)
{
  Scaleform::GFx::AS3::Value argv; // [rsp+40h] [rbp-28h] BYREF

  result->pObject = 0i64;
  argv.Flags = 10;
  argv.Bonus.pWeakProxy = 0i64;
  *(Scaleform::GFx::ASString *)&argv.value.VNumber = (Scaleform::GFx::ASString)type->pNode;
  if ( argv.value.VS._1.VStr == &argv.value.VS._1.VStr->pManager->NullStringNode )
  {
    argv.value.VS._1.VStr = 0i64;
    argv.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)argv.Bonus.pWeakProxy;
    argv.Flags = 12;
  }
  else
  {
    ++argv.value.VS._1.VStr->RefCount;
  }
  Scaleform::GFx::AS3::ASVM::_constructInstance(
    (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM,
    result,
    *(Scaleform::GFx::AS3::Object **)&this->pTraits.pObject->pVM[1].HandleException,
    1u,
    &argv);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&result->pObject[1].16,
    target);
  BYTE4(result->pObject[1].pPrevRoot) |= 1u;
  BYTE4(result->pObject[1].pPrevRoot) &= ~2u;
  result->pObject[2].vfptr = *(Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl **)&evtId[1].WcharCode;
  *(_QWORD *)&result->pObject[1].RefCount = *(_QWORD *)&evtId[1].AsciiCode;
  result->pObject[1].pTraits.pObject = *(Scaleform::GFx::AS3::Traits **)&evtId[2].Id;
  result->pObject[1].DynAttrs.mHash.pTable = *(Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType **)&evtId[2].KeyCode;
  if ( (argv.Flags & 0x1F) > 9 )
  {
    if ( (argv.Flags & 0x200) != 0 )
    {
      if ( argv.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&argv.Bonus, 0, 24);
      argv.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&argv);
    }
  }
  return result;
}

// File Line: 1381
// RVA: 0x7BCEB0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateGeolocationEventObject(
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        Scaleform::GFx::EventId *evtId,
        Scaleform::GFx::ASString *type,
        Scaleform::GFx::AS3::Instances::fl::XMLList *target)
{
  Scaleform::GFx::AS3::Value argv; // [rsp+40h] [rbp-28h] BYREF

  result->pObject = 0i64;
  argv.Flags = 10;
  argv.Bonus.pWeakProxy = 0i64;
  *(Scaleform::GFx::ASString *)&argv.value.VNumber = (Scaleform::GFx::ASString)type->pNode;
  if ( argv.value.VS._1.VStr == &argv.value.VS._1.VStr->pManager->NullStringNode )
  {
    argv.value.VS._1.VStr = 0i64;
    argv.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)argv.Bonus.pWeakProxy;
    argv.Flags = 12;
  }
  else
  {
    ++argv.value.VS._1.VStr->RefCount;
  }
  Scaleform::GFx::AS3::ASVM::_constructInstance(
    (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM,
    result,
    *(Scaleform::GFx::AS3::Object **)&this->pTraits.pObject->pVM[1].ExceptionObj.Flags,
    1u,
    &argv);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&result->pObject[1].16,
    target);
  BYTE4(result->pObject[1].pPrevRoot) |= 1u;
  BYTE4(result->pObject[1].pPrevRoot) &= ~2u;
  *(_QWORD *)&result->pObject[1].RefCount = *(_QWORD *)&evtId[1].WcharCode;
  result->pObject[1].pTraits.pObject = *(Scaleform::GFx::AS3::Traits **)&evtId[1].AsciiCode;
  result->pObject[1].DynAttrs.mHash.pTable = *(Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType **)&evtId[2].Id;
  result->pObject[2].vfptr = *(Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl **)&evtId[2].KeyCode;
  result->pObject[2].pRCCRaw = *(_QWORD *)&evtId[2].RollOverCnt;
  result->pObject[2].pNext = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&evtId[3].WcharCode;
  result->pObject[2].pPrev = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&evtId[3].AsciiCode;
  *(_QWORD *)&result->pObject[2].RefCount = *(_QWORD *)&evtId[4].Id;
  if ( (argv.Flags & 0x1F) > 9 )
  {
    if ( (argv.Flags & 0x200) != 0 )
    {
      if ( argv.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&argv.Bonus, 0, 24);
      argv.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&argv);
    }
  }
  return result;
}

// File Line: 1521
// RVA: 0x7BE650
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateProgressEventObject(
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        Scaleform::GFx::ASString *type)
{
  Scaleform::GFx::AS3::ASVM *pVM; // r10
  Scaleform::GFx::AS3::Value ptr; // [rsp+40h] [rbp-88h] BYREF
  int v7; // [rsp+60h] [rbp-68h]
  __int64 v8; // [rsp+68h] [rbp-60h]
  char v9; // [rsp+70h] [rbp-58h]
  int v10; // [rsp+80h] [rbp-48h]
  __int64 v11; // [rsp+88h] [rbp-40h]
  char v12; // [rsp+90h] [rbp-38h]
  __int64 v13; // [rsp+A0h] [rbp-28h]
  Scaleform::GFx::AS3::Value::VU v14; // [rsp+A8h] [rbp-20h]

  v13 = -2i64;
  pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  result->pObject = 0i64;
  ptr.Flags = 10;
  ptr.Bonus.pWeakProxy = 0i64;
  *(Scaleform::GFx::ASString *)&ptr.value.VNumber = (Scaleform::GFx::ASString)type->pNode;
  if ( ptr.value.VS._1.VStr == &ptr.value.VS._1.VStr->pManager->NullStringNode )
  {
    v14.VS._1.VStr = 0i64;
    ptr.value = v14;
    ptr.Flags = 12;
  }
  else
  {
    ++ptr.value.VS._1.VStr->RefCount;
  }
  v7 = 1;
  v8 = 0i64;
  v9 = 0;
  v10 = 1;
  v11 = 0i64;
  v12 = 0;
  Scaleform::GFx::AS3::ASVM::_constructInstance(pVM, result, pVM->ProgressEventClass.pObject, 3u, &ptr);
  `eh vector destructor iterator(&ptr, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  return result;
}

// File Line: 1543
// RVA: 0x7BCB70
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateFocusEventObject(
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        Scaleform::GFx::ASString *type,
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *relatedObj,
        char controllerIdx,
        int shiftKey)
{
  Scaleform::GFx::AS3::ASVM *pVM; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::Object **p_pObject; // r8
  Scaleform::GFx::AS3::Value::VU v11; // [rsp+40h] [rbp-B8h]
  Scaleform::GFx::AS3::Value ptr; // [rsp+50h] [rbp-A8h] BYREF
  int v13; // [rsp+70h] [rbp-88h]
  __int64 v14; // [rsp+78h] [rbp-80h]
  int v15; // [rsp+88h] [rbp-70h]
  __int64 v16; // [rsp+90h] [rbp-68h]
  char v17; // [rsp+98h] [rbp-60h]
  int v18; // [rsp+A8h] [rbp-50h]
  __int64 v19; // [rsp+B0h] [rbp-48h]
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v20; // [rsp+B8h] [rbp-40h]
  int v21; // [rsp+C8h] [rbp-30h]
  __int64 v22; // [rsp+D0h] [rbp-28h]
  char v23; // [rsp+D8h] [rbp-20h]
  int v24; // [rsp+E8h] [rbp-10h]
  __int64 v25; // [rsp+F0h] [rbp-8h]
  int v26; // [rsp+F8h] [rbp+0h]
  int v27; // [rsp+138h] [rbp+40h]

  pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  result->pObject = 0i64;
  ptr.Flags = 10;
  ptr.Bonus.pWeakProxy = 0i64;
  pNode = type->pNode;
  ptr.value.VS._1.VStr = pNode;
  if ( pNode == &pNode->pManager->NullStringNode )
  {
    v11.VS._1.VStr = 0i64;
    ptr.value = v11;
    ptr.Flags = 12;
  }
  else
  {
    ++pNode->RefCount;
  }
  v13 = 1;
  v14 = 1i64;
  v15 = 1;
  v16 = 0i64;
  v17 = 0;
  v18 = 12;
  v19 = 0i64;
  v20 = relatedObj;
  if ( relatedObj )
    relatedObj->RefCount = (relatedObj->RefCount + 1) & 0x8FBFFFFF;
  v21 = 1;
  v22 = 0i64;
  v23 = controllerIdx;
  v24 = 3;
  v25 = 0i64;
  v26 = shiftKey;
  p_pObject = &pVM->FocusEventExClass.pObject;
  if ( !pVM->ExtensionsEnabled )
    p_pObject = &pVM->FocusEventClass.pObject;
  Scaleform::GFx::AS3::ASVM::_constructInstance(pVM, result, *p_pObject, 6u, &ptr);
  if ( pVM->ExtensionsEnabled )
    LODWORD(result->pObject[1].DynAttrs.mHash.pTable) = v27;
  `eh vector destructor iterator(&ptr, 0x20ui64, 6, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  return result;
}

// File Line: 1560
// RVA: 0x7BD5D0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateIOErrorEventObject(
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        const char *errText)
{
  Scaleform::GFx::AS3::ASVM *pVM; // rbx
  Scaleform::GFx::AS3::Value::V1U *v7; // rax
  Scaleform::GFx::AS3::Value::V1U v8; // rdx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v10; // zf
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rdx
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::AS3::Class *Class; // rax
  Scaleform::StringDataPtr gname; // [rsp+38h] [rbp-71h] BYREF
  Scaleform::GFx::AS3::Value ptr; // [rsp+50h] [rbp-59h] BYREF
  int v18; // [rsp+70h] [rbp-39h]
  __int64 v19; // [rsp+78h] [rbp-31h]
  char v20; // [rsp+80h] [rbp-29h]
  int v21; // [rsp+90h] [rbp-19h]
  __int64 v22; // [rsp+98h] [rbp-11h]
  char v23; // [rsp+A0h] [rbp-9h]
  int v24; // [rsp+B0h] [rbp+7h]
  __int64 v25; // [rsp+B8h] [rbp+Fh]
  Scaleform::StringDataPtr v26; // [rsp+C0h] [rbp+17h]
  __int64 v27; // [rsp+D0h] [rbp+27h]
  Scaleform::GFx::ASString resulta; // [rsp+110h] [rbp+67h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *v29; // [rsp+118h] [rbp+6Fh]

  v29 = result;
  v27 = -2i64;
  pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  result->pObject = 0i64;
  v7 = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                                            pVM->StringManagerRef,
                                            &resulta,
                                            "ioError");
  ptr.Flags = 10;
  ptr.Bonus.pWeakProxy = 0i64;
  v8 = *v7;
  ptr.value.VS._1 = *v7;
  if ( v7->VStr == &v7->VStr->pManager->NullStringNode )
  {
    gname.pStr = 0i64;
    ptr.value = (Scaleform::GFx::AS3::Value::VU)gname;
    ptr.Flags = 12;
  }
  else
  {
    ++v8.VStr->RefCount;
  }
  pNode = resulta.pNode;
  v10 = resulta.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v18 = 1;
  v19 = 0i64;
  v20 = 0;
  v21 = 1;
  v22 = 0i64;
  v23 = 0;
  v11 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
          pVM->StringManagerRef,
          &resulta,
          errText);
  v24 = 10;
  v25 = 0i64;
  v12 = v11->pNode;
  v26.pStr = (const char *)v11->pNode;
  if ( v11->pNode == &v11->pNode->pManager->NullStringNode )
  {
    gname.pStr = 0i64;
    v26 = gname;
    v24 = 12;
  }
  else
  {
    ++v12->RefCount;
  }
  v13 = resulta.pNode;
  v10 = resulta.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  gname.pStr = "flash.events.IOErrorEvent";
  gname.Size = 25i64;
  Class = Scaleform::GFx::AS3::VM::GetClass(
            this->pTraits.pObject->pVM,
            &gname,
            this->pTraits.pObject->pVM->CurrentDomain.pObject);
  Scaleform::GFx::AS3::ASVM::_constructInstance(pVM, result, Class, 4u, &ptr);
  `eh vector destructor iterator(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  return result;
}

// File Line: 1591
// RVA: 0x7BDC40
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseCursorEventObject(
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        Scaleform::GFx::ASString *cursor,
        unsigned int controllerIdx)
{
  Scaleform::GFx::AS3::ASVM *pVM; // rdi
  Scaleform::GFx::AS3::MovieRoot *pMovieRoot; // rcx
  Scaleform::GFx::AS3::Value::V1U pNode; // rdx
  Scaleform::GFx::AS3::Class *Class; // rax
  Scaleform::GFx::AS3::Instances::fl_gfx::MouseCursorEvent *pObject; // rsi
  Scaleform::GFx::ASStringNode *v13; // rdi
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::StringDataPtr gname; // [rsp+38h] [rbp-90h] BYREF
  Scaleform::GFx::AS3::Value ptr; // [rsp+50h] [rbp-78h] BYREF
  int v19; // [rsp+70h] [rbp-58h]
  __int64 v20; // [rsp+78h] [rbp-50h]
  char v21; // [rsp+80h] [rbp-48h]
  int v22; // [rsp+90h] [rbp-38h]
  __int64 v23; // [rsp+98h] [rbp-30h]
  char v24; // [rsp+A0h] [rbp-28h]
  __int64 v25; // [rsp+B0h] [rbp-18h]

  v25 = -2i64;
  pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  result->pObject = 0i64;
  pMovieRoot = pVM->pMovieRoot;
  ptr.Flags = 10;
  ptr.Bonus.pWeakProxy = 0i64;
  pNode = (Scaleform::GFx::AS3::Value::V1U)pMovieRoot->BuiltinsMgr.Builtins[46].pNode;
  ptr.value.VS._1 = pNode;
  if ( pMovieRoot->BuiltinsMgr.Builtins[46].pNode == &pMovieRoot->BuiltinsMgr.Builtins[46].pNode->pManager->NullStringNode )
  {
    gname.pStr = 0i64;
    ptr.value = (Scaleform::GFx::AS3::Value::VU)gname;
    ptr.Flags = 12;
  }
  else
  {
    ++pNode.VStr->RefCount;
  }
  v19 = 1;
  v20 = 0i64;
  v21 = 0;
  v22 = 1;
  v23 = 0i64;
  v24 = 1;
  gname.pStr = "scaleform.gfx.MouseCursorEvent";
  gname.Size = 30i64;
  Class = Scaleform::GFx::AS3::VM::GetClass(
            this->pTraits.pObject->pVM,
            &gname,
            this->pTraits.pObject->pVM->CurrentDomain.pObject);
  if ( Class )
  {
    Scaleform::GFx::AS3::ASVM::_constructInstance(pVM, result, Class, 3u, &ptr);
    LODWORD(result->pObject[1].pTraits.pObject) = controllerIdx;
    pObject = (Scaleform::GFx::AS3::Instances::fl_gfx::MouseCursorEvent *)result->pObject;
    v13 = cursor->pNode;
    ++cursor->pNode->RefCount;
    v14 = pObject->cursor.pNode;
    if ( v14->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    pObject->cursor.pNode = v13;
  }
  `eh vector destructor iterator(&ptr, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  return result;
}

// File Line: 1620
// RVA: 0x77CDD0
void __fastcall Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher::EventDispatcher(
        Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::ClassInfo *ci)
{
  Scaleform::GFx::AS3::ClassTraits::Traits::Traits(this, vm, ci);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher::`vftable;
}

// File Line: 1627
// RVA: 0x75F1C0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rbx

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl_events::EventDispatcherCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl_events::EventDispatcherCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher::`vftable;
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    result->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))MHeap->vfptr->Alloc)(
                                       MHeap,
                                       88i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::`vftable;
    v10[1].vfptr = 0i64;
    v10[1].pRCCRaw = 0i64;
  }
  return result;
}

