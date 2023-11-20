// File Line: 44
// RVA: 0x254CF0
void __fastcall UFG::HttpHeader::~HttpHeader(UFG::HttpQueryData *this)
{
  UFG::HttpQueryData *v1; // rbx

  v1 = this;
  UFG::qTreeRB<UFG::Cookie,UFG::Cookie,1>::DeleteAll(&this->mDictionary);
  UFG::qTreeRB<UFG::Cookie,UFG::Cookie,1>::DeleteAll(&v1->mDictionary);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)v1);
}

// File Line: 152
// RVA: 0x254CE0
void __fastcall UFG::HttpBody::~HttpBody(UFG::HttpBody *this)
{
  JUMPOUT(this->mData, 0i64, operator delete[]);
}

