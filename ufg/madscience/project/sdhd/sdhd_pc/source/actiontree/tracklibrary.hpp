// File Line: 33
// RVA: 0x26E3E0
__int64 __fastcall TrackLibraryNode::GetClassNameUID(TrackLibraryNode *this)
{
  return TrackLibraryNode::sClassNameUID;
}

// File Line: 65
// RVA: 0x3190D0
void __fastcall ExecuteTrackLibraryTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::ExecuteTrackLibraryTrack", 0i64, 1u);
  if ( v0 )
    ExecuteTrackLibraryTrack::ExecuteTrackLibraryTrack((ExecuteTrackLibraryTrack *)v0);
}

