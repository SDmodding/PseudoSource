// File Line: 37
// RVA: 0x91F440
void __fastcall Scaleform::GFx::AS3::escapeMultiByteInternal(
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::ASString *value)
{
  char vfptr; // bl
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v7; // rax
  Scaleform::GFx::ASStringNode *pNode; // rax
  char *v9; // rsi
  int Char_Advance0; // eax
  __int16 v11; // bx
  unsigned int v12; // ecx
  char v13; // al
  char v14; // al
  char v15; // di
  char v16; // di
  char v17; // al
  char v18; // al
  unsigned __int8 v19; // bl
  char v20; // al
  char v21; // al
  unsigned __int8 v22; // bl
  Scaleform::GFx::ASString *v23; // rax
  Scaleform::GFx::ASStringNode *v24; // rbx
  Scaleform::GFx::ASStringNode *v25; // rcx
  bool v26; // zf
  Scaleform::GFx::ASStringNode *v27; // rcx
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::StringDataPtr qname; // [rsp+28h] [rbp-51h] BYREF
  Scaleform::StringBuffer src; // [rsp+38h] [rbp-41h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [rsp+68h] [rbp-11h] BYREF
  Scaleform::String pescapedStr; // [rsp+E0h] [rbp+67h] BYREF
  char *putf8Buffer; // [rsp+E8h] [rbp+6Fh] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+F8h] [rbp+7Fh] BYREF

  vfptr = 0;
  qname.pStr = "flash.utils.System";
  qname.Size = 18i64;
  Scaleform::GFx::AS3::Multiname::Multiname(&mn, vm, &qname);
  v7 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(vm, &mn, vm->CurrentDomain.pObject);
  if ( v7 && v7->ITraits.pObject )
    vfptr = (char)Scaleform::GFx::AS3::Traits::GetConstructor(v7)[1].vfptr;
  Scaleform::String::String(&pescapedStr);
  if ( vfptr )
  {
    Scaleform::GFx::ASUtils::EscapeWithMask(value->pNode->pData, value->pNode->Size, &pescapedStr, mask);
  }
  else
  {
    Scaleform::StringBuffer::StringBuffer(&src, Scaleform::Memory::pGlobalHeap);
    pNode = value->pNode;
    putf8Buffer = (char *)value->pNode->pData;
    v9 = &putf8Buffer[pNode->Size];
    while ( putf8Buffer < v9 )
    {
      Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
      v11 = Char_Advance0;
      if ( Char_Advance0 >= 128
        || (v12 = unescaped_mask[Char_Advance0 / 32], !_bittest((const int *)&v12, Char_Advance0 % 32)) )
      {
        Scaleform::StringBuffer::AppendChar(&src, 0x25u);
        if ( (v11 & 0xFF00) != 0 )
        {
          Scaleform::StringBuffer::AppendChar(&src, 0x75u);
          v13 = HIBYTE(v11) >> 4;
          if ( (unsigned __int8)(HIBYTE(v11) >> 4) >= 0xAu )
            v14 = v13 + 55;
          else
            v14 = v13 + 48;
          Scaleform::StringBuffer::AppendChar(&src, v14);
          v15 = HIBYTE(v11) & 0xF;
          if ( (HIBYTE(v11) & 0xFu) >= 0xA )
            v16 = v15 + 55;
          else
            v16 = v15 + 48;
          Scaleform::StringBuffer::AppendChar(&src, v16);
          v17 = (unsigned __int8)v11 >> 4;
          if ( (unsigned __int8)((unsigned __int8)v11 >> 4) >= 0xAu )
            v18 = v17 + 55;
          else
            v18 = v17 + 48;
          Scaleform::StringBuffer::AppendChar(&src, v18);
          v19 = v11 & 0xF;
          if ( v19 >= 0xAu )
            LOBYTE(v11) = v19 + 55;
          else
            LOBYTE(v11) = v19 + 48;
        }
        else
        {
          v20 = (unsigned __int8)v11 >> 4;
          if ( (unsigned __int8)((unsigned __int8)v11 >> 4) >= 0xAu )
            v21 = v20 + 55;
          else
            v21 = v20 + 48;
          Scaleform::StringBuffer::AppendChar(&src, v21);
          v22 = v11 & 0xF;
          if ( v22 >= 0xAu )
            LOBYTE(v11) = v22 + 55;
          else
            LOBYTE(v11) = v22 + 48;
        }
      }
      Scaleform::StringBuffer::AppendChar(&src, (char)v11);
    }
    Scaleform::String::operator=(&pescapedStr, &src);
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&src);
  }
  v23 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
          vm->StringManagerRef,
          &resulta,
          (const char *)((pescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
          *(_QWORD *)(pescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
  v24 = v23->pNode;
  ++v23->pNode->RefCount;
  v25 = result->pNode;
  v26 = result->pNode->RefCount-- == 1;
  if ( v26 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v25);
  result->pNode = v24;
  v27 = resulta.pNode;
  v26 = resulta.pNode->RefCount-- == 1;
  if ( v26 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v27);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((pescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&mn.Name);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&mn.Name);
  }
  pObject = mn.Obj.pObject;
  if ( mn.Obj.pObject )
  {
    if ( ((__int64)mn.Obj.pObject & 1) != 0 )
    {
      --mn.Obj.pObject;
    }
    else
    {
      RefCount = mn.Obj.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        mn.Obj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
}

// File Line: 65
// RVA: 0x927770
void __fastcall Scaleform::GFx::AS3::unescapeMultiByteInternal(
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::ASString *value)
{
  char vfptr; // bl
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v7; // rax
  char v8; // bl
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::StringDataPtr qname; // [rsp+28h] [rbp-90h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [rsp+38h] [rbp-80h] BYREF
  Scaleform::StringBuffer b; // [rsp+68h] [rbp-50h] BYREF
  Scaleform::String punescapedStr; // [rsp+C0h] [rbp+8h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+D8h] [rbp+20h] BYREF

  vfptr = 0;
  qname.pStr = "flash.utils.System";
  qname.Size = 18i64;
  Scaleform::GFx::AS3::Multiname::Multiname(&mn, vm, &qname);
  v7 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(vm, &mn, vm->CurrentDomain.pObject);
  if ( v7 && v7->ITraits.pObject )
    vfptr = (char)Scaleform::GFx::AS3::Traits::GetConstructor(v7)[1].vfptr;
  Scaleform::String::String(&punescapedStr);
  if ( vfptr )
  {
    Scaleform::GFx::ASUtils::Unescape(value->pNode->pData, value->pNode->Size, &punescapedStr);
  }
  else
  {
    Scaleform::StringBuffer::StringBuffer(&b, Scaleform::Memory::pGlobalHeap);
    v8 = Scaleform::GFx::ASUtils::AS3::Formatter::Unescape((char *)value->pNode->pData, value->pNode->Size, &b, 0);
    Scaleform::String::operator=(&punescapedStr, &b);
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&b);
    if ( !v8 )
      goto LABEL_11;
  }
  v9 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
         vm->StringManagerRef,
         &resulta,
         (const char *)((punescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
         *(_QWORD *)(punescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
  pNode = v9->pNode;
  ++v9->pNode->RefCount;
  v11 = result->pNode;
  v12 = result->pNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  result->pNode = pNode;
  v13 = resulta.pNode;
  v12 = resulta.pNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
LABEL_11:
  if ( !_InterlockedDecrement((volatile signed __int32 *)((punescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&mn.Name);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&mn.Name);
  }
  pObject = mn.Obj.pObject;
  if ( mn.Obj.pObject )
  {
    if ( ((__int64)mn.Obj.pObject & 1) != 0 )
    {
      --mn.Obj.pObject;
    }
    else
    {
      RefCount = mn.Obj.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        mn.Obj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
}

// File Line: 107
// RVA: 0x920F10
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::System::imeGet(
        Scaleform::GFx::AS3::Classes::fl_system::System *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method class_::System::imeGet() is not implemented\n");
}

// File Line: 114
// RVA: 0x9273A0
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::System::totalMemoryGet(
        Scaleform::GFx::AS3::Classes::fl_system::System *this,
        unsigned int *result)
{
  *result = Scaleform::Memory::pGlobalHeap->vfptr->GetTotalFootprint(Scaleform::Memory::pGlobalHeap);
}

// File Line: 120
// RVA: 0x91F720
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::System::exit(
        Scaleform::GFx::AS3::Classes::fl_system::System *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int code)
{
  Scaleform::GFx::AS3::VMVtbl *vfptr; // rax

  vfptr = this->pTraits.pObject->pVM[1].vfptr;
  *((_DWORD *)vfptr[2].__vecDelDtor + 5300) |= 0x200000u;
}

// File Line: 127
// RVA: 0x91FE60
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::System::gc(
        Scaleform::GFx::AS3::Classes::fl_system::System *this,
        Scaleform::GFx::AS3::Value *result)
{
  this->pTraits.pObject->pVM->GC.GC->CollectionScheduledFlags = 40;
}

// File Line: 134
// RVA: 0x921B40
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::System::pause(
        Scaleform::GFx::AS3::Classes::fl_system::System *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method class_::System::pause() is not implemented\n");
}

// File Line: 141
// RVA: 0x923410
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::System::resume(
        Scaleform::GFx::AS3::Classes::fl_system::System *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method class_::System::resume() is not implemented\n");
}

// File Line: 148
// RVA: 0x923760
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::System::setClipboard(
        Scaleform::GFx::AS3::Classes::fl_system::System *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASString *string)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method class_::System::setClipboard() is not implemented\n");
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
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_system::System::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v7; // rbp
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v8; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rax
  Scaleform::GFx::AS3::Class *v11; // rdi

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  v7.pV = 0i64;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(v5, vm, &Scaleform::GFx::AS3::fl_system::SystemCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_system::System::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v8 = (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  if ( v8 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(v8, vm, &Scaleform::GFx::AS3::fl_system::SystemCI);
    v7.pV = v9;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(result->pV, v7);
  v10 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))MHeap->vfptr->Alloc)(
                                        MHeap,
                                        80i64);
  v11 = v10;
  if ( v10 )
  {
    Scaleform::GFx::AS3::Class::Class(v10, result->pV);
    v11->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_system::System::`vftable;
    LOBYTE(v11[1].vfptr) = 0;
  }
  return result;
}

