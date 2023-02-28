Attribute VB_Name = "Export"

Sub Export()
  Dim db As DAO.Database
  Dim qdf As DAO.QueryDef
  
  Dim savepath As String
  savepath = Application.CurrentProject.FullName & "saved.sql"
  
  fd = FreeFile
  Open savepath For Output As fd

  Set db = CurrentDb()
  For Each qdf In db.QueryDefs
    Print #fd, "-- Feladat: " & qdf.Name
    Print #fd, qdf.SQL & vbCrLf & vbCrLf
    
  Next qdf

  Set qdf = Nothing
  Set db = Nothing
  Close fd
  
  MsgBox "Successfully dumped to: " & savepath
End Sub
