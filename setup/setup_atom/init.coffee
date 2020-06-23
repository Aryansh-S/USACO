# Your init script
#
# Atom will evaluate this file each time a new window is opened. It is run
# after packages are loaded/activated and after the previous editor state
# has been restored.
#
# An example hack to log to the console when each text editor is saved.
#
# atom.workspace.observeTextEditors (editor) ->
#   editor.onDidSave ->
#     console.log "Saved! #{editor.getPath()}"

 atom.commands.add 'atom-text-editor', 'template:widget', ->
  config = '<insert path>' #set path to local GitHub
  fs = require 'fs'
  foo = ->
    fs.readFileSync config, 'utf8' #get file contents
  
  setter = atom.workspace.getActiveTextEditor(); #get the editor
  
  setter.setText(foo()); #put file contents
  
  setter.moveToBottom(); #bottom of file
  setter.moveToBeginningOfPreviousParagraph(); #above comments
  setter.moveUp(2); #2 lines up (to the beginning of the IO line)
  
  setter.moveToEndOfLine() #get to the end of the IO line
  setter.insertNewline(); #enter to a new line
  
  setter.scrollToBottom(); #scroll to bottom of file for focus

  
