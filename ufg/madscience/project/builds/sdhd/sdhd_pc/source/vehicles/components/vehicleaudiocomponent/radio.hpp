// File Line: 68
// RVA: 0x66CF10
void __fastcall UFG::RadioStationAsset::~RadioStationAsset(UFG::RadioStationAsset *this)
{
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *v1; // rdx
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *v2; // rcx
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *v3; // rax

  this->vfptr = (UFG::RadioStationAssetVtbl *)&UFG::RadioStationAsset::`vftable';
  v1 = (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *)&this->mPrev;
  v2 = this->mPrev;
  v3 = v1->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mPrev = v1;
  v1->mNext = v1;
}

// File Line: 91
// RVA: 0x66CFE0
void __fastcall UFG::TrackAsset::~TrackAsset(UFG::TrackAsset *this)
{
  UFG::TrackAsset *v1; // rbx
  char *v2; // rcx
  char *v3; // rcx
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *v4; // rdx
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *v5; // rcx
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::RadioStationAssetVtbl *)&UFG::TrackAsset::`vftable';
  v2 = this->m_trackName;
  if ( v2 )
  {
    operator delete[](v2);
    v1->m_trackName = 0i64;
  }
  v3 = v1->m_artistName;
  if ( v3 )
  {
    operator delete[](v3);
    v1->m_artistName = 0i64;
  }
  v1->vfptr = (UFG::RadioStationAssetVtbl *)&UFG::RadioStationAsset::`vftable';
  v4 = (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *)&v1->mPrev;
  v5 = v1->mPrev;
  v6 = v1->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v4->mPrev = v4;
  v4->mNext = v4;
}

// File Line: 217
// RVA: 0x68A500
void __fastcall UFG::RadioStation::SetCurrentlyPlaying(UFG::RadioStation *this, UFG::RadioStationAsset *currentlyPlaying)
{
  UFG::RadioStationAsset *v2; // rbx
  UFG::RadioStation *v3; // rdi
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *v4; // rcx

  v2 = currentlyPlaying;
  v3 = this;
  if ( !currentlyPlaying || currentlyPlaying->m_type )
  {
    UFG::qString::Set(&this->m_currentlyPlayingAssetName, &customWorldMapCaption);
    v3->m_currentlyPlaying = v2;
  }
  else
  {
    v4 = currentlyPlaying[1].mNext;
    if ( v4 && (unsigned int)UFG::qStringCompare((const char *)v4, "(null)", -1) )
    {
      UFG::qString::Format(&v3->m_currentlyPlayingAssetName, "%s - %s\n", v2[1].mNext, v2[1].mPrev);
      v3->m_currentlyPlaying = v2;
    }
    else
    {
      UFG::qString::Format(&v3->m_currentlyPlayingAssetName, "%s\n", v2[1].mPrev);
      v3->m_currentlyPlaying = v2;
    }
  }
}

// File Line: 352
// RVA: 0x66CD20
void __fastcall UFG::Radio::~Radio(UFG::Radio *this)
{
  UFG::Radio *v1; // rbx
  UFG::AudioEvent *v2; // rcx

  v1 = this;
  this->vfptr = (UFG::AudioEntityVtbl *)&UFG::Radio::`vftable';
  v2 = this->m_ecRadio.m_pEvent;
  if ( v2 )
    UFG::AudioEvent::OnControllerDestroy(v2);
  UFG::AudioEntity::~AudioEntity((UFG::AudioEntity *)&v1->vfptr);
}

