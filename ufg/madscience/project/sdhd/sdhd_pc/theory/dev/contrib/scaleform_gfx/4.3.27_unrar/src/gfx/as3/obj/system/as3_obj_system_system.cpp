// File Line: 37
// RVA: 0x91F440
void __fastcall Scaleform::GFx::AS3::escapeMultiByteInternal(Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::ASString *result, Scaleform::GFx::ASString *value)
{
  const char ***v3; // rdi
  Scaleform::GFx::ASString *v4; // r15
  Scaleform::GFx::AS3::VM *v5; // r14
  char v6; // bl
  Scaleform::GFx::AS3::Traits *v7; // rax
  const char **v8; // rax
  char *v9; // rsi
  signed int v10; // eax
  __int16 v11; // bx
  int v12; // edx
  int v13; // eax
  unsigned int v14; // ecx
  char v15; // al
  char v16; // al
  char v17; // di
  char v18; // di
  char v19; // al
  char v20; // al
  unsigned __int8 v21; // bl
  char v22; // al
  char v23; // al
  unsigned __int8 v24; // bl
  Scaleform::GFx::ASStringNode *v25; // rbx
  Scaleform::GFx::ASStringNode *v26; // rcx
  bool v27; // zf
  Scaleform::GFx::ASStringNode *v28; // rcx
  Scaleform::GFx::AS3::GASRefCountBase *v29; // rcx
  unsigned int v30; // eax
  Scaleform::StringDataPtr qname; // [rsp+28h] [rbp-51h]
  Scaleform::StringBuffer src; // [rsp+38h] [rbp-41h]
  Scaleform::GFx::AS3::Multiname mn; // [rsp+68h] [rbp-11h]
  Scaleform::String pescapedStr; // [rsp+E0h] [rbp+67h]
  char *putf8Buffer; // [rsp+E8h] [rbp+6Fh]
  Scaleform::GFx::ASString resulta; // [rsp+F8h] [rbp+7Fh]

  v3 = (const char ***)value;
  v4 = result;
  v5 = vm;
  v6 = 0;
  qname.pStr = "flash.utils.System";
  qname.Size = 18i64;
  Scaleform::GFx::AS3::Multiname::Multiname(&mn, vm, &qname);
  v7 = (Scaleform::GFx::AS3::Traits *)Scaleform::GFx::AS3::VM::Resolve2ClassTraits(v5, &mn, v5->CurrentDomain.pObject);
  if ( v7 && v7[1].vfptr )
    v6 = (char)Scaleform::GFx::AS3::Traits::GetConstructor(v7)[1].vfptr;
  Scaleform::String::String(&pescapedStr);
  if ( v6 )
  {
    Scaleform::GFx::ASUtils::EscapeWithMask(**v3, *((unsigned int *)*v3 + 8), &pescapedStr, mask);
  }
  else
  {
    Scaleform::StringBuffer::StringBuffer(&src, Scaleform::Memory::pGlobalHeap);
    v8 = *v3;
    putf8Buffer = (char *)**v3;
    v9 = &putf8Buffer[*((unsigned int *)v8 + 8)];
    while ( putf8Buffer < v9 )
    {
      v10 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
      v11 = v10;
      if ( v10 >= 128
        || (v12 = (v10 >> 31) & 0x1F,
            v13 = v12 + v10,
            v14 = unescaped_mask[v13 >> 5],
            !_bittest((const signed int *)&v14, (v13 & 0x1F) - v12)) )
      {
        Scaleform::StringBuffer::AppendChar(&src, 0x25u);
        if ( v11 & 0xFF00 )
        {
          Scaleform::StringBuffer::AppendChar(&src, 0x75u);
          v15 = HIBYTE(v11) >> 4;
          if ( (unsigned __int8)(HIBYTE(v11) >> 4) >= 0xAu )
            v16 = v15 + 55;
          else
            v16 = v15 + 48;
          Scaleform::StringBuffer::AppendChar(&src, v16);
          v17 = HIBYTE(v11) & 0xF;
          if ( (HIBYTE(v11) & 0xFu) >= 0xA )
            v18 = v17 + 55;
          else
            v18 = v17 + 48;
          Scaleform::StringBuffer::AppendChar(&src, v18);
          v19 = (unsigned __int8)v11 >> 4;
          if ( (unsigned __int8)((unsigned __int8)v11 >> 4) >= 0xAu )
            v20 = v19 + 55;
          else
            v20 = v19 + 48;
          Scaleform::StringBuffer::AppendChar(&src, v20);
          v21 = v11 & 0xF;
          if ( v21 >= 0xAu )
            LOBYTE(v11) = v21 + 55;
          else
            LOBYTE(v11) = v21 + 48;
        }
        else
        {
          v22 = (unsigned __int8)v11 >> 4;
          if ( (unsigned __int8)((unsigned __int8)v11 >> 4) >= 0xAu )
            v23 = v22 + 55;
          else
            v23 = v22 + 48;
          Scaleform::StringBuffer::AppendChar(&src, v23);
          v24 = v11 & 0xF;
          if ( v24 >= 0xAu )
            LOBYTE(v11) = v24 + 55;
          else
            LOBYTE(v11) = v24 + 48;
        }
      }
      Scaleform::StringBuffer::AppendChar(&src, (char)v11);
    }
    Scaleform::String::operator=(&pescapedStr, &src);
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&src);
  }
  v25 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v5->StringManagerRef->Builtins,
          &resulta,
          (const char *)((pescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
          *(_QWORD *)(pescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64)->pNode;
  ++v25->RefCount;
  v26 = v4->pNode;
  v27 = v4->pNode->RefCount == 1;
  --v26->RefCount;
  if ( v27 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v26);
  v4->pNode = v25;
  v28 = resulta.pNode;
  v27 = resulta.pNode->RefCount == 1;
  --v28->RefCount;
  if ( v27 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v28);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((pescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&mn.Name);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&mn.Name);
  }
  v29 = mn.Obj.pObject;
  if ( mn.Obj.pObject )
  {
    if ( (_QWORD)mn.Obj.pObject & 1 )
    {
      --mn.Obj.pObject;
    }
    else
    {
      v30 = mn.Obj.pObject->RefCount;
      if ( v30 & 0x3FFFFF )
      {
        mn.Obj.pObject->RefCount = v30 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v29->vfptr);
      }
    }
  }
}

// File Line: 65
// RVA: 0x927770
void __fastcall Scaleform::GFx::AS3::unescapeMultiByteInternal(Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::ASString *result, Scaleform::GFx::ASString *value)
{
  const char ***v3; // rsi
  Scaleform::GFx::ASString *v4; // r14
  Scaleform::GFx::AS3::VM *v5; // rdi
  char v6; // bl
  Scaleform::GFx::AS3::Traits *v7; // rax
  char v8; // bl
  Scaleform::GFx::ASStringNode *v9; // rbx
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::AS3::GASRefCountBase *v13; // rcx
  unsigned int v14; // eax
  Scaleform::StringDataPtr qname; // [rsp+28h] [rbp-90h]
  Scaleform::GFx::AS3::Multiname mn; // [rsp+38h] [rbp-80h]
  Scaleform::StringBuffer b; // [rsp+68h] [rbp-50h]
  Scaleform::String punescapedStr; // [rsp+C0h] [rbp+8h]
  Scaleform::GFx::ASString resulta; // [rsp+D8h] [rbp+20h]

  v3 = (const char ***)value;
  v4 = result;
  v5 = vm;
  v6 = 0;
  qname.pStr = "flash.utils.System";
  qname.Size = 18i64;
  Scaleform::GFx::AS3::Multiname::Multiname(&mn, vm, &qname);
  v7 = (Scaleform::GFx::AS3::Traits *)Scaleform::GFx::AS3::VM::Resolve2ClassTraits(v5, &mn, v5->CurrentDomain.pObject);
  if ( v7 && v7[1].vfptr )
    v6 = (char)Scaleform::GFx::AS3::Traits::GetConstructor(v7)[1].vfptr;
  Scaleform::String::String(&punescapedStr);
  if ( v6 )
  {
    Scaleform::GFx::ASUtils::Unescape(**v3, *((unsigned int *)*v3 + 8), &punescapedStr);
  }
  else
  {
    Scaleform::StringBuffer::StringBuffer(&b, Scaleform::Memory::pGlobalHeap);
    v8 = Scaleform::GFx::ASUtils::AS3::Formatter::Unescape(**v3, *((unsigned int *)*v3 + 8), &b, 0);
    Scaleform::String::operator=(&punescapedStr, &b);
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&b);
    if ( !v8 )
      goto LABEL_11;
  }
  v9 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
         (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v5->StringManagerRef->Builtins,
         &resulta,
         (const char *)((punescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
         *(_QWORD *)(punescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64)->pNode;
  ++v9->RefCount;
  v10 = v4->pNode;
  v11 = v4->pNode->RefCount == 1;
  --v10->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  v4->pNode = v9;
  v12 = resulta.pNode;
  v11 = resulta.pNode->RefCount == 1;
  --v12->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
LABEL_11:
  if ( !_InterlockedDecrement((volatile signed __int32 *)((punescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&mn.Name);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&mn.Name);
  }
  v13 = mn.Obj.pObject;
  if ( mn.Obj.pObject )
  {
    if ( (_QWORD)mn.Obj.pObject & 1 )
    {
      --mn.Obj.pObject;
    }
    else
    {
      v14 = mn.Obj.pObject->RefCount;
      if ( v14 & 0x3FFFFF )
      {
        mn.Obj.pObject->RefCount = v14 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v13->vfptr);
      }
    }
  }
}

// File Line: 107
// RVA: 0x920F10
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::System::imeGet(Scaleform::GFx::AS3::Classes::fl_system::System *this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::FlashUI *v2; // rcx

  v2 = this->pTraits.pObject->pVM->UI;
  v2->vfptr->Output(v2, Output_Warning, "The method class_::System::imeGet() is not implemented\n");
}

// File Line: 114
// RVA: 0x9273A0
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::System::totalMemoryGet(Scaleform::GFx::AS3::Classes::fl_system::System *this, unsigned int *result)
{
  *result = ((__int64 (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->GetTotalFootprint)();
}

// File Line: 120
// RVA: 0x91F720
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::System::exit(Scaleform::GFx::AS3::Classes::fl_system::System *this, Scaleform::GFx::AS3::Value *result, unsigned int code)
{
  Scaleform::GFx::AS3::VMVtbl *v3; // rax

  v3 = this->pTraits.pObject->pVM[1].vfptr;
  *((_DWORD *)v3[2].__vecDelDtor + 5300) |= 0x200000u;
}

// File Line: 127
// RVA: 0x91FE60
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::System::gc(Scaleform::GFx::AS3::Classes::fl_system::System *this, Scaleform::GFx::AS3::Value *result)
{
  this->pTraits.pObject->pVM->GC.GC->CollectionScheduledFlags = 40;
}

// File Line: 134
// RVA: 0x921B40
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::System::pause(Scaleform::GFx::AS3::Classes::fl_system::System *this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::FlashUI *v2; // rcx

  v2 = this->pTraits.pObject->pVM->UI;
  v2->vfptr->Output(v2, Output_Warning, "The method class_::System::pause() is not implemented\n");
}

// File Line: 141
// RVA: 0x923410
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::System::resume(Scaleform::GFx::AS3::Classes::fl_system::System *this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::FlashUI *v2; // rcx

  v2 = this->pTraits.pObject->pVM->UI;
  v2->vfptr->Output(v2, Output_Warning, "The method class_::System::resume() is not implemented\n");
}

// File Line: 148
// RVA: 0x923760
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::System::setClipboard(Scaleform::GFx::AS3::Classes::fl_system::System *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::ASString *string)
{
  Scaleform::GFx::AS3::FlashUI *v3; // rcx

  v3 = this->pTraits.pObject->pVM->UI;
  v3->vfptr->Output(v3, Output_Warning, "The method class_::System::setClipboard() is not implemented\n");
}

// File Line: 167
// RVA: 0x1598560
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::System_0_Scaleform::GFx::AS3::Value_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F8D8 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::System,0,Scaleform::GFx::AS3::Value>::Method = Scaleform::GFx::AS3::Classes::fl_system::System::imeGet;
  return result;
}

// File Line: 168
// RVA: 0x15984A0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::System_1_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F8E8 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::System,1,unsigned long>::Method = Scaleform::GFx::AS3::Classes::fl_system::System::totalMemoryGet;
  return result;
}

// File Line: 169
// RVA: 0x159A060
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_system::System_2_Scaleform::GFx::AS3::Value_const__unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F8F8 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_system::System,2,Scaleform::GFx::AS3::Value const,unsigned long>::Method = Scaleform::GFx::AS3::Classes::fl_system::System::exit;
  return result;
}

// File Line: 170
// RVA: 0x15984D0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::System_3_Scaleform::GFx::AS3::Value_const__::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F908 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::System,3,Scaleform::GFx::AS3::Value const>::Method = Scaleform::GFx::AS3::Classes::fl_system::System::gc;
  return result;
}

// File Line: 171
// RVA: 0x1598500
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::System_4_Scaleform::GFx::AS3::Value_const__::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F918 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::System,4,Scaleform::GFx::AS3::Value const>::Method = Scaleform::GFx::AS3::Classes::fl_system::System::pause;
  return result;
}

// File Line: 172
// RVA: 0x1598530
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::System_5_Scaleform::GFx::AS3::Value_const__::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F928 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::System,5,Scaleform::GFx::AS3::Value const>::Method = Scaleform::GFx::AS3::Classes::fl_system::System::resume;
  return result;
}

// File Line: 173
// RVA: 0x159A090
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_system::System_6_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::ASString_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F938 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_system::System,6,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method = Scaleform::GFx::AS3::Classes::fl_system::System::setClipboard;
  return result;
}

// File Line: 212
// RVA: 0x8761C0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_system::System::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // r14
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rbx
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v6; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v7; // rbp
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v8; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rax
  Scaleform::GFx::AS3::Class *v11; // rdi

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  v7.pV = 0i64;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(v5, v2, &Scaleform::GFx::AS3::fl_system::SystemCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_system::System::`vftable';
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v6->vfptr;
  v8 = (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  if ( v8 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(v8, v2, &Scaleform::GFx::AS3::fl_system::SystemCI);
    v7.pV = v9;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(v3->pV, v7);
  v10 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                        v4,
                                        80i64);
  v11 = v10;
  if ( v10 )
  {
    Scaleform::GFx::AS3::Class::Class(v10, v3->pV);
    v11->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_system::System::`vftable';
    LOBYTE(v11[1].vfptr) = 0;
  }
  return v3;
}

