using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using extOSC;

public class Player : MonoBehaviour
{

    //////////////////////////////////////// OSC ////////////////////////////////////////
    // Le code initalise l'état initial du bouton comme relâché
    public extOSC.OSCReceiver oscReceiver;
    // Le code initalise l'état initial du bouton comme relâché
    private int etatEnMemoire = 1;


    void TraiterOscEncoder(OSCMessage message)
    {
    // Si le message n'a pas d'argument ou l'argument n'est pas un Int on l'ignore
        if (message.Values.Count == 0)
        {
            Debug.Log("No value in OSC message");
            return;
        }
            
        if (message.Values[0].Type != OSCValueType.Int)
        {
            Debug.Log("Value in message is not an Int");
            return;
        }

        // Récupérer la valeur du Encoder depuis le message OSC
        int valueEncoder = message.Values[0].IntValue;

        Debug.Log(valueEncoder);
            rb.AddTorque(torqueForce*-valueEncoder);
        
            
    }

    void TraiterOscBouton(OSCMessage message)
    {
    // Si le message n'a pas d'argument ou l'argument n'est pas un Int on l'ignore
        if (message.Values.Count == 0)
        {
            Debug.Log("No value in OSC message");
            return;
        }
            
        if (message.Values[0].Type != OSCValueType.Int)
        {
            Debug.Log("Value in message is not an Int");
            return;
        }

        // Récupérer la valeur du Encoder depuis le message OSC
        int valueBouton = message.Values[0].IntValue;

        int nouveauEtat = valueBouton;
        if (etatEnMemoire != nouveauEtat) { // Le code compare le nouvel etat avec l'etat en mémoire
            etatEnMemoire = nouveauEtat; // Le code met à jour l'état mémorisé
            if ( nouveauEtat  == 0  && IsGrounded()) {
                    rb.AddForce(Vector2.up * jumpForce, ForceMode2D.Impulse);
            }
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////

    public float torqueForce = 1f;
    public float jumpForce = 5f;

    public float checkRadius = 0.1f;
    public LayerMask groundLayer;

    private Rigidbody2D rb;

    void Start()
    {
        // L'OSC déclenche la fonction TraiterOscEncoder()
        oscReceiver.Bind("/encoder", TraiterOscEncoder);
        oscReceiver.Bind("/bouton", TraiterOscBouton);
        rb = GetComponent<Rigidbody2D>();
    }

    void FixedUpdate()
    {
        // Roll left/right
        if (Input.GetKey(KeyCode.RightArrow))
        {
            rb.AddTorque(-torqueForce); // clockwise
        }
        if (Input.GetKey(KeyCode.LeftArrow))
        {
            rb.AddTorque(torqueForce); // counter-clockwise
        }

       
    }

    void Update()
    {
         // Jump
         // GetKeyDown() does not work in FixedUpdate()
        if (Input.GetKeyDown(KeyCode.UpArrow)) 
        {
            if (IsGrounded())
            {
                rb.AddForce(Vector2.up * jumpForce, ForceMode2D.Impulse);
            }
        }
    }

    public bool IsGrounded()
    {
        float extraHeight = 0.1f;
        RaycastHit2D hit = Physics2D.Raycast(
            transform.position,
            Vector2.down,
            GetComponent<CircleCollider2D>().radius + extraHeight,
            groundLayer
        );
        return hit.collider != null;
    }
}
