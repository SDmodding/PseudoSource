// File Line: 68
// RVA: 0x66CF10
void __fastcall UFG::RadioStationAsset::~RadioStationAsset(UFG::RadioStationAsset *this)
{
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *v1; // rdx
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *mPrev; // rcx
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *mNext; // rax

  this->vfptr = (UFG::RadioStationAssetVtbl *)&UFG::RadioStationAsset::`vftable;
  v1 = &this->UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset>;
  mPrev = this->mPrev;
  mNext = v1->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
}

// File Line: 91
// RVA: 0x66CFE0
void __fastcall UFG::TrackAsset::~TrackAsset(UFG::TrackAsset *this)
{
  char *m_trackName; // rcx
  char *m_artistName; // rcx
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *mPrev; // rcx
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *mNext; // rax

  this->vfptr = (UFG::RadioStationAssetVtbl *)&UFG::TrackAsset::`vftable;
  m_trackName = this->m_trackName;
  if ( m_trackName )
  {
    operator delete[](m_trackName);
    this->m_trackName = 0i64;
  }
  m_artistName = this->m_artistName;
  if ( m_artistName )
  {
    operator delete[](m_artistName);
    this->m_artistName = 0i64;
  }
  this->vfptr = (UFG::RadioStationAssetVtbl *)&UFG::RadioStationAsset::`vftable;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset>;
  this->mNext = &this->UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset>;
}

// File Line: 217
// RVA: 0x68A500
void __fastcall UFG::RadioStation::SetCurrentlyPlaying(
        UFG::RadioStation *this,
        UFG::RadioStationAsset *currentlyPlaying)
{
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *mNext; // rcx

  if ( !currentlyPlaying || currentlyPlaying->m_type )
  {
    UFG::qString::Set(&this->m_currentlyPlayingAssetName, &customCaption);
    this->m_currentlyPlaying = currentlyPlaying;
  }
  else
  {
    mNext = currentlyPlaying[1].mNext;
    if ( mNext && (unsigned int)UFG::qStringCompare((const char *)mNext, "(null)", -1) )
    {
      UFG::qString::Format(
        &this->m_currentlyPlayingAssetName,
        "%s - %s\n",
        (const char *)currentlyPlaying[1].mNext,
        (const char *)currentlyPlaying[1].mPrev);
      this->m_currentlyPlaying = currentlyPlaying;
    }
    else
    {
      UFG::qString::Format(&this->m_currentlyPlayingAssetName, "%s\n", (const char *)currentlyPlaying[1].mPrev);
      this->m_currentlyPlaying = currentlyPlaying;
    }
  }
}

// File Line: 352
// RVA: 0x66CD20
void __fastcall UFG::Radio::~Radio(UFG::Radio *this)
{
  UFG::AudioEvent *m_pEvent; // rcx

  this->vfptr = (UFG::AudioEntityVtbl *)&UFG::Radio::`vftable;
  m_pEvent = this->m_ecRadio.m_pEvent;
  if ( m_pEvent )
    UFG::AudioEvent::OnControllerDestroy(m_pEvent);
  UFG::AudioEntity::~AudioEntity(this);
}

