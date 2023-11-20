// File Line: 64
// RVA: 0x1596A00
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc5_Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher_0_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::ASString_const_____ptr64_Scaleform::GFx::AS3::Value_const_____ptr64_bool_long_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243CB20 = v1;
  Scaleform::GFx::AS3::ThunkFunc5<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher,0,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Value const &,bool,long,bool>::Method = Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::addEventListener;
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
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcher(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v2; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v3; // rdi

  v2 = t;
  v3 = this;
  Scaleform::GFx::AS3::Instance::Instance((Scaleform::GFx::AS3::Instance *)&this->vfptr, t);
  v3->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable';
  v3->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::`vftable';
  v3->VMRef = v2->pVM;
  v3->pImpl.pObject = 0i64;
  v3->pImpl.Owner = 1;
}

// File Line: 84
// RVA: 0x82B150
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::addEventListener(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::ASString *type, Scaleform::GFx::AS3::Value *listener, bool useCapture, int priority, bool useWeakReference)
{
  Scaleform::GFx::AS3::Value *v7; // r13
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v8; // r15
  Scaleform::AutoPtr<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl> *v9; // r14
  __int64 v10; // rax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *v11; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v12; // rdi
  Scaleform::GFx::ASStringNode *v13; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v14; // rsi
  signed __int64 v15; // rax
  signed __int64 v16; // r12
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> **v17; // r12
  unsigned __int64 v18; // rsi
  bool v19; // zf
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> *v20; // rax
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> *v22; // r12
  unsigned __int64 v23; // r15
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *v24; // rdi
  Scaleform::GFx::AS3::Value *v25; // rbx
  unsigned __int64 v26; // rdi
  Scaleform::GFx::AS3::Value *v27; // rbx
  Scaleform::GFx::AS3::VM *v28; // r8
  Scaleform::GFx::AS3::StringManager *v29; // rcx
  Scaleform::GFx::ASStringNode *v30; // rbx
  Scaleform::GFx::EventId::IdCode v31; // edx
  Scaleform::GFx::AS3::Traits *v32; // rcx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *v33; // rax
  unsigned int v34; // edi
  Scaleform::GFx::AS3::WeakProxy *v35; // r12
  int v36; // er14
  long double v37; // rcx
  unsigned __int64 v38; // r13
  signed __int64 v39; // rdx
  signed __int64 v40; // r15
  Scaleform::GFx::AS3::WeakProxy *v41; // r15
  Scaleform::GFx::AS3::GASRefCountBase *v42; // r8
  unsigned __int64 v43; // rsi
  unsigned __int64 v44; // rcx
  long double v45; // rdx
  Scaleform::MemoryHeap *v46; // r8
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *v47; // rdi
  int v48; // ecx
  Scaleform::GFx::AS3::GASRefCountBase *v49; // rcx
  Scaleform::GFx::ASString key; // [rsp+20h] [rbp-60h]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> *v51; // [rsp+28h] [rbp-58h]
  Scaleform::MemoryHeap *v52; // [rsp+30h] [rbp-50h]
  long double v53; // [rsp+38h] [rbp-48h]
  Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeRef v54; // [rsp+40h] [rbp-40h]
  int v55; // [rsp+50h] [rbp-30h]
  Scaleform::GFx::AS3::Value v56; // [rsp+58h] [rbp-28h]
  __int64 v57; // [rsp+78h] [rbp-8h]
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v58; // [rsp+C0h] [rbp+40h]
  Scaleform::Pickable<Scaleform::GFx::AS3::WeakProxy> resulta; // [rsp+D0h] [rbp+50h]

  resulta.pV = (Scaleform::GFx::AS3::WeakProxy *)type;
  v58 = this;
  v57 = -2i64;
  v7 = listener;
  v8 = this;
  v9 = &this->pImpl;
  if ( !this->pImpl.pObject )
  {
    v52 = this->pTraits.pObject->pVM->MHeap;
    *(double *)&v10 = COERCE_DOUBLE((__int64)v52->vfptr->Alloc((Scaleform::MemoryHeap *)this, 24ui64, 0i64));
    v11 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *)v10;
    v53 = *(double *)&v10;
    if ( *(double *)&v10 == 0.0 )
    {
      v11 = 0i64;
    }
    else
    {
      *(_QWORD *)v10 = 0i64;
      v54.pFirst = (Scaleform::GFx::ASString *)(v10 + 8);
      key.pNode = (Scaleform::GFx::ASStringNode *)v54.pFirst;
      v54.pFirst->pNode = 0i64;
      *(_DWORD *)(v10 + 16) = 0;
    }
    Scaleform::AutoPtr<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl>::operator=(
      v9,
      v11);
    type = (Scaleform::GFx::ASString *)resulta.pV;
  }
  v12 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v9->pObject;
  if ( !useCapture )
    ++v12;
  v13 = type->pNode;
  key.pNode = v13;
  ++v13->RefCount;
  v14.pTable = v12->pTable;
  if ( v12->pTable
    && (v15 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                v12,
                &key,
                v13->HashFlags & v14.pTable->SizeMask),
        v15 >= 0)
    && (v16 = (signed __int64)v14.pTable + 8 * (3 * v15 + 3)) != 0 )
  {
    v17 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> **)(v16 + 8);
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
    v51 = v22;
  }
  else
  {
    v54.pFirst = (Scaleform::GFx::ASString *)v8->pTraits.pObject->pVM->MHeap;
    *(double *)&v20 = COERCE_DOUBLE(
                        ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *, signed __int64, _QWORD))v54.pFirst->pNode[2].pData)(
                          this,
                          24i64,
                          0i64));
    v52 = (Scaleform::MemoryHeap *)v20;
    if ( *(double *)&v20 == 0.0 )
    {
      *(double *)&v20 = 0.0;
    }
    else
    {
      v53 = *(double *)&v20;
      v20->Data = 0i64;
      v20->Size = 0i64;
      v20->Policy.Capacity = 0i64;
    }
    v51 = v20;
    key.pNode = *(Scaleform::GFx::ASStringNode **)&resulta.pV->RefCount;
    ++key.pNode->RefCount;
    v54.pFirst = &key;
    v54.pSecond = (Scaleform::GFx::MovieImpl::StickyVarNode *const *)&v51;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      v12,
      v12,
      &v54,
      key.pNode->HashFlags);
    v21 = key.pNode;
    v19 = key.pNode->RefCount == 1;
    --v21->RefCount;
    if ( v19 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v21);
    v22 = v51;
  }
  v23 = v22->Size;
  if ( !v23 )
  {
LABEL_30:
    v26 = v18;
    if ( v18 < v23 )
    {
      v27 = (Scaleform::GFx::AS3::Value *)((char *)v22->Data + 8 * (v18 + 4 * v18 + 1));
      while ( (v27->Flags >> 9) & 1 && !v27->Bonus.pWeakProxy->pObject || !Scaleform::GFx::AS3::StrictEqual(v27, v7) )
      {
        ++v26;
        v27 = (Scaleform::GFx::AS3::Value *)((char *)v27 + 40);
        if ( v26 >= v23 )
          goto LABEL_36;
      }
      return;
    }
LABEL_36:
    v28 = v58->pTraits.pObject->pVM;
    v29 = v28->StringManagerRef;
    v30 = *(Scaleform::GFx::ASStringNode **)&resulta.pV->RefCount;
    key.pNode = v30;
    ++v30->RefCount;
    if ( v30 == v29->Builtins[34].pNode )
    {
      v31 = 2;
      *((_DWORD *)v28[1].vfptr[2].__vecDelDtor + 5300) |= 0x80000u;
      v9->pObject->Flags |= 1u;
    }
    else if ( v30 == v29->Builtins[35].pNode )
    {
      v31 = 16777237;
      v9->pObject->Flags |= 0x20u;
    }
    else if ( v30 == v29->Builtins[36].pNode )
    {
      v31 = 16777238;
      v9->pObject->Flags |= 0x40u;
    }
    else if ( v30 == v29->Builtins[28].pNode )
    {
      v31 = 16777233;
      v9->pObject->Flags |= 2u;
    }
    else if ( v30 == v29->Builtins[33].pNode )
    {
      v31 = 16777234;
      v9->pObject->Flags |= 4u;
    }
    else if ( v30 == v29->Builtins[44].pNode )
    {
      v31 = 16777235;
      v9->pObject->Flags |= 8u;
    }
    else
    {
      if ( v30 != v29->Builtins[45].pNode )
      {
        if ( v29->Builtins[49].pNode == v30
          || v29->Builtins[53].pNode == v30
          || v29->Builtins[47].pNode == v30
          || v29->Builtins[48].pNode == v30
          || v29->Builtins[52].pNode == v30
          || v29->Builtins[51].pNode == v30
          || v29->Builtins[56].pNode == v30
          || v29->Builtins[55].pNode == v30 )
        {
          v33 = v9->pObject;
          if ( useCapture )
          {
            if ( v33->CaptureButtonHandlersCnt < 0xFFu )
              ++v33->CaptureButtonHandlersCnt;
          }
          else if ( v33->ButtonHandlersCnt < 0xFFu )
          {
            ++v33->ButtonHandlersCnt;
          }
        }
LABEL_67:
        v55 = priority;
        v34 = v7->Flags;
        v56.Flags = v34;
        v35 = v7->Bonus.pWeakProxy;
        v56.Bonus.pWeakProxy = v7->Bonus.pWeakProxy;
        v53 = v7->value.VNumber;
        v56.value.VNumber = v53;
        v52 = (Scaleform::MemoryHeap *)v7->value.VS._2.VObj;
        v56.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v52;
        v36 = v34 & 0x1F;
        if ( v36 <= 9 )
          goto LABEL_79;
        if ( (v34 >> 9) & 1 )
        {
          ++v35->RefCount;
          goto LABEL_79;
        }
        if ( v36 == 10 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v7->value.VNumber + 24i64);
        }
        else
        {
          if ( v36 <= 10 )
            goto LABEL_79;
          if ( v36 <= 15 )
          {
            v37 = v7->value.VNumber;
          }
          else
          {
            if ( v36 > 17 )
              goto LABEL_79;
            v37 = *(double *)&v7->value.VS._2.VObj;
          }
          if ( v37 != 0.0 )
            *(_DWORD *)(*(_QWORD *)&v37 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v37 + 32i64) + 1) & 0x8FBFFFFF;
        }
LABEL_79:
        resulta.pV = (Scaleform::GFx::AS3::WeakProxy *)v51;
        v38 = v51->Size;
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          v51,
          v51,
          v38 + 1);
        if ( v38 + 1 > v38 )
        {
          v39 = *(_QWORD *)&resulta.pV->RefCount + 40 * v38;
          v40 = 1i64;
          do
          {
            v54.pFirst = (Scaleform::GFx::ASString *)v39;
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
        v41 = resulta.pV;
        v42 = resulta.pV->pObject;
        if ( v18 < (unsigned __int64)&v42[-1].RefCount + 7 )
          memmove(
            (void *)(*(_QWORD *)&resulta.pV->RefCount + 40 * v18 + 40),
            (const void *)(*(_QWORD *)&resulta.pV->RefCount + 40 * v18),
            40i64 * (_QWORD)((char *)v42 - v18 - 1));
        v43 = 40 * v18;
        v19 = v43 + *(_QWORD *)&v41->RefCount == 0;
        v44 = v43 + *(_QWORD *)&v41->RefCount;
        resulta.pV = (Scaleform::GFx::AS3::WeakProxy *)(v43 + *(_QWORD *)&v41->RefCount);
        if ( !v19 )
        {
          *(_DWORD *)v44 = priority;
          *(_DWORD *)(v44 + 8) = v34;
          *(_QWORD *)(v44 + 16) = v35;
          v45 = v53;
          *(long double *)(v44 + 24) = v53;
          v46 = v52;
          *(_QWORD *)(v44 + 32) = v52;
          if ( v36 > 9 )
          {
            if ( (v34 >> 9) & 1 )
            {
              ++v35->RefCount;
            }
            else if ( v36 == 10 )
            {
              ++*(_DWORD *)(*(_QWORD *)&v45 + 24i64);
            }
            else if ( v36 > 10 )
            {
              if ( v36 <= 15 )
              {
                if ( v45 != 0.0 )
                  *(_DWORD *)(*(_QWORD *)&v45 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v45 + 32i64) + 1) & 0x8FBFFFFF;
              }
              else if ( v36 <= 17 && v46 )
              {
                v46->RefCount = (v46->RefCount + 1) & 0x8FBFFFFF;
              }
            }
          }
        }
        if ( v36 > 9 )
        {
          if ( (v34 >> 9) & 1 )
          {
            v19 = v35->RefCount-- == 1;
            if ( v19 )
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v35);
            v56.Bonus.pWeakProxy = 0i64;
            v56.value = 0ui64;
            v56.Flags = v34 & 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v56);
          }
        }
        if ( !useWeakReference )
          goto LABEL_117;
        v47 = &v51->Data[v43 / 0x28];
        if ( (v47->mFunction.Flags >> 9) & 1 )
          goto LABEL_117;
        v48 = v47->mFunction.Flags & 0x1F;
        if ( v48 <= 10 )
          goto LABEL_117;
        if ( v48 != 11 )
        {
          if ( v48 <= 11 )
            goto LABEL_117;
          if ( v48 > 15 )
          {
            if ( v48 <= 17 )
            {
              v49 = (Scaleform::GFx::AS3::GASRefCountBase *)&v47->mFunction.value.VS._2.VObj->vfptr;
              goto LABEL_115;
            }
LABEL_117:
            v19 = v30->RefCount-- == 1;
            if ( v19 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v30);
            return;
          }
        }
        v49 = (Scaleform::GFx::AS3::GASRefCountBase *)v47->mFunction.value.VS._1.VStr;
LABEL_115:
        if ( v49 )
        {
          v47->mFunction.Bonus.pWeakProxy = Scaleform::GFx::AS3::GASRefCountBase::CreateWeakProxy(v49, &resulta)->pV;
          v47->mFunction.Flags |= 0x200u;
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v47->mFunction);
        }
        goto LABEL_117;
      }
      v31 = 16777236;
      v9->pObject->Flags |= 0x10u;
    }
    if ( !v51->Size )
    {
      v32 = v58->pTraits.pObject;
      if ( (unsigned int)(v32->TraitsType - 22) <= 0xC )
      {
        if ( ~(LOBYTE(v32->Flags) >> 5) & 1 )
          Scaleform::GFx::AS3::EventChains::AddToChain(
            (Scaleform::GFx::AS3::EventChains *)&v28[1].vfptr[43],
            v31,
            (Scaleform::GFx::DisplayObject *)v58[1]._pRCC);
      }
    }
    goto LABEL_67;
  }
  v24 = v22->Data;
  v25 = &v22->Data->mFunction;
  while ( (v25->Flags >> 9) & 1 && !v25->Bonus.pWeakProxy->pObject || !Scaleform::GFx::AS3::StrictEqual(v25, v7) )
  {
    if ( priority <= (signed int)v24->Priority )
    {
      ++v18;
      ++v24;
      v25 = (Scaleform::GFx::AS3::Value *)((char *)v25 + 40);
      if ( v18 < v23 )
        continue;
    }
    goto LABEL_30;
  }
}

// File Line: 233
// RVA: 0x834A80
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::dispatchEvent(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this, bool *result, Scaleform::GFx::AS3::Instances::fl_events::Event *event)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *v3; // r14
  bool *v4; // rdi
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v5; // r13
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  long double v9; // rbx
  unsigned int v10; // esi
  long double *v11; // rax
  unsigned int v12; // er15
  long double v13; // rdi
  Scaleform::GFx::ASStringNode *v14; // rdx
  Scaleform::GFx::AS3::GASRefCountBase *v15; // r8
  int v16; // er12
  __int64 v17; // rax
  Scaleform::GFx::ASString *v18; // rax
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::AS3::Traits *v22; // rcx
  long double v23; // rax
  __int64 *v24; // rax
  Scaleform::GFx::ASStringNode *v25; // rcx
  unsigned int v26; // eax
  long double *v27; // rax
  long double v28; // rcx
  Scaleform::GFx::ASStringNode *v29; // rcx
  Scaleform::GFx::AS3::VM::Error *v30; // rax
  Scaleform::GFx::ASStringNode *v31; // rcx
  Scaleform::GFx::AS3::Traits *v32; // rcx
  int v33; // eax
  Scaleform::GFx::AS3::Value v34; // [rsp+40h] [rbp-C0h]
  Scaleform::GFx::AS3::Value v; // [rsp+60h] [rbp-A0h]
  Scaleform::GFx::AS3::Value func; // [rsp+80h] [rbp-80h]
  Scaleform::GFx::AS3::Value _this; // [rsp+A0h] [rbp-60h]
  Scaleform::GFx::AS3::VM::Error v38; // [rsp+C0h] [rbp-40h]
  Scaleform::GFx::AS3::Multiname v39; // [rsp+D0h] [rbp-30h]
  Scaleform::GFx::ASString v40; // [rsp+100h] [rbp+0h]
  __int64 v41; // [rsp+108h] [rbp+8h]
  bool *v42; // [rsp+158h] [rbp+58h]
  Scaleform::GFx::ASString resulta; // [rsp+160h] [rbp+60h]
  long double v44; // [rsp+168h] [rbp+68h]

  v42 = result;
  v41 = -2i64;
  v3 = event;
  v4 = result;
  v5 = this;
  if ( !event )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v38, eConvertNullToObjectError, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5->pTraits.pObject->pVM, v6, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v7 = v38.Message.pNode;
    v8 = v38.Message.pNode->RefCount == 1;
    --v7->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    return;
  }
  v9 = 0.0;
  v44 = 0.0;
  v10 = 10;
  if ( !Scaleform::GFx::AS3::Instances::fl_events::Event::NeedsCloning(event) )
  {
    v3->RefCount = (v3->RefCount + 1) & 0x8FBFFFFF;
    v9 = *(double *)&v3;
    v44 = *(double *)&v3;
LABEL_96:
    if ( v9 == 0.0 )
    {
      v27 = (long double *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                             (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v5->pTraits.pObject->pVM->StringManagerRef->Builtins,
                             &resulta,
                             "event");
      v34.Flags = 10;
      v34.Bonus.pWeakProxy = 0i64;
      v28 = *v27;
      v34.value.VNumber = v28;
      if ( *(_QWORD *)&v28 == *(_QWORD *)(*(_QWORD *)&v28 + 8i64) + 104i64 )
      {
        v34.value.VNumber = 0.0;
        v34.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v38.Message.pNode;
        v10 = 12;
        v34.Flags = 12;
      }
      else
      {
        ++*(_DWORD *)(*(_QWORD *)&v28 + 24i64);
      }
      v29 = resulta.pNode;
      v8 = resulta.pNode->RefCount == 1;
      --v29->RefCount;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v29);
      Scaleform::GFx::AS3::VM::Error::Error(&v38, eNullPointerError, v5->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5->pTraits.pObject->pVM, v30, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v31 = v38.Message.pNode;
      v8 = v38.Message.pNode->RefCount == 1;
      --v31->RefCount;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v31);
      if ( (char)(v10 & 0x1F) > 9 )
      {
        if ( (v10 >> 9) & 1 )
        {
          LODWORD(MEMORY[0]) = MEMORY[0] - 1;
          if ( !(_DWORD)MEMORY[0] )
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
          v34.Bonus.pWeakProxy = 0i64;
          v34.value = 0ui64;
          v34.Flags = v10 & 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v34);
        }
      }
    }
    else
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)(*(_QWORD *)&v9 + 72i64),
        (Scaleform::GFx::AS3::Instances::fl::XMLList *)v5);
      v32 = v5->pTraits.pObject;
      if ( (unsigned int)(v32->TraitsType - 22) <= 0xC && ~(LOBYTE(v32->Flags) >> 5) & 1 )
      {
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(
          v5,
          *(Scaleform::GFx::AS3::Instances::fl_events::Event **)&v9,
          (Scaleform::GFx::DisplayObject *)v5[1]._pRCC);
      }
      else
      {
        *(_BYTE *)(*(_QWORD *)&v9 + 84i64) |= 0x20u;
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(
          v5,
          *(Scaleform::GFx::AS3::Instances::fl_events::Event **)&v9,
          0);
      }
      *v4 = ~(*(_BYTE *)(*(_QWORD *)&v9 + 84i64) >> 2) & 1;
    }
    goto LABEL_115;
  }
  if ( !((LOBYTE(v3->pTraits.pObject->Flags) >> 4) & 1) )
  {
    v24 = (__int64 *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl_events::Event *, Scaleform::GFx::ASString *))v3->vfptr[7].~RefCountBaseGC<328>)(
                       v3,
                       &resulta);
    if ( v24 != (__int64 *)&v44 )
    {
      if ( *v24 )
        *(_DWORD *)(*v24 + 32) = (*(_DWORD *)(*v24 + 32) + 1) & 0x8FBFFFFF;
      v9 = *(double *)v24;
      v44 = *(double *)v24;
    }
    v25 = resulta.pNode;
    if ( resulta.pNode )
    {
      if ( (_QWORD)resulta.pNode & 1 )
      {
        --resulta.pNode;
      }
      else
      {
        v26 = resulta.pNode->Size;
        if ( v26 & 0x3FFFFF )
        {
          resulta.pNode->Size = v26 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v25);
        }
      }
    }
    goto LABEL_96;
  }
  _this.Flags = 12;
  _this.Bonus.pWeakProxy = 0i64;
  *(_QWORD *)&_this.value.VNumber = v3;
  v3->RefCount = (v3->RefCount + 1) & 0x8FBFFFFF;
  v.Flags = 0;
  v.Bonus.pWeakProxy = 0i64;
  func.Flags = 0;
  func.Bonus.pWeakProxy = 0i64;
  v11 = (long double *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                         (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v5->pTraits.pObject->pVM->StringManagerRef->Builtins,
                         (Scaleform::GFx::ASString *)&v38,
                         "clone");
  v12 = 10;
  v34.Flags = 10;
  v34.Bonus.pWeakProxy = 0i64;
  v13 = *v11;
  v34.value.VNumber = v13;
  if ( *(_QWORD *)&v13 == *(_QWORD *)(*(_QWORD *)&v13 + 8i64) + 104i64 )
  {
    v13 = 0.0;
    v34.value.VNumber = 0.0;
    v14 = v38.Message.pNode;
    v34.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v38.Message.pNode;
    v12 = 12;
    v34.Flags = 12;
  }
  else
  {
    ++*(_DWORD *)(*(_QWORD *)&v13 + 24i64);
    v14 = (Scaleform::GFx::ASStringNode *)v34.value.VS._2.VObj;
  }
  v15 = (Scaleform::GFx::AS3::GASRefCountBase *)&v5->pTraits.pObject->pVM->PublicNamespace.pObject->vfptr;
  v39.Kind = 0;
  v39.Obj.pObject = v15;
  if ( v15 )
    v15->RefCount = (v15->RefCount + 1) & 0x8FBFFFFF;
  v39.Name.Flags = 0;
  v39.Name.Bonus.pWeakProxy = 0i64;
  v16 = v12 & 0x1F;
  if ( (unsigned int)(v16 - 12) <= 3
    && v13 != 0.0
    && (v17 = *(_QWORD *)(*(_QWORD *)&v13 + 40i64), *(_DWORD *)(v17 + 120) == 17)
    && ~(*(_BYTE *)(v17 + 112) >> 5) & 1 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v39.Name, (Scaleform::GFx::ASString *)(*(_QWORD *)&v13 + 56i64));
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v39.Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v13 + 64i64));
    v39.Kind &= 0xFFFFFFF9;
  }
  else
  {
    __asm { prefetcht1 byte ptr [rsp+140h+var_100.Flags]; Prefetch to all cache levels }
    *(_QWORD *)&v39.Name.Flags = *(_QWORD *)&v34.Flags;
    v39.Name.Bonus.pWeakProxy = 0i64;
    v39.Name.value.VNumber = v13;
    v39.Name.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v14;
    if ( v16 > 9 )
    {
      if ( (v12 >> 9) & 1 )
      {
        LODWORD(MEMORY[0]) = MEMORY[0] + 1;
      }
      else if ( v16 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&v13 + 24i64);
      }
      else if ( v16 > 10 )
      {
        if ( v16 <= 15 )
        {
          if ( v13 != 0.0 )
            *(_DWORD *)(*(_QWORD *)&v13 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v13 + 32i64) + 1) & 0x8FBFFFFF;
        }
        else if ( v16 <= 17 && v14 )
        {
          v14->Size = (v14->Size + 1) & 0x8FBFFFFF;
        }
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
          v8 = v40.pNode->RefCount == 1;
          --v19->RefCount;
          if ( v8 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v19);
        }
      }
      v20 = resulta.pNode;
      v8 = resulta.pNode->RefCount == 1;
      --v20->RefCount;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v20);
    }
  }
  if ( v16 > 9 )
  {
    if ( (v12 >> 9) & 1 )
    {
      LODWORD(MEMORY[0]) = MEMORY[0] - 1;
      if ( !(_DWORD)MEMORY[0] )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
      v34.Bonus.pWeakProxy = 0i64;
      v34.value = 0ui64;
      v34.Flags = v12 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v34);
    }
  }
  v21 = *(Scaleform::GFx::ASStringNode **)&v38.ID;
  v8 = *(_DWORD *)(*(_QWORD *)&v38.ID + 24i64) == 1;
  --v21->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v21);
  if ( !*(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl_events::Event *, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))v3->vfptr[1].~RefCountBaseGC<328>)(
                    v3,
                    &resulta,
                    &v39,
                    &func) )
  {
LABEL_67:
    Scaleform::GFx::AS3::Multiname::~Multiname(&v39);
    if ( (func.Flags & 0x1F) > 9 )
    {
      if ( (func.Flags >> 9) & 1 )
      {
        v8 = func.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v8 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        func.Bonus.pWeakProxy = 0i64;
        func.value = 0ui64;
        func.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
      }
    }
    if ( (v.Flags & 0x1F) > 9 )
    {
      if ( (v.Flags >> 9) & 1 )
      {
        v8 = v.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v8 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v.Bonus.pWeakProxy = 0i64;
        v.value = 0ui64;
        v.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
      }
    }
    if ( (_this.Flags & 0x1F) > 9 )
    {
      if ( (_this.Flags >> 9) & 1 )
      {
        v8 = _this.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v8 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        _this.Bonus.pWeakProxy = 0i64;
        _this.value = 0ui64;
        _this.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
      }
    }
    v4 = v42;
    goto LABEL_96;
  }
  Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v5->pTraits.pObject->pVM, &func, &_this, &v, 0, 0i64, 0);
  v22 = v5->pTraits.pObject;
  if ( !v22->pVM->HandleException )
  {
    if ( (v.Flags & 0x1F) - 12 <= 3 )
    {
      if ( Scaleform::GFx::AS3::VM::IsOfType(
             v22->pVM,
             &v,
             *(Scaleform::GFx::AS3::ClassTraits::Traits **)&v22->pVM[1].XMLSupport_.pObject->Enabled) )
      {
        v23 = v.value.VNumber;
        if ( *(_QWORD *)&v.value.VNumber )
        {
          ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 32i64);
          *(_DWORD *)(*(_QWORD *)&v23 + 32i64) &= 0x8FBFFFFF;
          v9 = v23;
          v44 = v23;
        }
      }
    }
    goto LABEL_67;
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&v39);
  if ( (func.Flags & 0x1F) > 9 )
  {
    if ( (func.Flags >> 9) & 1 )
    {
      v8 = func.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      func.Bonus.pWeakProxy = 0i64;
      func.value = 0ui64;
      func.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
    }
  }
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags >> 9) & 1 )
    {
      v8 = v.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v.Bonus.pWeakProxy = 0i64;
      v.value = 0ui64;
      v.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    }
  }
  if ( (_this.Flags & 0x1F) > 9 )
  {
    if ( (_this.Flags >> 9) & 1 )
    {
      v8 = _this.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      _this.Bonus.pWeakProxy = 0i64;
      _this.value = 0ui64;
      _this.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
    }
  }
LABEL_115:
  if ( v9 != 0.0 )
  {
    if ( LOBYTE(v9) & 1 )
    {
      *(_QWORD *)&v44 = *(_QWORD *)&v9 - 1i64;
    }
    else
    {
      v33 = *(_DWORD *)(*(_QWORD *)&v9 + 32i64);
      if ( v33 & 0x3FFFFF )
      {
        *(_DWORD *)(*(_QWORD *)&v9 + 32i64) = v33 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v9);
      }
    }
  }
}

// File Line: 302
// RVA: 0x84DD20
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::hasEventListener(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this, bool *result, Scaleform::GFx::ASString *type)
{
  Scaleform::GFx::ASString *v3; // r14
  bool *v4; // rsi
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v5; // rbp
  Scaleform::GFx::ASStringNode *v6; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v7; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v8; // rdi
  signed __int64 v9; // rax
  signed __int64 v10; // rax
  signed __int64 v11; // rax
  bool v12; // al
  bool v13; // zf
  Scaleform::GFx::ASStringNode *v14; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v15; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v16; // rdi
  signed __int64 v17; // rax
  signed __int64 v18; // rax
  signed __int64 v19; // rax
  bool v20; // al
  Scaleform::GFx::ASString key; // [rsp+50h] [rbp+8h]

  v3 = type;
  v4 = result;
  v5 = this;
  v6 = type->pNode;
  key.pNode = v6;
  ++v6->RefCount;
  v7 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)this->pImpl.pObject;
  v12 = 0;
  if ( v7 )
  {
    v8 = v7[1].pTable;
    if ( v8 )
    {
      v9 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
             v7 + 1,
             &key,
             v6->HashFlags & v8->SizeMask);
      if ( v9 >= 0 )
      {
        v10 = (signed __int64)v8 + 8 * (3 * v9 + 3);
        if ( v10 )
        {
          v11 = v10 + 8;
          if ( v11 )
          {
            if ( *(_QWORD *)v11 && *(_QWORD *)(*(_QWORD *)v11 + 8i64) )
              v12 = 1;
          }
        }
      }
    }
  }
  *v4 = v12;
  v13 = v6->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  if ( !*v4 )
  {
    v14 = v3->pNode;
    key.pNode = v14;
    ++v14->RefCount;
    v15 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v5->pImpl.pObject;
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
          v18 = (signed __int64)v16.pTable + 8 * (3 * v17 + 3);
          if ( v18 )
          {
            v19 = v18 + 8;
            if ( v19 )
            {
              if ( *(_QWORD *)v19 && *(_QWORD *)(*(_QWORD *)v19 + 8i64) )
                v20 = 1;
            }
          }
        }
      }
    }
    *v4 = v20;
    v13 = v14->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  }
}efCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNo

// File Line: 310
// RVA: 0x859A00
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::removeEventListener(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::ASString *type, Scaleform::GFx::AS3::Value *listener, bool useCapture)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v5; // r13
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v6; // rcx
  Scaleform::GFx::AS3::Value *v7; // rbp
  Scaleform::GFx::ASString *v8; // r12
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v9; // rbx
  signed __int64 v10; // rax
  signed __int64 v11; // rax
  signed __int64 v12; // rax
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> > *v13; // r14
  unsigned __int64 v14; // rdi
  unsigned __int64 v15; // rsi
  Scaleform::GFx::AS3::Value *v16; // rbx

  v5 = this;
  v6 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)this->pImpl.pObject;
  v7 = listener;
  v8 = type;
  if ( v6 )
  {
    if ( !useCapture )
      ++v6;
    v9.pTable = v6->pTable;
    if ( v6->pTable )
    {
      v10 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
              v6,
              type,
              v9.pTable->SizeMask & type->pNode->HashFlags);
      if ( v10 >= 0 )
      {
        v11 = (signed __int64)v9.pTable + 8 * (3 * v10 + 3);
        if ( v11 )
        {
          v12 = v11 + 8;
          if ( v12 )
          {
            v13 = *(Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> > **)v12;
            v14 = 0i64;
            v15 = *(_QWORD *)(*(_QWORD *)v12 + 8i64);
            if ( v15 )
            {
              v16 = &v13->Data.Data->mFunction;
              while ( (v16->Flags >> 9) & 1 && !v16->Bonus.pWeakProxy->pObject
                   || !Scaleform::GFx::AS3::StrictEqual(v16, v7) )
              {
                ++v14;
                v16 = (Scaleform::GFx::AS3::Value *)((char *)v16 + 40);
                if ( v14 >= v15 )
                  return;
              }
              Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
                v13,
                v14);
              Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::OnRemoveEventListener(
                v5,
                v8,
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
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::willTrigger(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this, bool *result, Scaleform::GFx::ASString *type)
{
  Scaleform::GFx::ASString *v3; // r14
  bool *v4; // r15
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v5; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v6; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v7; // rdi
  signed __int64 v8; // rax
  signed __int64 v9; // rax
  signed __int64 v10; // rax
  bool v11; // al
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v12; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v13; // rdi
  signed __int64 v14; // rax
  signed __int64 v15; // rax
  signed __int64 v16; // rax
  bool v17; // al
  Scaleform::GFx::AS3::Traits *v18; // rcx
  __int64 v19; // rdi
  unsigned __int64 v20; // rbp
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *v21; // r12
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v22; // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v23; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v24; // rbx
  signed __int64 v25; // rax
  signed __int64 v26; // rax
  signed __int64 v27; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v28; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v29; // rbx
  signed __int64 v30; // rax
  signed __int64 v31; // rax
  signed __int64 v32; // rax
  bool v33; // al
  Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> evtFlowArray; // [rsp+40h] [rbp-148h]

  v3 = type;
  v4 = result;
  v5 = this;
  v6 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)this->pImpl.pObject;
  v11 = 0;
  if ( v6 )
  {
    v7.pTable = v6->pTable;
    if ( v6->pTable )
    {
      v8 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
             v6,
             type,
             type->pNode->HashFlags & v7.pTable->SizeMask);
      if ( v8 >= 0 )
      {
        v9 = (signed __int64)v7.pTable + 8 * (3 * v8 + 3);
        if ( v9 )
        {
          v10 = v9 + 8;
          if ( v10 )
          {
            if ( *(_QWORD *)v10 && *(_QWORD *)(*(_QWORD *)v10 + 8i64) )
              v11 = 1;
          }
        }
      }
    }
  }
  *v4 = v11;
  if ( !v11 )
  {
    v12 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v5->pImpl.pObject;
    v17 = 0;
    if ( v12 )
    {
      v13 = v12[1].pTable;
      if ( v13 )
      {
        v14 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                v12 + 1,
                v3,
                v3->pNode->HashFlags & v13->SizeMask);
        if ( v14 >= 0 )
        {
          v15 = (signed __int64)v13 + 8 * (3 * v14 + 3);
          if ( v15 )
          {
            v16 = v15 + 8;
            if ( v16 )
            {
              if ( *(_QWORD *)v16 && *(_QWORD *)(*(_QWORD *)v16 + 8i64) )
                v17 = 1;
            }
          }
        }
      }
    }
    *v4 = v17;
    if ( !v17 )
    {
      v18 = v5->pTraits.pObject;
      if ( (unsigned int)(v18->TraitsType - 22) <= 0xC )
      {
        if ( ~(LOBYTE(v18->Flags) >> 5) & 1 )
        {
          evtFlowArray.pHeap = v18->pVM->MHeap;
          v19 = 0i64;
          evtFlowArray.Size = 0i64;
          evtFlowArray.Reserved = 32i64;
          `eh vector constructor iterator'(
            evtFlowArray.Static,
            8ui64,
            32,
            (void (__fastcall *)(void *))Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>::`default constructor closure');
          evtFlowArray.Data = evtFlowArray.Static;
          Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CaptureEventFlow(
            v5,
            (Scaleform::GFx::DisplayObject *)v5[1]._pRCC,
            &evtFlowArray);
          v20 = evtFlowArray.Size;
          if ( evtFlowArray.Size )
          {
            v21 = evtFlowArray.Data;
            while ( 1 )
            {
              v22 = v21[v19].pObject;
              v23 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v22->pImpl.pObject;
              if ( v23 )
              {
                v24.pTable = v23->pTable;
                if ( v23->pTable )
                {
                  v25 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                          v23,
                          v3,
                          v3->pNode->HashFlags & v24.pTable->SizeMask);
                  if ( v25 >= 0 )
                  {
                    v26 = (signed __int64)v24.pTable + 8 * (3 * v25 + 3);
                    if ( v26 )
                    {
                      v27 = v26 + 8;
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
                          v3,
                          v3->pNode->HashFlags & v29->SizeMask);
                  if ( v30 >= 0 )
                  {
                    v31 = (signed __int64)v29 + 8 * (3 * v30 + 3);
                    if ( v31 )
                    {
                      v32 = v31 + 8;
                      if ( v32 )
                      {
                        if ( *(_QWORD *)v32 && *(_QWORD *)(*(_QWORD *)v32 + 8i64) )
                          v33 = 1;
                      }
                    }
                  }
                }
              }
              *v4 = v33;
              if ( !v33 && ++v19 < v20 )
                continue;
              goto LABEL_45;
            }
            *v4 = 1;
          }
LABEL_45:
          Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>::Clear(&evtFlowArray);
          `eh vector destructor iterator'(
            evtFlowArray.Static,
            8ui64,
            32,
            (void (__fastcall *)(void *))Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent>::~SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent>);
        }
      }
    }
  }
}

// File Line: 374
// RVA: 0x78A840
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::~EventDispatcher(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v1; // rbx

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::`vftable';
  Scaleform::AutoPtr<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl>::~AutoPtr<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl>(&this->pImpl);
  v1->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instance::`vftable';
  Scaleform::GFx::AS3::Traits::DestructTail(
    (Scaleform::GFx::AS3::Traits *)((_QWORD)v1->pTraits.pObject & 0xFFFFFFFFFFFFFFFEui64),
    (Scaleform::GFx::AS3::Object *)&v1->vfptr);
  Scaleform::GFx::AS3::Object::~Object((Scaleform::GFx::AS3::Object *)&v1->vfptr);
}

// File Line: 391
// RVA: 0x7D5AB0
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash::ForEachChild_GC(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **), Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *ed, bool useCapture)
{
  Scaleform::GFx::AS3::VM *v6; // rbx
  Scaleform::GFx::AS3::RefCountCollector<328> *v7; // r9
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash *v8; // r11
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v9; // r10
  unsigned __int64 v10; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v11; // rcx
  __int64 v12; // r14
  __int64 *v13; // rax
  __int64 v14; // rcx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> *v15; // rsi
  unsigned __int64 v16; // rdi
  __int64 v17; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *v18; // r8
  char v19; // dl
  int v20; // eax
  unsigned __int64 v21; // rdi
  unsigned __int64 v22; // rbp
  __int64 v23; // r15
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *v24; // rdx
  __int64 v25; // r8
  signed __int64 v26; // rbx
  Scaleform::GFx::AS3::WeakProxy *v27; // rdx
  bool v28; // zf
  int v29; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v30; // rdx
  signed __int64 v31; // r8
  unsigned __int64 v32; // rdx
  _QWORD *v33; // rcx
  signed __int64 v34; // [rsp+20h] [rbp-68h]
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *v35; // [rsp+28h] [rbp-60h]
  __m128i v36; // [rsp+30h] [rbp-58h]
  __int64 v37; // [rsp+90h] [rbp+8h]
  Scaleform::GFx::AS3::RefCountCollector<328> *v38; // [rsp+98h] [rbp+10h]
  void (__fastcall *v39)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // [rsp+A0h] [rbp+18h]
  Scaleform::GFx::AS3::VM *v40; // [rsp+A8h] [rbp+20h]

  v40 = vm;
  v39 = op;
  v38 = prcc;
  v34 = -2i64;
  v6 = vm;
  v7 = prcc;
  v8 = this;
  v9 = this->mHash.pTable;
  if ( this->mHash.pTable )
  {
    v10 = 0i64;
    v11 = v9 + 1;
    do
    {
      if ( v11->EntryCount != -2i64 )
        break;
      ++v10;
      v11 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scalefor)((char *)v11 + 24);
    }
    while ( v10 <= v9->SizeMask );
    v36.m128i_i64[0] = (__int64)v8;
    v36.m128i_i64[1] = v10;
  }
  else
  {
    v36 = 0ui64;
  }
  _mm_store_si128(&v36, v36);
  v12 = v36.m128i_i64[1];
  v37 = v36.m128i_i64[1];
LABEL_8:
  v13 = (__int64 *)v36.m128i_i64[0];
  while ( v13 )
  {
    v14 = *v13;
    if ( !*v13 || v12 > *(_QWORD *)(v14 + 8) )
      break;
    v15 = *(Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> **)(24 * v12 + v14 + 32);
    if ( !v15 )
      goto LABEL_57;
    if ( v6->InDestructor )
    {
      v16 = v15->Size;
      if ( !v16 )
        goto LABEL_57;
      v17 = 0i64;
      while ( 2 )
      {
        v18 = &v15->Data[v17];
        v19 = (v18->mFunction.Flags >> 9) & 1;
        if ( !v19 || v18->mFunction.Bonus.pWeakProxy->pObject )
        {
          v20 = v18->mFunction.Flags & 0x1F;
          if ( v20 > 10 && !v19 && v20 >= 11 )
          {
            if ( v20 <= 15 )
            {
              if ( *(_QWORD *)&v18->mFunction.value.VNumber )
                goto LABEL_26;
            }
            else if ( v20 <= 17 && v18->mFunction.value.VS._2.VObj )
            {
LABEL_26:
              ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))v39)(v7);
              v7 = v38;
            }
          }
        }
        ++v17;
        if ( !--v16 )
          goto LABEL_56;
        continue;
      }
    }
    v21 = 0i64;
    v22 = v15->Size;
    if ( !v22 )
      goto LABEL_57;
    v23 = 0i64;
    do
    {
      v24 = &v15->Data[v23];
      v25 = v24->mFunction.Flags >> 9;
      LOBYTE(v25) = v25 & 1;
      if ( !(_BYTE)v25 || v24->mFunction.Bonus.pWeakProxy->pObject )
      {
        v29 = v24->mFunction.Flags & 0x1F;
        if ( v29 > 10 && !(_BYTE)v25 && v29 >= 11 )
        {
          if ( v29 <= 15 )
          {
            v31 = (signed __int64)&v24->mFunction.value;
            if ( *(_QWORD *)&v24->mFunction.value.VNumber )
            {
              v30 = 0i64;
              if ( (unsigned int)(v29 - 11) <= 4 )
                v30 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)v31;
LABEL_53:
              v39(v7, v30);
            }
          }
          else if ( v29 <= 17 )
          {
            v30 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v24->mFunction.value.VS._2.VObj;
            if ( *v30 )
              goto LABEL_53;
          }
        }
        ++v21;
        ++v23;
        goto LABEL_55;
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
        v35 = &v15->Data[v23];
        v26 = (signed __int64)&v24->mFunction;
        if ( (v24->mFunction.Flags & 0x1F) > 9 )
        {
          if ( (v24->mFunction.Flags >> 9) & 1 )
          {
            v27 = v24->mFunction.Bonus.pWeakProxy;
            v28 = v27->RefCount-- == 1;
            if ( v28 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *, __int64, Scaleform::GFx::AS3::RefCountCollector<328> *, signed __int64, Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
                Scaleform::Memory::pGlobalHeap,
                v27,
                v25,
                v7,
                v34,
                v35);
            *(_QWORD *)(v26 + 8) = 0i64;
            *(_QWORD *)(v26 + 16) = 0i64;
            *(_QWORD *)(v26 + 24) = 0i64;
            *(_DWORD *)v26 &= 0xFFFFFDE0;
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
        (Scaleform::GFx::ASString *)(24 * v12 + *(_QWORD *)v36.m128i_i64[0] + 24i64),
        useCapture,
        --v22);
LABEL_55:
      v7 = v38;
    }
    while ( v21 < v22 );
LABEL_56:
    v6 = v40;
    v12 = v37;
LABEL_57:
    v13 = (__int64 *)v36.m128i_i64[0];
    v32 = *(_QWORD *)(*(_QWORD *)v36.m128i_i64[0] + 8i64);
    v7 = v38;
    if ( v12 <= (signed __int64)v32 )
    {
      v37 = ++v12;
      if ( v12 <= v32 )
      {
        v33 = (_QWORD *)(*(_QWORD *)v36.m128i_i64[0] + 24 * v12 + 16);
        while ( 1 )
        {
          v7 = v38;
          v13 = (__int64 *)v36.m128i_i64[0];
          if ( *v33 != -2i64 )
            break;
          v37 = ++v12;
          v33 += 3;
          if ( v12 > v32 )
            goto LABEL_8;
        }
      }
    }
  }
}

// File Line: 435
// RVA: 0x7D5760
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ForEachChild_GC(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  void (__fastcall *v3)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // rdi
  Scaleform::GFx::AS3::RefCountCollector<328> *v4; // rsi
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *ed; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash *v6; // rcx

  v3 = op;
  v4 = prcc;
  ed = this;
  Scaleform::GFx::AS3::Object::ForEachChild_GC((Scaleform::GFx::AS3::Object *)&this->vfptr, prcc, op);
  v6 = &ed->pImpl.pObject->CaptureListeners;
  if ( v6 )
  {
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash::ForEachChild_GC(
      v6,
      v4,
      v3,
      ed->VMRef,
      ed,
      1);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash::ForEachChild_GC(
      &ed->pImpl.pObject->Listeners,
      v4,
      v3,
      ed->VMRef,
      ed,
      0);
  }
}

// File Line: 447
// RVA: 0x7BC990
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *__fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateEventObject(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *result, Scaleform::GFx::ASString *type, bool bubbles, bool cancelable)
{
  bool v5; // si
  Scaleform::GFx::ASString *v6; // rbp
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *v7; // rdi
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher **v8; // rbx

  v5 = bubbles;
  v6 = type;
  v7 = result;
  v8 = (Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher **)this->pTraits.pObject;
  if ( !v8[17] )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Traits *))(*v8)->MouseEventTraits.pObject)(this->pTraits.pObject);
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateEventObject(v8[17], v7, v6, v5, cancelable);
  return v7;
}

// File Line: 453
// RVA: 0x7BE740
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent> *__fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateProgressEventObject(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent> *result, Scaleform::GFx::ASString *type)
{
  Scaleform::GFx::ASString *v3; // rsi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent> *v4; // rdi
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher **v5; // rbx

  v3 = type;
  v4 = result;
  v5 = (Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher **)this->pTraits.pObject;
  if ( !v5[17] )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Traits *))(*v5)->MouseEventTraits.pObject)(this->pTraits.pObject);
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateProgressEventObject(v5[17], v4, v3);
  return v4;
}

// File Line: 469
// RVA: 0x7BCCE0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::FocusEvent> *__fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateFocusEventObject(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::FocusEvent> *result, Scaleform::GFx::ASString *type, Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *relatedObj, unsigned int controllerIdx, bool shiftKey)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v6; // rsi
  Scaleform::GFx::ASString *v7; // rbp
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::FocusEvent> *v8; // rdi
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher **v9; // rbx
  int v11[2]; // [rsp+28h] [rbp-30h]

  v6 = relatedObj;
  v7 = type;
  v8 = result;
  v9 = (Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher **)this->pTraits.pObject;
  if ( !v9[17] )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Traits *))(*v9)->MouseEventTraits.pObject)(this->pTraits.pObject);
  LOBYTE(v11[0]) = shiftKey;
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateFocusEventObject(
    v9[17],
    v8,
    v7,
    v6,
    controllerIdx,
    v11[0]);
  return v8;
}

// File Line: 475
// RVA: 0x7BD780
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent> *__fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateIOErrorEventObject(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent> *result, const char *errText)
{
  const char *v3; // rsi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent> *v4; // rdi
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher **v5; // rbx

  v3 = errText;
  v4 = result;
  v5 = (Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher **)this->pTraits.pObject;
  if ( !v5[17] )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Traits *))(*v5)->MouseEventTraits.pObject)(this->pTraits.pObject);
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateIOErrorEventObject(v5[17], v4, v3);
  return v4;
}

// File Line: 514
// RVA: 0x7C4BD0
__int64 __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this, Scaleform::GFx::EventId *evtId, Scaleform::GFx::DisplayObject *dispObject)
{
  Scaleform::GFx::DisplayObject *v3; // r12
  Scaleform::GFx::EventId *v4; // r14
  Scaleform::GFx::AS3::Instances::fl::XMLList *target; // r13
  Scaleform::GFx::AS3::Traits *v6; // rbx
  Scaleform::GFx::AS3::VM *v7; // rdi
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *v8; // r10
  Scaleform::GFx::AS3::Instances::fl_events::Event *v9; // rbx
  unsigned int v10; // eax
  Scaleform::GFx::AS3::Object *v11; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v12; // rcx
  Scaleform::GFx::AS3::Object *v13; // rcx
  Scaleform::GFx::AS3::Object *v14; // rcx
  unsigned __int8 v15; // di
  Scaleform::GFx::AS3::Instances::fl_events::Event *v16; // rcx
  Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *v17; // rcx
  Scaleform::GFx::AS3::Object *v18; // rcx
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v19; // rcx
  Scaleform::GFx::AS3::Object *v20; // rcx
  unsigned int v21; // eax
  Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *v22; // rcx
  Scaleform::GFx::AS3::Instances::fl_events::Event *v23; // rsi
  __int64 v24; // rax
  signed __int64 v25; // rax
  __int64 v26; // rcx
  signed __int64 v27; // r15
  Scaleform::GFx::AS3::Instances::fl::XMLList *v28; // rdx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v29; // rcx
  unsigned int v30; // eax
  Scaleform::GFx::ASString *v31; // r8
  Scaleform::GFx::ASString *v32; // r8
  unsigned int v33; // eax
  Scaleform::GFx::AS3::Instances::fl_events::Event *v34; // rsi
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v35; // rcx
  unsigned int v36; // eax
  __int64 v37; // rax
  signed __int64 v38; // rax
  __int64 v39; // rcx
  signed __int64 v40; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v41; // rdx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Traits> *v42; // rdi
  Scaleform::GFx::AS3::Traits *v43; // rcx
  unsigned int v44; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v45; // rcx
  unsigned int v46; // eax
  unsigned int v47; // eax
  Scaleform::GFx::AS3::Object *v48; // rcx
  Scaleform::GFx::AS3::Object *v49; // rcx
  Scaleform::GFx::AS3::Object *v50; // rcx
  Scaleform::GFx::AS3::Instances::fl_events::AccelerometerEvent *v51; // rcx
  Scaleform::GFx::AS3::Instances::fl_events::GeolocationEvent *v52; // rcx
  Scaleform::GFx::ASString *v53; // rcx
  unsigned int v54; // eax
  unsigned int v55; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> v57; // [rsp+30h] [rbp-49h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> v58; // [rsp+38h] [rbp-41h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> v59; // [rsp+40h] [rbp-39h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> v60; // [rsp+48h] [rbp-31h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> v61; // [rsp+50h] [rbp-29h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> v62; // [rsp+58h] [rbp-21h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent> v63; // [rsp+60h] [rbp-19h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::AccelerometerEvent> v64; // [rsp+68h] [rbp-11h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent> v65; // [rsp+70h] [rbp-9h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::GeolocationEvent> v66; // [rsp+78h] [rbp-1h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> v67; // [rsp+80h] [rbp+7h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::StatusEvent> v68; // [rsp+88h] [rbp+Fh]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> v69; // [rsp+90h] [rbp+17h]
  __int64 v70; // [rsp+98h] [rbp+1Fh]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> v71; // [rsp+E8h] [rbp+6Fh]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> result; // [rsp+F8h] [rbp+7Fh]

  v70 = -2i64;
  v3 = dispObject;
  v4 = evtId;
  target = (Scaleform::GFx::AS3::Instances::fl::XMLList *)this;
  v6 = this->pTraits.pObject;
  v7 = v6->pVM;
  if ( !v6->pConstructor.pObject )
    v6->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&this->pTraits.pObject->vfptr);
  v8 = (Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *)v6->pConstructor.pObject;
  v9 = 0i64;
  v10 = v4->Id;
  if ( v4->Id > 0x100000A )
  {
    switch ( v10 )
    {
      case 0x100000Bu:
        v34 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
                                                                    v8,
                                                                    &v57,
                                                                    v4,
                                                                    (Scaleform::GFx::ASString *)&v7[1].vfptr[96],
                                                                    (Scaleform::GFx::AS3::Instances::fl::Object *)&target->vfptr)->pObject;
        v71.pObject = v34;
        if ( v34 )
          v34->RefCount = (v34->RefCount + 1) & 0x8FBFFFFF;
        v35 = v57.pObject;
        if ( v57.pObject )
        {
          if ( (_QWORD)v57.pObject & 1 )
          {
            --v57.pObject;
          }
          else
          {
            v36 = v57.pObject->RefCount;
            if ( v36 & 0x3FFFFF )
            {
              v57.pObject->RefCount = v36 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v35->vfptr);
            }
          }
        }
        if ( v34 )
        {
          v34->RefCount = (v34->RefCount + 1) & 0x8FBFFFFF;
          v9 = v34;
        }
        v37 = (unsigned int)v4->ControllerIndex;
        if ( (unsigned int)v37 < 6
          && (v38 = (signed __int64)&v7[1].vfptr[28 * (v37 + 4)]) != 0
          && (v39 = *(_QWORD *)(v38 + 24)) != 0 )
        {
          v40 = v39 + 4i64 * *(unsigned __int8 *)(v39 + 109);
          v41 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v40 + 16);
          if ( !v41 )
            v41 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v40 + 8);
          if ( (unsigned __int8)v41 & 1 )
            v41 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v41 - 1);
          v42 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Traits> *)&v34[1].8;
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v34[1].8,
            v41);
        }
        else
        {
          v42 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Traits> *)&v34[1].8;
          v43 = (Scaleform::GFx::AS3::Traits *)v34[1]._pRCC;
          if ( v43 )
          {
            if ( (unsigned __int8)v43 & 1 )
            {
              v42->pObject = (Scaleform::GFx::AS3::Traits *)((char *)v43 - 1);
            }
            else
            {
              v44 = v43->RefCount;
              if ( v44 & 0x3FFFFF )
              {
                v43->RefCount = v44 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v43->vfptr);
              }
            }
            v42->pObject = 0i64;
          }
        }
        if ( (Scaleform::GFx::AS3::Instances::fl::XMLList *)v42->pObject == target )
        {
          v45 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v42->pObject;
          if ( v42->pObject )
          {
            if ( (unsigned __int8)v45 & 1 )
            {
              v42->pObject = (Scaleform::GFx::AS3::Traits *)((char *)&v45[-1].List.Data.Policy.Capacity + 7);
            }
            else
            {
              v46 = v45->RefCount;
              if ( v46 & 0x3FFFFF )
              {
                v45->RefCount = v46 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v45->vfptr);
              }
            }
            v42->pObject = 0i64;
          }
        }
        if ( (unsigned __int8)v34 & 1 )
        {
          v71.pObject = (Scaleform::GFx::AS3::Instances::fl_events::Event *)((char *)v34 - 1);
          goto LABEL_163;
        }
        v47 = v34->RefCount;
        if ( !(v47 & 0x3FFFFF) )
          goto LABEL_163;
        v34->RefCount = v47 - 1;
        v12 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v34->vfptr;
        break;
      case 0x100000Cu:
        v48 = Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
                v8,
                &v58,
                v4,
                (Scaleform::GFx::ASString *)&v7[1].vfptr[92],
                (Scaleform::GFx::AS3::Instances::fl::Object *)&target->vfptr)->pObject;
        if ( v48 )
        {
          v48->RefCount = (v48->RefCount + 1) & 0x8FBFFFFF;
          v9 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v48;
        }
        v12 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v58.pObject;
        if ( !v58.pObject )
          goto LABEL_163;
        if ( !((_QWORD)v58.pObject & 1) )
          goto LABEL_160;
        --v58.pObject;
        goto LABEL_163;
      case 0x100000Du:
        v49 = Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
                v8,
                &v60,
                v4,
                (Scaleform::GFx::ASString *)&v7[1].vfptr[93],
                (Scaleform::GFx::AS3::Instances::fl::Object *)&target->vfptr)->pObject;
        if ( v49 )
        {
          v49->RefCount = (v49->RefCount + 1) & 0x8FBFFFFF;
          v9 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v49;
        }
        v12 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v60.pObject;
        if ( !v60.pObject )
          goto LABEL_163;
        if ( !((_QWORD)v60.pObject & 1) )
          goto LABEL_160;
        --v60.pObject;
        goto LABEL_163;
      case 0x100000Eu:
        v50 = Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
                v8,
                &v62,
                v4,
                (Scaleform::GFx::ASString *)&v7[1].vfptr[99],
                (Scaleform::GFx::AS3::Instances::fl::Object *)&target->vfptr)->pObject;
        if ( v50 )
        {
          v50->RefCount = (v50->RefCount + 1) & 0x8FBFFFFF;
          v9 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v50;
        }
        v12 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v62.pObject;
        if ( !v62.pObject )
          goto LABEL_163;
        if ( !((_QWORD)v62.pObject & 1) )
          goto LABEL_160;
        --v62.pObject;
        goto LABEL_163;
      case 0x1000011u:
      case 0x1000012u:
        v31 = (Scaleform::GFx::ASString *)v7[1].vfptr;
        if ( v4->Id == 16777233 )
          v32 = v31 + 73;
        else
          v32 = v31 + 78;
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateEventObject(v8, &v71, v32, 0, 0);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v71.pObject->Target,
          target);
        if ( !Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(
                (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)target,
                v71.pObject,
                0)
          && v3 )
        {
          v3->Flags |= 0x20u;
        }
        v15 = ~(*((_BYTE *)v71.pObject + 84) >> 2) & 1;
        goto LABEL_30;
      case 0x1000013u:
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateEventObject(
          v8,
          &v71,
          (Scaleform::GFx::ASString *)&v7[1].vfptr[89],
          0,
          0);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v71.pObject->Target,
          target);
        if ( !Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(
                (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)target,
                v71.pObject,
                0)
          && v3 )
        {
          v3->Flags |= 0x20u;
        }
        v15 = ~(*((_BYTE *)v71.pObject + 84) >> 2) & 1;
        goto LABEL_30;
      case 0x1000014u:
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateEventObject(
          v8,
          &v71,
          (Scaleform::GFx::ASString *)&v7[1].vfptr[90],
          0,
          0);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v71.pObject->Target,
          target);
        if ( !Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(
                (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)target,
                v71.pObject,
                0)
          && v3 )
        {
          v3->Flags |= 0x20u;
        }
        v15 = ~(*((_BYTE *)v71.pObject + 84) >> 2) & 1;
        goto LABEL_30;
      case 0x1000024u:
        v51 = Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateAccelerometerEventObject(
                v8,
                &v64,
                v4,
                (Scaleform::GFx::ASString *)&v7[1].vfptr[104],
                (Scaleform::GFx::AS3::Instances::fl::Object *)&target->vfptr)->pObject;
        if ( v51 )
        {
          v51->RefCount = (v51->RefCount + 1) & 0x8FBFFFFF;
          v9 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)&v51->vfptr;
        }
        v12 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v64.pObject;
        if ( !v64.pObject )
          goto LABEL_163;
        if ( !((_QWORD)v64.pObject & 1) )
          goto LABEL_160;
        --v64.pObject;
        goto LABEL_163;
      case 0x1000025u:
        v52 = Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateGeolocationEventObject(
                v8,
                &v66,
                v4,
                (Scaleform::GFx::ASString *)&v7[1].vfptr[104],
                (Scaleform::GFx::AS3::Instances::fl::Object *)&target->vfptr)->pObject;
        if ( v52 )
        {
          v52->RefCount = (v52->RefCount + 1) & 0x8FBFFFFF;
          v9 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)&v52->vfptr;
        }
        v12 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v66.pObject;
        if ( !v66.pObject )
          goto LABEL_163;
        if ( !((_QWORD)v66.pObject & 1) )
          goto LABEL_160;
        --v66.pObject;
        goto LABEL_163;
      case 0x1000026u:
        v53 = *Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateStatusEventObject(
                 v8,
                 &v68,
                 v4,
                 (Scaleform::GFx::ASString *)&v7[1].vfptr[105],
                 (Scaleform::GFx::AS3::Instances::fl::Object *)&target->vfptr);
        if ( v53 )
        {
          LODWORD(v53[4].pNode) = (LODWORD(v53[4].pNode) + 1) & 0x8FBFFFFF;
          v9 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v53;
        }
        v12 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v68.pObject;
        if ( !v68.pObject )
          goto LABEL_163;
        if ( !((_QWORD)v68.pObject & 1) )
          goto LABEL_160;
        --v68.pObject;
        goto LABEL_163;
      default:
        goto LABEL_164;
    }
    goto LABEL_162;
  }
  if ( v10 == 16777226 )
  {
    Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
      v8,
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> *)&v71,
      v4,
      (Scaleform::GFx::ASString *)&v7[1].vfptr[97],
      (Scaleform::GFx::AS3::Instances::fl::Object *)&target->vfptr);
    v23 = v71.pObject;
    if ( v71.pObject )
    {
      ++v71.pObject->RefCount;
      v23->RefCount &= 0x8FBFFFFF;
      v9 = v23;
      v23 = v71.pObject;
    }
    v24 = (unsigned int)v4->ControllerIndex;
    if ( (unsigned int)v24 < 6
      && (v25 = (signed __int64)&v7[1].vfptr[28 * (v24 + 4)]) != 0
      && (v26 = *(_QWORD *)(v25 + 24)) != 0 )
    {
      v27 = v26 + 4i64 * *(unsigned __int8 *)(v26 + 109);
      v28 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v27 + 16);
      if ( !v28 )
        v28 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v27 + 8);
      if ( (unsigned __int8)v28 & 1 )
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
        if ( (unsigned __int8)v29 & 1 )
        {
          v23[1].pRCCRaw = (unsigned __int64)&v29[-1].RefCount + 7;
        }
        else
        {
          v30 = v29->RefCount;
          if ( v30 & 0x3FFFFF )
          {
            v29->RefCount = v30 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v29);
          }
        }
        v23[1].pRCCRaw = 0i64;
      }
    }
    v12 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v71.pObject;
    if ( !v71.pObject )
      goto LABEL_163;
    if ( (_QWORD)v71.pObject & 1 )
    {
      --v71.pObject;
      goto LABEL_163;
    }
    goto LABEL_160;
  }
  if ( v10 > 0x40 )
  {
    switch ( v10 )
    {
      case 0x80u:
        v22 = Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateKeyboardEventObject(
                v8,
                &v63,
                v4,
                (Scaleform::GFx::ASString *)&v7[1].vfptr[103],
                (Scaleform::GFx::AS3::Instances::fl::Object *)&target->vfptr)->pObject;
        if ( v22 )
        {
          v22->RefCount = (v22->RefCount + 1) & 0x8FBFFFFF;
          v9 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)&v22->vfptr;
        }
        v12 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v63.pObject;
        if ( !v63.pObject )
          goto LABEL_163;
        if ( (_QWORD)v63.pObject & 1 )
        {
          --v63.pObject;
          goto LABEL_163;
        }
        goto LABEL_160;
      case 0x2000u:
        v20 = Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
                v8,
                &v69,
                v4,
                (Scaleform::GFx::ASString *)&v7[1].vfptr[101],
                (Scaleform::GFx::AS3::Instances::fl::Object *)&target->vfptr)->pObject;
        if ( v20 )
        {
          v20->RefCount = (v20->RefCount + 1) & 0x8FBFFFFF;
          v9 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v20;
        }
        v19 = v69.pObject;
        if ( !v69.pObject )
          goto LABEL_53;
        if ( (_QWORD)v69.pObject & 1 )
        {
          --v69.pObject;
          goto LABEL_53;
        }
        break;
      case 0x4000u:
        v18 = Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
                v8,
                &v61,
                v4,
                (Scaleform::GFx::ASString *)&v7[1].vfptr[100],
                (Scaleform::GFx::AS3::Instances::fl::Object *)&target->vfptr)->pObject;
        if ( v18 )
        {
          v18->RefCount = (v18->RefCount + 1) & 0x8FBFFFFF;
          v9 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v18;
        }
        v19 = v61.pObject;
        if ( !v61.pObject )
        {
LABEL_53:
          *((_BYTE *)v9 + 84) &= 0xFEu;
          goto LABEL_163;
        }
        if ( (_QWORD)v61.pObject & 1 )
        {
          --v61.pObject;
          goto LABEL_53;
        }
        break;
      default:
        goto LABEL_164;
    }
    v21 = v19->RefCount;
    if ( v21 & 0x3FFFFF )
    {
      v19->RefCount = v21 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v19->vfptr);
    }
    goto LABEL_53;
  }
  if ( v10 == 64 )
  {
    v17 = Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateKeyboardEventObject(
            v8,
            &v65,
            v4,
            (Scaleform::GFx::ASString *)&v7[1].vfptr[102],
            (Scaleform::GFx::AS3::Instances::fl::Object *)&target->vfptr)->pObject;
    if ( v17 )
    {
      v17->RefCount = (v17->RefCount + 1) & 0x8FBFFFFF;
      v9 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)&v17->vfptr;
    }
    v12 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v65.pObject;
    if ( !v65.pObject )
      goto LABEL_163;
    if ( (_QWORD)v65.pObject & 1 )
    {
      --v65.pObject;
      goto LABEL_163;
    }
    goto LABEL_160;
  }
  if ( v10 != 2 )
  {
    if ( v10 != 8 )
    {
      if ( v10 == 16 )
      {
        v13 = Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
                v8,
                &v67,
                v4,
                (Scaleform::GFx::ASString *)&v7[1].vfptr[94],
                (Scaleform::GFx::AS3::Instances::fl::Object *)&target->vfptr)->pObject;
        if ( v13 )
        {
          v13->RefCount = (v13->RefCount + 1) & 0x8FBFFFFF;
          v9 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v13;
        }
        v12 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v67.pObject;
        if ( !v67.pObject )
          goto LABEL_163;
        if ( (_QWORD)v67.pObject & 1 )
        {
          --v67.pObject;
          goto LABEL_163;
        }
        goto LABEL_160;
      }
      if ( v10 == 32 )
      {
        v11 = Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
                v8,
                &result,
                v4,
                (Scaleform::GFx::ASString *)&v7[1].vfptr[98],
                (Scaleform::GFx::AS3::Instances::fl::Object *)&target->vfptr)->pObject;
        if ( v11 )
        {
          v11->RefCount = (v11->RefCount + 1) & 0x8FBFFFFF;
          v9 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v11;
        }
        v12 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)result.pObject;
        if ( !result.pObject )
          goto LABEL_163;
        if ( (_QWORD)result.pObject & 1 )
        {
          --result.pObject;
LABEL_163:
          Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(
            (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)target,
            v9,
            v3);
          v15 = ~(*((_BYTE *)v9 + 84) >> 2) & 1;
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
            &v59,
            v4,
            (Scaleform::GFx::ASString *)&v7[1].vfptr[95],
            (Scaleform::GFx::AS3::Instances::fl::Object *)&target->vfptr)->pObject;
    if ( v14 )
    {
      v14->RefCount = (v14->RefCount + 1) & 0x8FBFFFFF;
      v9 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v14;
    }
    v12 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v59.pObject;
    if ( !v59.pObject )
      goto LABEL_163;
    if ( (_QWORD)v59.pObject & 1 )
    {
      --v59.pObject;
      goto LABEL_163;
    }
LABEL_160:
    v54 = v12->RefCount;
    if ( !(v54 & 0x3FFFFF) )
      goto LABEL_163;
    v12->RefCount = v54 - 1;
LABEL_162:
    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v12);
    goto LABEL_163;
  }
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateEventObject(
    v8,
    &v71,
    (Scaleform::GFx::ASString *)&v7[1].vfptr[79],
    0,
    0);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v71.pObject->Target,
    target);
  if ( !Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(
          (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)target,
          v71.pObject,
          0)
    && v3 )
  {
    v3->Flags |= 0x20u;
  }
  v15 = ~(*((_BYTE *)v71.pObject + 84) >> 2) & 1;
LABEL_30:
  v16 = v71.pObject;
  if ( v71.pObject )
  {
    if ( (_QWORD)v71.pObject & 1 )
    {
      --v71.pObject;
    }
    else
    {
      v33 = v71.pObject->RefCount;
      if ( v33 & 0x3FFFFF )
      {
        v71.pObject->RefCount = v33 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v16->vfptr);
      }
    }
  }
LABEL_165:
  if ( v9 )
  {
    if ( !((unsigned __int8)v9 & 1) )
    {
      v55 = v9->RefCount;
      if ( v55 & 0x3FFFFF )
      {
        v9->RefCount = v55 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v9->vfptr);
      }
    }
  }
  return v15;
}

// File Line: 719
// RVA: 0x7C56B0
__int64 __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this, Scaleform::GFx::AS3::Instances::fl_events::Event *evtObj, Scaleform::GFx::DisplayObject *dispObject)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl_events::Event *v4; // rsi
  Scaleform::GFx::DisplayObject *v5; // rbx

  v3 = this;
  v4 = evtObj;
  v5 = dispObject;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&evtObj->Target,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)this);
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(v3, v4, v5);
  return ~(*((_BYTE *)v4 + 84) >> 2) & 1;
}

// File Line: 729
// RVA: 0x7C6420
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this, Scaleform::GFx::AS3::Instances::fl_events::Event *evt, Scaleform::GFx::DisplayObject *dispObject)
{
  Scaleform::GFx::DisplayObject *v3; // r14
  Scaleform::GFx::AS3::Instances::fl_events::Event *v4; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v5; // rsi
  __int64 v6; // rdi
  unsigned __int64 v7; // rbp
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v8; // rax
  char v9; // al
  unsigned __int64 v10; // rbp
  unsigned int v11; // eax
  Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> evtFlowArray; // [rsp+40h] [rbp-148h]

  v3 = dispObject;
  v4 = evt;
  v5 = this;
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
  `eh vector constructor iterator'(
    evtFlowArray.Static,
    8ui64,
    32,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>::`default constructor closure');
  evtFlowArray.Data = evtFlowArray.Static;
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CaptureEventFlow(v5, v3, &evtFlowArray);
  v4->Phase = 1;
  v7 = evtFlowArray.Size - 1;
  if ( (signed __int64)(evtFlowArray.Size - 1) >= 0 )
  {
    while ( Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(
              (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&evtFlowArray.Data[v7].pObject->vfptr,
              v4,
              1) )
    {
      if ( Scaleform::GFx::AS3::Instances::fl_events::Event::IsPropagationStopped(v4) )
        goto LABEL_23;
      if ( (--v7 & 0x8000000000000000ui64) != 0i64 )
        goto LABEL_10;
    }
    v8 = evtFlowArray.Data[v7].pObject;
    goto LABEL_21;
  }
LABEL_10:
  v4->Phase = 2;
  if ( Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(v5, v4, 0) )
  {
    v9 = *((_BYTE *)v4 + 84);
    if ( !(v9 & 8) && !(v9 & 0x10) )
    {
      if ( v9 & 1 )
      {
        v4->Phase = 3;
        v10 = evtFlowArray.Size;
        if ( evtFlowArray.Size )
        {
          while ( Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(
                    (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&evtFlowArray.Data[v6].pObject->vfptr,
                    v4,
                    0) )
          {
            if ( !Scaleform::GFx::AS3::Instances::fl_events::Event::IsPropagationStopped(v4) && ++v6 < v10 )
              continue;
            goto LABEL_23;
          }
          v8 = evtFlowArray.Data[v6].pObject;
LABEL_21:
          if ( v8->pDispObj.pObject )
            v8->pDispObj.pObject->Flags |= 0x20u;
          goto LABEL_23;
        }
      }
    }
  }
  else
  {
    v3->Flags |= 0x20u;
  }
LABEL_23:
  Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>::Clear(&evtFlowArray);
  `eh vector destructor iterator'(
    evtFlowArray.Static,
    8ui64,
    32,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent>::~SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent>);
  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v3->vfptr);
  if ( !((unsigned __int8)v5 & 1) )
  {
    v11 = v5->RefCount;
    if ( v11 & 0x3FFFFF )
    {
      v5->RefCount = v11 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v5->vfptr);
    }
  }
}CountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v5->vfptr);
    }

// File Line: 811
// RVA: 0x7B3320
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CaptureEventFlow(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this, Scaleform::GFx::DisplayObject *dispObject, Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> *evtFlowArray)
{
  Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> *v3; // rsi
  Scaleform::GFx::InteractiveObject *i; // rdi
  signed __int64 v5; // rcx
  __int64 v6; // rax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v7; // rbx
  unsigned int v8; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> val; // [rsp+48h] [rbp+10h]

  v3 = evtFlowArray;
  for ( i = dispObject->pParent; i; i = i->pParent )
  {
    v5 = (signed __int64)i + 4 * (unsigned __int8)i->AvmObjOffset;
    v6 = (*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v5 + 8i64))(v5);
    if ( v6 )
      v6 -= 56i64;
    v7 = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)(v6 + 16);
    if ( !v7 )
      v7 = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)(v6 + 8);
    if ( (unsigned __int8)v7 & 1 )
      v7 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v7 - 1);
    if ( v7 )
    {
      val.pObject = v7;
      v7->RefCount = (v7->RefCount + 1) & 0x8FBFFFFF;
      Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>::PushBack(
        v3,
        &val);
      if ( (unsigned __int8)v7 & 1 )
      {
        val.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v7 - 1);
      }
      else
      {
        v8 = v7->RefCount;
        if ( v8 & 0x3FFFFF )
        {
          v7->RefCount = v8 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v7->vfptr);
        }
      }
    }
  }
}

// File Line: 826
// RVA: 0x7C5700
char __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this, Scaleform::GFx::AS3::Instances::fl_events::Event *evtObj, bool useCapture)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *v3; // r14
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v4; // r13
  int v5; // esi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v7; // rcx
  Scaleform::GFx::ASString *v8; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v9; // rbx
  signed __int64 v10; // rax
  signed __int64 v11; // rdi
  _QWORD **v12; // rdi
  char v13; // bl
  _QWORD *v14; // rdi
  unsigned __int64 v15; // rdx
  int v17; // edx
  _QWORD *v18; // r9
  __int64 v19; // r8
  __int64 v20; // r10
  unsigned int v21; // ebx
  int v22; // eax
  bool v23; // zf
  Scaleform::GFx::AS3::Value *v24; // rdx
  char v25; // bl
  __int64 v26; // rax
  int v27; // edx
  __int64 v28; // rdx
  unsigned int v29; // edi
  unsigned int v30; // ebx
  Scaleform::GFx::AS3::Traits *v31; // rcx
  char *v32; // rax
  unsigned __int64 v33; // r15
  unsigned __int64 v34; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *v35; // rcx
  unsigned __int64 v36; // r12
  int v38; // ecx
  Scaleform::GFx::AS3::Object *v39; // r8
  Scaleform::GFx::AS3::Value::V2U v40; // rdx
  Scaleform::GFx::AS3::Value::V2U v41; // r9
  unsigned int v42; // ebx
  int v43; // eax
  Scaleform::GFx::AS3::Value *v44; // rdx
  Scaleform::GFx::AS3::Value::V2U v45; // rax
  int v46; // ecx
  Scaleform::GFx::AS3::Value::V2U v47; // rcx
  unsigned int v48; // ebx
  unsigned int v49; // ebx
  Scaleform::GFx::AS3::Traits *v50; // rcx
  char v51; // bl
  unsigned __int64 v52; // r12
  Scaleform::GFx::AS3::Value *v53; // rbx
  unsigned __int64 v54; // r15
  Scaleform::GFx::AS3::WeakProxy *v55; // rdx
  unsigned int v56; // ecx
  Scaleform::GFx::AS3::Value v57; // [rsp+48h] [rbp-B8h]
  Scaleform::GFx::AS3::Value func; // [rsp+68h] [rbp-98h]
  Scaleform::GFx::AS3::Value argv; // [rsp+88h] [rbp-78h]
  Scaleform::GFx::AS3::Value _this; // [rsp+A8h] [rbp-58h]
  Scaleform::GFx::AS3::Value result; // [rsp+C8h] [rbp-38h]
  unsigned __int64 v62; // [rsp+E8h] [rbp-18h]
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v63; // [rsp+F0h] [rbp-10h]
  char *v64; // [rsp+F8h] [rbp-8h]
  char *v65; // [rsp+100h] [rbp+0h]
  __int64 v66; // [rsp+108h] [rbp+8h]
  char v67; // [rsp+110h] [rbp+10h]
  char v68; // [rsp+2E0h] [rbp+1E0h]
  char *v69; // [rsp+2F8h] [rbp+1F8h]

  v66 = -2i64;
  v3 = evtObj;
  v4 = this;
  v5 = 0;
  if ( !this->pImpl.pObject )
    return 1;
  v63 = this;
  this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  if ( useCapture )
    v7 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)this->pImpl.pObject;
  else
    v7 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->pImpl.pObject->Listeners;
  v8 = &evtObj->Type;
  v9.pTable = v7->pTable;
  if ( v7->pTable
    && (v10 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                v7,
                v8,
                v8->pNode->HashFlags & v9.pTable->SizeMask),
        v10 >= 0)
    && (v11 = (signed __int64)v9.pTable + 8 * (3 * v10 + 3)) != 0 )
  {
    v12 = (_QWORD **)(v11 + 8);
  }
  else
  {
    v12 = 0i64;
  }
  v13 = 1;
  v68 = 1;
  if ( v12 )
  {
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v3->CurrentTarget,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)v4);
    v14 = *v12;
    v15 = v14[1];
    if ( v15 == 1 )
    {
      _RCX = *v14;
      if ( !((*(_DWORD *)(*v14 + 8i64) >> 9) & 1) || *(_QWORD *)(*(_QWORD *)(_RCX + 16) + 8i64) != 0i64 )
      {
        _this.Flags = 0;
        _this.Bonus.pWeakProxy = 0i64;
        argv.Flags = 12;
        argv.Bonus.pWeakProxy = 0i64;
        *(_QWORD *)&argv.value.VNumber = v3;
        if ( v3 )
          v3->RefCount = (v3->RefCount + 1) & 0x8FBFFFFF;
        result.Flags = 0;
        result.Bonus.pWeakProxy = 0i64;
        v17 = *(_DWORD *)(_RCX + 8);
        if ( (*(_DWORD *)(_RCX + 8) >> 9) & 1 )
        {
          v57.Bonus.pWeakProxy = 0i64;
          __asm { prefetcht1 byte ptr [rcx+8]; Prefetch to all cache levels }
          *(_QWORD *)&v57.Flags = *(_QWORD *)(_RCX + 8);
          v18 = *(_QWORD **)(_RCX + 16);
          v57.Bonus.pWeakProxy = *(Scaleform::GFx::AS3::WeakProxy **)(_RCX + 16);
          v19 = *(_QWORD *)(_RCX + 24);
          v57.value.VNumber = *(long double *)(_RCX + 24);
          v20 = *(_QWORD *)(_RCX + 32);
          v57.value.VS._2.VObj = *(Scaleform::GFx::AS3::Object **)(_RCX + 32);
          if ( (v17 & 0x1F) > 9 )
            ++*(_DWORD *)v18;
          v21 = v57.Flags;
          if ( (v57.Flags >> 9) & 1 )
          {
            if ( v18[1] )
            {
              v22 = v57.Flags & 0x1F;
              if ( v22 == 10 )
              {
                ++*(_DWORD *)(v19 + 24);
              }
              else if ( v22 > 10 )
              {
                if ( v22 <= 15 )
                {
                  if ( v19 )
                    *(_DWORD *)(v19 + 32) = (*(_DWORD *)(v19 + 32) + 1) & 0x8FBFFFFF;
                }
                else if ( v22 <= 17 && v20 )
                {
                  *(_DWORD *)(v20 + 32) = (*(_DWORD *)(v20 + 32) + 1) & 0x8FBFFFFF;
                }
              }
              v23 = (*(_DWORD *)v18)-- == 1;
              if ( v23 )
                Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v18);
            }
            else
            {
              v57.value = 0ui64;
              v21 = v57.Flags & 0xFFFFFFE0;
              v57.Flags &= 0xFFFFFFE0;
            }
            v57.Bonus.pWeakProxy = 0i64;
            v57.Flags = v21 & 0xFFFFFDFF;
          }
          v24 = &v57;
          v25 = 1;
        }
        else
        {
          func.Flags = *(_DWORD *)(_RCX + 8);
          func.Bonus.pWeakProxy = *(Scaleform::GFx::AS3::WeakProxy **)(_RCX + 16);
          func.value.VNumber = *(long double *)(_RCX + 24);
          v26 = *(_QWORD *)(_RCX + 32);
          func.value.VS._2.VObj = *(Scaleform::GFx::AS3::Object **)(_RCX + 32);
          v27 = v17 & 0x1F;
          if ( v27 > 9 )
          {
            if ( v27 == 10 )
            {
              ++*(_DWORD *)(*(_QWORD *)(_RCX + 24) + 24i64);
            }
            else if ( v27 > 10 )
            {
              if ( v27 <= 15 )
              {
                v28 = *(_QWORD *)(_RCX + 24);
                if ( v28 )
                  *(_DWORD *)(v28 + 32) = (*(_DWORD *)(v28 + 32) + 1) & 0x8FBFFFFF;
              }
              else if ( v27 <= 17 && v26 )
              {
                *(_DWORD *)(v26 + 32) = (*(_DWORD *)(v26 + 32) + 1) & 0x8FBFFFFF;
              }
            }
          }
          v24 = &func;
          v25 = 2;
        }
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v4->pTraits.pObject->pVM, v24, &_this, &result, 1u, &argv, 0);
        if ( v25 & 2 )
        {
          v25 &= 0xFDu;
          v29 = func.Flags;
          if ( (func.Flags & 0x1F) > 9 )
          {
            if ( (func.Flags >> 9) & 1 )
            {
              v23 = func.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v23 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              func.Bonus.pWeakProxy = 0i64;
              func.value = 0ui64;
              func.Flags = v29 & 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
            }
          }
        }
        if ( v25 & 1 )
        {
          v30 = v57.Flags;
          if ( (v57.Flags & 0x1F) > 9 )
          {
            if ( (v57.Flags >> 9) & 1 )
            {
              v23 = v57.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v23 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              v57.Bonus.pWeakProxy = 0i64;
              v57.value = 0ui64;
              v57.Flags = v30 & 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v57);
            }
          }
        }
        v31 = v4->pTraits.pObject;
        if ( v31->pVM->HandleException )
        {
          Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v31->pVM);
          v13 = 0;
        }
        else
        {
          v13 = 1;
        }
        if ( (result.Flags & 0x1F) > 9 )
        {
          if ( (result.Flags >> 9) & 1 )
          {
            v23 = result.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v23 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            result.Bonus.pWeakProxy = 0i64;
            result.value = 0ui64;
            result.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
          }
        }
        if ( (argv.Flags & 0x1F) > 9 )
        {
          if ( (argv.Flags >> 9) & 1 )
          {
            v23 = argv.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v23 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            argv.Bonus.pWeakProxy = 0i64;
            argv.value = 0ui64;
            argv.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&argv);
          }
        }
        if ( (_this.Flags & 0x1F) > 9 )
        {
          if ( (_this.Flags >> 9) & 1 )
          {
            v23 = _this.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v23 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            _this.Bonus.pWeakProxy = 0i64;
            _this.value = 0ui64;
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
        v32 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                        Scaleform::Memory::pGlobalHeap,
                        v4,
                        40 * v15,
                        0i64);
      else
        v32 = &v67;
      v69 = v32;
      v33 = v14[1];
      v65 = v32;
      v34 = 0i64;
      v62 = 0i64;
      if ( v33 )
      {
        do
        {
          v35 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *)&v32[40 * v34];
          v64 = &v32[40 * v34];
          if ( v35 )
          {
            Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener::Listener(
              v35,
              (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *)(*v14 + 40 * v34));
            v32 = v69;
          }
          v62 = ++v34;
        }
        while ( v34 < v33 );
      }
      v36 = 0i64;
      if ( v33 )
      {
        _RDI = (Scaleform::GFx::AS3::Value::V2U *)(v32 + 32);
        do
        {
          if ( !((LODWORD(_RDI[-3].VObj) >> 9) & 1) || _RDI[-2].VObj->pRCCRaw )
          {
            func.Flags = 0;
            func.Bonus.pWeakProxy = 0i64;
            argv.Flags = 0;
            argv.Bonus.pWeakProxy = 0i64;
            v57.Flags = 12;
            v57.Bonus.pWeakProxy = 0i64;
            *(_QWORD *)&v57.value.VNumber = v3;
            if ( v3 )
              v3->RefCount = (v3->RefCount + 1) & 0x8FBFFFFF;
            v38 = (int)_RDI[-3].VObj;
            if ( (LODWORD(_RDI[-3].VObj) >> 9) & 1 )
            {
              _this.Bonus.pWeakProxy = 0i64;
              __asm { prefetcht1 byte ptr [rdi-18h]; Prefetch to all cache levels }
              *(Scaleform::GFx::AS3::Value::V2U *)&_this.Flags = _RDI[-3];
              v39 = _RDI[-2].VObj;
              _this.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)_RDI[-2].VObj;
              v40.VObj = _RDI[-1].VObj;
              *(Scaleform::GFx::AS3::Value::V2U *)&_this.value.VNumber = _RDI[-1];
              v41.VObj = _RDI->VObj;
              _this.value.VS._2 = (Scaleform::GFx::AS3::Value::V2U)_RDI->VObj;
              if ( (v38 & 0x1F) > 9 )
                ++LODWORD(v39->vfptr);
              v42 = _this.Flags;
              if ( (_this.Flags >> 9) & 1 )
              {
                if ( v39->pRCCRaw )
                {
                  v43 = _this.Flags & 0x1F;
                  if ( v43 == 10 )
                  {
                    ++LODWORD(v40.VObj->pPrev);
                  }
                  else if ( v43 > 10 )
                  {
                    if ( v43 <= 15 )
                    {
                      if ( v40.VObj )
                        v40.VObj->RefCount = (v40.VObj->RefCount + 1) & 0x8FBFFFFF;
                    }
                    else if ( v43 <= 17 && v41.VObj )
                    {
                      v41.VObj->RefCount = (v41.VObj->RefCount + 1) & 0x8FBFFFFF;
                    }
                  }
                  v23 = LODWORD(v39->vfptr)-- == 1;
                  if ( v23 )
                    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v39);
                }
                else
                {
                  _this.value = 0ui64;
                  v42 = _this.Flags & 0xFFFFFFE0;
                  _this.Flags &= 0xFFFFFFE0;
                }
                _this.Bonus.pWeakProxy = 0i64;
                _this.Flags = v42 & 0xFFFFFDFF;
              }
              v44 = &_this;
              v5 |= 4u;
            }
            else
            {
              result.Flags = (unsigned int)_RDI[-3].VObj;
              result.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)_RDI[-2].VObj;
              *(Scaleform::GFx::AS3::Value::V2U *)&result.value.VNumber = _RDI[-1];
              v45.VObj = _RDI->VObj;
              result.value.VS._2 = (Scaleform::GFx::AS3::Value::V2U)_RDI->VObj;
              v46 = v38 & 0x1F;
              if ( v46 > 9 )
              {
                if ( v46 == 10 )
                {
                  ++LODWORD(_RDI[-1].VObj->pPrev);
                }
                else if ( v46 > 10 )
                {
                  if ( v46 <= 15 )
                  {
                    v47.VObj = _RDI[-1].VObj;
                    if ( v47.VObj )
                      v47.VObj->RefCount = (v47.VObj->RefCount + 1) & 0x8FBFFFFF;
                  }
                  else if ( v46 <= 17 && v45.VObj )
                  {
                    v45.VObj->RefCount = (v45.VObj->RefCount + 1) & 0x8FBFFFFF;
                  }
                }
              }
              v44 = &result;
              v5 |= 8u;
            }
            Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v4->pTraits.pObject->pVM, v44, &func, &argv, 1u, &v57, 0);
            if ( v5 & 8 )
            {
              v5 &= 0xFFFFFFF7;
              v48 = result.Flags;
              if ( (result.Flags & 0x1F) > 9 )
              {
                if ( (result.Flags >> 9) & 1 )
                {
                  v23 = result.Bonus.pWeakProxy->RefCount-- == 1;
                  if ( v23 )
                    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                  result.Bonus.pWeakProxy = 0i64;
                  result.value = 0ui64;
                  result.Flags = v48 & 0xFFFFFDE0;
                }
                else
                {
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
                }
              }
            }
            if ( v5 & 4 )
            {
              v5 &= 0xFFFFFFFB;
              v49 = _this.Flags;
              if ( (_this.Flags & 0x1F) > 9 )
              {
                if ( (_this.Flags >> 9) & 1 )
                {
                  v23 = _this.Bonus.pWeakProxy->RefCount-- == 1;
                  if ( v23 )
                    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                  _this.Bonus.pWeakProxy = 0i64;
                  _this.value = 0ui64;
                  _this.Flags = v49 & 0xFFFFFDE0;
                }
                else
                {
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
                }
              }
            }
            v50 = v4->pTraits.pObject;
            if ( v50->pVM->HandleException )
            {
              Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v50->pVM);
              v51 = 0;
              v68 = 0;
            }
            else
            {
              v51 = v68;
            }
            Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::~HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>((Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *)&_RDI[-4]);
            if ( *((_BYTE *)v3 + 84) & 0x10 || !v51 )
            {
              if ( (v57.Flags & 0x1F) > 9 )
              {
                if ( (v57.Flags >> 9) & 1 )
                {
                  v23 = v57.Bonus.pWeakProxy->RefCount-- == 1;
                  if ( v23 )
                    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                  v57.Bonus.pWeakProxy = 0i64;
                  v57.value = 0ui64;
                  v57.Flags &= 0xFFFFFDE0;
                }
                else
                {
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&v57);
                }
              }
              if ( (argv.Flags & 0x1F) > 9 )
              {
                if ( (argv.Flags >> 9) & 1 )
                {
                  v23 = argv.Bonus.pWeakProxy->RefCount-- == 1;
                  if ( v23 )
                    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                  argv.Bonus.pWeakProxy = 0i64;
                  argv.value = 0ui64;
                  argv.Flags &= 0xFFFFFDE0;
                }
                else
                {
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&argv);
                }
              }
              if ( (func.Flags & 0x1F) > 9 )
              {
                if ( (func.Flags >> 9) & 1 )
                {
                  v23 = func.Bonus.pWeakProxy->RefCount-- == 1;
                  if ( v23 )
                    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                  func.Bonus.pWeakProxy = 0i64;
                  func.value = 0ui64;
                  func.Flags &= 0xFFFFFDE0;
                }
                else
                {
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
                }
              }
              break;
            }
            if ( (v57.Flags & 0x1F) > 9 )
            {
              if ( (v57.Flags >> 9) & 1 )
              {
                v23 = v57.Bonus.pWeakProxy->RefCount-- == 1;
                if ( v23 )
                  ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                v57.Bonus.pWeakProxy = 0i64;
                v57.value = 0ui64;
                v57.Flags &= 0xFFFFFDE0;
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(&v57);
              }
            }
            if ( (argv.Flags & 0x1F) > 9 )
            {
              if ( (argv.Flags >> 9) & 1 )
              {
                v23 = argv.Bonus.pWeakProxy->RefCount-- == 1;
                if ( v23 )
                  ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                argv.Bonus.pWeakProxy = 0i64;
                argv.value = 0ui64;
                argv.Flags &= 0xFFFFFDE0;
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(&argv);
              }
            }
            if ( (func.Flags & 0x1F) > 9 )
            {
              if ( (func.Flags >> 9) & 1 )
              {
                v23 = func.Bonus.pWeakProxy->RefCount-- == 1;
                if ( v23 )
                  ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                func.Bonus.pWeakProxy = 0i64;
                func.value = 0ui64;
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
            Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::~HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>((Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *)&_RDI[-4]);
          }
          ++v36;
          _RDI += 5;
        }
        while ( v36 < v33 );
      }
      v52 = v36 + 1;
      if ( v52 < v33 )
      {
        v53 = (Scaleform::GFx::AS3::Value *)&v69[8 * (v52 + 4 * v52 + 1)];
        v54 = v33 - v52;
        do
        {
          if ( (v53->Flags & 0x1F) > 9 )
          {
            if ( (v53->Flags >> 9) & 1 )
            {
              v55 = v53->Bonus.pWeakProxy;
              v23 = v55->RefCount-- == 1;
              if ( v23 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              v53->Bonus.pWeakProxy = 0i64;
              v53->value.VNumber = 0.0;
              v53->value.VS._2.VObj = 0i64;
              v53->Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(v53);
            }
          }
          v53 = (Scaleform::GFx::AS3::Value *)((char *)v53 + 40);
          --v54;
        }
        while ( v54 );
      }
      if ( v69 != &v67 )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v69);
      v13 = v68;
    }
  }
  if ( (unsigned __int8)v4 & 1 )
  {
    v63 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)v4 - 1);
  }
  else
  {
    v56 = v4->RefCount;
    if ( v56 & 0x3FFFFF )
    {
      v4->RefCount = v56 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->vfptr);
    }
  }
  return v13;
}

// File Line: 929
// RVA: 0x7C6240
char __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchToTarget(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this, Scaleform::GFx::ASString *type, Scaleform::GFx::AS3::Instances::fl::Object *target, bool useCapture, Scaleform::GFx::DisplayObject *dispObject)
{
  bool v5; // r14
  Scaleform::GFx::AS3::Instances::fl::XMLList *v6; // rbp
  Scaleform::GFx::ASString *v7; // rsi
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v8; // rdi
  Scaleform::GFx::AS3::Traits *v9; // rbx
  Scaleform::GFx::AS3::VM *v10; // rax
  Scaleform::GFx::AS3::ASVM *v11; // rdi
  Scaleform::GFx::LogState *v12; // rbx
  const char *v13; // rbx
  Scaleform::GFx::LogState *v14; // rax
  char v16; // bl
  Scaleform::GFx::AS3::Instances::fl_events::Event *v17; // rcx
  unsigned int v18; // edx
  Scaleform::Ptr<Scaleform::GFx::LogState> result; // [rsp+30h] [rbp-28h]
  __int64 v20; // [rsp+38h] [rbp-20h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> v21; // [rsp+60h] [rbp+8h]

  v20 = -2i64;
  v5 = useCapture;
  v6 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)target;
  v7 = type;
  v8 = this;
  if ( !this->pImpl.pObject )
    return 1;
  v9 = this->pTraits.pObject;
  v10 = v9->pVM;
  if ( v10->HandleException )
  {
    v11 = (Scaleform::GFx::AS3::ASVM *)v9->pVM;
    v12 = Scaleform::GFx::StateBag::GetLogState((Scaleform::GFx::StateBag *)v10[1].vfptr[2].__vecDelDtor + 2, &result)->pObject;
    if ( result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
    if ( v12 )
    {
      v13 = v7->pNode->pData;
      v14 = Scaleform::GFx::AS3::ASVM::GetLogState(v11);
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptError(
        (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)&v14->vfptr,
        "Can't dispatch '%s' - exception is not cleared",
        v13);
    }
    return 1;
  }
  if ( !v9->pConstructor.pObject )
    v9->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&this->pTraits.pObject->vfptr);
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateEventObject(
    (Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *)v9->pConstructor.pObject,
    &v21,
    v7,
    0,
    0);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v21.pObject->Target,
    v6);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v21.pObject->CurrentTarget,
    v6);
  if ( !Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(v8, v21.pObject, v5)
    && dispObject )
  {
    dispObject->Flags |= 0x20u;
  }
  v16 = ~(*((_BYTE *)v21.pObject + 84) >> 2) & 1;
  v17 = v21.pObject;
  if ( v21.pObject )
  {
    if ( (_QWORD)v21.pObject & 1 )
    {
      --v21.pObject;
    }
    else
    {
      v18 = v21.pObject->RefCount;
      if ( v18 & 0x3FFFFF )
      {
        v21.pObject->RefCount = v18 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v17->vfptr);
      }
    }
  }
  return v16;
}

// File Line: 981
// RVA: 0x7F1FD0
char __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::HasEventHandler(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this, Scaleform::GFx::ASString *type, bool useCapture)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v3; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v4; // rbx
  signed __int64 v5; // rax
  signed __int64 v6; // rax
  __int64 *v7; // rax
  __int64 v8; // rax
  char result; // al

  v3 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)this->pImpl.pObject;
  if ( !v3 )
    goto LABEL_14;
  if ( !useCapture )
    ++v3;
  v4.pTable = v3->pTable;
  if ( v3->pTable
    && (v5 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               v3,
               type,
               v4.pTable->SizeMask & type->pNode->HashFlags),
        v5 >= 0)
    && (v6 = (signed __int64)v4.pTable + 8 * (3 * v5 + 3)) != 0
    && (v7 = (__int64 *)(v6 + 8)) != 0i64
    && (v8 = *v7) != 0
    && *(_QWORD *)(v8 + 8) )
  {
    result = 1;
  }
  else
  {
LABEL_14:
    result = 0;
  }
  return result;
}

// File Line: 994
// RVA: 0x82A110
char __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::WillTrigger(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this, Scaleform::GFx::ASString *type, bool useCapture)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v3; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v4; // rcx
  bool v5; // si
  Scaleform::GFx::ASString *v6; // r14
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v7; // rbx
  signed __int64 v8; // rax
  signed __int64 v9; // rax
  __int64 *v10; // rax
  __int64 v11; // rax
  Scaleform::GFx::AS3::Traits *v13; // rcx
  Scaleform::GFx::AS3::RefCountCollector<328> *v14; // rbx
  __int64 v15; // rbx
  __int64 v16; // rax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v17; // rcx

  v3 = this;
  v4 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)this->pImpl.pObject;
  v5 = useCapture;
  v6 = type;
  if ( v4 )
  {
    if ( !useCapture )
      ++v4;
    v7.pTable = v4->pTable;
    if ( v4->pTable )
    {
      v8 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
             v4,
             type,
             v7.pTable->SizeMask & type->pNode->HashFlags);
      if ( v8 >= 0 )
      {
        v9 = (signed __int64)v7.pTable + 8 * (3 * v8 + 3);
        if ( v9 )
        {
          v10 = (__int64 *)(v9 + 8);
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
  v13 = v3->pTraits.pObject;
  if ( (unsigned int)(v13->TraitsType - 22) <= 0xC )
  {
    if ( ~(LOBYTE(v13->Flags) >> 5) & 1 )
    {
      v14 = v3[1]._pRCC;
      if ( v14 )
      {
        v15 = *(_QWORD *)&v14->Roots[2].nRoots;
        if ( v15 )
        {
          while ( 1 )
          {
            v16 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)(v15 + 4i64 * *(unsigned __int8 *)(v15 + 109)) + 8i64))(v15 + 4i64 * *(unsigned __int8 *)(v15 + 109));
            if ( v16 )
              v16 -= 56i64;
            v17 = *(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher **)(v16 + 16);
            if ( !v17 )
              v17 = *(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher **)(v16 + 8);
            if ( (unsigned __int8)v17 & 1 )
              v17 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)v17 - 1);
            if ( v17 && Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::HasEventHandler(v17, v6, v5) )
              break;
            v15 = *(_QWORD *)(v15 + 56);
            if ( !v15 )
              return 0;
          }
          return 1;
        }
      }
    }
  }
  return 0;
}

// File Line: 1021
// RVA: 0x805260
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::OnRemoveEventListener(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this, Scaleform::GFx::ASString *evtType, bool useCapture, unsigned __int64 listenersArrSize)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v4; // r10
  __int64 v5; // r11
  _QWORD *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rdx
  Scaleform::GFx::EventId::IdCode v8; // edx
  Scaleform::GFx::AS3::Traits *v9; // rcx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *v10; // rcx
  char v11; // al
  char v12; // al

  v4 = this;
  v5 = *(_QWORD *)(((_QWORD)this->pTraits.pObject & 0xFFFFFFFFFFFFFFFEui64) + 128);
  v6 = *(_QWORD **)(v5 + 744);
  if ( !v6 )
    return;
  v7 = evtType->pNode;
  if ( v7 == (Scaleform::GFx::ASStringNode *)v6[79] )
  {
    v8 = 2;
    *(_DWORD *)(v6[2] + 21200i64) |= 0x80000u;
LABEL_14:
    if ( !listenersArrSize )
    {
      v9 = this->pTraits.pObject;
      if ( (unsigned int)(v9->TraitsType - 22) <= 0xC )
      {
        if ( ~(LOBYTE(v9->Flags) >> 5) & 1 )
          Scaleform::GFx::AS3::EventChains::RemoveFromChain(
            (Scaleform::GFx::AS3::EventChains *)(*(_QWORD *)(v5 + 744) + 344i64),
            v8,
            (Scaleform::GFx::DisplayObject *)v4[1]._pRCC);
      }
    }
    return;
  }
  if ( v7 == (Scaleform::GFx::ASStringNode *)v6[80] )
  {
    v8 = 16777237;
    goto LABEL_14;
  }
  if ( v7 == (Scaleform::GFx::ASStringNode *)v6[81] )
  {
    v8 = 16777238;
    goto LABEL_14;
  }
  if ( v7 == (Scaleform::GFx::ASStringNode *)v6[73] )
  {
    v8 = 16777233;
    goto LABEL_14;
  }
  if ( v7 == (Scaleform::GFx::ASStringNode *)v6[78] )
  {
    v8 = 16777234;
    goto LABEL_14;
  }
  if ( v7 == (Scaleform::GFx::ASStringNode *)v6[89] )
  {
    v8 = 16777235;
    goto LABEL_14;
  }
  if ( (Scaleform::GFx::ASStringNode *)v6[94] == v7
    || (Scaleform::GFx::ASStringNode *)v6[98] == v7
    || (Scaleform::GFx::ASStringNode *)v6[92] == v7
    || (Scaleform::GFx::ASStringNode *)v6[93] == v7
    || (Scaleform::GFx::ASStringNode *)v6[97] == v7
    || (Scaleform::GFx::ASStringNode *)v6[96] == v7
    || (Scaleform::GFx::ASStringNode *)v6[101] == v7
    || (Scaleform::GFx::ASStringNode *)v6[100] == v7 )
  {
    v10 = this->pImpl.pObject;
    if ( useCapture )
    {
      v11 = v10->CaptureButtonHandlersCnt;
      if ( (unsigned __int8)v11 < 0xFFu )
        v10->CaptureButtonHandlersCnt = v11 - 1;
    }
    else
    {
      v12 = v10->ButtonHandlersCnt;
      if ( (unsigned __int8)v12 < 0xFFu )
        v10->ButtonHandlersCnt = v12 - 1;
    }
  }
}

// File Line: 1094
// RVA: 0x811BE0
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::RemoveListenersForMovieDef(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this, Scaleform::GFx::MovieDefImpl *defimpl, Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash *hash)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash *v3; // r12
  Scaleform::GFx::MovieDefImpl *v4; // r13
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v5; // r9
  unsigned __int64 v6; // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v7; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v8; // rdi
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> *v9; // rdi
  unsigned __int64 v10; // rbp
  __int64 v11; // r14
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *v12; // r8
  Scaleform::GFx::AS3::Value *v13; // rdx
  int v14; // ecx
  Scaleform::GFx::AS3::Traits *v15; // rax
  __int64 v16; // rax
  Scaleform::GFx::AS3::Value::V2U v17; // rcx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *v18; // rbx
  Scaleform::GFx::AS3::WeakProxy *v19; // rdx
  bool v20; // zf
  unsigned __int64 v21; // rdx
  unsigned __int64 *v22; // rcx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v23; // [rsp+70h] [rbp+8h]
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash *v24; // [rsp+80h] [rbp+18h]

  v23 = this;
  v3 = hash;
  v24 = hash;
  v4 = defimpl;
  v5 = hash->mHash.pTable;
  v6 = 0i64;
  if ( hash->mHash.pTable )
  {
    v7 = v5 + 1;
    do
    {
      if ( v7->EntryCount != -2i64 )
        break;
      ++v6;
      v7 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scalefor)((char *)v7 + 24);
    }
    while ( v6 <= v5->SizeMask );
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
      v12 = v9->Data;
      v13 = &v9->Data[v11].mFunction;
      if ( (v13->Flags >> 9) & 1 && !v13->Bonus.pWeakProxy->pObject )
      {
LABEL_30:
        ++v10;
        ++v11;
        continue;
      }
      v14 = v13->Flags & 0x1F;
      if ( v14 == 7 )
      {
        v17.VObj = (Scaleform::GFx::AS3::Object *)v12[v11].mFunction.value.VS._2;
        goto LABEL_18;
      }
      if ( v14 == 17 )
      {
        v17.VObj = (Scaleform::GFx::AS3::Object *)v12[v11].mFunction.value.VS._2.VObj->pTraits.pObject;
LABEL_18:
        v16 = ((__int64 (__cdecl *)(Scaleform::GFx::AS3::Value::V2U))v17.VObj->vfptr[2].~RefCountBaseGC<328>)(v17);
        goto LABEL_19;
      }
      v15 = Scaleform::GFx::AS3::VM::GetValueTraits(v23->pTraits.pObject->pVM, v13);
      v16 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *))v15->vfptr[2].~RefCountBaseGC<328>)(v15);
LABEL_19:
      if ( !v16 || *(Scaleform::GFx::MovieDefImpl **)(*(_QWORD *)(v16 + 152) + 368i64) != v4 )
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
          if ( (v18->mFunction.Flags >> 9) & 1 )
          {
            v19 = v18->mFunction.Bonus.pWeakProxy;
            v20 = v19->RefCount-- == 1;
            if ( v20 )
              ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            v18->mFunction.Bonus.pWeakProxy = 0i64;
            v18->mFunction.value.VNumber = 0.0;
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
    v21 = v3->mHash.pTable->SizeMask;
    if ( (signed __int64)v6 <= (signed __int64)v21 && ++v6 <= v21 )
    {
      v22 = &v3->mHash.pTable[1].EntryCount + 3 * v6;
      do
      {
        if ( *v22 != -2i64 )
          break;
        ++v6;
        v22 += 3;
      }
      while ( v6 <= v21 );
    }
  }
}

// File Line: 1169
// RVA: 0x77CE10
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher::EventDispatcher(Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher *this, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::ClassInfo *ci)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher *v3; // rbx

  v3 = this;
  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(
    (Scaleform::GFx::AS3::InstanceTraits::CTraits *)&this->vfptr,
    vm,
    ci);
  v3->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
  v3->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher::`vftable';
}

// File Line: 1176
// RVA: 0x7FF520
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 1195
// RVA: 0x7D56F0
void __fastcall Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::ForEachChild_GC(Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  void (__fastcall *v3)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // rdi
  Scaleform::GFx::AS3::RefCountCollector<328> *v4; // rsi
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *v5; // rbx

  v3 = op;
  v4 = prcc;
  v5 = this;
  Scaleform::GFx::AS3::Object::ForEachChild_GC((Scaleform::GFx::AS3::Object *)&this->vfptr, prcc, op);
  if ( v5->ParentClass.pObject )
    v3(v4, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v5->ParentClass);
  if ( v5->pPrototype.pObject )
    v3(v4, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v5->pPrototype);
  if ( v5->EventTraits.pObject )
    v3(v4, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v5->EventTraits);
  if ( v5->MouseEventTraits.pObject )
    v3(v4, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v5->MouseEventTraits);
}

// File Line: 1211
// RVA: 0x7BC890
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *__fastcall Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateEventObject(Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *result, Scaleform::GFx::ASString *type, bool bubbles, bool cancelable)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *v5; // rbx
  Scaleform::GFx::AS3::Value ptr; // [rsp+40h] [rbp-88h]
  int v8; // [rsp+60h] [rbp-68h]
  __int64 v9; // [rsp+68h] [rbp-60h]
  bool v10; // [rsp+70h] [rbp-58h]
  int v11; // [rsp+80h] [rbp-48h]
  __int64 v12; // [rsp+88h] [rbp-40h]
  bool v13; // [rsp+90h] [rbp-38h]
  __int64 v14; // [rsp+A0h] [rbp-28h]
  Scaleform::GFx::AS3::Value::VU v15; // [rsp+A8h] [rbp-20h]

  v14 = -2i64;
  v5 = result;
  result->pObject = 0i64;
  ptr.Flags = 10;
  ptr.Bonus.pWeakProxy = 0i64;
  *(Scaleform::GFx::ASString *)&ptr.value.VNumber = (Scaleform::GFx::ASString)type->pNode;
  if ( *(_QWORD *)&ptr.value.VNumber == *(_QWORD *)(*(_QWORD *)&ptr.value.VNumber + 8i64) + 104i64 )
  {
    v15.VNumber = 0.0;
    ptr.value = v15;
    ptr.Flags = 12;
  }
  else
  {
    ++*(_DWORD *)(*(_QWORD *)&ptr.value.VNumber + 24i64);
  }
  v8 = 1;
  v9 = 0i64;
  v10 = bubbles;
  v11 = 1;
  v12 = 0i64;
  v13 = cancelable;
  Scaleform::GFx::AS3::ASVM::_constructInstance(
    (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM,
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)result,
    (Scaleform::GFx::AS3::Object *)this->pTraits.pObject->pVM[1].XMLSupport_.pObject,
    3u,
    &ptr);
  `eh vector destructor iterator'(&ptr, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  return v5;
}

// File Line: 1246
// RVA: 0x7BDDC0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> *result, Scaleform::GFx::EventId *evtId, Scaleform::GFx::ASString *type, Scaleform::GFx::AS3::Instances::fl::Object *target)
{
  Scaleform::GFx::EventId *v5; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *v6; // rbx
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *v7; // r14
  Scaleform::GFx::ASStringNode *v8; // rdx
  Scaleform::GFx::AS3::ASVM *v9; // rsi
  Scaleform::GFx::AS3::Object **v10; // r8
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> v11; // rax
  Scaleform::GFx::AS3::Object *v12; // rcx
  __int64 v13; // rax
  signed __int64 v14; // rsi
  float v15; // xmm1_4
  unsigned int v16; // eax
  int v17; // ecx
  bool v18; // zf
  Scaleform::GFx::AS3::Value argv; // [rsp+40h] [rbp-20h]
  Scaleform::Render::Point<float> p; // [rsp+90h] [rbp+30h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> *v22; // [rsp+98h] [rbp+38h]

  v22 = result;
  v5 = evtId;
  v6 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)result;
  v7 = this;
  result->pObject = 0i64;
  argv.Flags = 10;
  argv.Bonus.pWeakProxy = 0i64;
  v8 = type->pNode;
  *(_QWORD *)&argv.value.VNumber = v8;
  if ( v8 == &v8->pManager->NullStringNode )
  {
    argv.value.VNumber = 0.0;
    argv.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)argv.Bonus.pWeakProxy;
    argv.Flags = 12;
  }
  else
  {
    ++v8->RefCount;
  }
  v9 = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  v10 = (Scaleform::GFx::AS3::Object **)&v9->MouseEventExClass;
  if ( !v9->ExtensionsEnabled )
    v10 = (Scaleform::GFx::AS3::Object **)&v9->MouseEventClass;
  Scaleform::GFx::AS3::ASVM::_constructInstance(v9, v6, *v10, 1u, &argv);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v6->pObject[1].16,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)target);
  v11.pObject = v6->pObject;
  if ( (v5->Id - 0x2000) & 0xFFFFDFFF )
    BYTE4(v11.pObject[1].pPrevRoot) |= 1u;
  else
    BYTE4(v11.pObject[1].pPrevRoot) &= 0xFEu;
  BYTE4(v6->pObject[1].pPrevRoot) &= 0xFDu;
  BYTE4(v6->pObject[2].pRCCRaw) = ((unsigned __int8)v5->KeysState.States >> 2) & 1;
  BYTE5(v6->pObject[2].pRCCRaw) = ((unsigned __int8)v5->KeysState.States >> 1) & 1;
  BYTE6(v6->pObject[2].pRCCRaw) = v5->KeysState.States & 1;
  v6->pObject[1].RefCount = v5->MouseWheelDelta;
  if ( v9->ExtensionsEnabled )
  {
    v12 = v6->pObject;
    LODWORD(v12[2].pNext) = v5->ControllerIndex;
    LODWORD(v12[2].pPrev) = (unsigned __int8)v5->RollOverCnt;
    HIDWORD(v12[2].pNextRoot) = (unsigned __int8)v5->AsciiCode;
  }
  v13 = (unsigned int)v5->ControllerIndex;
  if ( (unsigned int)v13 < 6 )
    v14 = (signed __int64)v7->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor + 80 * v13 + 8696;
  else
    v14 = 0i64;
  v15 = *(float *)(v14 + 60);
  p.x = *(float *)(v14 + 56);
  p.y = v15;
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent::SetStageCoords(
    (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)v6->pObject,
    &p);
  v16 = v5->Id;
  if ( v5->Id == 0x2000 || v16 == 0x4000 || v16 - 16777226 <= 1 )
    v17 = *(_DWORD *)(v14 + 52);
  else
    v17 = *(_DWORD *)(v14 + 48);
  LODWORD(v6->pObject[2]._pRCC) = v17;
  if ( (argv.Flags & 0x1F) > 9 )
  {
    if ( (argv.Flags >> 9) & 1 )
    {
      v18 = argv.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v18 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      argv.Bonus.pWeakProxy = 0i64;
      argv.value = 0ui64;
      argv.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&argv);
    }
  }
  return v6;
}

// File Line: 1300
// RVA: 0x7BD800
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent> *__fastcall Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateKeyboardEventObject(Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent> *result, Scaleform::GFx::EventId *evtId, Scaleform::GFx::ASString *type, Scaleform::GFx::AS3::Instances::fl::Object *target)
{
  Scaleform::GFx::EventId *v5; // rsi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent> *v6; // rbx
  Scaleform::GFx::AS3::ASVM *v7; // rdi
  Scaleform::GFx::AS3::Object **v8; // r8
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v9; // rbp
  Scaleform::GFx::EventId *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::AS3::Value argv; // [rsp+40h] [rbp-38h]

  v5 = evtId;
  v6 = result;
  result->pObject = 0i64;
  argv.Flags = 10;
  argv.Bonus.pWeakProxy = 0i64;
  *(Scaleform::GFx::ASString *)&argv.value.VNumber = (Scaleform::GFx::ASString)type->pNode;
  if ( *(_QWORD *)&argv.value.VNumber == *(_QWORD *)(*(_QWORD *)&argv.value.VNumber + 8i64) + 104i64 )
  {
    argv.value = 0ui64;
    argv.Flags = 12;
  }
  else
  {
    ++*(_DWORD *)(*(_QWORD *)&argv.value.VNumber + 24i64);
  }
  v7 = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  v8 = (Scaleform::GFx::AS3::Object **)&v7->KeyboardEventExClass;
  if ( !v7->ExtensionsEnabled )
    v8 = (Scaleform::GFx::AS3::Object **)&v7->KeyboardEventClass;
  Scaleform::GFx::AS3::ASVM::_constructInstance(
    v7,
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)result,
    *v8,
    1u,
    &argv);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v6->pObject->Target,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)target);
  v9 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)v6->pObject;
  v10 = &v6->pObject->EvtId;
  v10->Id = v5->Id;
  v10->WcharCode = v5->WcharCode;
  v10->KeyCode = v5->KeyCode;
  v10->AsciiCode = v5->AsciiCode;
  v10->RollOverCnt = v5->RollOverCnt;
  v10->ControllerIndex = v5->ControllerIndex;
  v10->KeysState.States = v5->KeysState.States;
  v10->MouseWheelDelta = v5->MouseWheelDelta;
  if ( !BYTE4(v9[12].pObject) )
    BYTE4(v9[12].pObject) = Scaleform::GFx::EventId::ConvertKeyCodeToAscii(v10);
  *((_BYTE *)&v6->pObject->0 + 84) |= 1u;
  *((_BYTE *)&v6->pObject->0 + 84) &= 0xFDu;
  if ( v7->ExtensionsEnabled )
    LODWORD(v6->pObject[1].vfptr) = v5->ControllerIndex;
  if ( (argv.Flags & 0x1F) > 9 )
  {
    if ( (argv.Flags >> 9) & 1 )
    {
      v11 = argv.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      argv.Bonus.pWeakProxy = 0i64;
      argv.value = 0ui64;
      argv.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&argv);
    }
  }
  return v6;
}

// File Line: 1342
// RVA: 0x7BF460
Scaleform::GFx::ASString **__fastcall Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateStatusEventObject(Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::StatusEvent> *result, Scaleform::GFx::EventId *evtId, Scaleform::GFx::ASString *type, Scaleform::GFx::AS3::Instances::fl::Object *target)
{
  Scaleform::GFx::EventId *v5; // rdi
  Scaleform::GFx::ASString **v6; // rbx
  bool v7; // zf
  Scaleform::GFx::AS3::Value argv; // [rsp+40h] [rbp-28h]

  v5 = evtId;
  v6 = (Scaleform::GFx::ASString **)result;
  result->pObject = 0i64;
  argv.Flags = 10;
  argv.Bonus.pWeakProxy = 0i64;
  *(Scaleform::GFx::ASString *)&argv.value.VNumber = (Scaleform::GFx::ASString)type->pNode;
  if ( *(_QWORD *)&argv.value.VNumber == *(_QWORD *)(*(_QWORD *)&argv.value.VNumber + 8i64) + 104i64 )
  {
    argv.value.VNumber = 0.0;
    argv.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)argv.Bonus.pWeakProxy;
    argv.Flags = 12;
  }
  else
  {
    ++*(_DWORD *)(*(_QWORD *)&argv.value.VNumber + 24i64);
  }
  Scaleform::GFx::AS3::ASVM::_constructInstance(
    (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM,
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)result,
    (Scaleform::GFx::AS3::Object *)this->pTraits.pObject->pVM[1].ScopeStack.Data.pHeap,
    1u,
    &argv);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&(*v6)[9],
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)target);
  BYTE4((*v6)[10].pNode) |= 1u;
  BYTE4((*v6)[10].pNode) &= 0xFDu;
  Scaleform::GFx::ASString::operator=(
    *v6 + 11,
    (const char *)((**(_QWORD **)&v5[1].WcharCode & 0xFFFFFFFFFFFFFFFCui64) + 12));
  Scaleform::GFx::ASString::operator=(
    *v6 + 12,
    (const char *)((**(_QWORD **)&v5[1].AsciiCode & 0xFFFFFFFFFFFFFFFCui64) + 12));
  if ( (argv.Flags & 0x1F) > 9 )
  {
    if ( (argv.Flags >> 9) & 1 )
    {
      v7 = argv.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v7 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      argv.Bonus.pWeakProxy = 0i64;
      argv.value = 0ui64;
      argv.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&argv);
    }
  }
  return v6;
}

// File Line: 1360
// RVA: 0x7BB7B0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::AccelerometerEvent> *__fastcall Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateAccelerometerEventObject(Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::AccelerometerEvent> *result, Scaleform::GFx::EventId *evtId, Scaleform::GFx::ASString *type, Scaleform::GFx::AS3::Instances::fl::Object *target)
{
  Scaleform::GFx::EventId *v5; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::AccelerometerEvent> *v6; // rbx
  bool v7; // zf
  Scaleform::GFx::AS3::Value argv; // [rsp+40h] [rbp-28h]

  v5 = evtId;
  v6 = result;
  result->pObject = 0i64;
  argv.Flags = 10;
  argv.Bonus.pWeakProxy = 0i64;
  *(Scaleform::GFx::ASString *)&argv.value.VNumber = (Scaleform::GFx::ASString)type->pNode;
  if ( *(_QWORD *)&argv.value.VNumber == *(_QWORD *)(*(_QWORD *)&argv.value.VNumber + 8i64) + 104i64 )
  {
    argv.value.VNumber = 0.0;
    argv.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)argv.Bonus.pWeakProxy;
    argv.Flags = 12;
  }
  else
  {
    ++*(_DWORD *)(*(_QWORD *)&argv.value.VNumber + 24i64);
  }
  Scaleform::GFx::AS3::ASVM::_constructInstance(
    (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM,
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)result,
    *(Scaleform::GFx::AS3::Object **)&this->pTraits.pObject->pVM[1].HandleException,
    1u,
    &argv);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v6->pObject->Target,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)target);
  *((_BYTE *)&v6->pObject->0 + 84) |= 1u;
  *((_BYTE *)&v6->pObject->0 + 84) &= 0xFDu;
  v6->pObject->timestamp = *(long double *)&v5[1].WcharCode;
  v6->pObject->accelerationX = *(long double *)&v5[1].AsciiCode;
  v6->pObject->accelerationY = *(long double *)&v5[2].Id;
  v6->pObject->accelerationZ = *(long double *)&v5[2].KeyCode;
  if ( (argv.Flags & 0x1F) > 9 )
  {
    if ( (argv.Flags >> 9) & 1 )
    {
      v7 = argv.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v7 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      argv.Bonus.pWeakProxy = 0i64;
      argv.value = 0ui64;
      argv.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&argv);
    }
  }
  return v6;
}

// File Line: 1381
// RVA: 0x7BCEB0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::GeolocationEvent> *__fastcall Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateGeolocationEventObject(Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::GeolocationEvent> *result, Scaleform::GFx::EventId *evtId, Scaleform::GFx::ASString *type, Scaleform::GFx::AS3::Instances::fl::Object *target)
{
  Scaleform::GFx::EventId *v5; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::GeolocationEvent> *v6; // rbx
  bool v7; // zf
  Scaleform::GFx::AS3::Value argv; // [rsp+40h] [rbp-28h]

  v5 = evtId;
  v6 = result;
  result->pObject = 0i64;
  argv.Flags = 10;
  argv.Bonus.pWeakProxy = 0i64;
  *(Scaleform::GFx::ASString *)&argv.value.VNumber = (Scaleform::GFx::ASString)type->pNode;
  if ( *(_QWORD *)&argv.value.VNumber == *(_QWORD *)(*(_QWORD *)&argv.value.VNumber + 8i64) + 104i64 )
  {
    argv.value.VNumber = 0.0;
    argv.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)argv.Bonus.pWeakProxy;
    argv.Flags = 12;
  }
  else
  {
    ++*(_DWORD *)(*(_QWORD *)&argv.value.VNumber + 24i64);
  }
  Scaleform::GFx::AS3::ASVM::_constructInstance(
    (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM,
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)result,
    *(Scaleform::GFx::AS3::Object **)&this->pTraits.pObject->pVM[1].ExceptionObj.Flags,
    1u,
    &argv);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v6->pObject->Target,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)target);
  *((_BYTE *)&v6->pObject->0 + 84) |= 1u;
  *((_BYTE *)&v6->pObject->0 + 84) &= 0xFDu;
  v6->pObject->latitude = *(long double *)&v5[1].WcharCode;
  v6->pObject->longitude = *(long double *)&v5[1].AsciiCode;
  v6->pObject->altitude = *(long double *)&v5[2].Id;
  v6->pObject->hAccuracy = *(long double *)&v5[2].KeyCode;
  v6->pObject->vAccuracy = *(long double *)&v5[2].RollOverCnt;
  v6->pObject->speed = *(long double *)&v5[3].WcharCode;
  v6->pObject->heading = *(long double *)&v5[3].AsciiCode;
  v6->pObject->timestamp = *(long double *)&v5[4].Id;
  if ( (argv.Flags & 0x1F) > 9 )
  {
    if ( (argv.Flags >> 9) & 1 )
    {
      v7 = argv.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v7 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      argv.Bonus.pWeakProxy = 0i64;
      argv.value = 0ui64;
      argv.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&argv);
    }
  }
  return v6;
}

// File Line: 1521
// RVA: 0x7BE650
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent> *__fastcall Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateProgressEventObject(Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent> *result, Scaleform::GFx::ASString *type)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent> *v3; // rbx
  Scaleform::GFx::AS3::VM *v4; // r10
  Scaleform::GFx::AS3::Value ptr; // [rsp+40h] [rbp-88h]
  int v7; // [rsp+60h] [rbp-68h]
  __int64 v8; // [rsp+68h] [rbp-60h]
  char v9; // [rsp+70h] [rbp-58h]
  int v10; // [rsp+80h] [rbp-48h]
  __int64 v11; // [rsp+88h] [rbp-40h]
  char v12; // [rsp+90h] [rbp-38h]
  __int64 v13; // [rsp+A0h] [rbp-28h]
  __int64 v14; // [rsp+A8h] [rbp-20h]

  v13 = -2i64;
  v3 = result;
  v4 = this->pTraits.pObject->pVM;
  result->pObject = 0i64;
  ptr.Flags = 10;
  ptr.Bonus.pWeakProxy = 0i64;
  *(Scaleform::GFx::ASString *)&ptr.value.VNumber = (Scaleform::GFx::ASString)type->pNode;
  if ( *(_QWORD *)&ptr.value.VNumber == *(_QWORD *)(*(_QWORD *)&ptr.value.VNumber + 8i64) + 104i64 )
  {
    v14 = 0i64;
    ptr.value = *(Scaleform::GFx::AS3::Value::VU *)&v14;
    ptr.Flags = 12;
  }
  else
  {
    ++*(_DWORD *)(*(_QWORD *)&ptr.value.VNumber + 24i64);
  }
  v7 = 1;
  v8 = 0i64;
  v9 = 0;
  v10 = 1;
  v11 = 0i64;
  v12 = 0;
  Scaleform::GFx::AS3::ASVM::_constructInstance(
    (Scaleform::GFx::AS3::ASVM *)v4,
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)result,
    (Scaleform::GFx::AS3::Object *)v4[1].ScopeStack.Data.Data,
    3u,
    &ptr);
  `eh vector destructor iterator'(&ptr, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  return v3;
}

// File Line: 1543
// RVA: 0x7BCB70
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::FocusEvent> *__fastcall Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateFocusEventObject(Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::FocusEvent> *result, Scaleform::GFx::ASString *type, Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *relatedObj, unsigned int controllerIdx, int shiftKey)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::FocusEvent> *v6; // rdi
  Scaleform::GFx::AS3::ASVM *v7; // rbx
  Scaleform::GFx::ASStringNode *v8; // rcx
  Scaleform::GFx::AS3::Object **v9; // r8
  Scaleform::GFx::AS3::Value::VU v11; // [rsp+40h] [rbp-B8h]
  Scaleform::GFx::AS3::Value ptr; // [rsp+50h] [rbp-A8h]
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

  v6 = result;
  v7 = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  result->pObject = 0i64;
  ptr.Flags = 10;
  ptr.Bonus.pWeakProxy = 0i64;
  v8 = type->pNode;
  *(_QWORD *)&ptr.value.VNumber = v8;
  if ( v8 == &v8->pManager->NullStringNode )
  {
    v11.VNumber = 0.0;
    ptr.value = v11;
    ptr.Flags = 12;
  }
  else
  {
    ++v8->RefCount;
  }
  v13 = 1;
  v14 = 0i64;
  LOBYTE(v14) = 1;
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
  v9 = (Scaleform::GFx::AS3::Object **)&v7->FocusEventExClass;
  if ( !v7->ExtensionsEnabled )
    v9 = (Scaleform::GFx::AS3::Object **)&v7->FocusEventClass;
  Scaleform::GFx::AS3::ASVM::_constructInstance(
    v7,
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)result,
    *v9,
    6u,
    &ptr);
  if ( v7->ExtensionsEnabled )
    LODWORD(v6->pObject[1].vfptr) = v27;
  `eh vector destructor iterator'(&ptr, 0x20ui64, 6, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  return v6;
}

// File Line: 1560
// RVA: 0x7BD5D0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateIOErrorEventObject(Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent> *result, const char *errText)
{
  const char *v3; // rsi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *v4; // rdi
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *v5; // r14
  Scaleform::GFx::AS3::VM *v6; // rbx
  long double *v7; // rax
  long double v8; // rdx
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rdx
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::AS3::Class *v14; // rax
  Scaleform::StringDataPtr gname; // [rsp+38h] [rbp-71h]
  Scaleform::GFx::AS3::Value ptr; // [rsp+50h] [rbp-59h]
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
  Scaleform::GFx::ASString resulta; // [rsp+110h] [rbp+67h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent> *v29; // [rsp+118h] [rbp+6Fh]

  v29 = result;
  v27 = -2i64;
  v3 = errText;
  v4 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)result;
  v5 = this;
  v6 = this->pTraits.pObject->pVM;
  result->pObject = 0i64;
  v7 = (long double *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                        (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v6->StringManagerRef->Builtins,
                        &resulta,
                        "ioError");
  ptr.Flags = 10;
  ptr.Bonus.pWeakProxy = 0i64;
  v8 = *v7;
  ptr.value.VNumber = *v7;
  if ( *(_QWORD *)v7 == *(_QWORD *)(*(_QWORD *)v7 + 8i64) + 104i64 )
  {
    gname.pStr = 0i64;
    ptr.value = (Scaleform::GFx::AS3::Value::VU)gname;
    ptr.Flags = 12;
  }
  else
  {
    ++*(_DWORD *)(*(_QWORD *)&v8 + 24i64);
  }
  v9 = resulta.pNode;
  v10 = resulta.pNode->RefCount == 1;
  --v9->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  v18 = 1;
  v19 = 0i64;
  v20 = 0;
  v21 = 1;
  v22 = 0i64;
  v23 = 0;
  v11 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v6->StringManagerRef->Builtins,
          &resulta,
          v3);
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
  v10 = resulta.pNode->RefCount == 1;
  --v13->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  gname.pStr = "flash.events.IOErrorEvent";
  gname.Size = 25i64;
  v14 = Scaleform::GFx::AS3::VM::GetClass(
          v5->pTraits.pObject->pVM,
          &gname,
          v5->pTraits.pObject->pVM->CurrentDomain.pObject);
  Scaleform::GFx::AS3::ASVM::_constructInstance(
    (Scaleform::GFx::AS3::ASVM *)v6,
    v4,
    (Scaleform::GFx::AS3::Object *)&v14->vfptr,
    4u,
    &ptr);
  `eh vector destructor iterator'(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  return v4;
}

// File Line: 1591
// RVA: 0x7BDC40
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseCursorEventObject(Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_gfx::MouseCursorEvent> *result, Scaleform::GFx::ASString *cursor, unsigned int controllerIdx)
{
  unsigned int v4; // esi
  Scaleform::GFx::ASString *v5; // r14
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *v6; // rbx
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *v7; // r10
  Scaleform::GFx::AS3::ASVM *v8; // rdi
  Scaleform::GFx::AS3::MovieRoot *v9; // rcx
  Scaleform::GFx::ASStringNode *v10; // rdx
  Scaleform::GFx::AS3::Class *v11; // rax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> v12; // rsi
  Scaleform::GFx::ASStringNode *v13; // rdi
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  Scaleform::StringDataPtr gname; // [rsp+38h] [rbp-90h]
  Scaleform::GFx::AS3::Value ptr; // [rsp+50h] [rbp-78h]
  int v19; // [rsp+70h] [rbp-58h]
  __int64 v20; // [rsp+78h] [rbp-50h]
  char v21; // [rsp+80h] [rbp-48h]
  int v22; // [rsp+90h] [rbp-38h]
  __int64 v23; // [rsp+98h] [rbp-30h]
  char v24; // [rsp+A0h] [rbp-28h]
  __int64 v25; // [rsp+B0h] [rbp-18h]

  v25 = -2i64;
  v4 = controllerIdx;
  v5 = cursor;
  v6 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)result;
  v7 = this;
  v8 = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  result->pObject = 0i64;
  v9 = v8->pMovieRoot;
  ptr.Flags = 10;
  ptr.Bonus.pWeakProxy = 0i64;
  v10 = v9->BuiltinsMgr.Builtins[46].pNode;
  *(_QWORD *)&ptr.value.VNumber = v9->BuiltinsMgr.Builtins[46].pNode;
  if ( v9->BuiltinsMgr.Builtins[46].pNode == &v9->BuiltinsMgr.Builtins[46].pNode->pManager->NullStringNode )
  {
    gname.pStr = 0i64;
    ptr.value = (Scaleform::GFx::AS3::Value::VU)gname;
    ptr.Flags = 12;
  }
  else
  {
    ++v10->RefCount;
  }
  v19 = 1;
  v20 = 0i64;
  v21 = 0;
  v22 = 1;
  v23 = 0i64;
  v24 = 1;
  gname.pStr = "scaleform.gfx.MouseCursorEvent";
  gname.Size = 30i64;
  v11 = Scaleform::GFx::AS3::VM::GetClass(
          v7->pTraits.pObject->pVM,
          &gname,
          v7->pTraits.pObject->pVM->CurrentDomain.pObject);
  if ( v11 )
  {
    Scaleform::GFx::AS3::ASVM::_constructInstance(v8, v6, (Scaleform::GFx::AS3::Object *)&v11->vfptr, 3u, &ptr);
    LODWORD(v6->pObject[1].pTraits.pObject) = v4;
    v12.pObject = v6->pObject;
    v13 = v5->pNode;
    ++v13->RefCount;
    v14 = *(Scaleform::GFx::ASStringNode **)&v12.pObject[1].RefCount;
    v15 = v14->RefCount-- == 1;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    *(_QWORD *)&v12.pObject[1].RefCount = v13;
  }
  `eh vector destructor iterator'(&ptr, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  return v6;
}

// File Line: 1620
// RVA: 0x77CDD0
void __fastcall Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher::EventDispatcher(Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher *this, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::ClassInfo *ci)
{
  Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher *v3; // rbx

  v3 = this;
  Scaleform::GFx::AS3::ClassTraits::Traits::Traits((Scaleform::GFx::AS3::ClassTraits::Traits *)&this->vfptr, vm, ci);
  v3->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable';
  v3->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher::`vftable';
}

// File Line: 1627
// RVA: 0x75F1C0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rdi
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rbx

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_events::EventDispatcherCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher::`vftable';
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl_events::EventDispatcherCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher::`vftable';
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    v3->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                       v4,
                                       88i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::`vftable';
    v10[1].vfptr = 0i64;
    v10[1].pRCCRaw = 0i64;
  }
  return v3;
}

