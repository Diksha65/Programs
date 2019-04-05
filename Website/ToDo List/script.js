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

const buttonAlert = document.getElementById("button-alert")
buttonAlert.addEventListener('click', event => {
    
    const listitem = document.getElementById('4thApril-task1')
    const newlistitem = document.createElement('li')
    newlistitem.id="4thAprilalert"

    const divitem = document.createElement('div')
    divitem.classList.add("alert", "alert-dark", "alert-dismissible", "fade", "show")
    divitem.role = "alert"

    const textItem = document.createTextNode('Task for 4th April')

    divitem.appendChild(textItem)
    newlistitem.appendChild(divitem)
    listitem.prepend(newlistitem)
})

const buttonDismiss = document.getElementById("button-dismiss")
buttonDismiss.addEventListener('click', (event) => {
    const element = document.getElementById('4thAprilalert')
    element.parentNode.removeChild(element)
})

const buttonAdd = document.getElementById("button-add")
buttonAdd.addEventListener('click', event => {
    
    var onSubmit = (event) => {
        const edittext = document.getElementById(`id1`)
        const value = edittext.value
        if(value === "")
            alert("Enter something or press cancel.")
        else {
            $('#4thAprilalert').alert('close')
        }
        
    }
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
    
}


function createInputElement(onSubmit, onCancel) {
    const listitem = document.createElement('id')

    const outerdiv = document.createElement('div')
    outerdiv.className = "input-group mb-3"

    const edittext = document.createElement('input')
    edittext.className = "form-control"
    edittext.placeholder = "Enter you todo item"
    edittext.required = true
    edittext.type = "text"
    edittext.id = "id1"

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

    innerdiv.appendChild(submitbutton) 
    innerdiv.appendChild(cancelbutton)
    outerdiv.appendChild(edittext) 
    outerdiv.appendChild(innerdiv)

    return outerdiv
}
