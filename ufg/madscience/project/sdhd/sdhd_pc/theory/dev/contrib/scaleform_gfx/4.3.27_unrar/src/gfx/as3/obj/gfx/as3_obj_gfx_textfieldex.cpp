// File Line: 50
// RVA: 0x7826E0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::TextFieldEx(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        Scaleform::GFx::AS3::ClassTraits::Traits *t)
{
  Scaleform::GFx::AS3::Class::Class(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::`vftable;
  this->VALIGN_NONE = "none";
  this->VALIGN_TOP = "top";
  this->VALIGN_CENTER = "center";
  this->VALIGN_BOTTOM = "bottom";
  this->TEXTAUTOSZ_NONE = "none";
  this->TEXTAUTOSZ_SHRINK = "shrink";
  this->TEXTAUTOSZ_FIT = "fit";
  this->VAUTOSIZE_NONE = "none";
  this->VAUTOSIZE_TOP = "top";
  this->VAUTOSIZE_CENTER = "center";
  this->VAUTOSIZE_BOTTOM = "bottom";
}

// File Line: 55
// RVA: 0x82C5A0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::appendHtml(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField,
        Scaleform::GFx::ASString *newHtml)
{
  Scaleform::GFx::AS3::Traits *pObject; // rax
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *Size; // rcx
  Scaleform::GFx::TextField *v10; // rbx
  Scaleform::MemoryHeap *v11; // rax
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> pimgInfoArr; // [rsp+38h] [rbp-30h] BYREF

  pObject = this->pTraits.pObject;
  if ( textField )
  {
    if ( pObject->pVM[1].CallStack.gap0[0] )
    {
      v10 = (Scaleform::GFx::TextField *)textField->pDispObj.pObject;
      if ( !Scaleform::GFx::TextField::HasStyleSheet(v10) )
      {
        v11 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v10);
        memset(&pimgInfoArr, 0, 24);
        pimgInfoArr.Data.pHeap = v11;
        Scaleform::Render::Text::DocView::AppendHtml(
          v10->pDocument.pObject,
          newHtml->pNode->pData,
          0xFFFFFFFFFFFFFFFFui64,
          0,
          &pimgInfoArr);
        v10->Flags |= 0x10000u;
        if ( pimgInfoArr.Data.Size )
          Scaleform::GFx::TextField::ProcessImageTags(v10, &pimgInfoArr);
        Scaleform::GFx::TextField::SetDirtyFlag(v10);
        Scaleform::ConstructorMov<Scaleform::Render::Text::StyledText::HTMLImageTagInfo>::DestructArray(
          pimgInfoArr.Data.Data,
          pimgInfoArr.Data.Size);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pimgInfoArr.Data.Data);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&pimgInfoArr, 1507, pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v7,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    Size = (Scaleform::GFx::ASStringNode *)pimgInfoArr.Data.Size;
    if ( (*(_DWORD *)(pimgInfoArr.Data.Size + 24))-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(Size);
  }
}

// File Line: 83
// RVA: 0x85EF40
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::setVerticalAlign(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField,
        Scaleform::GFx::ASString *valign)
{
  Scaleform::GFx::AS3::Traits *pObject; // rax
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::TextField *v10; // r9
  const char *pData; // r8
  __int64 v12; // rax
  __int64 v13; // rdx
  char v14; // cl
  Scaleform::Render::Text::DocView *v15; // rax
  __int64 v16; // rdx
  char v17; // cl
  __int64 v18; // rdx
  char v19; // cl
  char v20; // dl
  Scaleform::GFx::AS3::VM::Error v21; // [rsp+28h] [rbp-20h] BYREF

  pObject = this->pTraits.pObject;
  if ( textField )
  {
    if ( pObject->pVM[1].CallStack.gap0[0] )
    {
      v10 = (Scaleform::GFx::TextField *)textField->pDispObj.pObject;
      pData = valign->pNode->pData;
      v12 = 0i64;
      v13 = 0i64;
      while ( 1 )
      {
        v14 = pData[v13++];
        if ( v14 != aNone[v13 - 1] )
          break;
        if ( v13 == 5 )
        {
          v15 = v10->pDocument.pObject;
          v15->AlignProps &= 0xF3u;
LABEL_20:
          v15->RTFlags |= 1u;
          goto LABEL_21;
        }
      }
      v16 = 0i64;
      while ( 1 )
      {
        v17 = pData[v16++];
        if ( v17 != aTop_2[v16 - 1] )
          break;
        if ( v16 == 4 )
        {
          v15 = v10->pDocument.pObject;
          v15->AlignProps &= ~8u;
          v15->AlignProps |= 4u;
          goto LABEL_20;
        }
      }
      v18 = 0i64;
      while ( 1 )
      {
        v19 = pData[v18++];
        if ( v19 != aBottom[v18 - 1] )
          break;
        if ( v18 == 7 )
        {
          v15 = v10->pDocument.pObject;
          v15->AlignProps &= ~4u;
          v15->AlignProps |= 8u;
          goto LABEL_20;
        }
      }
      while ( 1 )
      {
        v20 = pData[v12++];
        if ( v20 != aCenter_0[v12 - 1] )
          break;
        if ( v12 == 7 )
        {
          v15 = v10->pDocument.pObject;
          v15->AlignProps |= 0xCu;
          goto LABEL_20;
        }
      }
LABEL_21:
      Scaleform::GFx::TextField::SetDirtyFlag(v10);
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v21, 1507, pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v7,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = v21.Message.pNode;
    if ( v21.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 114
// RVA: 0x84D340
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::getVerticalAlign(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField)
{
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString *v8; // rcx
  const char *v9; // rdx
  Scaleform::GFx::AS3::VM::Error v10; // [rsp+28h] [rbp-20h] BYREF

  if ( textField )
  {
    if ( ((BYTE1(textField->pDispObj.pObject[1].pGeomData[3].OrigMatrix.M[1][2]) >> 2) & 3) == 1 )
    {
      v9 = "top";
    }
    else
    {
      if ( ((BYTE1(textField->pDispObj.pObject[1].pGeomData[3].OrigMatrix.M[1][2]) >> 2) & 3) != 2 )
      {
        v8 = result;
        if ( ((BYTE1(textField->pDispObj.pObject[1].pGeomData[3].OrigMatrix.M[1][2]) >> 2) & 3) == 3 )
          v9 = "center";
        else
          v9 = "none";
        goto LABEL_12;
      }
      v9 = "bottom";
    }
    v8 = result;
LABEL_12:
    Scaleform::GFx::ASString::operator=(v8, v9);
    return;
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v10, 1507, this->pTraits.pObject->pVM);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(this->pTraits.pObject->pVM, v5, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
  pNode = v10.Message.pNode;
  if ( v10.Message.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 134
// RVA: 0x85F0D0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::setVerticalAutoSize(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField,
        Scaleform::GFx::ASString *vautoSize)
{
  Scaleform::GFx::AS3::Traits *pObject; // rax
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::TextField *v10; // rdi
  __int64 v11; // rbx
  __int64 v12; // rcx
  char v13; // al
  Scaleform::Render::Text::DocView *v14; // rax
  const char *pData; // rdx
  __int64 v16; // rcx
  char v17; // al
  __int64 v18; // rcx
  char v19; // al
  char v20; // al
  Scaleform::GFx::AS3::VM::Error v21; // [rsp+28h] [rbp-20h] BYREF

  pObject = this->pTraits.pObject;
  if ( textField )
  {
    if ( pObject->pVM[1].CallStack.gap0[0] )
    {
      v10 = (Scaleform::GFx::TextField *)textField->pDispObj.pObject;
      v11 = 0i64;
      v12 = 0i64;
      while ( 1 )
      {
        v13 = vautoSize->pNode->pData[v12++];
        if ( v13 != aNone[v12 - 1] )
          break;
        if ( v12 == 5 )
        {
          v10->pDocument.pObject->Flags &= ~2u;
          v14 = v10->pDocument.pObject;
          v14->AlignProps &= 0xF3u;
LABEL_20:
          v14->RTFlags |= 1u;
          goto LABEL_21;
        }
      }
      Scaleform::Render::Text::DocView::SetAutoSizeY(v10->pDocument.pObject);
      pData = vautoSize->pNode->pData;
      v16 = 0i64;
      while ( 1 )
      {
        v17 = pData[v16++];
        if ( v17 != aTop_2[v16 - 1] )
          break;
        if ( v16 == 4 )
        {
          v14 = v10->pDocument.pObject;
          v14->AlignProps &= ~8u;
          v14->AlignProps |= 4u;
          goto LABEL_20;
        }
      }
      v18 = 0i64;
      while ( 1 )
      {
        v19 = pData[v18++];
        if ( v19 != aBottom[v18 - 1] )
          break;
        if ( v18 == 7 )
        {
          v14 = v10->pDocument.pObject;
          v14->AlignProps &= ~4u;
          v14->AlignProps |= 8u;
          goto LABEL_20;
        }
      }
      while ( 1 )
      {
        v20 = pData[v11++];
        if ( v20 != aCenter_0[v11 - 1] )
          break;
        if ( v11 == 7 )
        {
          v14 = v10->pDocument.pObject;
          v14->AlignProps |= 0xCu;
          goto LABEL_20;
        }
      }
LABEL_21:
      Scaleform::GFx::TextField::SetDirtyFlag(v10);
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v21, 1507, pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v7,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = v21.Message.pNode;
    if ( v21.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 168
// RVA: 0x84D400
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::getVerticalAutoSize(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField)
{
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v7; // zf
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // rcx
  const char *v9; // rdx
  int v10; // ecx
  int v11; // ecx
  Scaleform::GFx::ASString *v12; // rcx
  Scaleform::GFx::AS3::VM::Error v13; // [rsp+28h] [rbp-20h] BYREF

  if ( textField )
  {
    pGeomData = textField->pDispObj.pObject[1].pGeomData;
    if ( (LOBYTE(pGeomData[3].OrigMatrix.M[1][2]) & 2) != 0 )
    {
      v10 = ((BYTE1(pGeomData[3].OrigMatrix.M[1][2]) >> 2) & 3) - 1;
      if ( v10 )
      {
        v11 = v10 - 1;
        if ( v11 )
        {
          v7 = v11 == 1;
          v12 = result;
          if ( v7 )
            v9 = "center";
          else
            v9 = "none";
          goto LABEL_14;
        }
        v9 = "bottom";
      }
      else
      {
        v9 = "top";
      }
    }
    else
    {
      v9 = "none";
    }
    v12 = result;
LABEL_14:
    Scaleform::GFx::ASString::operator=(v12, v9);
    return;
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v13, 1507, this->pTraits.pObject->pVM);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(this->pTraits.pObject->pVM, v5, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
  pNode = v13.Message.pNode;
  v7 = v13.Message.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 193
// RVA: 0x85E9C0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::setTextAutoSize(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField,
        Scaleform::GFx::ASString *autoSz)
{
  Scaleform::GFx::AS3::Traits *pObject; // rax
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::TextField *v10; // r9
  const char *pData; // r8
  __int64 v12; // rax
  __int64 v13; // rdx
  char v14; // cl
  Scaleform::Render::Text::DocView *v15; // rax
  __int64 v16; // rdx
  char v17; // cl
  char v18; // dl
  Scaleform::GFx::AS3::VM::Error v19; // [rsp+28h] [rbp-20h] BYREF

  pObject = this->pTraits.pObject;
  if ( textField )
  {
    if ( pObject->pVM[1].CallStack.gap0[0] )
    {
      v10 = (Scaleform::GFx::TextField *)textField->pDispObj.pObject;
      pData = autoSz->pNode->pData;
      v12 = 0i64;
      v13 = 0i64;
      while ( 1 )
      {
        v14 = pData[v13++];
        if ( v14 != aNone[v13 - 1] )
          break;
        if ( v13 == 5 )
        {
          v15 = v10->pDocument.pObject;
          v15->AlignProps &= 0xCFu;
LABEL_16:
          v15->RTFlags |= 1u;
          goto LABEL_17;
        }
      }
      v16 = 0i64;
      while ( 1 )
      {
        v17 = pData[v16++];
        if ( v17 != aShrink[v16 - 1] )
          break;
        if ( v16 == 7 )
        {
          v15 = v10->pDocument.pObject;
          v15->AlignProps &= ~0x20u;
          v15->AlignProps |= 0x10u;
          goto LABEL_16;
        }
      }
      while ( 1 )
      {
        v18 = pData[v12++];
        if ( v18 != aFit[v12 - 1] )
          break;
        if ( v12 == 4 )
        {
          v15 = v10->pDocument.pObject;
          v15->AlignProps &= ~0x10u;
          v15->AlignProps |= 0x20u;
          goto LABEL_16;
        }
      }
LABEL_17:
      Scaleform::GFx::TextField::SetDirtyFlag(v10);
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v19, 1507, pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v7,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = v19.Message.pNode;
    if ( v19.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 222
// RVA: 0x84CE90
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::getTextAutoSize(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField)
{
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  const char *v8; // rdx
  Scaleform::GFx::AS3::VM::Error v9; // [rsp+28h] [rbp-20h] BYREF

  if ( textField )
  {
    if ( ((BYTE1(textField->pDispObj.pObject[1].pGeomData[3].OrigMatrix.M[1][2]) >> 4) & 3) == 1 )
    {
      v8 = "shrink";
    }
    else if ( ((BYTE1(textField->pDispObj.pObject[1].pGeomData[3].OrigMatrix.M[1][2]) >> 4) & 3) == 2 )
    {
      v8 = "fit";
    }
    else
    {
      v8 = "none";
    }
    Scaleform::GFx::ASString::operator=(result, v8);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v9, 1507, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v5,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = v9.Message.pNode;
    if ( v9.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 241
// RVA: 0x85B3C0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::setIMEEnabled(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField,
        bool isEnabled)
{
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::DisplayObject *pObject; // rax
  Scaleform::GFx::AS3::VM::Error v9; // [rsp+28h] [rbp-20h] BYREF

  if ( textField )
  {
    pObject = textField->pDispObj.pObject;
    if ( isEnabled )
      *(_DWORD *)&pObject[1].BlendMode &= ~0x800u;
    else
      *(_DWORD *)&pObject[1].BlendMode |= 0x800u;
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v9, 1507, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v5,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = v9.Message.pNode;
    if ( v9.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 256
// RVA: 0x85B450
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::setImageSubstitutions(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField,
        Scaleform::GFx::AS3::Value *substInfo)
{
  Scaleform::GFx::AS3::Traits *pObject; // rax
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::AS3::VM *pVM; // r15
  Scaleform::GFx::TextField *v11; // rdi
  unsigned int v12; // ecx
  Scaleform::GFx::AS3::Value::V1U v13; // r12
  unsigned __int64 v14; // rbx
  Scaleform::GFx::ASStringNode *pLower; // rbp
  Scaleform::GFx::AS3::Value *v16; // r14
  char *v17; // rcx
  __int64 v18; // rax
  Scaleform::GFx::AS3::AvmTextField *v19; // rcx
  char *v20; // rcx
  __int64 v21; // rax
  Scaleform::GFx::AS3::AvmTextField *v22; // rsi
  Scaleform::GFx::ASString *Name; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v25; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+80h] [rbp+18h] BYREF

  pObject = this->pTraits.pObject;
  if ( textField )
  {
    pVM = pObject->pVM;
    v11 = (Scaleform::GFx::TextField *)textField->pDispObj.pObject;
    v12 = substInfo->Flags & 0x1F;
    if ( (v12 - 12 > 3 && v12 != 10 || substInfo->value.VS._1.VStr) && v12 )
    {
      if ( v12 - 12 > 3 )
      {
        Name = Scaleform::GFx::DisplayObject::GetName(textField->pDispObj.pObject, &resulta);
        Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
          &v11->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
          "%s.setImageSubstitutions() failed: parameter should be either null, object or array",
          Name->pNode->pData);
        pNode = resulta.pNode;
        v9 = resulta.pNode->RefCount-- == 1;
        if ( v9 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      }
      else
      {
        v13 = substInfo->value.VS._1;
        if ( Scaleform::GFx::AS3::VM::IsOfType(pVM, substInfo, pVM->TraitsArray.pObject) )
        {
          v14 = 0i64;
          pLower = v13.VStr[1].pLower;
          if ( pLower )
          {
            do
            {
              v16 = Scaleform::GFx::AS3::Impl::SparseArray::At(
                      (Scaleform::GFx::AS3::Impl::SparseArray *)&v13.VStr[1].16,
                      v14);
              if ( (v16->Flags & 0x1F) - 12 <= 3 )
              {
                v17 = (char *)v11 + 4 * (unsigned __int8)v11->AvmObjOffset;
                v18 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v17 + 8i64))(v17);
                v19 = (Scaleform::GFx::AS3::AvmTextField *)(v18 - 56);
                if ( !v18 )
                  v19 = 0i64;
                Scaleform::GFx::AS3::AvmTextField::ProceedImageSubstitution(v19, pVM, v14, v16);
              }
              ++v14;
            }
            while ( v14 < (unsigned __int64)pLower );
          }
        }
        else if ( (substInfo->Flags & 0x1F) - 12 <= 3 )
        {
          v20 = (char *)v11 + 4 * (unsigned __int8)v11->AvmObjOffset;
          v21 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v20 + 8i64))(v20);
          if ( v21 )
            v22 = (Scaleform::GFx::AS3::AvmTextField *)(v21 - 56);
          else
            v22 = 0i64;
          Scaleform::GFx::AS3::AvmTextField::ProceedImageSubstitution(v22, pVM, 0, substInfo);
        }
      }
    }
    else
    {
      Scaleform::GFx::TextField::ClearIdImageDescAssoc((Scaleform::GFx::TextField *)textField->pDispObj.pObject);
      Scaleform::GFx::TextField::ClearImageSubstitutor(v11);
      v11->pDocument.pObject->RTFlags |= 2u;
      Scaleform::GFx::TextField::SetDirtyFlag(v11);
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v25, 1507, pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v7,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    v8 = v25.Message.pNode;
    v9 = v25.Message.pNode->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
}

// File Line: 314
// RVA: 0x86B590
// bad sp value at call has been detected, the output may be wrong!
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::updateImageSubstitution(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField,
        Scaleform::GFx::ASString *id)
{
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::TextField *pObject; // rsi
  Scaleform::StringHashLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *pImageDescAssoc; // rdi
  __int64 pImage; // rbx
  unsigned __int64 v12; // rax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *pTable; // r14
  __int64 v14; // rdi
  __int64 v15; // r11
  __int64 *v16; // r10
  unsigned __int8 *v17; // rax
  int v18; // ecx
  int v19; // r8d
  __int64 v20; // r11
  Scaleform::Render::Text::ImageDesc **p_SizeMask; // rdi
  Scaleform::Render::Text::ImageDesc *v22; // r14
  Scaleform::Render::Text::DocView::ImageSubstitutor *ImageSubstitutor; // rax
  Scaleform::GFx::ImageResource *ImageResource; // r15
  Scaleform::GFx::Resource *v25; // rax
  __int64 v26; // rdi
  bool v27; // r12
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> *ImageCreator; // rax
  Scaleform::Render::Image *v29; // rcx
  Scaleform::String v30; // [rsp+0h] [rbp-51h] BYREF
  __int64 v31; // [rsp+8h] [rbp-49h]
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> v32; // [rsp+10h] [rbp-41h] BYREF
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> resulta; // [rsp+18h] [rbp-39h] BYREF
  int v34; // [rsp+20h] [rbp-31h] BYREF
  Scaleform::MemoryHeap *v35; // [rsp+28h] [rbp-29h]
  int v36; // [rsp+30h] [rbp-21h]
  int v37; // [rsp+34h] [rbp-1Dh]
  __int64 v38; // [rsp+38h] [rbp-19h]
  __int64 v39; // [rsp+40h] [rbp-11h]
  __int64 v40; // [rsp+48h] [rbp-9h]
  __int64 v41; // [rsp+50h] [rbp-1h]
  __int64 v42; // [rsp+58h] [rbp+7h]
  Scaleform::GFx::AS3::VM::Error v43; // [rsp+60h] [rbp+Fh] BYREF
  __int64 v44; // [rsp+70h] [rbp+1Fh]
  Scaleform::LogMessageId ida; // [rsp+C0h] [rbp+6Fh] BYREF
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *retaddr; // [rsp+D0h] [rbp+7Fh]

  v44 = -2i64;
  if ( textField )
  {
    pObject = (Scaleform::GFx::TextField *)textField->pDispObj.pObject;
    pImageDescAssoc = pObject->pImageDescAssoc;
    if ( pImageDescAssoc )
    {
      Scaleform::String::String(&v30, id->pNode->pData);
      pImage = 0i64;
      if ( !pImageDescAssoc->mHash.pTable )
        goto LABEL_17;
      v12 = Scaleform::String::BernsteinHashFunctionCIS(
              (const void *)((v30.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
              *(_QWORD *)(v30.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
              0x1505ui64);
      pTable = pImageDescAssoc->mHash.pTable;
      v14 = v12 & pImageDescAssoc->mHash.pTable->SizeMask;
      v15 = v14;
      v16 = (__int64 *)&pTable[2 * v14 + 1];
      if ( *v16 == -2 || v16[1] != v14 )
        goto LABEL_17;
      while ( 1 )
      {
        if ( v16[1] == v14 )
        {
          v17 = (unsigned __int8 *)((v16[2] & 0xFFFFFFFFFFFFFFFCui64) + 12);
          do
          {
            v18 = v17[(v30.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) - (v16[2] & 0xFFFFFFFFFFFFFFFCui64)];
            v19 = *v17 - v18;
            if ( v19 )
              break;
            ++v17;
          }
          while ( v18 );
          if ( !v19 )
            break;
        }
        v15 = *v16;
        if ( *v16 == -1 )
          goto LABEL_17;
        v16 = (__int64 *)&pTable[2 * v15 + 1];
      }
      if ( v15 < 0
        || (v20 = 2 * (v15 + 1), p_SizeMask = (Scaleform::Render::Text::ImageDesc **)&pTable[v20].SizeMask,
                                 !&pTable[v20]) )
      {
LABEL_17:
        p_SizeMask = 0i64;
      }
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v30.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      if ( p_SizeMask )
      {
        v22 = *p_SizeMask;
        if ( retaddr )
        {
          ImageResource = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::GetImageResource(retaddr);
          v25 = (Scaleform::GFx::Resource *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))pObject->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(pObject);
          v26 = (__int64)v25;
          if ( v25 )
            Scaleform::Render::RenderBuffer::AddRef(v25);
          v42 = v26;
          v31 = 0i64;
          if ( ((unsigned int (__fastcall *)(Scaleform::Render::ImageBase *))ImageResource->pImage->vfptr[3].__vecDelDtor)(ImageResource->pImage) )
          {
            pImage = (__int64)ImageResource->pImage;
            if ( pImage )
              (*(void (__fastcall **)(Scaleform::Render::ImageBase *))(*(_QWORD *)pImage + 8i64))(ImageResource->pImage);
            v31 = pImage;
          }
          else
          {
            v27 = Scaleform::GFx::StateBag::GetImageCreator((Scaleform::GFx::StateBag *)(v26 + 24), &resulta)->pObject == 0i64;
            if ( resulta.pObject )
              Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
            if ( v27 )
            {
              ida.Id = 135168;
              Scaleform::LogDebugMessage(
                (Scaleform::LogMessageId)&ida,
                "ImageCreator is null in UpdateImageSubstitution");
            }
            else
            {
              v35 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, pObject);
              v36 = 1;
              v37 = 1;
              v38 = 0i64;
              v39 = 0i64;
              v40 = 0i64;
              v41 = 0i64;
              ImageCreator = Scaleform::GFx::StateBag::GetImageCreator((Scaleform::GFx::StateBag *)(v26 + 24), &v32);
              pImage = ((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *, int *, Scaleform::Render::ImageBase *))ImageCreator->pObject->vfptr[4].__vecDelDtor)(
                         ImageCreator->pObject,
                         &v34,
                         ImageResource->pImage);
              v31 = pImage;
              if ( v32.pObject )
                Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v32.pObject);
            }
          }
          if ( pImage )
            (*(void (__fastcall **)(__int64))(*(_QWORD *)pImage + 8i64))(pImage);
          v29 = v22->pImage.pObject;
          if ( v29 )
            ((void (__fastcall *)(Scaleform::Render::Image *))v29->vfptr[2].__vecDelDtor)(v29);
          v22->pImage.pObject = (Scaleform::Render::Image *)pImage;
          Scaleform::GFx::TextField::SetDirtyFlag(pObject);
          if ( pImage )
            (*(void (__fastcall **)(__int64))(*(_QWORD *)pImage + 16i64))(pImage);
          if ( v26 )
            Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)v26);
        }
        else
        {
          ImageSubstitutor = Scaleform::GFx::TextField::CreateImageSubstitutor(pObject);
          if ( ImageSubstitutor )
          {
            Scaleform::Render::Text::DocView::ImageSubstitutor::RemoveImageDesc(ImageSubstitutor, v22);
            pObject->pDocument.pObject->RTFlags |= 2u;
            Scaleform::GFx::TextField::RemoveIdImageDescAssoc(pObject, id->pNode->pData);
            Scaleform::GFx::TextField::SetDirtyFlag(pObject);
          }
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v43, 1507, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v6,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = v43.Message.pNode;
    if ( v43.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 371
// RVA: 0x85B9B0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::setNoTranslate(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField,
        bool noTranslate)
{
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::DisplayObject *pObject; // rax
  Scaleform::GFx::AS3::VM::Error v9; // [rsp+28h] [rbp-20h] BYREF

  if ( textField )
  {
    pObject = textField->pDispObj.pObject;
    if ( noTranslate )
      *(_DWORD *)&pObject[1].BlendMode |= 8u;
    else
      *(_DWORD *)&pObject[1].BlendMode &= ~8u;
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v9, 1507, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v5,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = v9.Message.pNode;
    if ( v9.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 387
// RVA: 0x84BD20
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::getNoTranslate(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        bool *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField)
{
  Scaleform::GFx::AS3::VM::Error *v4; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v7; // [rsp+28h] [rbp-20h] BYREF

  if ( textField )
  {
    *result = (*(_DWORD *)&textField->pDispObj.pObject[1].BlendMode & 8) != 0;
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v7, 1507, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v4,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = v7.Message.pNode;
    if ( v7.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 401
// RVA: 0x85AED0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::setBidirectionalTextEnabled(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField,
        bool en)
{
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // rax
  Scaleform::GFx::AS3::VM::Error v9; // [rsp+28h] [rbp-20h] BYREF

  if ( textField )
  {
    pGeomData = textField->pDispObj.pObject[1].pGeomData;
    if ( en )
      BYTE2(pGeomData[3].OrigMatrix.M[1][2]) |= 4u;
    else
      BYTE2(pGeomData[3].OrigMatrix.M[1][2]) &= ~4u;
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v9, 1507, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v5,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = v9.Message.pNode;
    if ( v9.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 415
// RVA: 0x84A260
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::getBidirectionalTextEnabled(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        bool *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField)
{
  Scaleform::GFx::AS3::VM::Error *v4; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // rax
  __int64 v8; // rax
  bool v9; // al
  Scaleform::GFx::AS3::VM::Error v10; // [rsp+28h] [rbp-20h] BYREF

  if ( textField )
  {
    pGeomData = textField->pDispObj.pObject[1].pGeomData;
    v9 = 0;
    if ( (BYTE2(pGeomData[3].OrigMatrix.M[1][2]) & 4) != 0 )
    {
      v8 = *(_QWORD *)&pGeomData->OrigMatrix.M[0][0];
      if ( v8 )
      {
        if ( (*(_BYTE *)(v8 + 16) & 0x10) != 0 )
          v9 = 1;
      }
    }
    *result = v9;
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v10, 1507, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v4,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = v10.Message.pNode;
    if ( v10.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 429
// RVA: 0x85E910
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::setSelectionTextColor(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField,
        unsigned int selColor)
{
  Scaleform::GFx::AS3::Traits *pObject; // rax
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  long double Rotation; // rcx
  Scaleform::GFx::AS3::VM::Error v10; // [rsp+28h] [rbp-20h] BYREF

  pObject = this->pTraits.pObject;
  if ( textField )
  {
    if ( pObject->pVM[1].CallStack.gap0[0] )
    {
      Rotation = textField->pDispObj.pObject[1].pGeomData[2].Rotation;
      if ( Rotation != 0.0 )
      {
        *(_DWORD *)(*(_QWORD *)&Rotation + 148i64) = selColor;
        Scaleform::GFx::Text::EditorKit::InvalidateSelectionColors(*(Scaleform::GFx::Text::EditorKit **)&Rotation);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v10, 1507, pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v6,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = v10.Message.pNode;
    if ( v10.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 448
// RVA: 0x84CDA0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::getSelectionTextColor(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        unsigned int *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField)
{
  Scaleform::GFx::AS3::Traits *pObject; // rax
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  long double Rotation; // rax
  Scaleform::GFx::AS3::VM::Error v9; // [rsp+28h] [rbp-20h] BYREF

  pObject = this->pTraits.pObject;
  if ( textField )
  {
    if ( pObject->pVM[1].CallStack.gap0[0] )
    {
      Rotation = textField->pDispObj.pObject[1].pGeomData[2].Rotation;
      if ( Rotation != 0.0 )
        *result = *(_DWORD *)(*(_QWORD *)&Rotation + 148i64);
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v9, 1507, pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v5,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = v9.Message.pNode;
    if ( v9.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 466
// RVA: 0x85E870
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::setSelectionBkgColor(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField,
        unsigned int selColor)
{
  Scaleform::GFx::AS3::Traits *pObject; // rax
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  long double Rotation; // rcx
  Scaleform::GFx::AS3::VM::Error v10; // [rsp+28h] [rbp-20h] BYREF

  pObject = this->pTraits.pObject;
  if ( textField )
  {
    if ( pObject->pVM[1].CallStack.gap0[0] )
    {
      Rotation = textField->pDispObj.pObject[1].pGeomData[2].Rotation;
      if ( Rotation != 0.0 )
      {
        *(_DWORD *)(*(_QWORD *)&Rotation + 144i64) = selColor;
        Scaleform::GFx::Text::EditorKit::InvalidateSelectionColors(*(Scaleform::GFx::Text::EditorKit **)&Rotation);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v10, 1507, pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v6,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = v10.Message.pNode;
    if ( v10.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 485
// RVA: 0x84CD00
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::getSelectionBkgColor(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        unsigned int *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField)
{
  Scaleform::GFx::AS3::Traits *pObject; // rax
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  long double Rotation; // rax
  Scaleform::GFx::AS3::VM::Error v9; // [rsp+28h] [rbp-20h] BYREF

  pObject = this->pTraits.pObject;
  if ( textField )
  {
    if ( pObject->pVM[1].CallStack.gap0[0] )
    {
      Rotation = textField->pDispObj.pObject[1].pGeomData[2].Rotation;
      if ( Rotation != 0.0 )
        *result = *(_DWORD *)(*(_QWORD *)&Rotation + 144i64);
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v9, 1507, pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v5,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = v9.Message.pNode;
    if ( v9.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 503
// RVA: 0x85B6E0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::setInactiveSelectionTextColor(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField,
        unsigned int selColor)
{
  Scaleform::GFx::AS3::Traits *pObject; // rax
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  long double Rotation; // rcx
  Scaleform::GFx::AS3::VM::Error v10; // [rsp+28h] [rbp-20h] BYREF

  pObject = this->pTraits.pObject;
  if ( textField )
  {
    if ( pObject->pVM[1].CallStack.gap0[0] )
    {
      Rotation = textField->pDispObj.pObject[1].pGeomData[2].Rotation;
      if ( Rotation != 0.0 )
      {
        *(_DWORD *)(*(_QWORD *)&Rotation + 156i64) = selColor;
        Scaleform::GFx::Text::EditorKit::InvalidateSelectionColors(*(Scaleform::GFx::Text::EditorKit **)&Rotation);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v10, 1507, pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v6,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = v10.Message.pNode;
    if ( v10.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 522
// RVA: 0x84B8E0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::getInactiveSelectionTextColor(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        unsigned int *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField)
{
  Scaleform::GFx::AS3::Traits *pObject; // rax
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  long double Rotation; // rax
  Scaleform::GFx::AS3::VM::Error v9; // [rsp+28h] [rbp-20h] BYREF

  pObject = this->pTraits.pObject;
  if ( textField )
  {
    if ( pObject->pVM[1].CallStack.gap0[0] )
    {
      Rotation = textField->pDispObj.pObject[1].pGeomData[2].Rotation;
      if ( Rotation != 0.0 )
        *result = *(_DWORD *)(*(_QWORD *)&Rotation + 156i64);
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v9, 1507, pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v5,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = v9.Message.pNode;
    if ( v9.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 540
// RVA: 0x85B640
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::setInactiveSelectionBkgColor(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField,
        unsigned int selColor)
{
  Scaleform::GFx::AS3::Traits *pObject; // rax
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  long double Rotation; // rcx
  Scaleform::GFx::AS3::VM::Error v10; // [rsp+28h] [rbp-20h] BYREF

  pObject = this->pTraits.pObject;
  if ( textField )
  {
    if ( pObject->pVM[1].CallStack.gap0[0] )
    {
      Rotation = textField->pDispObj.pObject[1].pGeomData[2].Rotation;
      if ( Rotation != 0.0 )
      {
        *(_DWORD *)(*(_QWORD *)&Rotation + 152i64) = selColor;
        Scaleform::GFx::Text::EditorKit::InvalidateSelectionColors(*(Scaleform::GFx::Text::EditorKit **)&Rotation);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v10, 1507, pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v6,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = v10.Message.pNode;
    if ( v10.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 559
// RVA: 0x84B840
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::getInactiveSelectionBkgColor(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        unsigned int *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField)
{
  Scaleform::GFx::AS3::Traits *pObject; // rax
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  long double Rotation; // rax
  Scaleform::GFx::AS3::VM::Error v9; // [rsp+28h] [rbp-20h] BYREF

  pObject = this->pTraits.pObject;
  if ( textField )
  {
    if ( pObject->pVM[1].CallStack.gap0[0] )
    {
      Rotation = textField->pDispObj.pObject[1].pGeomData[2].Rotation;
      if ( Rotation != 0.0 )
        *result = *(_DWORD *)(*(_QWORD *)&Rotation + 152i64);
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v9, 1507, pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v5,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = v9.Message.pNode;
    if ( v9.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 604
// RVA: 0x1595D40
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx_0_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_text::TextField_____ptr64_Scaleform::GFx::ASString_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EB40 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx,0,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_text::TextField *,Scaleform::GFx::ASString const &>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::appendHtml;
  return result;
}

// File Line: 605
// RVA: 0x1595C20
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx_1_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_text::TextField_____ptr64_Scaleform::GFx::ASString_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EB50 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_text::TextField *,Scaleform::GFx::ASString const &>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::setVerticalAlign;
  return result;
}

// File Line: 606
// RVA: 0x15934F0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx_2_Scaleform::GFx::ASString_Scaleform::GFx::AS3::Instances::fl_text::TextField_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EB60 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx,2,Scaleform::GFx::ASString,Scaleform::GFx::AS3::Instances::fl_text::TextField *>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::getVerticalAlign;
  return result;
}

// File Line: 607
// RVA: 0x1595C50
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx_3_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_text::TextField_____ptr64_Scaleform::GFx::ASString_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EB70 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx,3,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_text::TextField *,Scaleform::GFx::ASString const &>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::setVerticalAutoSize;
  return result;
}

// File Line: 608
// RVA: 0x1593520
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx_4_Scaleform::GFx::ASString_Scaleform::GFx::AS3::Instances::fl_text::TextField_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EB80 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx,4,Scaleform::GFx::ASString,Scaleform::GFx::AS3::Instances::fl_text::TextField *>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::getVerticalAutoSize;
  return result;
}

// File Line: 609
// RVA: 0x1595C80
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx_5_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_text::TextField_____ptr64_Scaleform::GFx::ASString_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EB90 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx,5,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_text::TextField *,Scaleform::GFx::ASString const &>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::setTextAutoSize;
  return result;
}

// File Line: 610
// RVA: 0x1593550
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx_6_Scaleform::GFx::ASString_Scaleform::GFx::AS3::Instances::fl_text::TextField_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EBA0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx,6,Scaleform::GFx::ASString,Scaleform::GFx::AS3::Instances::fl_text::TextField *>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::getTextAutoSize;
  return result;
}

// File Line: 611
// RVA: 0x1595CB0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx_7_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_text::TextField_____ptr64_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EBB0 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx,7,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_text::TextField *,bool>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::setIMEEnabled;
  return result;
}

// File Line: 612
// RVA: 0x1595CE0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx_8_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_text::TextField_____ptr64_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EBC0 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx,8,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_text::TextField *,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::setImageSubstitutions;
  return result;
}

// File Line: 613
// RVA: 0x1596790
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc3_Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx_9_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_text::TextField_____ptr64_Scaleform::GFx::ASString_const_____ptr64_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EBD0 = v1;
  Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx,9,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_text::TextField *,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Instances::fl_display::BitmapData *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_text::TextField *, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Instances::fl_display::BitmapData *))Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::updateImageSubstitution;
  return result;
}

// File Line: 614
// RVA: 0x1595D10
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx_10_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_text::TextField_____ptr64_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EBE0 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx,10,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_text::TextField *,bool>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::setNoTranslate;
  return result;
}

// File Line: 615
// RVA: 0x1593610
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx_11_bool_Scaleform::GFx::AS3::Instances::fl_text::TextField_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EBF0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx,11,bool,Scaleform::GFx::AS3::Instances::fl_text::TextField *>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::getNoTranslate;
  return result;
}

// File Line: 616
// RVA: 0x1595E00
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx_12_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_text::TextField_____ptr64_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EC00 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx,12,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_text::TextField *,bool>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::setBidirectionalTextEnabled;
  return result;
}

// File Line: 617
// RVA: 0x1593640
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx_13_bool_Scaleform::GFx::AS3::Instances::fl_text::TextField_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EC10 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx,13,bool,Scaleform::GFx::AS3::Instances::fl_text::TextField *>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::getBidirectionalTextEnabled;
  return result;
}

// File Line: 618
// RVA: 0x1595E30
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx_14_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_text::TextField_____ptr64_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EC20 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx,14,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_text::TextField *,unsigned long>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::setSelectionTextColor;
  return result;
}

// File Line: 619
// RVA: 0x1593670
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx_15_unsigned_long_Scaleform::GFx::AS3::Instances::fl_text::TextField_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EC30 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx,15,unsigned long,Scaleform::GFx::AS3::Instances::fl_text::TextField *>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::getSelectionTextColor;
  return result;
}

// File Line: 620
// RVA: 0x1595D70
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx_16_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_text::TextField_____ptr64_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EC40 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx,16,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_text::TextField *,unsigned long>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::setSelectionBkgColor;
  return result;
}

// File Line: 621
// RVA: 0x1593580
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx_17_unsigned_long_Scaleform::GFx::AS3::Instances::fl_text::TextField_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EC50 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx,17,unsigned long,Scaleform::GFx::AS3::Instances::fl_text::TextField *>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::getSelectionBkgColor;
  return result;
}

// File Line: 622
// RVA: 0x1595DA0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx_18_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_text::TextField_____ptr64_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EC60 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx,18,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_text::TextField *,unsigned long>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::setInactiveSelectionTextColor;
  return result;
}

// File Line: 623
// RVA: 0x15935B0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx_19_unsigned_long_Scaleform::GFx::AS3::Instances::fl_text::TextField_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EC70 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx,19,unsigned long,Scaleform::GFx::AS3::Instances::fl_text::TextField *>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::getInactiveSelectionTextColor;
  return result;
}

// File Line: 624
// RVA: 0x1595DD0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx_20_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_text::TextField_____ptr64_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EC80 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx,20,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_text::TextField *,unsigned long>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::setInactiveSelectionBkgColor;
  return result;
}

// File Line: 625
// RVA: 0x15935E0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx_21_unsigned_long_Scaleform::GFx::AS3::Instances::fl_text::TextField_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EC90 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx,21,unsigned long,Scaleform::GFx::AS3::Instances::fl_text::TextField *>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::getInactiveSelectionBkgColor;
  return result;
}

// File Line: 704
// RVA: 0x741F60
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_gfx::TextFieldEx::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rdi
  Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *v9; // rax

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl_gfx::TextFieldExCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_gfx::DisplayObjectEx::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_gfx::InteractiveObjectEx::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_gfx::TextFieldEx::`vftable;
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl_gfx::TextFieldExCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    result->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v8);
  v9 = (Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *)MHeap->vfptr->Alloc(MHeap, 160ui64, 0i64);
  if ( v9 )
    Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::TextFieldEx(v9, result->pV);
  return result;
}

