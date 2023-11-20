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
void __fastcall Scaleform::GFx::AS3::Instances::fl_net::URLVariables::decode(Scaleform::GFx::AS3::Instances::fl_net::URLVariables *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::ASString *source)
{
  Scaleform::GFx::ASString *v3; // r12
  Scaleform::GFx::AS3::Instances::fl_net::URLVariables *v4; // r13
  char v5; // r15
  unsigned int v6; // ebx
  int v7; // er14
  signed int v8; // edi
  unsigned __int64 v9; // rax
  int v10; // er8
  int v11; // ecx
  int v12; // er14
  int v13; // ebx
  Scaleform::StringBuffer *v14; // rsi
  unsigned __int64 v15; // rdi
  Scaleform::GFx::AS3::VM *v16; // rcx
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v17; // rsi
  char *v18; // r8
  long double *v19; // rax
  unsigned int v20; // edi
  long double v21; // rbx
  Scaleform::GFx::AS3::Value::V2U v22; // r14
  char *v23; // r8
  long double *v24; // rax
  long double v25; // rdx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v26; // rdx
  int v27; // esi
  __int64 v28; // rax
  Scaleform::GFx::ASString *v29; // rax
  Scaleform::GFx::ASStringNode *v30; // rcx
  bool v31; // zf
  Scaleform::GFx::ASStringNode *v32; // rcx
  bool v33; // bl
  Scaleform::GFx::AS3::Instances::fl::XMLList *v34; // rcx
  unsigned int v35; // eax
  Scaleform::GFx::ASStringNode *v36; // rcx
  Scaleform::GFx::ASStringNode *v37; // rcx
  Scaleform::StringBuffer *v38; // rcx
  Scaleform::GFx::AS3::VM *v39; // rcx
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v40; // rsi
  char *v41; // r8
  long double *v42; // rax
  unsigned int v43; // edi
  long double v44; // rbx
  Scaleform::GFx::AS3::Value::V2U v45; // r14
  char *v46; // r8
  long double *v47; // rax
  long double v48; // rdx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v49; // rdx
  int v50; // esi
  __int64 v51; // rax
  Scaleform::GFx::ASString *v52; // rax
  Scaleform::GFx::ASStringNode *v53; // rcx
  Scaleform::GFx::ASStringNode *v54; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v55; // rcx
  unsigned int v56; // eax
  Scaleform::GFx::ASStringNode *v57; // rcx
  Scaleform::GFx::ASStringNode *v58; // rcx
  int v59; // [rsp+20h] [rbp-E0h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v60; // [rsp+28h] [rbp-D8h]
  Scaleform::GFx::AS3::Value v61; // [rsp+30h] [rbp-D0h]
  Scaleform::GFx::ASString v62; // [rsp+50h] [rbp-B0h]
  Scaleform::GFx::AS3::Value v63; // [rsp+58h] [rbp-A8h]
  Scaleform::GFx::AS3::Value v64; // [rsp+78h] [rbp-88h]
  Scaleform::GFx::ASString v65; // [rsp+98h] [rbp-68h]
  Scaleform::GFx::ASString resulta; // [rsp+A0h] [rbp-60h]
  Scaleform::GFx::AS3::Value::V2U v67; // [rsp+A8h] [rbp-58h]
  Scaleform::GFx::ASString v68; // [rsp+B0h] [rbp-50h]
  Scaleform::StringBuffer v69; // [rsp+B8h] [rbp-48h]
  Scaleform::StringBuffer v70; // [rsp+E8h] [rbp-18h]
  __int64 v71; // [rsp+118h] [rbp+18h]
  char v72; // [rsp+170h] [rbp+70h]
  char *offset; // [rsp+178h] [rbp+78h]

  v71 = -2i64;
  v3 = source;
  v4 = this;
  v5 = 1;
  Scaleform::StringBuffer::StringBuffer(&v69, Scaleform::Memory::pGlobalHeap);
  Scaleform::StringBuffer::StringBuffer(&v70, Scaleform::Memory::pGlobalHeap);
  if ( v3->pNode->Size )
  {
    v6 = Scaleform::GFx::ASConstString::GetFirstCharAt(
           (Scaleform::GFx::ASConstString *)&v3->pNode,
           0i64,
           (const char **)&offset);
    while ( v6 )
    {
      switch ( v6 )
      {
        case 0x25u:
          v6 = Scaleform::GFx::ASConstString::GetNextChar(
                 (Scaleform::GFx::ASConstString *)&v3->pNode,
                 (const char **)&offset);
          v7 = 0;
          if ( v6 )
          {
            v8 = 0;
            do
            {
              if ( v8 >= 8 )
                break;
              v9 = (unsigned __int64)(unsigned __int16)v6 >> 8;
              v10 = Scaleform::UnicodeXDigitBits[v9];
              if ( !Scaleform::UnicodeXDigitBits[v9] )
                goto LABEL_94;
              if ( v10 != 1 )
              {
                v11 = Scaleform::UnicodeXDigitBits[v10 + (((unsigned int)(unsigned __int16)v6 >> 4) & 0xF)];
                if ( !_bittest(&v11, v6 & 0xF) )
                  goto LABEL_94;
              }
              if ( v6 - 65 <= 0x19 )
                v6 += 32;
              v12 = v7 << v8;
              v13 = v6 > 0x39 ? v6 - 87 : v6 - 48;
              v7 = v13 | v12;
              v6 = Scaleform::GFx::ASConstString::GetNextChar(
                     (Scaleform::GFx::ASConstString *)&v3->pNode,
                     (const char **)&offset);
              v8 += 4;
            }
            while ( v6 );
            if ( v7 )
            {
              v14 = &v69;
              if ( !v5 )
                v14 = &v70;
              v15 = v14->Size;
              Scaleform::StringBuffer::Resize(v14, v15 + 1);
              v14->pData[v15] = v7;
              continue;
            }
          }
          break;
        case 0xDu:
          v6 = 10;
          break;
        case 0x26u:
          v16 = v4->pTraits.pObject->pVM;
          v17 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v16->StringManagerRef->Builtins;
          v18 = &customWorldMapCaption;
          if ( v69.pData )
            v18 = v69.pData;
          v19 = (long double *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                                 (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v16->StringManagerRef->Builtins,
                                 &resulta,
                                 v18);
          v20 = 10;
          v64.Flags = 10;
          v64.Bonus.pWeakProxy = 0i64;
          v21 = *v19;
          v64.value.VNumber = v21;
          if ( *(_QWORD *)&v21 == *(_QWORD *)(*(_QWORD *)&v21 + 8i64) + 104i64 )
          {
            v21 = 0.0;
            v64.value.VNumber = 0.0;
            v22.VObj = v67.VObj;
            v64.value.VS._2 = v67;
            v20 = 12;
            v64.Flags = 12;
          }
          else
          {
            ++*(_DWORD *)(*(_QWORD *)&v21 + 24i64);
            v22.VObj = (Scaleform::GFx::AS3::Object *)v64.value.VS._2;
          }
          v23 = &customWorldMapCaption;
          if ( v70.pData )
            v23 = v70.pData;
          v24 = (long double *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                                 v17,
                                 &v65,
                                 v23);
          v63.Flags = 10;
          v63.Bonus.pWeakProxy = 0i64;
          v25 = *v24;
          v63.value.VNumber = *v24;
          if ( *(_QWORD *)v24 == *(_QWORD *)(*(_QWORD *)v24 + 8i64) + 104i64 )
          {
            v63.value.VNumber = 0.0;
            v63.value.VS._2 = v67;
            v63.Flags = 12;
          }
          else
          {
            ++*(_DWORD *)(*(_QWORD *)&v25 + 24i64);
          }
          v26 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v4->pTraits.pObject->pVM->PublicNamespace.pObject;
          v59 = 0;
          v60.pObject = v26;
          if ( v26 )
            v26->RefCount = (v26->RefCount + 1) & 0x8FBFFFFF;
          v61.Flags = 0;
          v61.Bonus.pWeakProxy = 0i64;
          v27 = v20 & 0x1F;
          if ( (unsigned int)(v27 - 12) <= 3
            && v21 != 0.0
            && (v28 = *(_QWORD *)(*(_QWORD *)&v21 + 40i64), *(_DWORD *)(v28 + 120) == 17)
            && ~(*(_BYTE *)(v28 + 112) >> 5) & 1 )
          {
            Scaleform::GFx::AS3::Value::Assign(&v61, (Scaleform::GFx::ASString *)(*(_QWORD *)&v21 + 56i64));
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
              &v60,
              *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v21 + 64i64));
            v59 &= 0xFFFFFFF9;
          }
          else
          {
            __asm { prefetcht1 byte ptr [rsp+150h+var_D8.Flags]; Prefetch to all cache levels }
            *(_QWORD *)&v61.Flags = *(_QWORD *)&v64.Flags;
            v61.Bonus.pWeakProxy = 0i64;
            v61.value.VNumber = v21;
            v61.value.VS._2 = v22;
            if ( v27 > 9 )
            {
              if ( (v20 >> 9) & 1 )
              {
                LODWORD(MEMORY[0]) = MEMORY[0] + 1;
              }
              else if ( v27 == 10 )
              {
                ++*(_DWORD *)(*(_QWORD *)&v21 + 24i64);
              }
              else if ( v27 > 10 )
              {
                if ( v27 <= 15 )
                {
                  if ( v21 != 0.0 )
                    *(_DWORD *)(*(_QWORD *)&v21 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v21 + 32i64) + 1) & 0x8FBFFFFF;
                }
                else if ( v27 <= 17 && v22.VObj )
                {
                  v22.VObj->RefCount = (v22.VObj->RefCount + 1) & 0x8FBFFFFF;
                }
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
                  v30 = v68.pNode;
                  v31 = v68.pNode->RefCount == 1;
                  --v30->RefCount;
                  if ( v31 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v30);
                }
              }
              v32 = v62.pNode;
              v31 = v62.pNode->RefCount == 1;
              --v32->RefCount;
              if ( v31 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v32);
            }
          }
          v33 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl_net::URLVariables *, char *, int *, Scaleform::GFx::AS3::Value *))v4->vfptr[1].ForEachChild_GC)(
                            v4,
                            &v72,
                            &v59,
                            &v63) == 0;
          if ( (v61.Flags & 0x1F) > 9 )
          {
            if ( (v61.Flags >> 9) & 1 )
            {
              v31 = v61.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v31 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              v61.Bonus.pWeakProxy = 0i64;
              v61.value = 0ui64;
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
            if ( (_QWORD)v60.pObject & 1 )
            {
              --v60.pObject;
            }
            else
            {
              v35 = v60.pObject->RefCount;
              if ( v35 & 0x3FFFFF )
              {
                v60.pObject->RefCount = v35 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v34->vfptr);
              }
            }
          }
          if ( (v63.Flags & 0x1F) > 9 )
          {
            if ( (v63.Flags >> 9) & 1 )
            {
              v31 = v63.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v31 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              v63.Bonus.pWeakProxy = 0i64;
              v63.value = 0ui64;
              v63.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v63);
            }
          }
          v36 = v65.pNode;
          v31 = v65.pNode->RefCount == 1;
          --v36->RefCount;
          if ( v31 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v36);
          if ( v27 > 9 )
          {
            if ( (v20 >> 9) & 1 )
            {
              LODWORD(MEMORY[0]) = MEMORY[0] - 1;
              if ( !(_DWORD)MEMORY[0] )
                Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
              v64.Bonus.pWeakProxy = 0i64;
              v64.value = 0ui64;
              v64.Flags = v20 & 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v64);
            }
          }
          v37 = resulta.pNode;
          v31 = resulta.pNode->RefCount == 1;
          --v37->RefCount;
          if ( v31 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v37);
          if ( v33 )
            goto LABEL_160;
          Scaleform::StringBuffer::Clear(&v69);
          Scaleform::StringBuffer::Clear(&v70);
          v5 = 1;
          break;
        default:
          if ( !v5 )
          {
            v38 = &v70;
            goto LABEL_93;
          }
          if ( v6 != 61 )
          {
            v38 = &v69;
LABEL_93:
            Scaleform::StringBuffer::AppendChar(v38, v6);
            break;
          }
          v5 = 0;
          break;
      }
LABEL_94:
      v6 = Scaleform::GFx::ASConstString::GetNextChar(
             (Scaleform::GFx::ASConstString *)&v3->pNode,
             (const char **)&offset);
    }
    if ( Scaleform::StringBuffer::GetLength(&v69) )
    {
      v39 = v4->pTraits.pObject->pVM;
      v40 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v39->StringManagerRef->Builtins;
      v41 = &customWorldMapCaption;
      if ( v69.pData )
        v41 = v69.pData;
      v42 = (long double *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                             (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v39->StringManagerRef->Builtins,
                             &v68,
                             v41);
      v43 = 10;
      v64.Flags = 10;
      v64.Bonus.pWeakProxy = 0i64;
      v44 = *v42;
      v64.value.VNumber = v44;
      if ( *(_QWORD *)&v44 == *(_QWORD *)(*(_QWORD *)&v44 + 8i64) + 104i64 )
      {
        v44 = 0.0;
        v64.value.VNumber = 0.0;
        v45.VObj = v67.VObj;
        v64.value.VS._2 = v67;
        v43 = 12;
        v64.Flags = 12;
      }
      else
      {
        ++*(_DWORD *)(*(_QWORD *)&v44 + 24i64);
        v45.VObj = (Scaleform::GFx::AS3::Object *)v64.value.VS._2;
      }
      v46 = &customWorldMapCaption;
      if ( v70.pData )
        v46 = v70.pData;
      v47 = (long double *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                             v40,
                             &v65,
                             v46);
      v63.Flags = 10;
      v63.Bonus.pWeakProxy = 0i64;
      v48 = *v47;
      v63.value.VNumber = *v47;
      if ( *(_QWORD *)v47 == *(_QWORD *)(*(_QWORD *)v47 + 8i64) + 104i64 )
      {
        v63.value.VNumber = 0.0;
        v63.value.VS._2 = v67;
        v63.Flags = 12;
      }
      else
      {
        ++*(_DWORD *)(*(_QWORD *)&v48 + 24i64);
      }
      v49 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v4->pTraits.pObject->pVM->PublicNamespace.pObject;
      v59 = 0;
      v60.pObject = v49;
      if ( v49 )
        v49->RefCount = (v49->RefCount + 1) & 0x8FBFFFFF;
      v61.Flags = 0;
      v61.Bonus.pWeakProxy = 0i64;
      v50 = v43 & 0x1F;
      if ( (unsigned int)(v50 - 12) <= 3
        && v44 != 0.0
        && (v51 = *(_QWORD *)(*(_QWORD *)&v44 + 40i64), *(_DWORD *)(v51 + 120) == 17)
        && ~(*(_BYTE *)(v51 + 112) >> 5) & 1 )
      {
        Scaleform::GFx::AS3::Value::Assign(&v61, (Scaleform::GFx::ASString *)(*(_QWORD *)&v44 + 56i64));
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          &v60,
          *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v44 + 64i64));
        v59 &= 0xFFFFFFF9;
      }
      else
      {
        __asm { prefetcht1 byte ptr [rsp+150h+var_D8.Flags]; Prefetch to all cache levels }
        *(_QWORD *)&v61.Flags = *(_QWORD *)&v64.Flags;
        v61.Bonus.pWeakProxy = 0i64;
        v61.value.VNumber = v44;
        v61.value.VS._2 = v45;
        if ( v50 > 9 )
        {
          if ( (v43 >> 9) & 1 )
          {
            LODWORD(MEMORY[0]) = MEMORY[0] + 1;
          }
          else if ( v50 == 10 )
          {
            ++*(_DWORD *)(*(_QWORD *)&v44 + 24i64);
          }
          else if ( v50 > 10 )
          {
            if ( v50 <= 15 )
            {
              if ( v44 != 0.0 )
                *(_DWORD *)(*(_QWORD *)&v44 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v44 + 32i64) + 1) & 0x8FBFFFFF;
            }
            else if ( v50 <= 17 && v45.VObj )
            {
              v45.VObj->RefCount = (v45.VObj->RefCount + 1) & 0x8FBFFFFF;
            }
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
              v31 = resulta.pNode->RefCount == 1;
              --v53->RefCount;
              if ( v31 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v53);
            }
          }
          v54 = v62.pNode;
          v31 = v62.pNode->RefCount == 1;
          --v54->RefCount;
          if ( v31 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v54);
        }
      }
      ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl_net::URLVariables *, char *, int *, Scaleform::GFx::AS3::Value *))v4->vfptr[1].ForEachChild_GC)(
        v4,
        &v72,
        &v59,
        &v63);
      if ( (v61.Flags & 0x1F) > 9 )
      {
        if ( (v61.Flags >> 9) & 1 )
        {
          v31 = v61.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v31 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v61.Bonus.pWeakProxy = 0i64;
          v61.value = 0ui64;
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
        if ( (_QWORD)v60.pObject & 1 )
        {
          --v60.pObject;
        }
        else
        {
          v56 = v60.pObject->RefCount;
          if ( v56 & 0x3FFFFF )
          {
            v60.pObject->RefCount = v56 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v55->vfptr);
          }
        }
      }
      if ( (v63.Flags & 0x1F) > 9 )
      {
        if ( (v63.Flags >> 9) & 1 )
        {
          v31 = v63.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v31 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v63.Bonus.pWeakProxy = 0i64;
          v63.value = 0ui64;
          v63.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v63);
        }
      }
      v57 = v65.pNode;
      v31 = v65.pNode->RefCount == 1;
      --v57->RefCount;
      if ( v31 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v57);
      if ( v50 > 9 )
      {
        if ( (v43 >> 9) & 1 )
        {
          LODWORD(MEMORY[0]) = MEMORY[0] - 1;
          if ( !(_DWORD)MEMORY[0] )
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
          v64.Bonus.pWeakProxy = 0i64;
          v64.value = 0ui64;
          v64.Flags = v43 & 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v64);
        }
      }
      v58 = v68.pNode;
      v31 = v68.pNode->RefCount == 1;
      --v58->RefCount;
      if ( v31 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v58);
    }
  }
LABEL_160:
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v70);
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v69);
}

// File Line: 141
// RVA: 0x869120
void __fastcall Scaleform::GFx::AS3::Instances::fl_net::URLVariables::toString(Scaleform::GFx::AS3::Instances::fl_net::URLVariables *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // r15
  Scaleform::GFx::AS3::Instances::fl_net::URLVariables *v3; // r14
  Scaleform::HashLH<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *v4; // r9
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v5; // r8
  unsigned __int64 v6; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v7; // rcx
  __int64 v8; // rbx
  __int64 v9; // rdi
  __int64 v10; // rcx
  __int64 v11; // rsi
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  unsigned __int64 v14; // rcx
  _QWORD *v15; // rax
  char *v16; // r8
  Scaleform::GFx::ASStringNode *v17; // rbx
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASStringNode *v19; // rcx
  __m128i v20; // [rsp+30h] [rbp-68h]
  Scaleform::StringBuffer b; // [rsp+40h] [rbp-58h]
  Scaleform::GFx::AS3::CheckResult v22; // [rsp+A0h] [rbp+8h]
  Scaleform::GFx::ASString resulta; // [rsp+A8h] [rbp+10h]

  v2 = result;
  v3 = this;
  Scaleform::StringBuffer::StringBuffer(&b, Scaleform::Memory::pGlobalHeap);
  v4 = &v3->DynAttrs;
  if ( v3 != (Scaleform::GFx::AS3::Instances::fl_net::URLVariables *)-48i64 )
  {
    v5 = v4->mHash.pTable;
    v6 = 0i64;
    if ( v4->mHash.pTable )
    {
      v7 = v5 + 1;
      do
      {
        if ( v7->EntryCount != -2i64 )
          break;
        ++v6;
        v7 += 4;
      }
      while ( v6 <= v5->SizeMask );
      v20.m128i_i64[0] = (__int64)&v3->DynAttrs;
    }
    else
    {
      v20.m128i_i64[0] = 0i64;
    }
    v20.m128i_i64[1] = v6;
    _mm_store_si128(&v20, v20);
    v8 = v20.m128i_i64[1];
    v9 = v20.m128i_i64[0];
    while ( v9 )
    {
      v10 = *(_QWORD *)v9;
      if ( !*(_QWORD *)v9 || v8 > *(_QWORD *)(v10 + 8) )
        break;
      v11 = v10 + (v8 << 6);
      if ( Scaleform::StringBuffer::GetLength(&b) )
        Scaleform::StringBuffer::AppendChar(&b, 0x26u);
      Scaleform::GFx::ASUtils::AS3::EncodeURIComponent(
        **(const char ***)(v11 + 40),
        *(unsigned int *)(*(_QWORD *)(v11 + 40) + 32i64),
        &b,
        1);
      Scaleform::StringBuffer::AppendChar(&b, 0x3Du);
      Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
        (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v3->pTraits.pObject->pVM->StringManagerRef->Builtins,
        &resulta);
      if ( Scaleform::GFx::AS3::Value::Convert2String((Scaleform::GFx::AS3::Value *)(v11 + 48), &v22, &resulta)->Result )
        Scaleform::GFx::ASUtils::AS3::EncodeVar(resulta.pNode->pData, resulta.pNode->Size, &b, 1);
      v12 = resulta.pNode;
      v13 = resulta.pNode->RefCount == 1;
      --v12->RefCount;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      v14 = *(_QWORD *)(*(_QWORD *)v9 + 8i64);
      if ( v8 <= (signed __int64)v14 && ++v8 <= v14 )
      {
        v15 = (_QWORD *)(*(_QWORD *)v9 + (v8 << 6) + 16);
        do
        {
          if ( *v15 != -2i64 )
            break;
          ++v8;
          v15 += 8;
        }
        while ( v8 <= v14 );
      }
    }
  }
  v16 = &customWorldMapCaption;
  if ( b.pData )
    v16 = b.pData;
  v17 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v3->pTraits.pObject->pVM->StringManagerRef->Builtins,
          (Scaleform::GFx::ASString *)&v22,
          v16)->pNode;
  ++v17->RefCount;
  v18 = v2->pNode;
  v13 = v2->pNode->RefCount == 1;
  --v18->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  v2->pNode = v17;
  v19 = *(Scaleform::GFx::ASStringNode **)&v22.Result;
  v13 = *(_DWORD *)(*(_QWORD *)&v22.Result + 24i64) == 1;
  --v19->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&b);
}

// File Line: 173
// RVA: 0x799D90
void __fastcall Scaleform::GFx::AS3::Instances::fl_net::URLVariables::AS3Constructor(Scaleform::GFx::AS3::Instances::fl_net::URLVariables *this, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl_net::URLVariables *v4; // rbx
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  Scaleform::GFx::AS3::Value v7; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::AS3::CheckResult v8; // [rsp+68h] [rbp+10h]
  Scaleform::GFx::ASString result; // [rsp+78h] [rbp+20h]

  if ( argc >= 1 )
  {
    v3 = argv;
    v4 = this;
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->pTraits.pObject->pVM->StringManagerRef->Builtins,
      &result);
    if ( Scaleform::GFx::AS3::Value::Convert2String(v3, &v8, &result)->Result )
    {
      v7.Flags = 0;
      v7.Bonus.pWeakProxy = 0i64;
      Scaleform::GFx::AS3::Instances::fl_net::URLVariables::decode(v4, &v7, &result);
    }
    v5 = result.pNode;
    v6 = result.pNode->RefCount == 1;
    --v5->RefCount;
    if ( v6 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  }
}

// File Line: 214
// RVA: 0x8003F0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_net::URLVariables::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_net::URLVariables *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_net::URLVariables> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_net::URLVariables::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_net::URLVariables *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 236
// RVA: 0x737B80
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_net::URLVariables::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rdi
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_net::URLVariablesCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_net::URLVariables::`vftable;
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl_net::URLVariablesCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_net::URLVariables::`vftable;
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
                                       72i64);
  if ( v9 )
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
  return v3;
}

