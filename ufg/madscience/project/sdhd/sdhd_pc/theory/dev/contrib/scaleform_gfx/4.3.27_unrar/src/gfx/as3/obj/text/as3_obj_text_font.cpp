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
void __fastcall Scaleform::GFx::AS3::Instances::fl_text::Font::Font(
        Scaleform::GFx::AS3::Instances::fl_text::Font *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::fl::Object::Object(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_text::Font::`vftable;
  this->pFont.pObject = 0i64;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    t->pVM->StringManagerRef,
    &this->fontName);
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    t->pVM->StringManagerRef,
    &this->fontStyle);
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    t->pVM->StringManagerRef,
    &this->fontType);
}

// File Line: 57
// RVA: 0x91FAD0
void __fastcall Scaleform::GFx::AS3::Instances::fl_text::Font::fontNameGet(
        Scaleform::GFx::AS3::Instances::fl_text::Font *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::Render::Font *pObject; // rdx
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // rbx
  const char *v5; // rax
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString *p_fontName; // rsi
  Scaleform::GFx::ASStringNode *v10; // rcx
  unsigned int Size; // ebx
  unsigned int Length; // eax
  Scaleform::GFx::AS3::Value::V2U v13; // [rsp+30h] [rbp-18h]
  Scaleform::GFx::ASString resulta; // [rsp+50h] [rbp+8h] BYREF

  pObject = this->pFont.pObject;
  if ( pObject )
  {
    StringManagerRef = this->pTraits.pObject->pVM->StringManagerRef;
    v5 = (const char *)((__int64 (__fastcall *)(Scaleform::Render::Font *))pObject->vfptr[1].__vecDelDtor)(this->pFont.pObject);
    v6 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
           StringManagerRef,
           &resulta,
           v5);
    Scaleform::GFx::AS3::Value::Assign(result, v6);
    pNode = resulta.pNode;
    if ( resulta.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    p_fontName = &this->fontName;
    v10 = this->fontName.pNode;
    Size = v10->Size;
    if ( (v10->HashFlags & 0x8000000) == 0 )
    {
      Length = Scaleform::UTF8Util::GetLength(v10->pData, Size);
      if ( Length == Size )
        p_fontName->pNode->HashFlags |= 0x8000000u;
      Size = Length;
    }
    if ( Size )
    {
      Scaleform::GFx::AS3::Value::Assign(result, p_fontName);
    }
    else
    {
      if ( (result->Flags & 0x1F) > 9 )
      {
        if ( (result->Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(result);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(result);
      }
      result->Flags &= 0xFFFFFFEC;
      result->Flags |= 0xCu;
      result->value.VS._1.VStr = 0i64;
      result->value.VS._2 = v13;
    }
  }
}

// File Line: 71
// RVA: 0x91FBE0
void __fastcall Scaleform::GFx::AS3::Instances::fl_text::Font::fontStyleGet(
        Scaleform::GFx::AS3::Instances::fl_text::Font *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::Render::Font *pObject; // rax
  int v4; // eax
  Scaleform::GFx::ASString *v5; // rax
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // rcx
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString *p_fontStyle; // rsi
  Scaleform::GFx::ASStringNode *v12; // rcx
  unsigned int Size; // edi
  unsigned int Length; // eax
  Scaleform::GFx::AS3::Value::V2U v15; // [rsp+30h] [rbp-18h]
  Scaleform::GFx::ASString resulta; // [rsp+50h] [rbp+8h] BYREF

  pObject = this->pFont.pObject;
  if ( pObject )
  {
    v4 = pObject->Flags & 3;
    if ( (v4 & 3) != 0 )
    {
      v5 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
             this->pTraits.pObject->pVM->StringManagerRef,
             &resulta,
             "boldItalic");
      Scaleform::GFx::AS3::Value::Assign(result, v5);
    }
    else if ( (v4 & 2) != 0 )
    {
      v6 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
             this->pTraits.pObject->pVM->StringManagerRef,
             &resulta,
             "bold");
      Scaleform::GFx::AS3::Value::Assign(result, v6);
    }
    else
    {
      StringManagerRef = this->pTraits.pObject->pVM->StringManagerRef;
      if ( (v4 & 1) != 0 )
        v8 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
               StringManagerRef,
               &resulta,
               "italic");
      else
        v8 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
               StringManagerRef,
               &resulta,
               "regular");
      Scaleform::GFx::AS3::Value::Assign(result, v8);
    }
    pNode = resulta.pNode;
    if ( resulta.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    p_fontStyle = &this->fontStyle;
    v12 = this->fontStyle.pNode;
    Size = v12->Size;
    if ( (v12->HashFlags & 0x8000000) == 0 )
    {
      Length = Scaleform::UTF8Util::GetLength(v12->pData, Size);
      if ( Length == Size )
        p_fontStyle->pNode->HashFlags |= 0x8000000u;
      Size = Length;
    }
    if ( Size )
    {
      Scaleform::GFx::AS3::Value::Assign(result, p_fontStyle);
    }
    else
    {
      if ( (result->Flags & 0x1F) > 9 )
      {
        if ( (result->Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(result);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(result);
      }
      result->Flags &= 0xFFFFFFEC;
      result->Flags |= 0xCu;
      result->value.VS._1.VStr = 0i64;
      result->value.VS._2 = v15;
    }
  }
}

// File Line: 93
// RVA: 0x91FD50
void __fastcall Scaleform::GFx::AS3::Instances::fl_text::Font::fontTypeGet(
        Scaleform::GFx::AS3::Instances::fl_text::Font *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::Render::Font *pObject; // rax
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // rcx
  Scaleform::GFx::ASString *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString *p_fontType; // rsi
  Scaleform::GFx::ASStringNode *v9; // rcx
  unsigned int Size; // edi
  unsigned int Length; // eax
  Scaleform::GFx::AS3::Value::V2U v12; // [rsp+30h] [rbp-18h]
  Scaleform::GFx::ASString resulta; // [rsp+50h] [rbp+8h] BYREF

  pObject = this->pFont.pObject;
  if ( pObject )
  {
    StringManagerRef = this->pTraits.pObject->pVM->StringManagerRef;
    if ( (pObject->Flags & 0x10) != 0 )
      v5 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
             StringManagerRef,
             &resulta,
             "device");
    else
      v5 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
             StringManagerRef,
             &resulta,
             "embedded");
    Scaleform::GFx::AS3::Value::Assign(result, v5);
    pNode = resulta.pNode;
    if ( resulta.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    p_fontType = &this->fontType;
    v9 = this->fontType.pNode;
    Size = v9->Size;
    if ( (v9->HashFlags & 0x8000000) == 0 )
    {
      Length = Scaleform::UTF8Util::GetLength(v9->pData, Size);
      if ( Length == Size )
        p_fontType->pNode->HashFlags |= 0x8000000u;
      Size = Length;
    }
    if ( Size )
    {
      Scaleform::GFx::AS3::Value::Assign(result, p_fontType);
    }
    else
    {
      if ( (result->Flags & 0x1F) > 9 )
      {
        if ( (result->Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(result);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(result);
      }
      result->Flags &= 0xFFFFFFEC;
      result->Flags |= 0xCu;
      result->value.VS._1.VStr = 0i64;
      result->value.VS._2 = v12;
    }
  }
}

// File Line: 110
// RVA: 0x920C10
void __fastcall Scaleform::GFx::AS3::Instances::fl_text::Font::hasGlyphs(
        Scaleform::GFx::AS3::Instances::fl_text::Font *this,
        bool *result,
        Scaleform::GFx::ASString *str)
{
  Scaleform::GFx::ASStringNode *pNode; // rax
  char *v6; // r8
  __int64 Size; // rbx
  unsigned __int64 v8; // rbx
  unsigned int Char_Advance0; // eax
  char *putf8Buffer; // [rsp+30h] [rbp+8h] BYREF

  if ( this->pFont.pObject )
  {
    pNode = str->pNode;
    putf8Buffer = (char *)str->pNode->pData;
    v6 = putf8Buffer;
    Size = pNode->Size;
    *result = 1;
    v8 = (unsigned __int64)&v6[Size];
    if ( (unsigned __int64)v6 < v8 )
    {
      while ( 1 )
      {
        Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
        if ( !Char_Advance0 )
          --putf8Buffer;
        if ( (__int64)this->pFont.pObject->vfptr[2].__vecDelDtor(this->pFont.pObject, (unsigned __int16)Char_Advance0) < 0 )
          break;
        if ( (unsigned __int64)putf8Buffer >= v8 )
          return;
      }
      *result = 0;
    }
  }
  else
  {
    *result = 0;
  }
}

// File Line: 136
// RVA: 0x8E45E0
void __fastcall Scaleform::GFx::AS3::Instances::fl_text::Font::InitInstance(
        Scaleform::GFx::AS3::Instances::fl_text::Font *this,
        bool extCall)
{
  if ( !extCall )
    Scaleform::GFx::AS3::Instances::fl_text::Font::CreateLibraryObject(this);
}

// File Line: 146
// RVA: 0x8C0680
bool __fastcall Scaleform::GFx::AS3::Instances::fl_text::Font::CreateLibraryObject(
        Scaleform::GFx::AS3::Instances::fl_text::Font *this)
{
  Scaleform::GFx::AS3::ASVM *pVM; // r15
  Scaleform::GFx::MovieDefImpl *ResourceMovieDef; // r14
  Scaleform::GFx::AS3::Traits *pObject; // rcx
  Scaleform::GFx::MovieImpl *pMovieImpl; // rdi
  char v6; // al
  Scaleform::GFx::MovieDefImpl *v7; // rsi
  Scaleform::GFx::MovieDefRootNode *pNext; // rbx
  Scaleform::List<Scaleform::GFx::MovieDefRootNode,Scaleform::GFx::MovieDefRootNode> *p_RootMovieDefNodes; // rdi
  Scaleform::GFx::MovieDefRootNode *v10; // rax
  Scaleform::GFx::MovieDefImpl *pDefImpl; // rcx
  bool v12; // di
  Scaleform::GFx::AS3::MovieRoot *pMovieRoot; // rdi
  Scaleform::GFx::LogState *v14; // rsi
  const char *v15; // rsi
  Scaleform::GFx::LogState *v16; // rdi
  Scaleform::Render::Font *vfptr; // rdi
  Scaleform::Render::RenderBuffer *v18; // rcx
  Scaleform::GFx::Resource *v19; // rdi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::ResourceBindData pdata; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::GFx::ASStringNode *v25; // [rsp+80h] [rbp+8h] BYREF
  Scaleform::String symbol; // [rsp+88h] [rbp+10h] BYREF
  Scaleform::Ptr<Scaleform::GFx::LogState> result; // [rsp+90h] [rbp+18h] BYREF
  Scaleform::Ptr<Scaleform::GFx::LogState> v28; // [rsp+98h] [rbp+20h] BYREF

  if ( !this->pFont.pObject )
  {
    pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
    ResourceMovieDef = Scaleform::GFx::AS3::ASVM::GetResourceMovieDef(pVM, this);
    if ( ResourceMovieDef )
    {
      pObject = this->pTraits.pObject;
      if ( (pObject->Flags & 0x10) != 0 )
      {
        ((void (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::GFx::ASStringNode **, __int64))pObject->vfptr[1].Finalize_GC)(
          pObject,
          &v25,
          1i64);
        pdata.pResource.pObject = 0i64;
        pdata.pBinding = 0i64;
        Scaleform::String::String(&symbol, v25->pData);
        pMovieImpl = pVM->pMovieRoot->pMovieImpl;
        if ( Scaleform::GFx::MovieDefImpl::GetExportedResource(ResourceMovieDef, &pdata, &symbol, 0i64) )
        {
LABEL_5:
          v6 = 1;
        }
        else
        {
          v7 = ResourceMovieDef;
          pNext = pMovieImpl->RootMovieDefNodes.Root.pNext;
          p_RootMovieDefNodes = &pMovieImpl->RootMovieDefNodes;
          while ( 1 )
          {
            v10 = (Scaleform::GFx::MovieDefRootNode *)&p_RootMovieDefNodes[-1].Root.8;
            if ( !p_RootMovieDefNodes )
              v10 = 0i64;
            if ( pNext == v10 )
              break;
            pDefImpl = pNext->pDefImpl;
            if ( pDefImpl != ResourceMovieDef && Scaleform::GFx::MovieDefImpl::DoesDirectlyImport(pDefImpl, v7) )
            {
              if ( Scaleform::GFx::MovieDefImpl::GetExportedResource(pNext->pDefImpl, &pdata, &symbol, 0i64) )
                goto LABEL_5;
              v7 = pNext->pDefImpl;
            }
            pNext = pNext->pNext;
          }
          v6 = 0;
        }
        v12 = v6 == 0;
        if ( !_InterlockedDecrement((volatile signed __int32 *)((symbol.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        if ( v12 )
        {
          pMovieRoot = pVM->pMovieRoot;
          v14 = Scaleform::GFx::StateBag::GetLogState(&pMovieRoot->pMovieImpl->Scaleform::GFx::StateBag, &result)->pObject;
          if ( result.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
          if ( v14 )
          {
            v15 = v25->pData;
            v16 = Scaleform::GFx::StateBag::GetLogState(&pMovieRoot->pMovieImpl->Scaleform::GFx::StateBag, &v28)->pObject;
            if ( v28.pObject )
              Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v28.pObject);
            Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
              &v16->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
              "Attaching a font with class %s failed",
              v15);
          }
        }
        else if ( pdata.pResource.pObject
               && (((__int64 (__fastcall *)(Scaleform::GFx::Resource *))pdata.pResource.pObject->vfptr->GetResourceTypeCode)(pdata.pResource.pObject) & 0x200) != 0 )
        {
          vfptr = (Scaleform::Render::Font *)pdata.pResource.pObject[1].vfptr;
          if ( vfptr )
            Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pdata.pResource.pObject[1].vfptr);
          v18 = (Scaleform::Render::RenderBuffer *)this->pFont.pObject;
          if ( v18 )
            Scaleform::RefCountImpl::Release(v18);
          this->pFont.pObject = vfptr;
        }
        v19 = pdata.pResource.pObject;
        if ( pdata.pResource.pObject && !_InterlockedDecrement(&pdata.pResource.pObject->RefCount.Value) )
        {
          pLib = v19->pLib;
          if ( pLib )
          {
            pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v19);
            v19->pLib = 0i64;
          }
          v19->vfptr->__vecDelDtor(v19, 1u);
        }
        v21 = v25;
        if ( v25->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v21);
      }
    }
  }
  return 0;
}

// File Line: 210
// RVA: 0x8EADF0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_text::Font::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_text::Font *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_text::Font *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::Font> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::Font> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_text::Font::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 228
// RVA: 0x91EC10
void __fastcall Scaleform::GFx::AS3::Classes::fl_text::Font::enumerateFonts(
        Scaleform::GFx::AS3::Classes::fl_text::Font *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result,
        bool enumerateDeviceFonts)
{
  Scaleform::GFx::StateBag *vecDelDtor; // r15
  __int64 v4; // rcx
  Scaleform::GFx::StateBagVtbl *vfptr; // r14
  __int64 v6; // rsi
  Scaleform::Render::Font *v7; // rdi
  __int64 v8; // rcx
  unsigned __int64 v9; // rbx
  unsigned __int64 v10; // r9
  __int64 v11; // rdx
  unsigned __int64 *v12; // r8
  char *v13; // rbx
  Scaleform::Render::RenderBuffer *v14; // rcx
  Scaleform::GFx::StateBag *v15; // r12
  Scaleform::GFx::FontLib *pObject; // r15
  Scaleform::GFx::FontLibImpl *pImpl; // rax
  unsigned int v18; // r14d
  __int64 v19; // rcx
  Scaleform::GFx::MovieDataDef *v20; // rbx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v21; // rcx
  Scaleform::Ptr<Scaleform::Render::Font> *i; // rsi
  __int64 v23; // rcx
  unsigned __int64 v24; // r9
  unsigned __int64 v25; // r10
  __int64 v26; // rcx
  unsigned __int64 *v27; // r8
  char *v28; // rdi
  Scaleform::GFx::Resource *v29; // rcx
  Scaleform::Render::RenderBuffer *v30; // rcx
  Scaleform::GFx::AS3::ASVM *v31; // r13
  Scaleform::GFx::AS3::Class *Class; // r15
  unsigned __int64 v33; // rax
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Font>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> > > >::TableType *v34; // rdx
  signed __int64 v35; // rbx
  __int64 v36; // rdi
  __int64 v37; // r14
  Scaleform::GFx::AS3::Object *v38; // rsi
  Scaleform::GFx::Resource *v39; // rcx
  Scaleform::Render::RenderBuffer *v40; // rcx
  Scaleform::GFx::AS3::Object *v41; // rcx
  unsigned int RefCount; // eax
  unsigned __int64 v43; // rdx
  _QWORD *v44; // rcx
  Scaleform::GFx::FontProvider *v45; // rbx
  unsigned __int64 v46; // rcx
  _QWORD *v47; // rdx
  signed __int64 v48; // rbx
  Scaleform::GFx::AS3::ASVM *v49; // r12
  Scaleform::GFx::AS3::Object *v50; // rsi
  unsigned __int64 v51; // rdx
  Scaleform::GFx::ASStringNode *StringNode; // r14
  Scaleform::GFx::ASStringNode *pRCC; // rcx
  Scaleform::GFx::AS3::Object *v55; // rcx
  unsigned int v56; // eax
  unsigned __int64 v57; // rdx
  _QWORD *v58; // rcx
  __int64 v59; // rdx
  __int64 v60; // rsi
  __int64 v61; // r14
  _QWORD *v62; // rbx
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *v64; // rdi
  Scaleform::GFx::AS3::Instances::fl::Array *v65; // rcx
  unsigned int v66; // eax
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Font>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> > > >::TableType *pTable; // rdx
  __int64 v68; // rdi
  unsigned __int64 v69; // rsi
  char *v70; // rbx
  Scaleform::Render::RenderBuffer *v71; // rcx
  __int64 *v72; // [rsp+30h] [rbp-D0h]
  __int64 v73; // [rsp+38h] [rbp-C8h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> v74; // [rsp+40h] [rbp-C0h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> pobj; // [rsp+48h] [rbp-B8h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> v76; // [rsp+50h] [rbp-B0h] BYREF
  Scaleform::GFx::AS3::VM *pVM; // [rsp+58h] [rbp-A8h]
  __int64 v78[2]; // [rsp+60h] [rbp-A0h] BYREF
  __int128 v79; // [rsp+70h] [rbp-90h]
  Scaleform::Ptr<Scaleform::GFx::FontProvider> v80; // [rsp+80h] [rbp-80h] BYREF
  Scaleform::Render::Font *v81; // [rsp+88h] [rbp-78h]
  Scaleform::Render::Font *key; // [rsp+90h] [rbp-70h] BYREF
  Scaleform::Ptr<Scaleform::GFx::FontLib> resulta; // [rsp+98h] [rbp-68h] BYREF
  Scaleform::GFx::AS3::Value v84; // [rsp+A0h] [rbp-60h] BYREF
  Scaleform::GFx::AS3::Value v; // [rsp+C0h] [rbp-40h] BYREF
  Scaleform::StringDataPtr gname; // [rsp+E0h] [rbp-20h] BYREF
  __int64 v87; // [rsp+F0h] [rbp-10h]
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Font>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> > > > pmemAddr; // [rsp+150h] [rbp+50h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *v89; // [rsp+158h] [rbp+58h]
  bool v90; // [rsp+160h] [rbp+60h]
  __int64 v91; // [rsp+168h] [rbp+68h] BYREF

  v90 = enumerateDeviceFonts;
  v89 = result;
  v87 = -2i64;
  pVM = this->pTraits.pObject->pVM;
  vecDelDtor = (Scaleform::GFx::StateBag *)pVM[1].vfptr[2].__vecDelDtor;
  v4 = ((__int64 (__fastcall *)(Scaleform::GFx::StateBag *))vecDelDtor->vfptr->~StateBag)(vecDelDtor);
  pmemAddr.pTable = 0i64;
  v78[0] = (__int64)`Scaleform::GFx::AS3::Classes::fl_text::Font::enumerateFonts::`2::FontsVisitor::`vftable;
  v78[1] = (__int64)&pmemAddr;
  (*(void (__fastcall **)(__int64, __int64 *, __int64))(*(_QWORD *)v4 + 208i64))(v4, v78, 1i64);
  vfptr = vecDelDtor[2654].vfptr;
  if ( vfptr )
  {
    v6 = 0i64;
    do
    {
      v7 = (Scaleform::Render::Font *)(*(_QWORD **)((char *)&vecDelDtor[2653].vfptr->~StateBag + v6))[3];
      key = v7;
      if ( v7 )
        Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v7);
      v81 = v7;
      v8 = 8i64;
      v9 = 5381i64;
      do
      {
        --v8;
        v9 = *((unsigned __int8 *)&v81 + v8) + 65599 * v9;
      }
      while ( v8 );
      if ( v7 )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v7);
      if ( !pmemAddr.pTable )
        goto LABEL_22;
      v10 = v9 & pmemAddr.pTable->SizeMask;
      v11 = v10;
      v12 = &pmemAddr.pTable[v10 + 1].EntryCount + v10;
      if ( *v12 == -2i64 || v12[1] != v10 )
        goto LABEL_22;
      while ( v12[1] != v10 || (Scaleform::Render::Font *)v12[2] != v7 )
      {
        v11 = *v12;
        if ( *v12 == -1i64 )
          goto LABEL_22;
        v12 = &pmemAddr.pTable[v11 + 1].EntryCount + v11;
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
          (Scaleform::GFx::Resource **)&key,
          v9);
      }
      v6 += 16i64;
      vfptr = (Scaleform::GFx::StateBagVtbl *)((char *)vfptr - 1);
    }
    while ( vfptr );
  }
  v15 = vecDelDtor + 2;
  pObject = Scaleform::GFx::StateBag::GetFontLib(vecDelDtor + 2, &resulta)->pObject;
  if ( resulta.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
  if ( pObject )
  {
    pImpl = pObject->pImpl;
    if ( pImpl )
    {
      v18 = 0;
      if ( pImpl->FontMovies.Data.Size )
      {
        v19 = 0i64;
        do
        {
          v20 = pImpl->FontMovies.Data.Data[v19].pObject;
          v21 = v20->pData.pObject;
          if ( v21->LoadState <= LS_LoadingFrames )
            Scaleform::GFx::LoadUpdateSync::WaitForLoadFinished(v21->pFrameUpdate.pObject);
          for ( i = (Scaleform::Ptr<Scaleform::Render::Font> *)v20->pData.pObject->BindData.pFonts.Value;
                i;
                i = (Scaleform::Ptr<Scaleform::Render::Font> *)i[3].pObject )
          {
            v23 = 8i64;
            v24 = 5381i64;
            do
            {
              --v23;
              v24 = *((unsigned __int8 *)&i[1].pObject + v23) + 65599 * v24;
            }
            while ( v23 );
            if ( !pmemAddr.pTable )
              goto LABEL_48;
            v25 = v24 & pmemAddr.pTable->SizeMask;
            v26 = v25;
            v27 = &pmemAddr.pTable[v25 + 1].EntryCount + v25;
            if ( *v27 == -2i64 || v27[1] != v25 )
              goto LABEL_48;
            while ( v27[1] != v25 || (Scaleform::Render::Font *)v27[2] != i[1].pObject )
            {
              v26 = *v27;
              if ( *v27 == -1i64 )
                goto LABEL_48;
              v27 = &pmemAddr.pTable[v26 + 1].EntryCount + v26;
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
          pImpl = pObject->pImpl;
          v19 = v18;
        }
        while ( v18 < pImpl->FontMovies.Data.Size );
      }
    }
  }
  gname.pStr = "flash.text.Font";
  gname.Size = 15i64;
  v31 = (Scaleform::GFx::AS3::ASVM *)pVM;
  Class = Scaleform::GFx::AS3::VM::GetClass(pVM, &gname, pVM->CurrentDomain.pObject);
  Scaleform::GFx::AS3::VM::MakeArray(pVM, &v76);
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
    *(_QWORD *)&v79 = &pmemAddr;
    *((_QWORD *)&v79 + 1) = v33;
  }
  else
  {
    v79 = 0ui64;
  }
  v35 = *((_QWORD *)&v79 + 1);
  v36 = v79;
  while ( v36 && *(_QWORD *)v36 && v35 <= *(_QWORD *)(*(_QWORD *)v36 + 8i64) )
  {
    pobj.pObject = 0i64;
    Scaleform::GFx::AS3::ASVM::_constructInstance(
      v31,
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&pobj,
      Class,
      0,
      0i64);
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
      if ( (v.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    }
    v41 = pobj.pObject;
    if ( pobj.pObject )
    {
      if ( ((__int64)pobj.pObject & 1) != 0 )
      {
        --pobj.pObject;
      }
      else
      {
        RefCount = pobj.pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pobj.pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v41);
        }
      }
    }
    v43 = *(_QWORD *)(*(_QWORD *)v36 + 8i64);
    if ( v35 <= (__int64)v43 && ++v35 <= v43 )
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
  if ( v90 )
  {
    v45 = Scaleform::GFx::StateBag::GetFontProvider(v15, &v80)->pObject;
    if ( v80.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v80.pObject);
    if ( v45 )
    {
      v91 = 0i64;
      v45->vfptr[2].__vecDelDtor(v45, (unsigned int)&v91);
      if ( v91 )
      {
        v46 = 0i64;
        v47 = (_QWORD *)(v91 + 16);
        do
        {
          if ( *v47 != -2i64 )
            break;
          ++v46;
          v47 += 4;
        }
        while ( v46 <= *(_QWORD *)(v91 + 8) );
        v72 = &v91;
        v73 = v46;
      }
      else
      {
        v72 = 0i64;
        v73 = 0i64;
      }
      v48 = v73;
      v49 = (Scaleform::GFx::AS3::ASVM *)pVM;
      while ( v72 && *v72 && v48 <= *(_QWORD *)(*v72 + 8) )
      {
        v74.pObject = 0i64;
        Scaleform::GFx::AS3::ASVM::_constructInstance(
          v49,
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v74,
          Class,
          0,
          0i64);
        v50 = v74.pObject;
        v51 = *(_QWORD *)(*v72 + 32 * (v48 + 1)) & 0xFFFFFFFFFFFFFFFCui64;
        StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                       *(Scaleform::GFx::ASStringManager **)(v74.pObject[1].pRCCRaw + 8),
                       (const char *)(v51 + 12),
                       *(_QWORD *)v51 & 0x7FFFFFFFFFFFFFFFi64);
        ++StringNode->RefCount;
        pRCC = (Scaleform::GFx::ASStringNode *)v50[1]._pRCC;
        if ( pRCC->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pRCC);
        v50[1].pRCCRaw = (unsigned __int64)StringNode;
        v84.Flags = 0;
        v84.Bonus.pWeakProxy = 0i64;
        Scaleform::GFx::AS3::Value::AssignUnsafe(&v84, v74.pObject);
        Scaleform::GFx::AS3::Impl::SparseArray::PushBack(&v76.pV->SA, &v84);
        if ( (v84.Flags & 0x1F) > 9 )
        {
          if ( (v84.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v84);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v84);
        }
        v55 = v74.pObject;
        if ( v74.pObject )
        {
          if ( ((__int64)v74.pObject & 1) != 0 )
          {
            --v74.pObject;
          }
          else
          {
            v56 = v74.pObject->RefCount;
            if ( (v56 & 0x3FFFFF) != 0 )
            {
              v74.pObject->RefCount = v56 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v55);
            }
          }
        }
        v57 = *(_QWORD *)(*v72 + 8);
        if ( v48 <= (__int64)v57 && ++v48 <= v57 )
        {
          v58 = (_QWORD *)(32 * v48 + *v72 + 16);
          do
          {
            if ( *v58 != -2i64 )
              break;
            ++v48;
            v58 += 4;
          }
          while ( v48 <= v57 );
        }
      }
      v59 = v91;
      if ( v91 )
      {
        v60 = 0i64;
        v61 = *(_QWORD *)(v91 + 8) + 1i64;
        do
        {
          v62 = (_QWORD *)(v60 + v59);
          if ( *(_QWORD *)(v60 + v59 + 16) != -2i64 )
          {
            if ( !_InterlockedDecrement((volatile signed __int32 *)((v62[5] & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            if ( !_InterlockedDecrement((volatile signed __int32 *)((v62[4] & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            v62[2] = -2i64;
            v59 = v91;
          }
          v60 += 32i64;
          --v61;
        }
        while ( v61 );
        if ( v59 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v91 = 0i64;
      }
    }
  }
  pV = v76.pV;
  v64 = v89;
  v65 = v89->pObject;
  if ( v76.pV != v89->pObject )
  {
    if ( v65 )
    {
      if ( ((unsigned __int8)v65 & 1) != 0 )
      {
        v89->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v65 - 1);
      }
      else
      {
        v66 = v65->RefCount;
        if ( (v66 & 0x3FFFFF) != 0 )
        {
          v65->RefCount = v66 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v65);
        }
      }
    }
    v64->pObject = pV;
  }
  v78[0] = (__int64)&Scaleform::GFx::MovieDef::ResourceVisitor::`vftable;
  pTable = pmemAddr.pTable;
  if ( pmemAddr.pTable )
  {
    v68 = 0i64;
    v69 = pmemAddr.pTable->SizeMask + 1;
    do
    {
      v70 = (char *)pTable + v68;
      if ( *(unsigned __int64 *)((char *)&pTable[1].EntryCount + v68) != -2i64 )
      {
        v71 = (Scaleform::Render::RenderBuffer *)*((_QWORD *)v70 + 4);
        if ( v71 )
          Scaleform::RefCountImpl::Release(v71);
        *((_QWORD *)v70 + 2) = -2i64;
        pTable = pmemAddr.pTable;
      }
      v68 += 24i64;
      --v69;
    }
    while ( v69 );
    if ( pTable )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 246
// RVA: 0x919650
void __fastcall Scaleform::GFx::AS3::Classes::fl_text::Font::enumerateFonts_::_2_::FontsVisitor::Visit(
        Scaleform::GFx::MovieDef *__formal,
        Scaleform::GFx::Resource *presource,
        Scaleform::Render::Font **a3,
        const char *a4)
{
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Font>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> > > > *v6; // rcx
  Scaleform::Render::Font *key; // [rsp+40h] [rbp+18h] BYREF

  if ( ((*(__int64 (__fastcall **)(Scaleform::Render::Font **, Scaleform::GFx::Resource *, Scaleform::Render::Font **, const char *))&(*a3)->Ascent)(
          a3,
          presource,
          a3,
          a4) & 0xFF00) == 512 )
  {
    v6 = *(Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Font>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> > > > **)&__formal->RefCount.Value;
    key = a3[3];
    Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font>>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font>>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Font>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font>>>>::Set<Scaleform::Render::Font *>(
      v6,
      v6,
      (Scaleform::GFx::Resource **)&key);
  }
}

// File Line: 311
// RVA: 0x9229B0
void __fastcall Scaleform::GFx::AS3::Classes::fl_text::Font::registerFont(
        Scaleform::GFx::AS3::Classes::fl_text::Font *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Class *font)
{
  Scaleform::GFx::AS3::VM *pVM; // r14
  __int64 v6; // rax
  Scaleform::GFx::MovieDefImpl *v7; // rbp
  void *(__fastcall *vecDelDtor)(Scaleform::GFx::AS3::VM *, unsigned int); // rdi
  char v9; // di
  Scaleform::GFx::MovieDefImpl *v10; // rsi
  __int64 v11; // rbx
  char *v12; // rdi
  __int64 v13; // rax
  Scaleform::GFx::MovieDefImpl *v14; // rcx
  Scaleform::GFx::Resource *pObject; // rdi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::ASStringNode *v17; // rcx
  bool v18; // zf
  __int64 v19; // rax
  Scaleform::GFx::AS3::VM::Error *v20; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::String v22; // [rsp+20h] [rbp-48h] BYREF
  __int64 v23; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::ResourceBindData pdata; // [rsp+30h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::VM::Error v25; // [rsp+40h] [rbp-28h] BYREF
  Scaleform::String symbol; // [rsp+80h] [rbp+18h] BYREF
  Scaleform::GFx::ASStringNode *v27; // [rsp+88h] [rbp+20h] BYREF

  v23 = -2i64;
  if ( font
    && Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(
         (Scaleform::GFx::AS3::ClassTraits::Traits *)this->pTraits.pObject,
         (Scaleform::GFx::AS3::ClassTraits::Traits *)font->pTraits.pObject) )
  {
    pVM = this->pTraits.pObject->pVM;
    (*((void (__fastcall **)(Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *, Scaleform::GFx::ASStringNode **, __int64))font->pTraits.pObject[1].vfptr->ForEachChild_GC
     + 5))(
      font->pTraits.pObject[1].vfptr,
      &v27,
      1i64);
    v6 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *))font->pTraits.pObject->Scaleform::GFx::AS3::Object::vfptr[2].~RefCountBaseGC<328>)(font->pTraits.pObject);
    if ( v6 )
    {
      v7 = *(Scaleform::GFx::MovieDefImpl **)(*(_QWORD *)(v6 + 152) + 368i64);
      pdata.pResource.pObject = 0i64;
      pdata.pBinding = 0i64;
      Scaleform::String::String(&symbol, v27->pData);
      vecDelDtor = pVM[1].vfptr[2].__vecDelDtor;
      if ( Scaleform::GFx::MovieDefImpl::GetExportedResource(v7, &pdata, &symbol, 0i64) )
      {
LABEL_5:
        v9 = 1;
      }
      else
      {
        v10 = v7;
        v11 = *((_QWORD *)vecDelDtor + 15);
        v12 = (char *)vecDelDtor + 112;
        while ( 1 )
        {
          v13 = v12 ? (__int64)(v12 - 8) : 0i64;
          if ( v11 == v13 )
            break;
          v14 = *(Scaleform::GFx::MovieDefImpl **)(v11 + 32);
          if ( v14 != v7 && (unsigned __int8)Scaleform::GFx::MovieDefImpl::DoesDirectlyImport(v14, v10) )
          {
            if ( Scaleform::GFx::MovieDefImpl::GetExportedResource(
                   *(Scaleform::GFx::MovieDefImpl **)(v11 + 32),
                   &pdata,
                   &symbol,
                   0i64) )
            {
              goto LABEL_5;
            }
            v10 = *(Scaleform::GFx::MovieDefImpl **)(v11 + 32);
          }
          v11 = *(_QWORD *)(v11 + 16);
        }
        v9 = 0;
      }
      if ( !_InterlockedDecrement((volatile signed __int32 *)((symbol.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      if ( v9
        && pdata.pResource.pObject
        && (((__int64 (__fastcall *)(Scaleform::GFx::Resource *))pdata.pResource.pObject->vfptr->GetResourceTypeCode)(pdata.pResource.pObject) & 0x200) != 0 )
      {
        Scaleform::GFx::MovieImpl::RegisterFont(
          (Scaleform::GFx::MovieImpl *)pVM[1].vfptr[2].__vecDelDtor,
          v7,
          (Scaleform::GFx::FontResource *)pdata.pResource.pObject);
      }
      pObject = pdata.pResource.pObject;
      if ( pdata.pResource.pObject && !_InterlockedDecrement(&pdata.pResource.pObject->RefCount.Value) )
      {
        pLib = pObject->pLib;
        if ( pLib )
        {
          pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)pObject);
          pObject->pLib = 0i64;
        }
        pObject->vfptr->__vecDelDtor(pObject, 1u);
      }
    }
    v17 = v27;
    v18 = v27->RefCount-- == 1;
    if ( v18 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  }
  else
  {
    Scaleform::String::String(&v22, "unknown");
    if ( font )
    {
      v19 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *))font->pTraits.pObject->Scaleform::GFx::AS3::Object::vfptr[2].~RefCountBaseGC<328>)(font->pTraits.pObject);
      if ( v19 )
        Scaleform::String::operator=(&v22, (Scaleform::String *)(*(_QWORD *)(v19 + 152) + 24i64));
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v25, 2136, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v20);
    pNode = v25.Message.pNode;
    v18 = v25.Message.pNode->RefCount-- == 1;
    if ( v18 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v22.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
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
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_text::Font::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v8; // rdi
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rdi

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(v5, vm, &Scaleform::GFx::AS3::fl_text::FontCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_text::Font::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(v7, vm, &Scaleform::GFx::AS3::fl_text::FontCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_text::Font::`vftable;
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
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_text::Font::`vftable;
  }
  return result;
}

