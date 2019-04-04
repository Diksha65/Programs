/*const todolist = document.getElementById("todoul")
function li(text) {
    
    const listitem=document.createElement("li")
    listitem.className="list-group-item"

    var checkbox=document.createElement('input')
    checkbox.type="checkbox"
    checkbox.id="id"
    checkbox.value="name"
    checkbox.checked=false

    const textnode=document.createTextNode(text)
    
    listitem.appendChild(checkbox)
    listitem.appendChild(textnode)
    return listitem
}
*/

const buttonAdd = document.getElementById("button-add")
buttonAdd.addEventListener('click', event => {
    
})

function createlistItem(text) {
    const listitem = document.createElement('li')

    const outerdiv = document.createElement('div')
    outerdiv.className = "input-group mb-3"

    const middlediv = document.createElement('div')
    middlediv.className = "input-group-prepend"

    const innerdiv = document.createElement('div')
    innerdiv.className = "input-group-text"

    const checkbox = document.createElement('input')
    checkbox.type = "checkbox"
    checkbox.checked = onChecked;

    const textitem = document.createTextNode(text)
    
    middlediv.appendChild(innerdiv, checkbox)
}

function createInputElement(onSubmit, onCancel) {
    const outerdiv = document.createElement('div')
    outerdiv.className = "input-group mb-3"

    const edittext = document.createElement('input')
    edittext.className = "form-control"
    edittext.placeholder = "Enter you todo item"
    edittext.required = true
    edittext.type = "text"

    const innerdiv = document.createElement('div');
    innerdiv.className = "input-group-append";

    const submitbutton = document.createElement('button')
    submitbutton.classList.add("btn", "btn-outline-primary");
    submitButton.type = "button";
    submitButton.innerText = "Submit"
    submitButton.onclick = onSubmit;

    const cancelbutton = document.createElement('button')
    cancelbutton.classList.add("btn", "btn-outline-primary");
    cancelbutton.type = "button";
    cancelbutton.innerText = "Cancel"
    cancelbutton.onclick = onCancel;

    innerdiv.appendChild(submitbutton, cancelbutton)
    outerdiv.appendChild(edittext, innerdiv)

    return outerdiv
}
