// File Line: 46
// RVA: 0x82ABE0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::actionVerboseSet(
        Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *this,
        Scaleform::GFx::AS3::Value *result,
        bool verbose)
{
  void *(__fastcall *vecDelDtor)(Scaleform::GFx::AS3::VM *, unsigned int); // rcx

  vecDelDtor = this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor;
  (*(void (__fastcall **)(void *(__fastcall *)(Scaleform::GFx::AS3::VM *, unsigned int), bool))(*(_QWORD *)vecDelDtor
                                                                                              + 544i64))(
    vecDelDtor,
    verbose);
  this->pTraits.pObject->pVM->UI->NeedToCheck = verbose;
}

// File Line: 57
// RVA: 0x82ABB0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::actionVerboseGet(
        Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *this,
        bool *result)
{
  *result = (*((_DWORD *)this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor + 5300) & 4) != 0;
}

// File Line: 65
// RVA: 0x85AEA0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::setBackgroundAlpha(
        Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *this,
        Scaleform::GFx::AS3::Value *result,
        long double value)
{
  void *(__fastcall *vecDelDtor)(Scaleform::GFx::AS3::VM *, unsigned int); // rcx

  vecDelDtor = this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor;
  (*(void (__fastcall **)(void *(__fastcall *)(Scaleform::GFx::AS3::VM *, unsigned int), Scaleform::GFx::AS3::Value *))(*(_QWORD *)vecDelDtor + 264i64))(
    vecDelDtor,
    result);
}

// File Line: 82
// RVA: 0x84ABA0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::getCodeFileName(
        Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::VM::GetCodeFileName(this->pTraits.pObject->pVM, result);
}

// File Line: 90
// RVA: 0x84ABB0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::getCodeFileNames(
        Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *this,
        Scaleform::Array<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2,Scaleform::ArrayDefaultPolicy> *result)
{
  __int64 *v2; // r14
  unsigned __int64 AllLoadedAbcFiles; // r15
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // rbx
  __int64 v6; // rsi
  Scaleform::GFx::AS3::Value *pSecond; // r12
  Scaleform::GFx::ASString *String; // rax
  Scaleform::GFx::ASStringNode *pNode; // rdx
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  unsigned __int64 Length; // rcx
  __int64 v13; // rcx
  __int64 v14; // rdx
  __int64 v15; // rdx
  Scaleform::GFx::ASStringNode *v16; // rax
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v18; // rcx
  unsigned int RefCount; // eax
  __int64 v20; // rcx
  int v21; // eax
  unsigned int v22; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *Data; // rdx
  unsigned __int64 Size; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *v25; // rbx
  Scaleform::GFx::AS3::VMAbcFile *pObject; // rcx
  unsigned int v27; // eax
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [rsp+30h] [rbp-39h] BYREF
  Scaleform::Array<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2,Scaleform::ArrayDefaultPolicy> destArray; // [rsp+40h] [rbp-29h] BYREF
  int v30; // [rsp+58h] [rbp-11h] BYREF
  _DWORD *v31; // [rsp+60h] [rbp-9h]
  Scaleform::GFx::ASStringNode *v32; // [rsp+68h] [rbp-1h]
  Scaleform::GFx::ASStringNode *v33; // [rsp+70h] [rbp+7h]
  Scaleform::GFx::AS3::Instances::fl::Array *v34; // [rsp+D0h] [rbp+67h] BYREF
  Scaleform::Array<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2,Scaleform::ArrayDefaultPolicy> *p_destArray; // [rsp+D8h] [rbp+6Fh]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> resulta; // [rsp+E0h] [rbp+77h] BYREF
  __int64 v37; // [rsp+E8h] [rbp+7Fh]

  p_destArray = result;
  v2 = (__int64 *)result;
  resulta.pV = (Scaleform::GFx::AS3::Instances::fl::Array *)&destArray;
  memset(&destArray, 0, sizeof(destArray));
  AllLoadedAbcFiles = Scaleform::GFx::AS3::VM::GetAllLoadedAbcFiles(this->pTraits.pObject->pVM, &destArray);
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
    &resulta,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)this->pTraits.pObject->pVM->TraitsArray.pObject->ITraits.pObject);
  pV = resulta.pV;
  v34 = resulta.pV;
  v6 = 0i64;
  if ( AllLoadedAbcFiles )
  {
    pSecond = key.pSecond;
    while ( 1 )
    {
      String = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                 this->pTraits.pObject->pVM->StringManagerRef,
                 (Scaleform::GFx::ASString *)&resulta,
                 (const char *)((destArray.Data.Data[v6].pObject->File.pObject->Source.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                              + 12));
      v30 = 10;
      v31 = 0i64;
      pNode = String->pNode;
      v32 = String->pNode;
      if ( String->pNode == &String->pNode->pManager->NullStringNode )
      {
        v32 = 0i64;
        v33 = (Scaleform::GFx::ASStringNode *)pSecond;
        v30 = 12;
      }
      else
      {
        ++pNode->RefCount;
      }
      v10 = (Scaleform::GFx::ASStringNode *)resulta.pV;
      v11 = LODWORD(resulta.pV->pPrev)-- == 1;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
      Length = pV->SA.Length;
      if ( Length == pV->SA.ValueA.Data.Size )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          &pV->SA.ValueA.Data,
          (__int64 *)pV->SA.ValueA.Data.pHeap,
          pV->SA.ValueA.Data.Size + 1);
        v13 = 32 * pV->SA.ValueA.Data.Size;
        v14 = (__int64)&pV->SA.ValueA.Data.Data[-1];
        v11 = v13 + v14 == 0;
        v15 = v13 + v14;
        v37 = v15;
        if ( !v11 )
        {
          *(_DWORD *)v15 = v30;
          *(_QWORD *)(v15 + 8) = v31;
          *(_QWORD *)(v15 + 16) = v32;
          *(_QWORD *)(v15 + 24) = v33;
          if ( (v30 & 0x1Fu) > 9 )
          {
            if ( (v30 & 0x200) != 0 )
            {
              ++*v31;
            }
            else if ( (v30 & 0x1F) == 10 )
            {
              ++v32->RefCount;
            }
            else if ( (v30 & 0x1Fu) > 0xA )
            {
              if ( (v30 & 0x1Fu) <= 0xF )
              {
                v16 = v32;
LABEL_19:
                if ( v16 )
                {
                  ++v16->Size;
                  v16->Size &= 0x8FBFFFFF;
                }
                goto LABEL_24;
              }
              if ( (v30 & 0x1Fu) <= 0x11 )
              {
                v16 = v33;
                goto LABEL_19;
              }
            }
          }
        }
      }
      else
      {
        pV->SA.ValueHHighInd = Length;
        key.pFirst = &pV->SA.ValueHHighInd;
        key.pSecond = (Scaleform::GFx::AS3::Value *)&v30;
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
          &pV->SA.ValueH.mHash,
          pV->SA.ValueH.mHash.pHeap,
          &key);
      }
LABEL_24:
      ++pV->SA.Length;
      if ( (v30 & 0x1Fu) > 9 )
      {
        if ( (v30 & 0x200) != 0 )
        {
          v11 = (*v31)-- == 1;
          if ( v11 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          v31 = 0i64;
          v32 = 0i64;
          v33 = 0i64;
          v30 &= 0xFFFFFDE0;
        }
        else
        {
          switch ( v30 & 0x1F )
          {
            case 0xA:
              v17 = v32;
              v11 = v32->RefCount-- == 1;
              if ( v11 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v17);
              break;
            case 0xB:
            case 0xC:
            case 0xD:
            case 0xE:
            case 0xF:
              v18 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v32;
              if ( ((unsigned __int8)v32 & 1) == 0 )
                goto LABEL_36;
              v32 = (Scaleform::GFx::ASStringNode *)((char *)v32 - 1);
              break;
            case 0x10:
            case 0x11:
              v18 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v33;
              if ( ((unsigned __int8)v33 & 1) != 0 )
              {
                v33 = (Scaleform::GFx::ASStringNode *)((char *)v33 - 1);
              }
              else
              {
LABEL_36:
                if ( v18 )
                {
                  RefCount = v18->RefCount;
                  if ( (RefCount & 0x3FFFFF) != 0 )
                  {
                    v18->RefCount = RefCount - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v18);
                  }
                }
              }
              break;
            default:
              break;
          }
        }
      }
      if ( ++v6 >= AllLoadedAbcFiles )
      {
        v2 = (__int64 *)p_destArray;
        break;
      }
    }
  }
  if ( &v34 != (Scaleform::GFx::AS3::Instances::fl::Array **)v2 )
  {
    if ( pV )
      pV->RefCount = (pV->RefCount + 1) & 0x8FBFFFFF;
    v20 = *v2;
    if ( *v2 )
    {
      if ( (v20 & 1) != 0 )
      {
        *v2 = v20 - 1;
      }
      else
      {
        v21 = *(_DWORD *)(v20 + 32);
        if ( (v21 & 0x3FFFFF) != 0 )
        {
          *(_DWORD *)(v20 + 32) = v21 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v20);
        }
      }
    }
    *v2 = (__int64)pV;
  }
  if ( pV )
  {
    if ( ((unsigned __int8)pV & 1) != 0 )
    {
      v34 = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)pV - 1);
    }
    else
    {
      v22 = pV->RefCount;
      if ( (v22 & 0x3FFFFF) != 0 )
      {
        pV->RefCount = v22 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
      }
    }
  }
  p_destArray = &destArray;
  Data = destArray.Data.Data;
  Size = destArray.Data.Size;
  v25 = &destArray.Data.Data[destArray.Data.Size - 1];
  if ( destArray.Data.Size )
  {
    do
    {
      pObject = v25->pObject;
      if ( v25->pObject )
      {
        if ( ((unsigned __int8)pObject & 1) != 0 )
        {
          v25->pObject = (Scaleform::GFx::AS3::VMAbcFile *)((char *)pObject - 1);
        }
        else
        {
          v27 = pObject->RefCount;
          if ( (v27 & 0x3FFFFF) != 0 )
          {
            pObject->RefCount = v27 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
          }
        }
      }
      --v25;
      --Size;
    }
    while ( Size );
    Data = destArray.Data.Data;
  }
  if ( Data )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 110
// RVA: 0x834780
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::describeType(
        Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::ASString *v4; // rax
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::ASStringNode *v8; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+40h] [rbp+8h] BYREF

  v4 = Scaleform::GFx::AS3::VM::describeTypeEx(this->pTraits.pObject->pVM, &resulta, v);
  pNode = v4->pNode;
  ++v4->pNode->RefCount;
  v6 = result->pNode;
  v7 = result->pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  result->pNode = pNode;
  v8 = resulta.pNode;
  v7 = resulta.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
}

// File Line: 116
// RVA: 0x858740
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::printObjectsReport(
        Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *this,
        Scaleform::GFx::AS3::Value *result,
        bool runGarbageCollector,
        unsigned int reportFlags,
        Scaleform::GFx::ASString *swfFilter)
{
  void *(__fastcall *vecDelDtor)(Scaleform::GFx::AS3::VM *, unsigned int); // rbx

  vecDelDtor = this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor;
  if ( runGarbageCollector )
    (*(void (__fastcall **)(void *(__fastcall *)(Scaleform::GFx::AS3::VM *, unsigned int), __int64))(*(_QWORD *)vecDelDtor + 392i64))(
      vecDelDtor,
      2i64);
  (*(void (__fastcall **)(void *(__fastcall *)(Scaleform::GFx::AS3::VM *, unsigned int), _QWORD, _QWORD, const char *, _QWORD, _QWORD))(*(_QWORD *)vecDelDtor + 416i64))(
    vecDelDtor,
    reportFlags,
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
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx,5,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array>>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *))Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::getCodeFileNames;
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
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_gfx::SystemEx::MakeClassTraits(
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
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl_gfx::SystemExCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_gfx::SystemEx::`vftable;
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl_gfx::SystemExCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
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
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::`vftable;
    LODWORD(v10[1].vfptr) = 1;
    HIDWORD(v10[1].vfptr) = 2;
    LODWORD(v10[1]._pRCC) = 4;
    HIDWORD(v10[1].pRCCRaw) = 8;
  }
  return result;
}

