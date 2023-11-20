// File Line: 46
// RVA: 0x82ABE0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::actionVerboseSet(Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *this, Scaleform::GFx::AS3::Value *result, bool verbose)
{
  Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *v3; // rbx
  bool v4; // di
  void *(__fastcall *v5)(Scaleform::GFx::AS3::VM *, unsigned int); // rcx

  v3 = this;
  v4 = verbose;
  v5 = this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor;
  (*(void (__fastcall **)(void *(__fastcall *)(Scaleform::GFx::AS3::VM *, unsigned int), bool))(*(_QWORD *)v5 + 544i64))(
    v5,
    verbose);
  v3->pTraits.pObject->pVM->UI->NeedToCheck = v4;
}

// File Line: 57
// RVA: 0x82ABB0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::actionVerboseGet(Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *this, bool *result)
{
  *result = (*((_DWORD *)this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor + 5300) >> 2) & 1;
}

// File Line: 65
// RVA: 0x85AEA0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::setBackgroundAlpha(Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *this, Scaleform::GFx::AS3::Value *result, long double value)
{
  void *(__fastcall *v3)(Scaleform::GFx::AS3::VM *, unsigned int); // rcx

  v3 = this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor;
  (*(void (__fastcall **)(void *(__fastcall *)(Scaleform::GFx::AS3::VM *, unsigned int), Scaleform::GFx::AS3::Value *))(*(_QWORD *)v3 + 264i64))(
    v3,
    result);
}

// File Line: 82
// RVA: 0x84ABA0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::getCodeFileName(Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::VM::GetCodeFileName(this->pTraits.pObject->pVM, result);
}

// File Line: 90
// RVA: 0x84ABB0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::getCodeFileNames(Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result)
{
  __int64 *v2; // r14
  Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *v3; // r13
  unsigned __int64 v4; // r15
  Scaleform::GFx::AS3::Instances::fl::Array *v5; // rbx
  __int64 v6; // rsi
  Scaleform::GFx::AS3::Value *v7; // r12
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rdx
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  unsigned __int64 v12; // rcx
  signed __int64 v13; // rcx
  signed __int64 v14; // rdx
  __int64 v15; // rdx
  int v16; // eax
  Scaleform::GFx::ASStringNode *v17; // rax
  int v18; // eax
  _DWORD *v19; // rdx
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v21; // rcx
  unsigned int v22; // eax
  __int64 v23; // rcx
  int v24; // eax
  unsigned int v25; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *v26; // rdx
  unsigned __int64 v27; // rdi
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v28; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v29; // rcx
  unsigned int v30; // eax
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [rsp+30h] [rbp-39h]
  Scaleform::Array<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2,Scaleform::ArrayDefaultPolicy> destArray; // [rsp+40h] [rbp-29h]
  unsigned int v33; // [rsp+58h] [rbp-11h]
  _DWORD *v34; // [rsp+60h] [rbp-9h]
  Scaleform::GFx::ASStringNode *v35; // [rsp+68h] [rbp-1h]
  Scaleform::GFx::ASStringNode *v36; // [rsp+70h] [rbp+7h]
  Scaleform::GFx::AS3::Instances::fl::Array *v37; // [rsp+D0h] [rbp+67h]
  __int64 *v38; // [rsp+D8h] [rbp+6Fh]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> resulta; // [rsp+E0h] [rbp+77h]
  __int64 v40; // [rsp+E8h] [rbp+7Fh]

  v38 = (__int64 *)result;
  v2 = (__int64 *)result;
  v3 = this;
  resulta.pV = (Scaleform::GFx::AS3::Instances::fl::Array *)&destArray;
  destArray.Data.Data = 0i64;
  destArray.Data.Size = 0i64;
  destArray.Data.Policy.Capacity = 0i64;
  v4 = Scaleform::GFx::AS3::VM::GetAllLoadedAbcFiles(this->pTraits.pObject->pVM, &destArray);
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
    &resulta,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)v3->pTraits.pObject->pVM->TraitsArray.pObject->ITraits.pObject);
  v5 = resulta.pV;
  v37 = resulta.pV;
  v6 = 0i64;
  if ( v4 )
  {
    v7 = key.pSecond;
    while ( 1 )
    {
      v8 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
             (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v3->pTraits.pObject->pVM->StringManagerRef->Builtins,
             (Scaleform::GFx::ASString *)&resulta,
             (const char *)((destArray.Data.Data[v6].pObject->File.pObject->Source.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                          + 12));
      v33 = 10;
      v34 = 0i64;
      v9 = v8->pNode;
      v35 = v8->pNode;
      if ( v8->pNode == &v8->pNode->pManager->NullStringNode )
      {
        v35 = 0i64;
        v36 = (Scaleform::GFx::ASStringNode *)v7;
        v33 = 12;
      }
      else
      {
        ++v9->RefCount;
      }
      v10 = (Scaleform::GFx::ASStringNode *)resulta.pV;
      v11 = LODWORD(resulta.pV->pPrev) == 1;
      --v10->RefCount;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
      v12 = v5->SA.Length;
      if ( v12 == v5->SA.ValueA.Data.Size )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v5->SA.ValueA.Data.Data,
          v5->SA.ValueA.Data.pHeap,
          v5->SA.ValueA.Data.Size + 1);
        v13 = 32 * v5->SA.ValueA.Data.Size;
        v14 = (signed __int64)&v5->SA.ValueA.Data.Data[-1];
        v11 = v13 + v14 == 0;
        v15 = v13 + v14;
        v40 = v15;
        if ( !v11 )
        {
          *(_DWORD *)v15 = v33;
          *(_QWORD *)(v15 + 8) = v34;
          *(_QWORD *)(v15 + 16) = v35;
          *(_QWORD *)(v15 + 24) = v36;
          v16 = v33 & 0x1F;
          if ( v16 > 9 )
          {
            if ( (v33 >> 9) & 1 )
            {
              ++*v34;
            }
            else if ( v16 == 10 )
            {
              ++v35->RefCount;
            }
            else if ( v16 > 10 )
            {
              if ( v16 <= 15 )
              {
                v17 = v35;
LABEL_19:
                if ( v17 )
                {
                  ++v17->Size;
                  v17->Size &= 0x8FBFFFFF;
                }
                goto LABEL_24;
              }
              if ( v16 <= 17 )
              {
                v17 = v36;
                goto LABEL_19;
              }
            }
          }
        }
      }
      else
      {
        v5->SA.ValueHHighInd = v12;
        key.pFirst = &v5->SA.ValueHHighInd;
        key.pSecond = (Scaleform::GFx::AS3::Value *)&v33;
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
          (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v5->SA.ValueH.mHash.pTable,
          v5->SA.ValueH.mHash.pHeap,
          &key);
      }
LABEL_24:
      ++v5->SA.Length;
      v18 = v33 & 0x1F;
      if ( v18 > 9 )
      {
        if ( (v33 >> 9) & 1 )
        {
          v19 = v34;
          v11 = *v34 == 1;
          --*v19;
          if ( v11 )
            ((void (__cdecl *)(Scaleform::MemoryHeap *, _DWORD *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
              Scaleform::Memory::pGlobalHeap,
              v19);
          v34 = 0i64;
          v35 = 0i64;
          v36 = 0i64;
          v33 &= 0xFFFFFDE0;
        }
        else
        {
          switch ( v18 )
          {
            case 10:
              v20 = v35;
              v11 = v35->RefCount == 1;
              --v20->RefCount;
              if ( v11 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v20);
              break;
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
              v21 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v35;
              if ( !((unsigned __int8)v35 & 1) )
                goto LABEL_36;
              v35 = (Scaleform::GFx::ASStringNode *)((char *)v35 - 1);
              break;
            case 16:
            case 17:
              v21 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v36;
              if ( (unsigned __int8)v36 & 1 )
              {
                v36 = (Scaleform::GFx::ASStringNode *)((char *)v36 - 1);
              }
              else
              {
LABEL_36:
                if ( v21 )
                {
                  v22 = v21->RefCount;
                  if ( v22 & 0x3FFFFF )
                  {
                    v21->RefCount = v22 - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v21);
                  }
                }
              }
              break;
            default:
              break;
          }
        }
      }
      if ( ++v6 >= v4 )
      {
        v2 = v38;
        break;
      }
    }
  }
  if ( &v37 != (Scaleform::GFx::AS3::Instances::fl::Array **)v2 )
  {
    if ( v5 )
      v5->RefCount = (v5->RefCount + 1) & 0x8FBFFFFF;
    v23 = *v2;
    if ( *v2 )
    {
      if ( v23 & 1 )
      {
        *v2 = v23 - 1;
      }
      else
      {
        v24 = *(_DWORD *)(v23 + 32);
        if ( v24 & 0x3FFFFF )
        {
          *(_DWORD *)(v23 + 32) = v24 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v23);
        }
      }
    }
    *v2 = (__int64)v5;
  }
  if ( v5 )
  {
    if ( (unsigned __int8)v5 & 1 )
    {
      v37 = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v5 - 1);
    }
    else
    {
      v25 = v5->RefCount;
      if ( v25 & 0x3FFFFF )
      {
        v5->RefCount = v25 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v5->vfptr);
      }
    }
  }
  v38 = (__int64 *)&destArray;
  v26 = destArray.Data.Data;
  v27 = destArray.Data.Size;
  v28 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&destArray.Data.Data[destArray.Data.Size - 1];
  if ( destArray.Data.Size )
  {
    do
    {
      v29 = *v28;
      if ( *v28 )
      {
        if ( (unsigned __int8)v29 & 1 )
        {
          *v28 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v29 - 1);
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
      }
      --v28;
      --v27;
    }
    while ( v27 );
    v26 = destArray.Data.Data;
  }
  if ( v26 )
    ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v26);
}

// File Line: 110
// RVA: 0x834780
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::describeType(Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *this, Scaleform::GFx::ASString *result, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::ASString *v3; // rdi
  Scaleform::GFx::ASStringNode *v4; // rbx
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  Scaleform::GFx::ASStringNode *v7; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+40h] [rbp+8h]

  v3 = result;
  v4 = Scaleform::GFx::AS3::VM::describeTypeEx(this->pTraits.pObject->pVM, &resulta, v)->pNode;
  ++v4->RefCount;
  v5 = v3->pNode;
  v6 = v3->pNode->RefCount == 1;
  --v5->RefCount;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  v3->pNode = v4;
  v7 = resulta.pNode;
  v6 = resulta.pNode->RefCount == 1;
  --v7->RefCount;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
}

// File Line: 116
// RVA: 0x858740
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::printObjectsReport(Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *this, Scaleform::GFx::AS3::Value *result, bool runGarbageCollector, unsigned int reportFlags, Scaleform::GFx::ASString *swfFilter)
{
  unsigned int v5; // edi
  void *(__fastcall *v6)(Scaleform::GFx::AS3::VM *, unsigned int); // rbx

  v5 = reportFlags;
  v6 = this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor;
  if ( runGarbageCollector )
    (*(void (__fastcall **)(void *(__fastcall *)(Scaleform::GFx::AS3::VM *, unsigned int), signed __int64))(*(_QWORD *)v6 + 392i64))(
      v6,
      2i64);
  (*(void (__fastcall **)(void *(__fastcall *)(Scaleform::GFx::AS3::VM *, unsigned int), _QWORD, _QWORD, const char *, _QWORD, _QWORD))(*(_QWORD *)v6 + 416i64))(
    v6,
    v5,
    0i64,
    swfFilter->pNode->pData,
    0i64,
    0i64);
}

// File Line: 141
// RVA: 0x1593490
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx_0_Scaleform::GFx::AS3::Value_const__bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E850 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx,0,Scaleform::GFx::AS3::Value const,bool>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::actionVerboseSet;
  return result;
}

// File Line: 142
// RVA: 0x158DAC0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx_1_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E860 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx,1,bool>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::actionVerboseGet;
  return result;
}

// File Line: 143
// RVA: 0x1593430
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx_2_Scaleform::GFx::AS3::Value_const__double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E870 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx,2,Scaleform::GFx::AS3::Value const,double>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::setBackgroundAlpha;
  return result;
}

// File Line: 144
// RVA: 0x158DAF0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx_3_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E880 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx,3,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Instances::fl::Error::getStackTrace;
  return result;
}

// File Line: 145
// RVA: 0x158DB20
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx_4_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E890 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx,4,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::getCodeFileName;
  return result;
}

// File Line: 146
// RVA: 0x158DB50
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx_5_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::Array___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E8A0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx,5,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array>>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::getCodeFileNames;
  return result;
}

// File Line: 147
// RVA: 0x1593460
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx_6_Scaleform::GFx::ASString_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E8B0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx,6,Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::describeType;
  return result;
}

// File Line: 148
// RVA: 0x1596760
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc3_Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx_7_Scaleform::GFx::AS3::Value_const__bool_unsigned_long_Scaleform::GFx::ASString_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E8C0 = v1;
  Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx,7,Scaleform::GFx::AS3::Value const,bool,unsigned long,Scaleform::GFx::ASString const &>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::printObjectsReport;
  return result;
}

// File Line: 195
// RVA: 0x740E00
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_gfx::SystemEx::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
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
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_gfx::SystemExCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_gfx::SystemEx::`vftable';
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl_gfx::SystemExCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
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
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::`vftable';
    LODWORD(v10[1].vfptr) = 1;
    HIDWORD(v10[1].vfptr) = 2;
    LODWORD(v10[1]._pRCC) = 4;
    HIDWORD(v10[1].pRCCRaw) = 8;
  }
  return v3;
}

