// Play Note
void note(int note,int dur){
  tone(8,note,dur);
  delay(1+dur);
}
// For Playback
int getNote(char* pass){
  if(pass[0] == 'A'){
    return LA4;
  }else if(pass[0] == 'B'){
  return B4;
  }  else if(pass[0] == 'C'){
    return C4;
  }else if(pass[0] == 'D'){
    return D4;
  }  else if(pass[0] == 'E'){
    return E4;
  }else if(pass[0] == 'F'){
    return F4;
  }else if(pass[0] == 'G'){
    return G4;
  } else if (pass[0] == '*'){
    if(pass[1] == 'A'){
    return Bb4;
  }else if(pass[1] == 'C'){
    return Db4;
  }else if(pass[1] == 'D'){
    return Eb4;
  } else if(pass[1] == 'F'){
    return Gb4;
  }else if(pass[1] == 'G'){
    return Ab4;
  } 
  }    
}

// Success
void victory(){
    note(C4,S);
    note(C4,S);
    note(C4,S);
    note(C4,E+S);
    note(Ab4,E+S);
    note(Bb4,E+S);
    note(C4,E);
    note(Bb4,S);
    note(C4,H);
};
//
void kingdom(){
  note(C4,Q+E);
  note(C4, E);
  note(G3, Q+E);
  note(G3, E);
  note(F3, Q+E);
  note(F3, E);
  note(D4,Q+E);
  note(D4,E);
  //
  note(C4,Q+E);
  note(C4, E);
  note(G3, Q+E);
  note(G3, E);
  note(F3, Q+E);
  note(F3, E);
  note(D4,Q+E);
  note(D4,E);
  //
  note(E4, Q+E);
  note(E4, E);
  note(D4, Q+E);
  note(D4, E);
  note(G4,Q+E);
  note(G4, E);
  note(F4,S);
  note(G4,S);
  note(F4,E+E+S);
  note(F4,E);
};
// Failure
void buzz(){
  note(D3,E);
  note(D3,E);
}

