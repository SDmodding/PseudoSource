// File Line: 34
// RVA: 0x1593D90
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_net::URLVariables_0_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::ASString_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F5A0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLVariables,0,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method = Scaleform::GFx::AS3::Instances::fl_net::URLVariables::decode;
  return result;
}

// File Line: 35
// RVA: 0x158E540
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_net::URLVariables_1_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F5B0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::URLVariables,1,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Instances::fl_net::URLVariables::toString;
  return result;
}

// File Line: 49
// RVA: 0x8335B0
void __fastcall Scaleform::GFx::AS3::Instances::fl_net::URLVariables::decode(
        Scaleform::GFx::AS3::Instances::fl_net::URLVariables *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASString *source)
{
  char v5; // r15
  unsigned int FirstCharAt; // ebx
  int v7; // r14d
  int v8; // edi
  unsigned __int64 v9; // rax
  int v10; // r8d
  int v11; // ecx
  int v12; // r14d
  int v13; // ebx
  Scaleform::StringBuffer *v14; // rsi
  unsigned __int64 Size; // rdi
  Scaleform::GFx::AS3::VM *pVM; // rcx
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *StringManagerRef; // rsi
  char *pData; // r8
  Scaleform::GFx::AS3::Value::V1U *v19; // rax
  char v20; // di
  Scaleform::GFx::AS3::Value::V1U v21; // rbx
  Scaleform::GFx::AS3::Value::V2U v22; // r14
  char *v23; // r8
  Scaleform::GFx::AS3::Value::V1U *v24; // rax
  Scaleform::GFx::AS3::Value::V1U v25; // rdx
  Scaleform::GFx::AS3::Instances::fl::XMLList *pObject; // rdx
  int v27; // esi
  const char *v28; // rax
  Scaleform::GFx::ASString *v29; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v31; // zf
  Scaleform::GFx::ASStringNode *v32; // rcx
  bool v33; // bl
  Scaleform::GFx::AS3::Instances::fl::XMLList *v34; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v36; // rcx
  Scaleform::GFx::ASStringNode *v37; // rcx
  Scaleform::StringBuffer *v38; // rcx
  Scaleform::GFx::AS3::VM *v39; // rcx
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v40; // rsi
  char *v41; // r8
  Scaleform::GFx::AS3::Value::V1U *v42; // rax
  char v43; // di
  Scaleform::GFx::AS3::Value::V1U v44; // rbx
  Scaleform::GFx::AS3::Value::V2U v45; // r14
  char *v46; // r8
  Scaleform::GFx::AS3::Value::V1U *v47; // rax
  Scaleform::GFx::AS3::Value::V1U v48; // rdx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v49; // rdx
  int v50; // esi
  const char *v51; // rax
  Scaleform::GFx::ASString *v52; // rax
  Scaleform::GFx::ASStringNode *v53; // rcx
  Scaleform::GFx::ASStringNode *v54; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v55; // rcx
  unsigned int v56; // eax
  Scaleform::GFx::ASStringNode *v57; // rcx
  Scaleform::GFx::ASStringNode *v58; // rcx
  int v59; // [rsp+20h] [rbp-E0h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v60; // [rsp+28h] [rbp-D8h] BYREF
  Scaleform::GFx::AS3::Value v61; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::GFx::ASString v62; // [rsp+50h] [rbp-B0h] BYREF
  Scaleform::GFx::AS3::Value v63; // [rsp+58h] [rbp-A8h] BYREF
  Scaleform::GFx::AS3::Value v64; // [rsp+78h] [rbp-88h] BYREF
  Scaleform::GFx::ASString v65; // [rsp+98h] [rbp-68h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+A0h] [rbp-60h] BYREF
  Scaleform::GFx::AS3::Value::V2U v67; // [rsp+A8h] [rbp-58h]
  Scaleform::GFx::ASString v68; // [rsp+B0h] [rbp-50h] BYREF
  Scaleform::StringBuffer v69; // [rsp+B8h] [rbp-48h] BYREF
  Scaleform::StringBuffer v70; // [rsp+E8h] [rbp-18h] BYREF
  __int64 v71; // [rsp+118h] [rbp+18h]
  char v72; // [rsp+170h] [rbp+70h] BYREF
  char *offset; // [rsp+178h] [rbp+78h] BYREF

  v71 = -2i64;
  v5 = 1;
  Scaleform::StringBuffer::StringBuffer(&v69, Scaleform::Memory::pGlobalHeap);
  Scaleform::StringBuffer::StringBuffer(&v70, Scaleform::Memory::pGlobalHeap);
  if ( source->pNode->Size )
  {
    FirstCharAt = Scaleform::GFx::ASConstString::GetFirstCharAt(source, 0i64, (const char **)&offset);
    while ( FirstCharAt )
    {
      switch ( FirstCharAt )
      {
        case 0x25u:
          FirstCharAt = Scaleform::GFx::ASConstString::GetNextChar(source, (const char **)&offset);
          v7 = 0;
          if ( FirstCharAt )
          {
            v8 = 0;
            do
            {
              if ( v8 >= 8 )
                break;
              v9 = (unsigned __int64)(unsigned __int16)FirstCharAt >> 8;
              v10 = Scaleform::UnicodeXDigitBits[v9];
              if ( !Scaleform::UnicodeXDigitBits[v9] )
                goto LABEL_87;
              if ( v10 != 1 )
              {
                v11 = Scaleform::UnicodeXDigitBits[v10 + (((unsigned __int16)FirstCharAt >> 4) & 0xF)];
                if ( !_bittest(&v11, FirstCharAt & 0xF) )
                  goto LABEL_87;
              }
              if ( FirstCharAt - 65 <= 0x19 )
                FirstCharAt += 32;
              v12 = v7 << v8;
              v13 = FirstCharAt > 0x39 ? FirstCharAt - 87 : FirstCharAt - 48;
              v7 = v13 | v12;
              FirstCharAt = Scaleform::GFx::ASConstString::GetNextChar(source, (const char **)&offset);
              v8 += 4;
            }
            while ( FirstCharAt );
            if ( v7 )
            {
              v14 = &v69;
              if ( !v5 )
                v14 = &v70;
              Size = v14->Size;
              Scaleform::StringBuffer::Resize(v14, Size + 1);
              v14->pData[Size] = v7;
              continue;
            }
          }
          break;
        case 0xDu:
          FirstCharAt = 10;
          break;
        case 0x26u:
          pVM = this->pTraits.pObject->pVM;
          StringManagerRef = pVM->StringManagerRef;
          pData = &customCaption;
          if ( v69.pData )
            pData = v69.pData;
          v19 = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                                                     pVM->StringManagerRef,
                                                     &resulta,
                                                     pData);
          v20 = 10;
          v64.Flags = 10;
          v64.Bonus.pWeakProxy = 0i64;
          v21 = *v19;
          v64.value.VS._1 = v21;
          if ( v21.VStr == &v21.VStr->pManager->NullStringNode )
          {
            v21.VStr = 0i64;
            v64.value.VS._1.VStr = 0i64;
            v22.VObj = v67.VObj;
            v64.value.VS._2 = v67;
            v20 = 12;
            v64.Flags = 12;
          }
          else
          {
            ++v21.VStr->RefCount;
            v22.VObj = (Scaleform::GFx::AS3::Object *)v64.value.VS._2;
          }
          v23 = &customCaption;
          if ( v70.pData )
            v23 = v70.pData;
          v24 = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                                                     StringManagerRef,
                                                     &v65,
                                                     v23);
          v63.Flags = 10;
          v63.Bonus.pWeakProxy = 0i64;
          v25 = *v24;
          v63.value.VS._1 = *v24;
          if ( v24->VStr == &v24->VStr->pManager->NullStringNode )
          {
            v63.value.VS._1.VStr = 0i64;
            v63.value.VS._2 = v67;
            v63.Flags = 12;
          }
          else
          {
            ++v25.VStr->RefCount;
          }
          pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)this->pTraits.pObject->pVM->PublicNamespace.pObject;
          v59 = 0;
          v60.pObject = pObject;
          if ( pObject )
            pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
          v61.Flags = 0;
          v61.Bonus.pWeakProxy = 0i64;
          v27 = v20 & 0x1F;
          if ( (unsigned int)(v27 - 12) <= 3
            && v21.VStr
            && (v28 = v21.VStr[1].pData, *((_DWORD *)v28 + 30) == 17)
            && (v28[112] & 0x20) == 0 )
          {
            Scaleform::GFx::AS3::Value::Assign(&v61, (Scaleform::GFx::ASString *)&v21.VStr[1].16);
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
              &v60,
              *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v21.VStr[1].RefCount);
            v59 &= 0xFFFFFFF9;
          }
          else
          {
            _mm_prefetch((const char *)&v64, 2);
            *(_QWORD *)&v61.Flags = *(_QWORD *)&v64.Flags;
            v61.Bonus.pWeakProxy = 0i64;
            v61.value.VS._1 = v21;
            v61.value.VS._2 = v22;
            if ( (v20 & 0x1Fu) > 9 )
            {
              if ( v27 == 10 )
              {
                ++v21.VStr->RefCount;
              }
              else if ( (v20 & 0x1Fu) <= 0xF )
              {
                if ( v21.VStr )
                  v21.VStr->Size = (v21.VStr->Size + 1) & 0x8FBFFFFF;
              }
              else if ( (v20 & 0x1Fu) <= 0x11 && v22.VObj )
              {
                v22.VObj->RefCount = (v22.VObj->RefCount + 1) & 0x8FBFFFFF;
              }
            }
            if ( (v61.Flags & 0x1F) == 10 )
            {
              Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v61, &v62);
              if ( v62.pNode->Size )
              {
                if ( *v62.pNode->pData == 64 )
                {
                  v59 |= 8u;
                  v29 = Scaleform::GFx::ASString::Substring(&v62, &v68, 1, v62.pNode->Size);
                  Scaleform::GFx::AS3::Value::Assign(&v61, v29);
                  pNode = v68.pNode;
                  v31 = v68.pNode->RefCount-- == 1;
                  if ( v31 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
                }
              }
              v32 = v62.pNode;
              v31 = v62.pNode->RefCount-- == 1;
              if ( v31 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v32);
            }
          }
          v33 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl_net::URLVariables *, char *, int *, Scaleform::GFx::AS3::Value *))this->vfptr[1].ForEachChild_GC)(
                            this,
                            &v72,
                            &v59,
                            &v63) == 0;
          if ( (v61.Flags & 0x1F) > 9 )
          {
            if ( (v61.Flags & 0x200) != 0 )
            {
              v31 = v61.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v31 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              memset(&v61.Bonus, 0, 24);
              v61.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v61);
            }
          }
          v34 = v60.pObject;
          if ( v60.pObject )
          {
            if ( ((__int64)v60.pObject & 1) != 0 )
            {
              --v60.pObject;
            }
            else
            {
              RefCount = v60.pObject->RefCount;
              if ( (RefCount & 0x3FFFFF) != 0 )
              {
                v60.pObject->RefCount = RefCount - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v34);
              }
            }
          }
          if ( (v63.Flags & 0x1F) > 9 )
          {
            if ( (v63.Flags & 0x200) != 0 )
            {
              v31 = v63.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v31 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              memset(&v63.Bonus, 0, 24);
              v63.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v63);
            }
          }
          v36 = v65.pNode;
          v31 = v65.pNode->RefCount-- == 1;
          if ( v31 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v36);
          if ( (v20 & 0x1Fu) > 9 )
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v64);
          v37 = resulta.pNode;
          v31 = resulta.pNode->RefCount-- == 1;
          if ( v31 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v37);
          if ( v33 )
            goto LABEL_146;
          Scaleform::StringBuffer::Clear(&v69);
          Scaleform::StringBuffer::Clear(&v70);
          v5 = 1;
          break;
        default:
          if ( !v5 )
          {
            v38 = &v70;
            goto LABEL_86;
          }
          if ( FirstCharAt != 61 )
          {
            v38 = &v69;
LABEL_86:
            Scaleform::StringBuffer::AppendChar(v38, FirstCharAt);
            break;
          }
          v5 = 0;
          break;
      }
LABEL_87:
      FirstCharAt = Scaleform::GFx::ASConstString::GetNextChar(source, (const char **)&offset);
    }
    if ( Scaleform::StringBuffer::GetLength(&v69) )
    {
      v39 = this->pTraits.pObject->pVM;
      v40 = v39->StringManagerRef;
      v41 = &customCaption;
      if ( v69.pData )
        v41 = v69.pData;
      v42 = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                                                 v39->StringManagerRef,
                                                 &v68,
                                                 v41);
      v43 = 10;
      v64.Flags = 10;
      v64.Bonus.pWeakProxy = 0i64;
      v44 = *v42;
      v64.value.VS._1 = v44;
      if ( v44.VStr == &v44.VStr->pManager->NullStringNode )
      {
        v44.VStr = 0i64;
        v64.value.VS._1.VStr = 0i64;
        v45.VObj = v67.VObj;
        v64.value.VS._2 = v67;
        v43 = 12;
        v64.Flags = 12;
      }
      else
      {
        ++v44.VStr->RefCount;
        v45.VObj = (Scaleform::GFx::AS3::Object *)v64.value.VS._2;
      }
      v46 = &customCaption;
      if ( v70.pData )
        v46 = v70.pData;
      v47 = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                                                 v40,
                                                 &v65,
                                                 v46);
      v63.Flags = 10;
      v63.Bonus.pWeakProxy = 0i64;
      v48 = *v47;
      v63.value.VS._1 = *v47;
      if ( v47->VStr == &v47->VStr->pManager->NullStringNode )
      {
        v63.value.VS._1.VStr = 0i64;
        v63.value.VS._2 = v67;
        v63.Flags = 12;
      }
      else
      {
        ++v48.VStr->RefCount;
      }
      v49 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)this->pTraits.pObject->pVM->PublicNamespace.pObject;
      v59 = 0;
      v60.pObject = v49;
      if ( v49 )
        v49->RefCount = (v49->RefCount + 1) & 0x8FBFFFFF;
      v61.Flags = 0;
      v61.Bonus.pWeakProxy = 0i64;
      v50 = v43 & 0x1F;
      if ( (unsigned int)(v50 - 12) <= 3
        && v44.VStr
        && (v51 = v44.VStr[1].pData, *((_DWORD *)v51 + 30) == 17)
        && (v51[112] & 0x20) == 0 )
      {
        Scaleform::GFx::AS3::Value::Assign(&v61, (Scaleform::GFx::ASString *)&v44.VStr[1].16);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          &v60,
          *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v44.VStr[1].RefCount);
        v59 &= 0xFFFFFFF9;
      }
      else
      {
        _mm_prefetch((const char *)&v64, 2);
        *(_QWORD *)&v61.Flags = *(_QWORD *)&v64.Flags;
        v61.Bonus.pWeakProxy = 0i64;
        v61.value.VS._1 = v44;
        v61.value.VS._2 = v45;
        if ( (v43 & 0x1Fu) > 9 )
        {
          if ( v50 == 10 )
          {
            ++v44.VStr->RefCount;
          }
          else if ( (v43 & 0x1Fu) <= 0xF )
          {
            if ( v44.VStr )
              v44.VStr->Size = (v44.VStr->Size + 1) & 0x8FBFFFFF;
          }
          else if ( (v43 & 0x1Fu) <= 0x11 && v45.VObj )
          {
            v45.VObj->RefCount = (v45.VObj->RefCount + 1) & 0x8FBFFFFF;
          }
        }
        if ( (v61.Flags & 0x1F) == 10 )
        {
          Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v61, &v62);
          if ( v62.pNode->Size )
          {
            if ( *v62.pNode->pData == 64 )
            {
              v59 |= 8u;
              v52 = Scaleform::GFx::ASString::Substring(&v62, &resulta, 1, v62.pNode->Size);
              Scaleform::GFx::AS3::Value::Assign(&v61, v52);
              v53 = resulta.pNode;
              v31 = resulta.pNode->RefCount-- == 1;
              if ( v31 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v53);
            }
          }
          v54 = v62.pNode;
          v31 = v62.pNode->RefCount-- == 1;
          if ( v31 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v54);
        }
      }
      ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl_net::URLVariables *, char *, int *, Scaleform::GFx::AS3::Value *))this->vfptr[1].ForEachChild_GC)(
        this,
        &v72,
        &v59,
        &v63);
      if ( (v61.Flags & 0x1F) > 9 )
      {
        if ( (v61.Flags & 0x200) != 0 )
        {
          v31 = v61.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v31 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&v61.Bonus, 0, 24);
          v61.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v61);
        }
      }
      v55 = v60.pObject;
      if ( v60.pObject )
      {
        if ( ((__int64)v60.pObject & 1) != 0 )
        {
          --v60.pObject;
        }
        else
        {
          v56 = v60.pObject->RefCount;
          if ( (v56 & 0x3FFFFF) != 0 )
          {
            v60.pObject->RefCount = v56 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v55);
          }
        }
      }
      if ( (v63.Flags & 0x1F) > 9 )
      {
        if ( (v63.Flags & 0x200) != 0 )
        {
          v31 = v63.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v31 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&v63.Bonus, 0, 24);
          v63.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v63);
        }
      }
      v57 = v65.pNode;
      v31 = v65.pNode->RefCount-- == 1;
      if ( v31 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v57);
      if ( (v43 & 0x1Fu) > 9 )
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v64);
      v58 = v68.pNode;
      v31 = v68.pNode->RefCount-- == 1;
      if ( v31 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v58);
    }
  }
LABEL_146:
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v70);
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v69);
}

// File Line: 141
// RVA: 0x869120
void __fastcall Scaleform::GFx::AS3::Instances::fl_net::URLVariables::toString(
        Scaleform::GFx::AS3::Instances::fl_net::URLVariables *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::HashLH<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *p_DynAttrs; // r9
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *pTable; // r8
  unsigned __int64 v6; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v7; // rcx
  signed __int64 v8; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v9; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v10; // rsi
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v12; // zf
  unsigned __int64 SizeMask; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v14; // rax
  char *pData; // r8
  Scaleform::GFx::ASString *v16; // rax
  Scaleform::GFx::ASStringNode *v17; // rbx
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::HashLH<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *v20; // [rsp+30h] [rbp-68h]
  Scaleform::StringBuffer b; // [rsp+40h] [rbp-58h] BYREF
  Scaleform::GFx::ASString v22; // [rsp+A0h] [rbp+8h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+A8h] [rbp+10h] BYREF

  Scaleform::StringBuffer::StringBuffer(&b, Scaleform::Memory::pGlobalHeap);
  p_DynAttrs = &this->DynAttrs;
  if ( this != (Scaleform::GFx::AS3::Instances::fl_net::URLVariables *)-48i64 )
  {
    pTable = p_DynAttrs->mHash.pTable;
    v6 = 0i64;
    if ( p_DynAttrs->mHash.pTable )
    {
      v7 = pTable + 1;
      do
      {
        if ( v7->EntryCount != -2i64 )
          break;
        ++v6;
        v7 += 4;
      }
      while ( v6 <= pTable->SizeMask );
      v20 = &this->DynAttrs;
    }
    else
    {
      v20 = 0i64;
    }
    v8 = v6;
    while ( v20 )
    {
      v9 = v20->mHash.pTable;
      if ( !v20->mHash.pTable || v8 > (signed __int64)v9->SizeMask )
        break;
      v10 = &v9[4 * v8];
      if ( Scaleform::StringBuffer::GetLength(&b) )
        Scaleform::StringBuffer::AppendChar(&b, 0x26u);
      Scaleform::GFx::ASUtils::AS3::EncodeURIComponent(
        *(const char **)v10[2].SizeMask,
        *(unsigned int *)(v10[2].SizeMask + 32),
        &b,
        1);
      Scaleform::StringBuffer::AppendChar(&b, 0x3Du);
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
        this->pTraits.pObject->pVM->StringManagerRef,
        &resulta);
      if ( Scaleform::GFx::AS3::Value::Convert2String(
             (Scaleform::GFx::AS3::Value *)&v10[3],
             (Scaleform::GFx::AS3::CheckResult *)&v22,
             &resulta)->Result )
        Scaleform::GFx::ASUtils::AS3::EncodeVar(resulta.pNode->pData, resulta.pNode->Size, &b, 1);
      pNode = resulta.pNode;
      v12 = resulta.pNode->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      SizeMask = v20->mHash.pTable->SizeMask;
      if ( v8 <= (__int64)SizeMask && ++v8 <= SizeMask )
      {
        v14 = &v20->mHash.pTable[4 * v8 + 1];
        do
        {
          if ( v14->EntryCount != -2i64 )
            break;
          ++v8;
          v14 += 4;
        }
        while ( v8 <= SizeMask );
      }
    }
  }
  pData = &customCaption;
  if ( b.pData )
    pData = b.pData;
  v16 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
          this->pTraits.pObject->pVM->StringManagerRef,
          &v22,
          pData);
  v17 = v16->pNode;
  ++v16->pNode->RefCount;
  v18 = result->pNode;
  v12 = result->pNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  result->pNode = v17;
  v19 = v22.pNode;
  v12 = v22.pNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&b);
}

// File Line: 173
// RVA: 0x799D90
void __fastcall Scaleform::GFx::AS3::Instances::fl_net::URLVariables::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_net::URLVariables *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::Value v7; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::CheckResult v8; // [rsp+68h] [rbp+10h] BYREF
  Scaleform::GFx::ASString result; // [rsp+78h] [rbp+20h] BYREF

  if ( argc )
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      this->pTraits.pObject->pVM->StringManagerRef,
      &result);
    if ( Scaleform::GFx::AS3::Value::Convert2String(argv, &v8, &result)->Result )
    {
      v7.Flags = 0;
      v7.Bonus.pWeakProxy = 0i64;
      Scaleform::GFx::AS3::Instances::fl_net::URLVariables::decode(this, &v7, &result);
    }
    pNode = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 214
// RVA: 0x8003F0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_net::URLVariables::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_net::URLVariables *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_net::URLVariables *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_net::URLVariables> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_net::URLVariables> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_net::URLVariables::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 236
// RVA: 0x737B80
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_net::URLVariables::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl_net::URLVariablesCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_net::URLVariables::`vftable;
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl_net::URLVariablesCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_net::URLVariables::`vftable;
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
                                       72i64);
  if ( v9 )
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
  return result;
}

