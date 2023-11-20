// File Line: 37
// RVA: 0x15980B0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_text::Font_0_Scaleform::GFx::AS3::Value_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F948 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::Font,0,Scaleform::GFx::AS3::Value>::Method = Scaleform::GFx::AS3::Instances::fl_text::Font::fontNameGet;
  return result;
}

// File Line: 38
// RVA: 0x1598050
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_text::Font_1_Scaleform::GFx::AS3::Value_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F958 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::Font,1,Scaleform::GFx::AS3::Value>::Method = Scaleform::GFx::AS3::Instances::fl_text::Font::fontStyleGet;
  return result;
}

// File Line: 39
// RVA: 0x1598080
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_text::Font_2_Scaleform::GFx::AS3::Value_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F968 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::Font,2,Scaleform::GFx::AS3::Value>::Method = Scaleform::GFx::AS3::Instances::fl_text::Font::fontTypeGet;
  return result;
}

// File Line: 40
// RVA: 0x1599D00
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_text::Font_3_bool_Scaleform::GFx::ASString_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F978 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::Font,3,bool,Scaleform::GFx::ASString const &>::Method = Scaleform::GFx::AS3::Instances::fl_text::Font::hasGlyphs;
  return result;
}

// File Line: 51
// RVA: 0x8962A0
void __fastcall Scaleform::GFx::AS3::Instances::fl_text::Font::Font(Scaleform::GFx::AS3::Instances::fl_text::Font *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v2; // rbx
  Scaleform::GFx::AS3::Instances::fl_text::Font *v3; // rdi

  v2 = t;
  v3 = this;
  Scaleform::GFx::AS3::Instances::fl::Object::Object((Scaleform::GFx::AS3::Instances::fl::Object *)&this->vfptr, t);
  v3->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_text::Font::`vftable;
  v3->pFont.pObject = 0i64;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v2->pVM->StringManagerRef->Builtins,
    &v3->fontName);
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v2->pVM->StringManagerRef->Builtins,
    &v3->fontStyle);
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v2->pVM->StringManagerRef->Builtins,
    &v3->fontType);
}

// File Line: 57
// RVA: 0x91FAD0
void __fastcall Scaleform::GFx::AS3::Instances::fl_text::Font::fontNameGet(Scaleform::GFx::AS3::Instances::fl_text::Font *this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v2; // rdi
  Scaleform::Render::Font *v3; // rdx
  Scaleform::GFx::AS3::StringManager *v4; // rbx
  const char *v5; // rax
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::ASString *v9; // rsi
  Scaleform::GFx::ASStringNode *v10; // rcx
  unsigned int v11; // ebx
  unsigned int v12; // eax
  Scaleform::GFx::AS3::Value::V2U v13; // [rsp+30h] [rbp-18h]
  Scaleform::GFx::ASString resulta; // [rsp+50h] [rbp+8h]

  v2 = result;
  v3 = this->pFont.pObject;
  if ( v3 )
  {
    v4 = this->pTraits.pObject->pVM->StringManagerRef;
    v5 = (const char *)((__int64 (__fastcall *)(Scaleform::Render::Font *))v3->vfptr[1].__vecDelDtor)(this->pFont.pObject);
    v6 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
           (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->Builtins,
           &resulta,
           v5);
    Scaleform::GFx::AS3::Value::Assign(v2, v6);
    v7 = resulta.pNode;
    v8 = resulta.pNode->RefCount == 1;
    --v7->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
  else
  {
    v9 = &this->fontName;
    v10 = this->fontName.pNode;
    v11 = v10->Size;
    if ( !(v10->HashFlags & 0x8000000) )
    {
      v12 = Scaleform::UTF8Util::GetLength(v10->pData, v11);
      if ( v12 == v11 )
        v9->pNode->HashFlags |= 0x8000000u;
      v11 = v12;
    }
    if ( v11 )
    {
      Scaleform::GFx::AS3::Value::Assign(v2, v9);
    }
    else
    {
      if ( (v2->Flags & 0x1F) > 9 )
      {
        if ( (v2->Flags >> 9) & 1 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(v2);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(v2);
      }
      v2->Flags &= 0xFFFFFFEC;
      v2->Flags |= 0xCu;
      v2->value.VNumber = 0.0;
      v2->value.VS._2 = v13;
    }
  }
}

// File Line: 71
// RVA: 0x91FBE0
void __fastcall Scaleform::GFx::AS3::Instances::fl_text::Font::fontStyleGet(Scaleform::GFx::AS3::Instances::fl_text::Font *this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v2; // rbx
  Scaleform::Render::Font *v3; // rax
  int v4; // eax
  Scaleform::GFx::ASString *v5; // rax
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::AS3::StringManager *v7; // rcx
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASString *v11; // rsi
  Scaleform::GFx::ASStringNode *v12; // rcx
  unsigned int v13; // edi
  unsigned int v14; // eax
  Scaleform::GFx::AS3::Value::V2U v15; // [rsp+30h] [rbp-18h]
  Scaleform::GFx::ASString resulta; // [rsp+50h] [rbp+8h]

  v2 = result;
  v3 = this->pFont.pObject;
  if ( v3 )
  {
    v4 = v3->Flags & 3;
    if ( v4 & 3 )
    {
      v5 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
             (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->pTraits.pObject->pVM->StringManagerRef->Builtins,
             &resulta,
             "boldItalic");
      Scaleform::GFx::AS3::Value::Assign(v2, v5);
    }
    else if ( v4 & 2 )
    {
      v6 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
             (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->pTraits.pObject->pVM->StringManagerRef->Builtins,
             &resulta,
             "bold");
      Scaleform::GFx::AS3::Value::Assign(v2, v6);
    }
    else
    {
      v7 = this->pTraits.pObject->pVM->StringManagerRef;
      if ( v4 & 1 )
        v8 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
               (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->Builtins,
               &resulta,
               "italic");
      else
        v8 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
               (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->Builtins,
               &resulta,
               "regular");
      Scaleform::GFx::AS3::Value::Assign(v2, v8);
    }
    v9 = resulta.pNode;
    v10 = resulta.pNode->RefCount == 1;
    --v9->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  }
  else
  {
    v11 = &this->fontStyle;
    v12 = this->fontStyle.pNode;
    v13 = v12->Size;
    if ( !(v12->HashFlags & 0x8000000) )
    {
      v14 = Scaleform::UTF8Util::GetLength(v12->pData, v13);
      if ( v14 == v13 )
        v11->pNode->HashFlags |= 0x8000000u;
      v13 = v14;
    }
    if ( v13 )
    {
      Scaleform::GFx::AS3::Value::Assign(v2, v11);
    }
    else
    {
      if ( (v2->Flags & 0x1F) > 9 )
      {
        if ( (v2->Flags >> 9) & 1 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(v2);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(v2);
      }
      v2->Flags &= 0xFFFFFFEC;
      v2->Flags |= 0xCu;
      v2->value.VNumber = 0.0;
      v2->value.VS._2 = v15;
    }
  }
}

// File Line: 93
// RVA: 0x91FD50
void __fastcall Scaleform::GFx::AS3::Instances::fl_text::Font::fontTypeGet(Scaleform::GFx::AS3::Instances::fl_text::Font *this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v2; // rbx
  Scaleform::Render::Font *v3; // rax
  Scaleform::GFx::AS3::StringManager *v4; // rcx
  Scaleform::GFx::ASString *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::ASString *v8; // rsi
  Scaleform::GFx::ASStringNode *v9; // rcx
  unsigned int v10; // edi
  unsigned int v11; // eax
  Scaleform::GFx::AS3::Value::V2U v12; // [rsp+30h] [rbp-18h]
  Scaleform::GFx::ASString resulta; // [rsp+50h] [rbp+8h]

  v2 = result;
  v3 = this->pFont.pObject;
  if ( v3 )
  {
    v4 = this->pTraits.pObject->pVM->StringManagerRef;
    if ( (v3->Flags >> 4) & 1 )
      v5 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
             (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->Builtins,
             &resulta,
             "device");
    else
      v5 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
             (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->Builtins,
             &resulta,
             "embedded");
    Scaleform::GFx::AS3::Value::Assign(v2, v5);
    v6 = resulta.pNode;
    v7 = resulta.pNode->RefCount == 1;
    --v6->RefCount;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  }
  else
  {
    v8 = &this->fontType;
    v9 = this->fontType.pNode;
    v10 = v9->Size;
    if ( !(v9->HashFlags & 0x8000000) )
    {
      v11 = Scaleform::UTF8Util::GetLength(v9->pData, v10);
      if ( v11 == v10 )
        v8->pNode->HashFlags |= 0x8000000u;
      v10 = v11;
    }
    if ( v10 )
    {
      Scaleform::GFx::AS3::Value::Assign(v2, v8);
    }
    else
    {
      if ( (v2->Flags & 0x1F) > 9 )
      {
        if ( (v2->Flags >> 9) & 1 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(v2);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(v2);
      }
      v2->Flags &= 0xFFFFFFEC;
      v2->Flags |= 0xCu;
      v2->value.VNumber = 0.0;
      v2->value.VS._2 = v12;
    }
  }
}

// File Line: 110
// RVA: 0x920C10
void __fastcall Scaleform::GFx::AS3::Instances::fl_text::Font::hasGlyphs(Scaleform::GFx::AS3::Instances::fl_text::Font *this, bool *result, Scaleform::GFx::ASString *str)
{
  bool *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl_text::Font *v4; // rsi
  Scaleform::GFx::ASStringNode *v5; // rax
  char *v6; // r8
  __int64 v7; // rbx
  unsigned __int64 v8; // rbx
  unsigned int v9; // eax
  char *putf8Buffer; // [rsp+30h] [rbp+8h]

  v3 = result;
  v4 = this;
  if ( this->pFont.pObject )
  {
    v5 = str->pNode;
    putf8Buffer = (char *)str->pNode->pData;
    v6 = putf8Buffer;
    v7 = v5->Size;
    *result = 1;
    v8 = (unsigned __int64)&v6[v7];
    if ( (unsigned __int64)v6 < v8 )
    {
      while ( 1 )
      {
        v9 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
        if ( !v9 )
          --putf8Buffer;
        if ( (signed int)v4->pFont.pObject->vfptr[2].__vecDelDtor(
                           (Scaleform::RefCountImplCore *)v4->pFont.pObject,
                           (unsigned __int16)v9) < 0 )
          break;
        if ( (unsigned __int64)putf8Buffer >= v8 )
          return;
      }
      *v3 = 0;
    }
  }
  else
  {
    *result = 0;
  }
}

// File Line: 136
// RVA: 0x8E45E0
void __fastcall Scaleform::GFx::AS3::Instances::fl_text::Font::InitInstance(Scaleform::GFx::AS3::Instances::fl_text::Font *this, bool extCall)
{
  JUMPOUT(extCall, 0, Scaleform::GFx::AS3::Instances::fl_text::Font::CreateLibraryObject);
}

// File Line: 146
// RVA: 0x8C0680
bool __fastcall Scaleform::GFx::AS3::Instances::fl_text::Font::CreateLibraryObject(Scaleform::GFx::AS3::Instances::fl_text::Font *this)
{
  Scaleform::GFx::AS3::Instances::fl_text::Font *v1; // rbp
  Scaleform::GFx::AS3::ASVM *v2; // r15
  Scaleform::GFx::MovieDefImpl *v3; // r14
  Scaleform::GFx::AS3::Traits *v4; // rcx
  Scaleform::GFx::MovieImpl *v5; // rdi
  char v6; // al
  Scaleform::GFx::MovieDefImpl *v7; // rsi
  Scaleform::GFx::MovieDefRootNode *v8; // rbx
  signed __int64 v9; // rdi
  signed __int64 v10; // rax
  Scaleform::GFx::MovieDefImpl *v11; // rcx
  bool v12; // di
  Scaleform::GFx::AS3::MovieRoot *v13; // rdi
  Scaleform::GFx::LogState *v14; // rsi
  const char *v15; // rsi
  Scaleform::GFx::LogState *v16; // rdi
  int v17; // eax
  Scaleform::GFx::ResourceVtbl *v18; // rdi
  Scaleform::Render::RenderBuffer *v19; // rcx
  Scaleform::GFx::Resource *v20; // rdi
  Scaleform::GFx::ResourceLibBase *v21; // rcx
  Scaleform::GFx::ASStringNode *v22; // rcx
  bool v23; // zf
  Scaleform::GFx::ResourceBindData pdata; // [rsp+28h] [rbp-50h]
  Scaleform::GFx::ASStringNode *v26; // [rsp+80h] [rbp+8h]
  Scaleform::String symbol; // [rsp+88h] [rbp+10h]
  Scaleform::Ptr<Scaleform::GFx::LogState> result; // [rsp+90h] [rbp+18h]
  Scaleform::Ptr<Scaleform::GFx::LogState> v29; // [rsp+98h] [rbp+20h]

  v1 = this;
  if ( !this->pFont.pObject )
  {
    v2 = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
    v3 = Scaleform::GFx::AS3::ASVM::GetResourceMovieDef(v2, (Scaleform::GFx::AS3::Instances::fl::Object *)&this->vfptr);
    if ( v3 )
    {
      v4 = v1->pTraits.pObject;
      if ( (LOBYTE(v4->Flags) >> 4) & 1 )
      {
        ((void (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::GFx::ASStringNode **, signed __int64))v4->vfptr[1].Finalize_GC)(
          v4,
          &v26,
          1i64);
        pdata.pResource.pObject = 0i64;
        pdata.pBinding = 0i64;
        Scaleform::String::String(&symbol, v26->pData);
        v5 = v2->pMovieRoot->pMovieImpl;
        if ( Scaleform::GFx::MovieDefImpl::GetExportedResource(v3, &pdata, &symbol, 0i64) )
        {
LABEL_5:
          v6 = 1;
        }
        else
        {
          v7 = v3;
          v8 = v5->RootMovieDefNodes.Root.pNext;
          v9 = (signed __int64)&v5->RootMovieDefNodes;
          while ( 1 )
          {
            v10 = v9 - 8;
            if ( !v9 )
              v10 = 0i64;
            if ( v8 == (Scaleform::GFx::MovieDefRootNode *)v10 )
              break;
            v11 = v8->pDefImpl;
            if ( v11 != v3 && Scaleform::GFx::MovieDefImpl::DoesDirectlyImport(v11, v7) )
            {
              if ( Scaleform::GFx::MovieDefImpl::GetExportedResource(v8->pDefImpl, &pdata, &symbol, 0i64) )
                goto LABEL_5;
              v7 = v8->pDefImpl;
            }
            v8 = v8->pNext;
          }
          v6 = 0;
        }
        v12 = v6 == 0;
        if ( !_InterlockedDecrement((volatile signed __int32 *)((symbol.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        if ( v12 )
        {
          v13 = v2->pMovieRoot;
          v14 = Scaleform::GFx::StateBag::GetLogState((Scaleform::GFx::StateBag *)&v13->pMovieImpl->vfptr, &result)->pObject;
          if ( result.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
          if ( v14 )
          {
            v15 = v26->pData;
            v16 = Scaleform::GFx::StateBag::GetLogState((Scaleform::GFx::StateBag *)&v13->pMovieImpl->vfptr, &v29)->pObject;
            if ( v29.pObject )
              Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v29.pObject);
            Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
              (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)&v16->vfptr,
              "Attaching a font with class %s failed",
              v15);
          }
        }
        else if ( pdata.pResource.pObject )
        {
          v17 = ((__int64 (__cdecl *)(Scaleform::GFx::Resource *))pdata.pResource.pObject->vfptr->GetResourceTypeCode)(pdata.pResource.pObject);
          if ( _bittest(&v17, 9u) )
          {
            v18 = pdata.pResource.pObject[1].vfptr;
            if ( v18 )
              Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pdata.pResource.pObject[1].vfptr);
            v19 = (Scaleform::Render::RenderBuffer *)v1->pFont.pObject;
            if ( v19 )
              Scaleform::RefCountImpl::Release(v19);
            v1->pFont.pObject = (Scaleform::Render::Font *)v18;
          }
        }
        v20 = pdata.pResource.pObject;
        if ( pdata.pResource.pObject && !_InterlockedDecrement(&pdata.pResource.pObject->RefCount.Value) )
        {
          v21 = v20->pLib;
          if ( v21 )
          {
            v21->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v21->vfptr, (unsigned int)v20);
            v20->pLib = 0i64;
          }
          v20->vfptr->__vecDelDtor(v20, 1u);
        }
        v22 = v26;
        v23 = v26->RefCount == 1;
        --v22->RefCount;
        if ( v23 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v22);
      }
    }
  }
  return 0;
}

// File Line: 210
// RVA: 0x8EADF0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_text::Font::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_text::Font *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::Font> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_text::Font::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_text::Font *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 228
// RVA: 0x91EC10
void __fastcall Scaleform::GFx::AS3::Classes::fl_text::Font::enumerateFonts(Scaleform::GFx::AS3::Classes::fl_text::Font *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result, bool enumerateDeviceFonts)
{
  Scaleform::GFx::StateBag *v3; // r15
  __int64 v4; // rcx
  Scaleform::GFx::StateBagVtbl *v5; // r14
  __int64 v6; // rsi
  Scaleform::Render::Font *v7; // rdi
  signed __int64 v8; // rcx
  unsigned __int64 v9; // rbx
  unsigned __int64 v10; // r9
  signed __int64 v11; // rdx
  unsigned __int64 *v12; // r8
  char *v13; // rbx
  Scaleform::Render::RenderBuffer *v14; // rcx
  Scaleform::GFx::StateBag *v15; // r12
  Scaleform::GFx::FontLib *v16; // r15
  Scaleform::GFx::FontLibImpl *v17; // rax
  unsigned int v18; // er14
  __int64 v19; // rcx
  Scaleform::GFx::MovieDataDef *v20; // rbx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v21; // rcx
  Scaleform::Ptr<Scaleform::Render::Font> *i; // rsi
  signed __int64 v23; // rcx
  unsigned __int64 v24; // r9
  unsigned __int64 v25; // r10
  signed __int64 v26; // rcx
  unsigned __int64 *v27; // r8
  char *v28; // rdi
  Scaleform::GFx::Resource *v29; // rcx
  Scaleform::Render::RenderBuffer *v30; // rcx
  Scaleform::GFx::AS3::ASVM *v31; // r13
  Scaleform::GFx::AS3::Class *v32; // r15
  unsigned __int64 v33; // rax
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Font>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> > > >::TableType *v34; // rdx
  __int64 v35; // rbx
  __int64 v36; // rdi
  signed __int64 v37; // r14
  Scaleform::GFx::AS3::Object *v38; // rsi
  Scaleform::GFx::Resource *v39; // rcx
  Scaleform::Render::RenderBuffer *v40; // rcx
  Scaleform::GFx::AS3::Object *v41; // rcx
  unsigned int v42; // eax
  unsigned __int64 v43; // rdx
  _QWORD *v44; // rcx
  Scaleform::GFx::FontProvider *v45; // rbx
  unsigned __int64 v46; // rcx
  _QWORD *v47; // rdx
  __int64 v48; // rbx
  __int64 v49; // rdi
  Scaleform::GFx::AS3::ASVM *v50; // r12
  Scaleform::GFx::AS3::Object *v51; // rsi
  unsigned __int64 v52; // rdx
  Scaleform::GFx::ASStringNode *v53; // r14
  Scaleform::GFx::ASStringNode *v54; // rcx
  bool v55; // zf
  Scaleform::GFx::AS3::Object *v56; // rcx
  unsigned int v57; // eax
  unsigned __int64 v58; // rdx
  _QWORD *v59; // rcx
  __int64 v60; // rdx
  __int64 v61; // rsi
  signed __int64 v62; // r14
  _QWORD *v63; // rbx
  Scaleform::GFx::AS3::Instances::fl::Array *v64; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *v65; // rdi
  Scaleform::GFx::AS3::Instances::fl::Array *v66; // rcx
  unsigned int v67; // eax
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Font>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> > > >::TableType *v68; // rdx
  __int64 v69; // rdi
  unsigned __int64 v70; // rsi
  char *v71; // rbx
  Scaleform::Render::RenderBuffer *v72; // rcx
  __m128i v73; // [rsp+30h] [rbp-D0h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> v74; // [rsp+40h] [rbp-C0h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> pobj; // [rsp+48h] [rbp-B8h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> v76; // [rsp+50h] [rbp-B0h]
  Scaleform::GFx::AS3::VM *v77; // [rsp+58h] [rbp-A8h]
  void **v78; // [rsp+60h] [rbp-A0h]
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Font>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> > > > *v79; // [rsp+68h] [rbp-98h]
  __m128i v80; // [rsp+70h] [rbp-90h]
  Scaleform::Ptr<Scaleform::GFx::FontProvider> v81; // [rsp+80h] [rbp-80h]
  Scaleform::Render::Font *v82; // [rsp+88h] [rbp-78h]
  Scaleform::Render::Font *key; // [rsp+90h] [rbp-70h]
  Scaleform::Ptr<Scaleform::GFx::FontLib> resulta; // [rsp+98h] [rbp-68h]
  Scaleform::GFx::AS3::Value v85; // [rsp+A0h] [rbp-60h]
  Scaleform::GFx::AS3::Value v; // [rsp+C0h] [rbp-40h]
  Scaleform::StringDataPtr gname; // [rsp+E0h] [rbp-20h]
  __int64 v88; // [rsp+F0h] [rbp-10h]
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Font>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> > > > pmemAddr; // [rsp+150h] [rbp+50h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *v90; // [rsp+158h] [rbp+58h]
  bool v91; // [rsp+160h] [rbp+60h]
  __int64 v92; // [rsp+168h] [rbp+68h]

  v91 = enumerateDeviceFonts;
  v90 = result;
  v88 = -2i64;
  v77 = this->pTraits.pObject->pVM;
  v3 = (Scaleform::GFx::StateBag *)v77[1].vfptr[2].__vecDelDtor;
  v4 = ((__int64 (__fastcall *)(void *(__fastcall *)(Scaleform::GFx::AS3::VM *, unsigned int)))v3->vfptr->~StateBag)(v77[1].vfptr[2].__vecDelDtor);
  pmemAddr.pTable = 0i64;
  v78 = (void **)`Scaleform::GFx::AS3::Classes::fl_text::Font::enumerateFonts::`2::FontsVisitor::`vftable;
  v79 = &pmemAddr;
  (*(void (__fastcall **)(__int64, void ***, signed __int64))(*(_QWORD *)v4 + 208i64))(v4, &v78, 1i64);
  v5 = v3[2654].vfptr;
  if ( v5 )
  {
    v6 = 0i64;
    do
    {
      v7 = (Scaleform::Render::Font *)(*(_QWORD **)((char *)&v3[2653].vfptr->~StateBag + v6))[3];
      key = v7;
      if ( v7 )
        Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v7);
      v82 = v7;
      v8 = 8i64;
      v9 = 5381i64;
      do
        v9 = *((unsigned __int8 *)&v82 + --v8) + 65599 * v9;
      while ( v8 );
      if ( v7 )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v7);
      if ( !pmemAddr.pTable )
        goto LABEL_22;
      v10 = v9 & pmemAddr.pTable->SizeMask;
      v11 = v10;
      v12 = &pmemAddr.pTable->EntryCount + v10 + 2 * (v10 + 1);
      if ( *v12 == -2i64 || v12[1] != v10 )
        goto LABEL_22;
      while ( v12[1] != v10 || (Scaleform::Render::Font *)v12[2] != v7 )
      {
        v11 = *v12;
        if ( *v12 == -1i64 )
          goto LABEL_22;
        v12 = &pmemAddr.pTable->EntryCount + v11 + 2 * (v11 + 1);
      }
      if ( v11 >= 0 )
      {
        v13 = (char *)pmemAddr.pTable + 24 * v11;
        if ( v7 )
          Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v7);
        v14 = (Scaleform::Render::RenderBuffer *)*((_QWORD *)v13 + 4);
        if ( v14 )
          Scaleform::RefCountImpl::Release(v14);
        *((_QWORD *)v13 + 4) = v7;
      }
      else
      {
LABEL_22:
        Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font>>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font>>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Font>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font>>>>::add<Scaleform::Render::Font *>(
          &pmemAddr,
          &pmemAddr,
          &key,
          v9);
      }
      v6 += 16i64;
      v5 = (Scaleform::GFx::StateBagVtbl *)((char *)v5 - 1);
    }
    while ( v5 );
  }
  v15 = v3 + 2;
  v16 = Scaleform::GFx::StateBag::GetFontLib(v3 + 2, &resulta)->pObject;
  if ( resulta.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
  if ( v16 )
  {
    v17 = v16->pImpl;
    if ( v17 )
    {
      v18 = 0;
      if ( v17->FontMovies.Data.Size )
      {
        v19 = 0i64;
        do
        {
          v20 = v17->FontMovies.Data.Data[v19].pObject;
          v21 = v20->pData.pObject;
          if ( v21->LoadState <= 1 )
            Scaleform::GFx::LoadUpdateSync::WaitForLoadFinished(v21->pFrameUpdate.pObject);
          for ( i = (Scaleform::Ptr<Scaleform::Render::Font> *)v20->pData.pObject->BindData.pFonts.Value;
                i;
                i = (Scaleform::Ptr<Scaleform::Render::Font> *)i[3].pObject )
          {
            v23 = 8i64;
            v24 = 5381i64;
            do
              v24 = *((unsigned __int8 *)&i[1].pObject + --v23) + 65599 * v24;
            while ( v23 );
            if ( !pmemAddr.pTable )
              goto LABEL_48;
            v25 = v24 & pmemAddr.pTable->SizeMask;
            v26 = v25;
            v27 = &pmemAddr.pTable->EntryCount + v25 + 2 * (v25 + 1);
            if ( *v27 == -2i64 || v27[1] != v25 )
              goto LABEL_48;
            while ( v27[1] != v25 || (Scaleform::Render::Font *)v27[2] != i[1].pObject )
            {
              v26 = *v27;
              if ( *v27 == -1i64 )
                goto LABEL_48;
              v27 = &pmemAddr.pTable->EntryCount + v26 + 2 * (v26 + 1);
            }
            if ( v26 >= 0 )
            {
              v28 = (char *)pmemAddr.pTable + 24 * v26;
              v29 = (Scaleform::GFx::Resource *)i[1].pObject;
              if ( v29 )
                Scaleform::Render::RenderBuffer::AddRef(v29);
              v30 = (Scaleform::Render::RenderBuffer *)*((_QWORD *)v28 + 4);
              if ( v30 )
                Scaleform::RefCountImpl::Release(v30);
              *((Scaleform::Ptr<Scaleform::Render::Font> *)v28 + 4) = i[1];
            }
            else
            {
LABEL_48:
              Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font>>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font>>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Font>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font>>>>::add<Scaleform::Ptr<Scaleform::Render::Font>>(
                &pmemAddr,
                &pmemAddr,
                i + 1,
                v24);
            }
          }
          ++v18;
          v17 = v16->pImpl;
          v19 = v18;
        }
        while ( v18 < v17->FontMovies.Data.Size );
      }
    }
  }
  gname.pStr = "flash.text.Font";
  gname.Size = 15i64;
  v31 = (Scaleform::GFx::AS3::ASVM *)v77;
  v32 = Scaleform::GFx::AS3::VM::GetClass(v77, &gname, v77->CurrentDomain.pObject);
  Scaleform::GFx::AS3::VM::MakeArray(v77, &v76);
  if ( pmemAddr.pTable )
  {
    v33 = 0i64;
    v34 = pmemAddr.pTable + 1;
    do
    {
      if ( v34->EntryCount != -2i64 )
        break;
      ++v33;
      v34 = (Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Font>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> > > >::TableType *)((char *)v34 + 24);
    }
    while ( v33 <= pmemAddr.pTable->SizeMask );
    v80.m128i_i64[0] = (__int64)&pmemAddr;
    v80.m128i_i64[1] = v33;
  }
  else
  {
    v80 = 0ui64;
  }
  _mm_store_si128(&v73, v80);
  v35 = v73.m128i_i64[1];
  v36 = v73.m128i_i64[0];
  while ( v36 && *(_QWORD *)v36 && v35 <= *(_QWORD *)(*(_QWORD *)v36 + 8i64) )
  {
    pobj.pObject = 0i64;
    Scaleform::GFx::AS3::ASVM::_constructInstance(v31, &pobj, (Scaleform::GFx::AS3::Object *)&v32->vfptr, 0, 0i64);
    v37 = *(_QWORD *)v36 + 24 * v35;
    v38 = pobj.pObject;
    v39 = *(Scaleform::GFx::Resource **)(v37 + 32);
    if ( v39 )
      Scaleform::Render::RenderBuffer::AddRef(v39);
    v40 = (Scaleform::Render::RenderBuffer *)v38[1].vfptr;
    if ( v40 )
      Scaleform::RefCountImpl::Release(v40);
    v38[1].vfptr = *(Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl **)(v37 + 32);
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    Scaleform::GFx::AS3::Value::AssignUnsafe(&v, pobj.pObject);
    Scaleform::GFx::AS3::Impl::SparseArray::PushBack(&v76.pV->SA, &v);
    if ( (v.Flags & 0x1F) > 9 )
    {
      if ( (v.Flags >> 9) & 1 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    }
    v41 = pobj.pObject;
    if ( pobj.pObject )
    {
      if ( (_QWORD)pobj.pObject & 1 )
      {
        --pobj.pObject;
      }
      else
      {
        v42 = pobj.pObject->RefCount;
        if ( v42 & 0x3FFFFF )
        {
          pobj.pObject->RefCount = v42 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v41->vfptr);
        }
      }
    }
    v43 = *(_QWORD *)(*(_QWORD *)v36 + 8i64);
    if ( v35 <= (signed __int64)v43 && ++v35 <= v43 )
    {
      v44 = (_QWORD *)(*(_QWORD *)v36 + 24 * v35 + 16);
      do
      {
        if ( *v44 != -2i64 )
          break;
        ++v35;
        v44 += 3;
      }
      while ( v35 <= v43 );
    }
  }
  if ( v91 )
  {
    v45 = Scaleform::GFx::StateBag::GetFontProvider(v15, &v81)->pObject;
    if ( v81.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v81.pObject);
    if ( v45 )
    {
      v73.m128i_i64[0] = (__int64)&v92;
      v92 = 0i64;
      v45->vfptr[2].__vecDelDtor((Scaleform::RefCountImplCore *)&v45->vfptr, (unsigned int)&v92);
      if ( v92 )
      {
        v46 = 0i64;
        v47 = (_QWORD *)(v92 + 16);
        do
        {
          if ( *v47 != -2i64 )
            break;
          ++v46;
          v47 += 4;
        }
        while ( v46 <= *(_QWORD *)(v92 + 8) );
        v73.m128i_i64[0] = (__int64)&v92;
        v73.m128i_i64[1] = v46;
      }
      else
      {
        v73 = 0ui64;
      }
      _mm_store_si128(&v73, v73);
      v48 = v73.m128i_i64[1];
      v49 = v73.m128i_i64[0];
      v50 = (Scaleform::GFx::AS3::ASVM *)v77;
      while ( v49 && *(_QWORD *)v49 && v48 <= *(_QWORD *)(*(_QWORD *)v49 + 8i64) )
      {
        v74.pObject = 0i64;
        Scaleform::GFx::AS3::ASVM::_constructInstance(v50, &v74, (Scaleform::GFx::AS3::Object *)&v32->vfptr, 0, 0i64);
        v51 = v74.pObject;
        v52 = *(_QWORD *)(*(_QWORD *)v49 + 32 * (v48 + 1)) & 0xFFFFFFFFFFFFFFFCui64;
        v53 = Scaleform::GFx::ASStringManager::CreateStringNode(
                *(Scaleform::GFx::ASStringManager **)(v74.pObject[1].pRCCRaw + 8),
                (const char *)(v52 + 12),
                *(_QWORD *)v52 & 0x7FFFFFFFFFFFFFFFi64);
        ++v53->RefCount;
        v54 = (Scaleform::GFx::ASStringNode *)v51[1]._pRCC;
        v55 = v54->RefCount-- == 1;
        if ( v55 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v54);
        v51[1].pRCCRaw = (unsigned __int64)v53;
        v85.Flags = 0;
        v85.Bonus.pWeakProxy = 0i64;
        Scaleform::GFx::AS3::Value::AssignUnsafe(&v85, v74.pObject);
        Scaleform::GFx::AS3::Impl::SparseArray::PushBack(&v76.pV->SA, &v85);
        if ( (v85.Flags & 0x1F) > 9 )
        {
          if ( (v85.Flags >> 9) & 1 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v85);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v85);
        }
        v56 = v74.pObject;
        if ( v74.pObject )
        {
          if ( (_QWORD)v74.pObject & 1 )
          {
            --v74.pObject;
          }
          else
          {
            v57 = v74.pObject->RefCount;
            if ( v57 & 0x3FFFFF )
            {
              v74.pObject->RefCount = v57 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v56->vfptr);
            }
          }
        }
        v58 = *(_QWORD *)(*(_QWORD *)v49 + 8i64);
        if ( v48 <= (signed __int64)v58 && ++v48 <= v58 )
        {
          v59 = (_QWORD *)(32 * v48 + *(_QWORD *)v49 + 16i64);
          do
          {
            if ( *v59 != -2i64 )
              break;
            ++v48;
            v59 += 4;
          }
          while ( v48 <= v58 );
        }
      }
      v73.m128i_i64[0] = (__int64)&v92;
      v60 = v92;
      if ( v92 )
      {
        v61 = 0i64;
        v62 = *(_QWORD *)(v92 + 8) + 1i64;
        do
        {
          v63 = (_QWORD *)(v61 + v60);
          if ( *(_QWORD *)(v61 + v60 + 16) != -2i64 )
          {
            v73.m128i_i64[0] = (__int64)(v63 + 4);
            if ( !_InterlockedDecrement((volatile signed __int32 *)((v63[5] & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            if ( !_InterlockedDecrement((volatile signed __int32 *)((v63[4] & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            v63[2] = -2i64;
            v60 = v92;
          }
          v61 += 32i64;
          --v62;
        }
        while ( v62 );
        if ( v60 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v92 = 0i64;
      }
    }
  }
  v64 = v76.pV;
  v65 = v90;
  v66 = v90->pObject;
  if ( v76.pV != v90->pObject )
  {
    if ( v66 )
    {
      if ( (unsigned __int8)v66 & 1 )
      {
        v90->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v66 - 1);
      }
      else
      {
        v67 = v66->RefCount;
        if ( v67 & 0x3FFFFF )
        {
          v66->RefCount = v67 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v66->vfptr);
        }
      }
    }
    v65->pObject = v64;
  }
  v78 = &Scaleform::GFx::MovieDef::ResourceVisitor::`vftable;
  v68 = pmemAddr.pTable;
  if ( pmemAddr.pTable )
  {
    v69 = 0i64;
    v70 = pmemAddr.pTable->SizeMask + 1;
    do
    {
      v71 = (char *)v68 + v69;
      if ( *(unsigned __int64 *)((char *)&v68[1].EntryCount + v69) != -2i64 )
      {
        v72 = (Scaleform::Render::RenderBuffer *)*((_QWORD *)v71 + 4);
        if ( v72 )
          Scaleform::RefCountImpl::Release(v72);
        *((_QWORD *)v71 + 2) = -2i64;
        v68 = pmemAddr.pTable;
      }
      v69 += 24i64;
      --v70;
    }
    while ( v70 );
    if ( v68 )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  }
}

// File Line: 246
// RVA: 0x919650
void __fastcall Scaleform::GFx::AS3::Classes::fl_text::Font::enumerateFonts_::_2_::FontsVisitor::Visit(Scaleform::GFx::MovieDef *__formal, Scaleform::GFx::Resource *presource, __int64 a3, const char *a4)
{
  Scaleform::GFx::MovieDef *v4; // rdi
  __int64 v5; // rbx
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Font>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> > > > *v6; // rcx
  void *v7; // rdx
  Scaleform::Render::Font *key; // [rsp+40h] [rbp+18h]

  v4 = __formal;
  v5 = a3;
  if ( ((*(__int64 (__fastcall **)(__int64, Scaleform::GFx::Resource *, __int64, const char *))(*(_QWORD *)a3 + 16i64))(
          a3,
          presource,
          a3,
          a4) & 0xFF00) == 512 )
  {
    v6 = *(Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Font>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> > > > **)&v4->RefCount.Value;
    v7 = *(void **)&v4->RefCount.Value;
    key = *(Scaleform::Render::Font **)(v5 + 24);
    Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font>>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font>>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Font>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font>>>>::Set<Scaleform::Render::Font *>(
      v6,
      v7,
      &key);
  }
}

// File Line: 311
// RVA: 0x9229B0
void __fastcall Scaleform::GFx::AS3::Classes::fl_text::Font::registerFont(Scaleform::GFx::AS3::Classes::fl_text::Font *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Class *font)
{
  Scaleform::GFx::AS3::Class *v3; // rbx
  Scaleform::GFx::AS3::Classes::fl_text::Font *v4; // rdi
  Scaleform::GFx::AS3::VM *v5; // r14
  __int64 v6; // rax
  Scaleform::GFx::MovieDefImpl *v7; // rbp
  void *(__fastcall *v8)(Scaleform::GFx::AS3::VM *, unsigned int); // rdi
  char v9; // di
  Scaleform::GFx::MovieDefImpl *v10; // rsi
  __int64 v11; // rbx
  signed __int64 v12; // rdi
  signed __int64 v13; // rax
  Scaleform::GFx::MovieDefImpl *v14; // rcx
  int v15; // eax
  Scaleform::GFx::Resource *v16; // rdi
  Scaleform::GFx::ResourceLibBase *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rcx
  bool v19; // zf
  __int64 v20; // rax
  Scaleform::GFx::AS3::VM::Error *v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::String v23; // [rsp+20h] [rbp-48h]
  __int64 v24; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::ResourceBindData pdata; // [rsp+30h] [rbp-38h]
  Scaleform::GFx::AS3::VM::Error v26; // [rsp+40h] [rbp-28h]
  Scaleform::String symbol; // [rsp+80h] [rbp+18h]
  Scaleform::GFx::ASStringNode *v28; // [rsp+88h] [rbp+20h]

  v24 = -2i64;
  v3 = font;
  v4 = this;
  if ( font
    && Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(
         (Scaleform::GFx::AS3::ClassTraits::Traits *)this->pTraits.pObject,
         (Scaleform::GFx::AS3::ClassTraits::Traits *)font->pTraits.pObject) )
  {
    v5 = v4->pTraits.pObject->pVM;
    (*((void (__fastcall **)(Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *, Scaleform::GFx::ASStringNode **, signed __int64))v3->pTraits.pObject[1].vfptr->ForEachChild_GC
     + 5))(
      v3->pTraits.pObject[1].vfptr,
      &v28,
      1i64);
    v6 = ((__int64 (*)(void))v3->pTraits.pObject->vfptr[2].~RefCountBaseGC<328>)();
    if ( v6 )
    {
      v7 = *(Scaleform::GFx::MovieDefImpl **)(*(_QWORD *)(v6 + 152) + 368i64);
      pdata.pResource.pObject = 0i64;
      pdata.pBinding = 0i64;
      Scaleform::String::String(&symbol, v28->pData);
      v8 = v5[1].vfptr[2].__vecDelDtor;
      if ( (unsigned __int8)Scaleform::GFx::MovieDefImpl::GetExportedResource(v7, &pdata, &symbol, 0i64) )
      {
LABEL_5:
        v9 = 1;
      }
      else
      {
        v10 = v7;
        v11 = *((_QWORD *)v8 + 15);
        v12 = (signed __int64)v8 + 112;
        while ( 1 )
        {
          v13 = v12 ? v12 - 8 : 0i64;
          if ( v11 == v13 )
            break;
          v14 = *(Scaleform::GFx::MovieDefImpl **)(v11 + 32);
          if ( v14 != v7 && (unsigned __int8)Scaleform::GFx::MovieDefImpl::DoesDirectlyImport(v14, v10) )
          {
            if ( (unsigned __int8)Scaleform::GFx::MovieDefImpl::GetExportedResource(
                                    *(Scaleform::GFx::MovieDefImpl **)(v11 + 32),
                                    &pdata,
                                    &symbol,
                                    0i64) )
              goto LABEL_5;
            v10 = *(Scaleform::GFx::MovieDefImpl **)(v11 + 32);
          }
          v11 = *(_QWORD *)(v11 + 16);
        }
        v9 = 0;
      }
      if ( !_InterlockedDecrement((volatile signed __int32 *)((symbol.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      if ( v9 )
      {
        if ( pdata.pResource.pObject )
        {
          v15 = ((__int64 (*)(void))pdata.pResource.pObject->vfptr->GetResourceTypeCode)();
          if ( _bittest(&v15, 9u) )
            Scaleform::GFx::MovieImpl::RegisterFont(
              (Scaleform::GFx::MovieImpl *)v5[1].vfptr[2].__vecDelDtor,
              (Scaleform::GFx::MovieDef *)&v7->vfptr,
              (Scaleform::GFx::FontResource *)pdata.pResource.pObject);
        }
      }
      v16 = pdata.pResource.pObject;
      if ( pdata.pResource.pObject && !_InterlockedDecrement(&pdata.pResource.pObject->RefCount.Value) )
      {
        v17 = v16->pLib;
        if ( v17 )
        {
          v17->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v17->vfptr, (unsigned int)v16);
          v16->pLib = 0i64;
        }
        v16->vfptr->__vecDelDtor(v16, 1u);
      }
    }
    v18 = v28;
    v19 = v28->RefCount == 1;
    --v18->RefCount;
    if ( v19 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  }
  else
  {
    Scaleform::String::String(&v23, "unknown");
    if ( v3 )
    {
      v20 = ((__int64 (*)(void))v3->pTraits.pObject->vfptr[2].~RefCountBaseGC<328>)();
      if ( v20 )
        Scaleform::String::operator=(&v23, (Scaleform::String *)(*(_QWORD *)(v20 + 152) + 24i64));
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v26, eSWFHasInvalidData, v4->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(v4->pTraits.pObject->pVM, v21);
    v22 = v26.Message.pNode;
    v19 = v26.Message.pNode->RefCount == 1;
    --v22->RefCount;
    if ( v19 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v22);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v23.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  }
}

// File Line: 371
// RVA: 0x1599CD0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_text::Font_0_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::Array__bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F988 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_text::Font,0,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array>,bool>::Method = Scaleform::GFx::AS3::Classes::fl_text::Font::enumerateFonts;
  return result;
}

// File Line: 372
// RVA: 0x1599CA0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_text::Font_1_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Class_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F998 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_text::Font,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Class *>::Method = Scaleform::GFx::AS3::Classes::fl_text::Font::registerFont;
  return result;
}

// File Line: 397
// RVA: 0x875FD0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_text::Font::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rbx
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v8; // rdi
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rdi

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(v5, v2, &Scaleform::GFx::AS3::fl_text::FontCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_text::Font::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v6->vfptr;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(v7, v2, &Scaleform::GFx::AS3::fl_text::FontCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_text::Font::`vftable;
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
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_text::Font::`vftable;
  }
  return v3;
}

