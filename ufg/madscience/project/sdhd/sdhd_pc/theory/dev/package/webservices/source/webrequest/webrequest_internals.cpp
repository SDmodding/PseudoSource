// File Line: 44
// RVA: 0x254CF0
void __fastcall UFG::HttpHeader::~HttpHeader(UFG::HttpQueryData *this)
{
  UFG::qTreeRB<UFG::Cookie,UFG::Cookie,1>::DeleteAll(&this->mDictionary);
  UFG::qTreeRB<UFG::Cookie,UFG::Cookie,1>::DeleteAll(&this->mDictionary);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)this);
}

// File Line: 152
// RVA: 0x254CE0
void __fastcall UFG::HttpBody::~HttpBody(UFG::HttpBody *this)
{
  char *mData; // rcx

  mData = this->mData;
  if ( mData )
    operator delete[](mData);
}

