// File Line: 54
// RVA: 0x48CDB0
void __fastcall UFG::PersistentData::ID::ID(UFG::PersistentData::ID *this)
{
  this->mValue = UFG::gNullQSymbol;
}

// File Line: 113
// RVA: 0x48DF50
void __fastcall Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(Render::Poly *this)
{
  this->mVertices = 0i64;
}

// File Line: 180
// RVA: 0x48A930
void __fastcall UFG::PersistentData::IntRanged::IntRanged(UFG::PersistentData::IntRanged *this)
{
  *this = 0i64;
}

// File Line: 204
// RVA: 0x48DEF0
void __fastcall UFG::PersistentData::String::String(UFG::Editor::Terminal::LineInfo *this)
{
  UFG::qString::qString(&this->mText);
}

// File Line: 222
// RVA: 0x3DE8E0
void __fastcall UFG::PersistentData::Binary::Binary(UFG::PersistentData::Binary *this)
{
  this->mpBuffer = 0i64;
  this->mSize = 0;
}

