// File Line: 19
// RVA: 0x62FD40
void __fastcall UFG::UISlot::highlight(UFG::UISlot *this)
{
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  if ( !this->m_isHighlighted )
  {
    this->m_isHighlighted = 1;
    UFG::operator+(&result, &this->m_pathToSlot, ".highlight");
    Scaleform::GFx::Movie::Invoke(this->m_screen->mRenderable->m_movie.pObject, result.mData, &customCaption);
    UFG::qString::~qString(&result);
  }
}

// File Line: 33
// RVA: 0x63B850
void __fastcall UFG::UISlot::unhighlight(UFG::UISlot *this)
{
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  if ( this->m_isHighlighted )
  {
    this->m_isHighlighted = 0;
    UFG::operator+(&result, &this->m_pathToSlot, ".unhighlight");
    Scaleform::GFx::Movie::Invoke(this->m_screen->mRenderable->m_movie.pObject, result.mData, &customCaption);
    UFG::qString::~qString(&result);
  }
}

// File Line: 47
// RVA: 0x63A420
void __fastcall UFG::UISlot::select(UFG::UISlot *this)
{
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  UFG::operator+(&result, &this->m_pathToSlot, ".select");
  Scaleform::GFx::Movie::Invoke(this->m_screen->mRenderable->m_movie.pObject, result.mData, &customCaption);
  UFG::qString::~qString(&result);
}

// File Line: 57
// RVA: 0x63B2E0
void __fastcall UFG::UISlot::show(UFG::UISlot *this)
{
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  if ( this->m_isHidden )
  {
    this->m_isHidden = 0;
    UFG::operator+(&result, &this->m_pathToSlot, ".show");
    Scaleform::GFx::Movie::Invoke(this->m_screen->mRenderable->m_movie.pObject, result.mData, &customCaption);
    UFG::qString::~qString(&result);
  }
}

// File Line: 72
// RVA: 0x62FC60
void __fastcall UFG::UISlot::hide(UFG::UISlot *this)
{
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  if ( !this->m_isHidden )
  {
    this->m_isHidden = 1;
    UFG::operator+(&result, &this->m_pathToSlot, ".hide");
    Scaleform::GFx::Movie::Invoke(this->m_screen->mRenderable->m_movie.pObject, result.mData, &customCaption);
    UFG::qString::~qString(&result);
  }
}

