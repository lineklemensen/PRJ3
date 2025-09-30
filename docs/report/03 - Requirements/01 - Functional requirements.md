# Functional requirements

# Actor-Context Diagram

# Actor Description


<table>
  <tr>
    <th>Actor name</th>
    <td>User</td>
  </tr>
  <tr>
    <th>Alternative reference</th>
    <td>Pharmaceutical Nurse</td>
  </tr>
  <tr>
    <th> Actor Type</th>
    <td>Primary</td>
  </tr>
  <tr>
    <th>Description</th>
    <td>Reads what medecin is needed from GUI and packs it into the medecin box on the car and then press a start button</td>
  </tr>
</table>

<table>
  <tr>
    <th>Actor name</th>
    <td>Patient Nurse</td>
  </tr>
  <tr>
    <th>Alternative reference</th>
    <td> Dispensaries Nurse </td>
  </tr>
  <tr>
    <th> Actor Type</th>
    <td>Secondary</td>
  </tr>
  <tr>
    <th>Description</th>
    <td>Nurse opens and empties medecin box on the car, once the medecin box is empty the nurse closes the box and presses a return button</td>
  </tr>
</table>


<table>
  <tr>
    <th>Actor name</th>
    <td>Server</td>
  </tr>
  <tr>
    <th>Alternative reference</th>
    <td>Database</td>
  </tr>
  <tr>
    <th> Actor Type </th>
    <td>Secondary</td>
  </tr>
  <tr>
    <th>Description</th>
    <td>Receives a order request from the GUI to create an order of medecin, and then sends that order to the medecin storage</td>
  </tr>
</table>

